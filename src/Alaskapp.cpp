#include "Alaskapp.h"
#include "Gerenciador_Eventos.h"
#include "Menu.h"

using namespace Alaska;

Alaska::Alaskapp::Alaskapp()
    : GG(), pJog1(nullptr), pJog2(nullptr), pFaseSelecionada(nullptr), pFase(nullptr),
      faseEscolhida(TipoFase::NENHUMA), estado(EstadoJogo::MENU), qntd_pontos(0),
      qntdJogadores(0), pausado(false), faseCarregadaDeSave(false), tempoPartidaSegundos(0.0f)
{
    executar();
}

Alaska::Alaskapp::~Alaskapp()
{
    delete pFase;
    pFase = nullptr;
    limparJogadores();
}

void Alaskapp::executar()
{
    sementear();

    Gerenciadores::Gerenciador_Eventos GE;
    Ente::setGG(&GG);
    Alaska::Menu menu(this, &GE);
    GE.setJanela(GG.getJanela());
    GE.setMenu(&menu);

    while (GG.isJanelaAberta())
    {
        switch (estado)
        {
        case EstadoJogo::MENU:
            executarMenu(&menu, GE);
            break;

        case EstadoJogo::FASE:
            executarFase(GE);
            break;

        case EstadoJogo::ENCERRANDO:
            return;
        }
    }
}

void Alaska::Alaskapp::sementear()
{
    srand(time(NULL));
}

void Alaska::Alaskapp::limparJogadores()
{
    delete pJog1;
    delete pJog2;
    pJog1 = nullptr;
    pJog2 = nullptr;
    qntdJogadores = 0;
}

void Alaska::Alaskapp::criarJogadores(int qntd)
{
    delete pFase;
    pFase = nullptr;
    limparJogadores();

    qntdJogadores = qntd;
    qntd_pontos = 0;
    tempoPartidaSegundos = 0.0f;
    faseCarregadaDeSave = false;
    pausado = false;

    if (qntd >= 1)
        pJog1 = new Entidades::Personagens::Jogador(1);
    if (qntd >= 2)
        pJog2 = new Entidades::Personagens::Jogador(2);
}

void Alaska::Alaskapp::setNomeJogador(int indice, const std::string& nome)
{
    if (indice == 1 && pJog1)
        pJog1->setNome(nome);
    else if (indice == 2 && pJog2)
        pJog2->setNome(nome);
}

bool Alaska::Alaskapp::verificarJogadores() const
{
    if (pJog1 && pJog1->estaVivo() && (!pJog2 || pJog2->estaVivo()))
        return true;
    return false;
}

void Alaskapp::executarFase(Gerenciadores::Gerenciador_Eventos& GE)
{
    if (!pFase) return;

    GE.setMenu(nullptr);
    GE.setJogadores(pJog1, pJog2);

    if (!faseCarregadaDeSave)
    {
        if (pJog1) pJog1->resetar();
        if (pJog2) pJog2->resetar();
        pFase->iniciarFase(getNumeroFaseAtual());
    }
    else
    {
        faseCarregadaDeSave = false;
    }

    pausado = false;
    sf::Clock relogioLoop;

    while (GG.isJanelaAberta() && verificarJogadores() && !pFase->terminou())
    {
        GE.verificarEventos(!pausado);

        if (GE.pause())
            pausado = !pausado;

        if (GE.salvaEstadoAtual() && !pausado)
            salvarJogoAtual();

        const float delta = relogioLoop.restart().asSeconds();
        if (!pausado)
            tempoPartidaSegundos += delta;

        qntd_pontos = pJog1 ? pJog1->getPontos() : 0;
        if (pJog2)
            qntd_pontos += pJog2->getPontos();

        GG.limpar();

        if (pausado)
            pFase->desenharEstadoAtual();
        else
            pFase->executar();

        GG.mostrarPontos(qntd_pontos);

        if (pausado)
            GG.desenharOverlayPausa();

        GG.mostrar();
    }

    const bool concluiuComSucesso = verificarJogadores() && pFase->faseTerminada();
    const TipoFase faseFinalizada = faseEscolhida;

    delete pFase;
    pFase = nullptr;
    pausado = false;

    if (concluiuComSucesso && faseFinalizada == TipoFase::TUNDRA)
    {
        faseEscolhida = TipoFase::CAVERNA;
        criarFaseSelecionada();
        estado = EstadoJogo::FASE;
        return;
    }

    if (concluiuComSucesso && faseFinalizada == TipoFase::CAVERNA)
        registrarResultadoLeaderboard();

    GE.setMenu(nullptr);
    estado = EstadoJogo::MENU;
}

Alaska::Fases::Fase* Alaska::Alaskapp::criarFase(short numFase)
{
    switch (numFase)
    {
    case 1: return new Fases::Tundra(pJog1, pJog2);
    case 2: return new Fases::Caverna(pJog1, pJog2);
    default: return nullptr;
    }
}

void Alaskapp::executarMenu(Alaska::Menu* pMenu, Gerenciadores::Gerenciador_Eventos& GE)
{
    GE.setJogadores(nullptr, nullptr);
    GE.setMenu(pMenu);

    pMenu->reset();
    pMenu->executar();

    if (!GG.isJanelaAberta())
        return;

    if (!pFase)
        criarFaseSelecionada();

    estado = pFase ? EstadoJogo::FASE : EstadoJogo::MENU;
}

void Alaskapp::criarFaseSelecionada()
{
    delete pFase;
    pFase = nullptr;

    switch (faseEscolhida)
    {
    case TipoFase::TUNDRA:
        pFase = new Fases::Tundra(pJog1, pJog2);
        break;

    case TipoFase::CAVERNA:
        pFase = new Fases::Caverna(pJog1, pJog2);
        break;

    default:
        break;
    }
}

