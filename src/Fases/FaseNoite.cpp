#include "FaseNoite.h"
#include "Plataforma.h"
#include "Ice_Spike.h"
#include "Nevoso.h"
#include "Lobo.h"
#include "Ente.h"
#include "Gelo.h"


Alaska::Fases::FaseNoite::FaseNoite(Entidades::Personagens::Jogador* pJ): Fase(pJ)
{
    criarCenario();
}

Alaska::Fases::FaseNoite::~FaseNoite()
{}

void Alaska::Fases::FaseNoite::criarCenario() 
{
    if (pJogador)
        lista_ents.incluir(pJogador);
    criarInimigos();
    criarObstaculos();
}

void Alaska::Fases::FaseNoite::criarInimigos() 
{
    lista_ents.incluir(new Entidades::Personagens::Lobo(400.0f, 100.0f, pJogador));
    lista_ents.incluir(new Entidades::Personagens::Lobo(300.0f, 150.0f, pJogador));
    lista_ents.incluir(new Entidades::Personagens::Lobo(200.0f, 50.0f, pJogador));
}

void Alaska::Fases::FaseNoite::criarObstaculos() 
{
    lista_ents.incluir(new Entidades::Obstaculos::Plataforma(0.0f, 250.0f));
    lista_ents.incluir(new Entidades::Obstaculos::Plataforma(1000.0f, 250.0f));
    lista_ents.incluir(new Entidades::Obstaculos::Plataforma(500.0f, 400.0f));
    lista_ents.incluir(new Entidades::Obstaculos::Gelo(300.0f, 550.0f));
}


