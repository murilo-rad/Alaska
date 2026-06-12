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
        pGG->desenharOpcaoMenu("Opcoes",     2, opcao == 2);
        pGG->desenharOpcaoMenu("Scoreboard", 3, opcao == 3);
        pGG->desenharOpcaoMenu("Sair",       4, opcao == 4);
        pGG->mostrar();
    }
}

void Menu::mudarOpcao(int direcao) {
    opcao = (opcao + direcao + 4) % 4;
}

void Menu::confirmarOpcao() {
    if (opcao == 0 || opcao == 1)
    {
        ativo = false;
    }
    else if (opcao == 2) 
    {

    }          
    else if (opcao == 3) 
    {
        pGG->getJanela()->close();
    }
}
