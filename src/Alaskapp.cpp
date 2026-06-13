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
	printf("Menu finalizado %d\n", menu.getOpcao());

    if (pJog1 == nullptr)
        pJog1 = new Entidades::Personagens::Jogador();

    Gerenciador_Eventos.setJogador(pJog1);
    
	if (faseSelecionada)
		faseSelecionada->iniciarFase(menu.getOpcao() + 1);

    Gerenciador_Eventos.setMenu(nullptr);
    while (GG.isJanelaAberta() && pJog1->getPontos() > -1)
    {
        Gerenciador_Eventos.verificarEventos();

        GG.limpar();
        if (faseSelecionada)
            faseSelecionada->executar();

        GG.mostrar();
    }
}

void Alaska::Alaskapp::sementear()
{
    srand(time(NULL));
}