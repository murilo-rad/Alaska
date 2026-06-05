#include "FaseNoite.h"
#include "Plataforma.h"
#include "Ice_Spike.h"
#include "Nevoso.h"
#include "Lobo.h"
#include "Ente.h"
#include "Graficos.h"

Alaska::Fases::FaseNoite::FaseNoite() : Fase(), maxLobos(0), maxGelos(0)
{
}

Alaska::Fases::FaseNoite::FaseNoite(int n, int p, int l, int g, Entidades::Personagens::Jogador* pJ): Fase(n, p, pJ), maxLobos(l), maxGelos(g)
{
    criarCenario();
}

Alaska::Fases::FaseNoite::~FaseNoite()
{

}

void Alaska::Fases::FaseNoite::executar() 
{
    auto* lista = lista_ents.getLista();


    for (auto it = lista->begin(); it != lista->end(); ++it)
    {
        if (*it)
            (*it)->executar();
    }

    if (pColisoes)
        pColisoes->executar();

    if (pGG)
        pGG->atualizarCamera(pJogador->getX() + 25.0f, 300.0f);


    for (auto it = lista->begin(); it != lista->end(); ++it)
    {
        if (*it)
            (*it)->desenhar();
    }

    pJogador->desenhar();
}

void Alaska::Fases::FaseNoite::criarChao()
{

}

void Alaska::Fases::FaseNoite::criarInimigos()
{

}

void Alaska::Fases::FaseNoite::criarObstaculos()
{

}

void Alaska::Fases::FaseNoite::criarLobos() 
{

}

void Alaska::Fases::FaseNoite::criarGelos() 
{

}



void Alaska::Fases::FaseNoite::criarCenario()
{
    if (pJogador)
        lista_ents.incluir(pJogador);

    lista_ents.incluir(new Entidades::Obstaculos::Plataforma(0.0f, 550.0f));
    lista_ents.incluir(new Entidades::Obstaculos::Plataforma(1000.0f, 550.0f));
    lista_ents.incluir(new Entidades::Obstaculos::Plataforma(500.0f, 400.0f));

    lista_ents.incluir(new Entidades::Personagens::Lobo(400.0f, 100.0f, pJogador));
    printf("fase1\n");
}
