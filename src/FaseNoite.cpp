#include "FaseNoite.h"
#include "Plataforma.h"
#include "Ice_Spike.h"

Alaska::Fases::FaseNoite::FaseNoite(Entidades::Personagens::Jogador* pJ): Fase(pJ)
{
    criarCenario();
}

Alaska::Fases::FaseNoite::~FaseNoite()
{
}

void Alaska::Fases::FaseNoite::criarCenario() 
{

    listaEntidades.push_back(new Entidades::Obstaculos::Plataforma(0.0f, 550.0f)); 
    listaEntidades.push_back(new Entidades::Obstaculos::Plataforma(1000.0f, 400.0f)); 
    listaEntidades.push_back(new Entidades::Obstaculos::Plataforma(1200.0f, 200.0f));
}
