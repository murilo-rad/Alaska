#include "Menu.h"
#include "Ente.h"
#include "Alaskapp.h"
#include "Eventos.h"

using namespace Alaska;

Menu::Menu(Alaskapp* pAlaskapp, Gerenciadores::Eventos* pEventos)
    : opcao(0), ativo(true), pAlaskapp(pAlaskapp), pEventos(pEventos), Ente() {}

Menu::~Menu() {
    pAlaskapp = nullptr;
    pEventos  = nullptr;
}

void Menu::executar() {
    ativo = true;
    while (pGG->isJanelaAberta() && ativo) {
        pEventos->verificarEventos(); // processes input → calls mudarOpcao/confirmarOpcao

        pGG->limpar();
        pGG->desenharTituloMenu("Alaska");
        pGG->desenharOpcaoMenu("Iniciar",    0, opcao == 0);
        pGG->desenharOpcaoMenu("Opcoes",     1, opcao == 1);
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
    }
    else if (opcao == 1)
    {
    
    }
    else if (opcao == 2) 
    {

    }          
    else if (opcao == 3) 
    {
        pGG->getJanela()->close();
    }
}
