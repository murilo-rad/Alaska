#include "Menu.h"

using namespace Alaska;

Menu::Menu(Alaskapp* pAlaskapp, Gerenciadores::Gerenciador_Eventos* pEventos)
    : opcao(0), ativo(true), pAlaskapp(pAlaskapp), pEventos(pEventos), Ente(), nmrFase(0), nmrJogadores(0), estagio(0), maxOpcoes(4){}

Menu::~Menu() {
    pAlaskapp = nullptr;
    pEventos  = nullptr;
    nmrFase = 0;
    nmrJogadores = 0;
}

void Menu::executar() {
    ativo = true;
    while (pGG->isJanelaAberta() && ativo) {
        pEventos->verificarEventos(); 

        pGG->limpar();
        pGG->desenharTituloMenu("Alaska");
        desenharEstagio();
        pGG->mostrar();
    }
}

void Menu::mudarOpcao(int direcao) {
    opcao = (opcao + direcao + maxOpcoes) % maxOpcoes;
}

void Menu::confirmarOpcao() {
    switch(opcao){
	    case 0:
			if (pAlaskapp->getPJog1() == nullptr)
                pAlaskapp->criarJogadores(1);
            else {
                pAlaskapp->setFaseSelecionada(new Fases::Tundra(pAlaskapp->getPJog1(), pAlaskapp->getPJog2()));
                ativo = false;
            }
            estagio = 1;
            break;
        case 1:
            if (pAlaskapp->getPJog1() == nullptr && pAlaskapp->getPJog2() == nullptr)
                pAlaskapp->criarJogadores(2);
            else {
				pAlaskapp->setFaseSelecionada(new Fases::Caverna(pAlaskapp->getPJog1(), pAlaskapp->getPJog2()));
                ativo = false;
            }
            estagio = 1;
            break;
        case 2:
            break;
        case 3:
            pGG->getJanela()->close();
            break;
    }
}

void Menu::reset() {
	opcao = 0;
	ativo = true;
}

void Menu::desenharEstagio() {
    if (estagio == 0) {
        maxOpcoes = 4;
        pGG->desenharOpcaoMenu("1 Jogador", 0, opcao == 0);
        pGG->desenharOpcaoMenu("2 Jogadores", 1, opcao == 1);
        pGG->desenharOpcaoMenu("Scoreboard", 2, opcao == 2);
        pGG->desenharOpcaoMenu("Sair", 3, opcao == 3);
    }
    else if (estagio == 1) {
        maxOpcoes = 2;
        pGG->desenharOpcaoMenu("Iniciar Fase 1", 0, opcao == 0);
        pGG->desenharOpcaoMenu("Iniciar Fase 2", 1, opcao == 1);
    }
	else if (estagio == 2) {
        maxOpcoes = 1;
		pGG->desenharOpcaoMenu("Nome Jogador", 0, opcao == 0);
	}
    else if (estagio == 3) {
        maxOpcoes = 2;
        pGG->desenharOpcaoMenu("Nome Jogador 1", 0, opcao == 0);
        pGG->desenharOpcaoMenu("Nome Jogador 2", 1, opcao == 1);
    }
}