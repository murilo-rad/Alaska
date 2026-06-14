#include "Alaskapp.h"

using namespace Alaska;

Alaska::Alaskapp::Alaskapp() : GG(), pJog1(nullptr), pJog2(nullptr), faseTundra(nullptr), faseCaverna(nullptr), faseSelecionada(nullptr)
{
    //pJog1 = new Alaska::Entidades::Personagens::Jogador();
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

    //if (pJog1 == nullptr)
    //    pJog1 = new Entidades::Personagens::Jogador();

    Gerenciador_Eventos.setJogadores(pJog1, pJog2);
    
	if (faseSelecionada)
		faseSelecionada->iniciarFase(menu.getOpcao() + 1);

    Gerenciador_Eventos.setMenu(nullptr);
    while (GG.isJanelaAberta() && verificarJogadores())
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

void Alaska::Alaskapp::criarJogadores(int qntd)
{
	if (qntd == 1) {
		pJog1 = new Entidades::Personagens::Jogador(1);
	}
	else if (qntd == 2) {
		pJog1 = new Entidades::Personagens::Jogador(1);
		pJog2 = new Entidades::Personagens::Jogador(2);
	}
}

bool Alaska::Alaskapp::verificarJogadores() const
{
	if (pJog1 && pJog1->getPontos()>=0 && (!pJog2 || (pJog2 && pJog2->getPontos()>=0)))
		return true;

	return false;
}