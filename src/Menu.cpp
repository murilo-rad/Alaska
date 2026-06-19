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
    //nmrFase = 0;
    //nmrJogadores = 0;
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

//void Menu::confirmarOpcao()
//{
//    switch (estado)
//    {
//    case EstadoMenu::EscolherJogadores:
//
//        if (opcao == 0)
//        {
//            pAlaskapp->criarJogadores(1);
//            estado = EstadoMenu::EscolherFase;
//        }
//        else if (opcao == 1)
//        {
//            pAlaskapp->criarJogadores(2);
//            estado = EstadoMenu::EscolherFase;
//        }
//        else if (opcao == 2)
//        {
//            // scoreboard
//        }
//        else if (opcao == 3)
//        {
//            pGG->getJanela()->close();
//        }
//
//        break;
//
//    case EstadoMenu::EscolherFase:
//
//        if (opcao == 0)
//        {
//            pAlaskapp->setFaseSelecionada(
//                new Fases::Tundra(
//                    pAlaskapp->getPJog1(),
//                    pAlaskapp->getPJog2()
//                )
//            );
//
//            ativo = false;
//        }
//        else if (opcao == 1)
//        {
//            pAlaskapp->setFaseSelecionada(
//                new Fases::Caverna(
//                    pAlaskapp->getPJog1(),
//                    pAlaskapp->getPJog2()
//                )
//            );
//
//            ativo = false;
//        }
//
//        break;
//
//    case EstadoMenu::NomeJogador1:
//        break;
//
//    case EstadoMenu::NomeJogador2:
//        break;
//    }
//}

//void Menu::reset() {
//	opcao = 0;
//	ativo = true;
//}

//void Menu::desenharEstagio()
//{
//    switch (estado)
//    {
//    case EstadoMenu::EscolherJogadores:
//
//        maxOpcoes = 4;
//
//        pGG->desenharOpcaoMenu("1 Jogador", 0, opcao == 0);
//        pGG->desenharOpcaoMenu("2 Jogadores", 1, opcao == 1);
//        pGG->desenharOpcaoMenu("Scoreboard", 2, opcao == 2);
//        pGG->desenharOpcaoMenu("Sair", 3, opcao == 3);
//
//        break;
//
//    case EstadoMenu::EscolherFase:
//
//        maxOpcoes = 2;
//
//        pGG->desenharOpcaoMenu("Tundra", 0, opcao == 0);
//        pGG->desenharOpcaoMenu("Caverna", 1, opcao == 1);
//
//        break;
//
//    case EstadoMenu::NomeJogador1:
//
//        maxOpcoes = 1;
//        pGG->desenharOpcaoMenu("Nome Jogador 1", 0, true);
//
//        break;
//
//    case EstadoMenu::NomeJogador2:
//
//        maxOpcoes = 1;
//        pGG->desenharOpcaoMenu("Nome Jogador 2", 0, true);
//
//        break;
//    }
//}

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

    // futuramente:
    // carregarMenuScoreboard();
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