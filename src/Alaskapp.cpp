#include <Alaskapp.h>

using namespace Alaska;

Alaska::Alaskapp::Alaskapp() : GG(), pJog1(nullptr) {
    pJog1 = new Alaska::Entidades::Personagens::Jogador();
    executar();
}

Alaska::Alaskapp::~Alaskapp() {}

void Alaska::Alaskapp::executar() {
    Gerenciadores::Eventos eventos;

    Ente::setGG(&GG);
    eventos.setJanela(GG.getJanela());


    Alaska::Menu menu(this, &eventos);
    eventos.setMenu(&menu);
    menu.executar();

    eventos.setMenu(nullptr);

    if (pJog1 == nullptr)
        pJog1 = new Entidades::Personagens::Jogador();

    eventos.setJogador(pJog1);
    Fases::FaseNoite fasePrimeira(pJog1);

    while (GG.isJanelaAberta())
    {
            eventos.verificarEventos();

        GG.limpar();

            fasePrimeira.executar();

        GG.mostrar();
    }
}