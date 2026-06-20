#include "Menu.h"
#include "Alaskapp.h"
#include "Gerenciador_Eventos.h"

using namespace Alaska;

Menu::Menu(Alaskapp* pAlaskapp, Gerenciadores::Gerenciador_Eventos* pEventos)
    : ativo(true), pAlaskapp(pAlaskapp), pEventos(pEventos), estadoMenu(EstadoMenu::Principal),
      textoDigitado(""), mensagemRodape(""), fundoCarregado(false),
      opcaoSelecionada(0), quantidadeJogadoresSelecionada(1), Ente()
{
    carregarFundo();
    carregarMenuPrincipal();
}

Menu::~Menu() {
    pAlaskapp = nullptr;
    pEventos  = nullptr;
}

void Menu::carregarFundo()
{
    fundoCarregado = texturaFundo.loadFromFile("imgs/FundoTundra.png");

    if (!fundoCarregado)
        return;

    spriteFundo.setTexture(texturaFundo);

    const sf::Vector2u tamanhoTextura = texturaFundo.getSize();
    if (tamanhoTextura.x > 0 && tamanhoTextura.y > 0)
    {
        spriteFundo.setScale(
            L_TELA / static_cast<float>(tamanhoTextura.x),
            A_TELA / static_cast<float>(tamanhoTextura.y)
        );
    }

    spriteFundo.setPosition(0.f, 0.f);
}

void Menu::desenharFundo()
{
    if (fundoCarregado && pGG && pGG->getJanela() && pGG->getJanela()->isOpen())
        pGG->getJanela()->draw(spriteFundo);
}

void Menu::executar()
{
    ativo = true;

    while (pGG->isJanelaAberta() && ativo)
    {
        pEventos->verificarEventos();

        pGG->limpar();
        desenharFundo();

        if (estaDigitandoNome())
            desenharInputNome();
        else if (estadoMenu == EstadoMenu::Leaderboard)
            desenharLeaderboard();
        else
        {
            pGG->desenharTituloMenu("Alaska");
            desenhar();
        }

        if (!mensagemRodape.empty())
            pGG->desenharTextoMenu(mensagemRodape, 260.f, 700.f, 24, sf::Color::Red);

        pGG->mostrar();
    }
}

void Menu::mudarOpcao(int direcao)
{
    if (opcoes.empty() || estaDigitandoNome())
        return;

    opcaoSelecionada =
        (opcaoSelecionada + direcao + opcoes.size())
        % opcoes.size();
}

void Menu::desenhar()
{
    for (size_t i = 0; i < opcoes.size(); i++)
    {
        pGG->desenharOpcaoMenu(
            opcoes[i].texto,
            static_cast<int>(i),
            i == static_cast<size_t>(opcaoSelecionada)
        );
    }
}

void Menu::carregarMenuPrincipal()
{
    opcoes.clear();
    estadoMenu = EstadoMenu::Principal;
    mensagemRodape.clear();

    adicionarOpcao("1 Jogador", &Menu::acaoUmJogador);
    adicionarOpcao("2 Jogadores", &Menu::acaoDoisJogadores);
    adicionarOpcao("Carregar Jogo", &Menu::acaoCarregarJogo);
    adicionarOpcao("Leaderboard", &Menu::acaoScoreboard);
    adicionarOpcao("Sair", &Menu::acaoSair);

    opcaoSelecionada = 0;
}

void Menu::carregarMenuFases()
{
    opcoes.clear();
    estadoMenu = EstadoMenu::EscolherFase;
    mensagemRodape.clear();

    adicionarOpcao("Tundra", &Menu::acaoTundra);
    adicionarOpcao("Caverna", &Menu::acaoCaverna);
    adicionarOpcao("Voltar", &Menu::acaoVoltarPrincipal);

    opcaoSelecionada = 0;
}

void Menu::carregarMenuLeaderboard()
{
    opcoes.clear();
    linhasLeaderboard = pAlaskapp ? pAlaskapp->carregarLeaderboardTexto(MAX_LEADERBOARD) : std::vector<std::string>();
    estadoMenu = EstadoMenu::Leaderboard;
    mensagemRodape.clear();

    adicionarOpcao("Voltar", &Menu::acaoVoltarPrincipal);
    opcaoSelecionada = 0;
}

void Menu::subir()
{
    mudarOpcao(-1);
}

void Menu::descer()
{
    mudarOpcao(1);
}

