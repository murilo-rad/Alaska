#include "Menu.h"

using namespace Alaska;

Menu::Menu(Alaskapp* pAlaskapp, Gerenciadores::Gerenciador_Eventos* pEventos)
    : opcao(0), ativo(true), pAlaskapp(pAlaskapp), pEventos(pEventos), Ente() {}

Menu::~Menu() {
    pAlaskapp = nullptr;
    pEventos  = nullptr;
}

void Menu::executar() {
    ativo = true;
    while (pGG->isJanelaAberta() && ativo) {
        pEventos->verificarEventos(); 

        pGG->limpar();
        pGG->desenharTituloMenu("Alaska");
        pGG->desenharOpcaoMenu("Iniciar fase 1",    0, opcao == 0);
        pGG->desenharOpcaoMenu("Iniciar fase 2",    1, opcao == 1);
        pGG->desenharOpcaoMenu("Scoreboard", 2, opcao == 2);
        pGG->desenharOpcaoMenu("Sair",       3, opcao == 3);
        pGG->mostrar();
    }
}

void Menu::mudarOpcao(int direcao) {
    opcao = (opcao + direcao + 4) % 4;
}

void Menu::confirmarOpcao() {
    if (opcao == 0)
    {
        ativo = false;
		pAlaskapp->setFaseSelecionada(new Fases::Tundra(pAlaskapp->getPJog1(), nullptr));
    }
	else if (opcao == 1)
	{
		ativo = false;
        pAlaskapp->setFaseSelecionada(new Fases::Caverna(pAlaskapp->getPJog1(), nullptr));
    }
    else if (opcao == 2) 
    {

    }          
    else if (opcao == 3) 
    {
        pGG->getJanela()->close();
    }
}

void Menu::reset() {
	opcao = 0;
	ativo = true;
}