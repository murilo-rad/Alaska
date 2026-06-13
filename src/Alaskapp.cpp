#include "Alaskapp.h"

using namespace Alaska;

Alaska::Alaskapp::Alaskapp() : GG(), pJog1(nullptr) 
{
    pJog1 = new Alaska::Entidades::Personagens::Jogador();
    executar();
}

Alaska::Alaskapp::~Alaskapp() {}

void Alaska::Alaskapp::executar() 
{
    sementear();

    Gerenciadores::Gerenciador_Eventos Gerenciador_Eventos;

    Ente::setGG(&GG);
    Gerenciador_Eventos.setJanela(GG.getJanela());


    Alaska::Menu menu(this, &Gerenciador_Eventos);
    Gerenciador_Eventos.setMenu(&menu);
    menu.executar();
    Gerenciador_Eventos.setMenu(nullptr);

    if (pJog1 == nullptr)
        pJog1 = new Entidades::Personagens::Jogador();

    Gerenciador_Eventos.setJogador(pJog1);
    Fases::Tundra fasePrimeira(pJog1);
    fasePrimeira.iniciarFase(1);
    while (GG.isJanelaAberta() && pJog1->getPontos() > -1)
    {
        Gerenciador_Eventos.verificarEventos();

        GG.limpar();

        fasePrimeira.executar();

        GG.mostrar();
    }
}

void Alaska::Alaskapp::sementear()
{
    srand(time(NULL));
}