#include <Alaskapp.h>

using namespace Alaska;

Alaska::Alaskapp::Alaskapp() : GG(), pJog1(nullptr) {
	//pJog1 = new Entidades::Personagens::Jogador();
	executar();
}

Alaska::Alaskapp::~Alaskapp() {}

void Alaska::Alaskapp::executar() {
    Gerenciadores::Eventos eventos;

    Ente::setGG(&GG);
    eventos.setJanela(GG.getJanela());

    Entidades::Personagens::Jogador jogador;
    eventos.setJogador(&jogador);

    Fases::FaseNoite fasePrimeira(&jogador);

    while (GG.isJanelaAberta())
    {
        eventos.verificarEventos();

        GG.limpar();

        fasePrimeira.executar();

        GG.mostrar();
    }
}