int Alaskapp::getNumeroFaseAtual() const
{
    return faseEscolhida == TipoFase::CAVERNA ? 2 : 1;
}

bool Alaskapp::salvarJogoAtual()
{
    if (!pFase || !pJog1)
        return false;

    garantirPastaSaveAlaska();
    pFase->salvarEstado();

    std::ofstream meta(CAMINHO_META_SAVE, std::ios::trunc);
    if (!meta.is_open())
        return false;

    meta << "fase=" << getNumeroFaseAtual() << "\n";
    meta << "jogadores=" << (pJog2 ? 2 : 1) << "\n";
    meta << "tempo=" << tempoPartidaSegundos << "\n";
    meta.close();

    printf("Jogo salvo com sucesso.\n");
    return true;
}

bool Alaskapp::carregarJogoSalvo()
{
    std::ifstream meta(CAMINHO_META_SAVE);
    std::ifstream save(CAMINHO_SAVE);

    if (!meta.is_open() || !save.is_open())
        return false;

    int fase = 1;
    int jogadores = 1;
    float tempo = 0.0f;
    std::string linha;

    while (std::getline(meta, linha))
    {
        const size_t pos = linha.find('=');
        if (pos == std::string::npos)
            continue;

        const std::string chave = linha.substr(0, pos);
        const std::string valor = linha.substr(pos + 1);

        try
        {
            if (chave == "fase")
                fase = std::stoi(valor);
            else if (chave == "jogadores")
                jogadores = std::stoi(valor);
            else if (chave == "tempo")
                tempo = std::stof(valor);
        }
        catch (const std::exception&)
        {
        }
    }

    meta.close();
    save.close();

    criarJogadores(jogadores);
    tempoPartidaSegundos = tempo;
    faseEscolhida = (fase == 2) ? TipoFase::CAVERNA : TipoFase::TUNDRA;

    criarFaseSelecionada();
    if (!pFase)
        return false;

    pFase->carregarFaseSalva(static_cast<short>(fase));
    faseCarregadaDeSave = true;
    pausado = false;

    qntd_pontos = pJog1 ? pJog1->getPontos() : 0;
    if (pJog2)
        qntd_pontos += pJog2->getPontos();

    return true;
}

void Alaskapp::registrarResultadoLeaderboard()
{
    if (!pJog1)
        return;

    struct Registro
    {
        std::string nome;
        int pontos;
        float tempo;
    };

    std::vector<Registro> registros;
    std::ifstream entrada(CAMINHO_LEADERBOARD);
    std::string linha;

    while (std::getline(entrada, linha))
    {
        std::stringstream ss(linha);
        std::string nome, pontosStr, tempoStr;

        if (std::getline(ss, nome, ';') && std::getline(ss, pontosStr, ';') && std::getline(ss, tempoStr, ';'))
        {
            try
            {
                registros.push_back({ nome, std::stoi(pontosStr), std::stof(tempoStr) });
            }
            catch (const std::exception&)
            {
            }
        }
    }

    std::string nomeRegistro = pJog1->getNome();
    if (pJog2)
        nomeRegistro += " & " + pJog2->getNome();

    registros.push_back({ nomeRegistro, qntd_pontos, tempoPartidaSegundos });

    std::sort(registros.begin(), registros.end(), [](const Registro& a, const Registro& b)
    {
        if (a.pontos != b.pontos)
            return a.pontos > b.pontos;
        return a.tempo < b.tempo;
    });

    if (registros.size() > MAX_LEADERBOARD)
        registros.resize(MAX_LEADERBOARD);

    garantirPastaSaveAlaska();
    std::ofstream saida(CAMINHO_LEADERBOARD, std::ios::trunc);
    for (const auto& r : registros)
        saida << r.nome << ';' << r.pontos << ';' << r.tempo << ";\n";
}

std::vector<std::string> Alaskapp::carregarLeaderboardTexto(int limite) const
{
    struct Registro
    {
        std::string nome;
        int pontos;
        float tempo;
    };

    std::vector<Registro> registros;
    std::ifstream entrada(CAMINHO_LEADERBOARD);
    std::string linha;

    while (std::getline(entrada, linha))
    {
        std::stringstream ss(linha);
        std::string nome, pontosStr, tempoStr;

        if (std::getline(ss, nome, ';') && std::getline(ss, pontosStr, ';') && std::getline(ss, tempoStr, ';'))
        {
            try
            {
                registros.push_back({ nome, std::stoi(pontosStr), std::stof(tempoStr) });
            }
            catch (const std::exception&)
            {
            }
        }
    }

    std::sort(registros.begin(), registros.end(), [](const Registro& a, const Registro& b)
    {
        if (a.pontos != b.pontos)
            return a.pontos > b.pontos;
        return a.tempo < b.tempo;
    });

    std::vector<std::string> linhas;
    const int total = std::min(limite, static_cast<int>(registros.size()));

    for (int i = 0; i < total; ++i)
    {
        const int minutos = static_cast<int>(registros[i].tempo) / 60;
        const int segundos = static_cast<int>(registros[i].tempo) % 60;

        std::stringstream linhaFormatada;
        linhaFormatada << (i + 1) << ". " << registros[i].nome
                       << " - " << registros[i].pontos << " pts - "
                       << std::setw(2) << std::setfill('0') << minutos << ':'
                       << std::setw(2) << std::setfill('0') << segundos;

        linhas.push_back(linhaFormatada.str());
    }

    return linhas;
}
