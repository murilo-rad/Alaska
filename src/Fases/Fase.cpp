#include "Fase.h"
#include "Graficos.h"

Alaska::Fases::Fase::Fase(int n, int p, Alaska::Entidades::Personagens::Jogador* pJ) : max_nevosos(n), max_plataformas(p)
{
    if(pJ)
        pJogador = pJ;

    pColisoes = new Alaska::Gerenciadores::Colisoes(pJogador, &lista_ents);
}

Alaska::Fases::Fase::~Fase()
{

    auto* lista = lista_ents.getLista();
    for (auto it = lista->begin(); it != lista->end(); ++it)
    {
        if (*it)
            delete *it;
    }

    delete pColisoes;
}

void Alaska::Fases::Fase::criarCenario()
{

}

void Alaska::Fases::Fase::criarNevosos()
{

}

void Alaska::Fases::Fase::criarPlataformas()
{

}



/* void Alaska::Fases::Fase::executar()
{
    auto* lista = lista_ents.getLista();


    for (auto it = lista->begin(); it != lista->end(); ++it)
    {
        if (*it)
            (*it)->executar();
    }

    if(pColisoes)
        pColisoes->executar(); 

    if(pGG)
        pGG->atualizarCamera(pJogador->getX() + 25.0f, 300.0f);


    for (auto it = lista->begin(); it != lista->end(); ++it)
    {
        if (*it)
            (*it)->desenhar();
    }

    pJogador->desenhar();
} */