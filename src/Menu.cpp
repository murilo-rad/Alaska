#include "Menu.h"

using namespace Alaska;

Menu::Menu(Alaskapp* pAlaskapp, Gerenciadores::Gerenciador_Eventos* pEventos)
    : ativo(true), pAlaskapp(pAlaskapp), pEventos(pEventos), opcaoSelecionada(0), Ente()
{ 
    carregarMenuPrincipal();
}

Menu::~Menu() {
    pAlaskapp = nullptr;
    pEventos  = nullptr;
}


void Menu::executar()
{
    ativo = true;

    while (pGG->isJanelaAberta() && ativo)
    {
        pEventos->verificarEventos();

        pGG->limpar();
        pGG->desenharTituloMenu("Alaska");

        desenhar();

        pGG->mostrar();
    }
}

void Menu::mudarOpcao(int direcao)
{
    if (opcoes.empty())
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
            i,
            i == opcaoSelecionada
        );
    }
}


void Menu::carregarMenuPrincipal()
{
    opcoes.clear();

    adicionarOpcao("1 Jogador", &Menu::acaoUmJogador);
    adicionarOpcao("2 Jogadores", &Menu::acaoDoisJogadores);
    adicionarOpcao("Scoreboard", &Menu::acaoScoreboard);
    adicionarOpcao("Sair", &Menu::acaoSair);

    opcaoSelecionada = 0;
}

void Menu::carregarMenuFases()
{
    opcoes.clear();

    adicionarOpcao("Tundra", &Menu::acaoTundra);
    adicionarOpcao("Caverna", &Menu::acaoCaverna);
    adicionarOpcao("Voltar", &Menu::acaoVoltarPrincipal);

    opcaoSelecionada = 0;
}

void Menu::subir()
{
    opcaoSelecionada--;

    if (opcaoSelecionada < 0)
        opcaoSelecionada = static_cast<int>(opcoes.size()) - 1;
}

void Menu::descer()
{
    opcaoSelecionada++;

    if (opcaoSelecionada >= static_cast<int>(opcoes.size()))
        opcaoSelecionada = 0;
}

void Menu::confirmarOpcao()
{
    if (opcaoSelecionada >= 0 &&
        opcaoSelecionada < opcoes.size())
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

void Menu::acaoUmJogador()
{
    pAlaskapp->criarJogadores(1);
    carregarMenuFases();
}

void Menu::acaoDoisJogadores()
{
    pAlaskapp->criarJogadores(2);
    carregarMenuFases();
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
    std::cout << "Scoreboard ainda nao implementado.\n";
    // carregarMenuScoreboard() dps;
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

    carregarMenuPrincipal();
}