void Menu::confirmarOpcao()
{
    if (opcaoSelecionada >= 0 &&
        opcaoSelecionada < static_cast<int>(opcoes.size()))
    {
        (this->*opcoes[opcaoSelecionada].acao)();
    }
}

void Menu::adicionarOpcao(
    const std::string& texto,
    void (Menu::* acao)()
)
{
    opcoes.push_back({ texto, acao });
}

bool Menu::estaDigitandoNome() const
{
    return estadoMenu == EstadoMenu::NomeJogador1 || estadoMenu == EstadoMenu::NomeJogador2;
}

void Menu::receberTexto(sf::Uint32 unicode)
{
    if (!estaDigitandoNome())
        return;

    if (unicode >= 32 && unicode < 127 && textoDigitado.size() < 16)
    {
        char c = static_cast<char>(unicode);
        if (c != ',')
            textoDigitado += c;
    }
}

void Menu::apagarCaractere()
{
    if (estaDigitandoNome() && !textoDigitado.empty())
        textoDigitado.pop_back();
}

void Menu::confirmarNomeDigitado()
{
    if (!pAlaskapp || !estaDigitandoNome())
        return;

    const int indiceJogador = (estadoMenu == EstadoMenu::NomeJogador1) ? 1 : 2;
    std::string nome = textoDigitado.empty() ? ("Jogador " + std::to_string(indiceJogador)) : textoDigitado;

    pAlaskapp->setNomeJogador(indiceJogador, nome);

    if (indiceJogador == 1 && quantidadeJogadoresSelecionada == 2)
        carregarTelaNomeJogador(2);
    else
        carregarMenuFases();
}

void Menu::acaoUmJogador()
{
    quantidadeJogadoresSelecionada = 1;
    if (pAlaskapp)
        pAlaskapp->criarJogadores(1);
    carregarTelaNomeJogador(1);
}

void Menu::acaoDoisJogadores()
{
    quantidadeJogadoresSelecionada = 2;
    if (pAlaskapp)
        pAlaskapp->criarJogadores(2);
    carregarTelaNomeJogador(1);
}

void Menu::acaoCarregarJogo()
{
    if (pAlaskapp && pAlaskapp->carregarJogoSalvo())
        ativo = false;
    else
        mensagemRodape = "Nenhum save rapido encontrado.";
}

void Menu::acaoTundra()
{
    pAlaskapp->setFaseEscolhida(TipoFase::TUNDRA);
    ativo = false;
}

void Menu::acaoCaverna()
{
    pAlaskapp->setFaseEscolhida(TipoFase::CAVERNA);
    ativo = false;
}

void Menu::acaoScoreboard()
{
    carregarMenuLeaderboard();
}

void Menu::acaoVoltarPrincipal()
{
    carregarMenuPrincipal();
}

void Menu::acaoSair()
{
    pGG->getJanela()->close();
}

void Menu::reset()
{
    ativo = true;
    opcaoSelecionada = 0;
    textoDigitado.clear();
    mensagemRodape.clear();
    carregarMenuPrincipal();
}

void Menu::carregarTelaNomeJogador(int indiceJogador)
{
    opcoes.clear();
    textoDigitado.clear();
    mensagemRodape.clear();
    estadoMenu = (indiceJogador == 1) ? EstadoMenu::NomeJogador1 : EstadoMenu::NomeJogador2;
    opcaoSelecionada = 0;
}

void Menu::desenharInputNome()
{
    const int indiceJogador = (estadoMenu == EstadoMenu::NomeJogador1) ? 1 : 2;

    pGG->desenharTituloMenu("Alaska");
    pGG->desenharTextoMenu("Nome do Jogador " + std::to_string(indiceJogador), 450.f, 300.f, 34);
    pGG->desenharTextoMenu(textoDigitado + "_", 450.f, 370.f, 38, sf::Color::Cyan);
    pGG->desenharTextoMenu("Enter confirma | Backspace apaga", 450.f, 440.f, 22);
}

void Menu::desenharLeaderboard()
{
    pGG->desenharTituloMenu("Leaderboard");

    if (linhasLeaderboard.empty())
        pGG->desenharTextoMenu("Nenhum resultado salvo ainda.", 420.f, 310.f, 30);
    else
    {
        for (size_t i = 0; i < linhasLeaderboard.size(); ++i)
            pGG->desenharTextoMenu(linhasLeaderboard[i], 330.f, 280.f + static_cast<float>(i) * 38.f, 26);
    }

    pGG->desenharOpcaoMenu(opcoes[0].texto, 6, true);
}
