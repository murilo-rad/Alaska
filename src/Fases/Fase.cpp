#include "Fase.h"
#include "Graficos.h"

Alaska::Fases::Fase::Fase(int n, int p, Alaska::Entidades::Personagens::Jogador* pJ) : maxNevosos(n), max_plataformas(p)
{
    if(pJ)
        pJogador = pJ;

    GC = new Alaska::Gerenciadores::Colisoes(pJogador, &lista_ents);
}

Alaska::Fases::Fase::~Fase()
{
    auto* lista = lista_ents.getLista();
    for (auto it = lista->begin(); it != lista->end(); ++it)
    {
        if (*it)
            delete *it;
    }
    delete GC;
}

void Alaska::Fases::Fase::criarCenario()
{
    criarPlataformas();
    criarNevosos();
}

void Alaska::Fases::Fase::criarNevosos()
{
    int quantidade = (rand()%maxNevosos);
    if(quantidade < MIN)
        quantidade = MIN;
    
    Alaska::Entidades::Personagens::Inimigo* pInimigo;
    pInimigo = nullptr;

    for(int i = 0; i < quantidade; i++)
    {
        pInimigo = new Alaska::Entidades::Personagens::Nevoso();
        if(pInimigo)
        {
            GC->incluirInimigo(pInimigo);
            lista_ents.incluir(dynamic_cast<Alaska::Entidades::Entidade*>(pInimigo));
        }
    }

    pInimigo = nullptr;
    delete pInimigo;
}

void Alaska::Fases::Fase::criarPlataformas()
{
    int quantidade = (rand()%max_plataformas);
    if(quantidade < MIN)
        quantidade = MIN;
    
    Alaska::Entidades::Obstaculos::Obstaculo* pObstaculo;
    pObstaculo= nullptr;

    for(int i = 0; i < quantidade; i++)
    {
        pObstaculo = new Alaska::Entidades::Obstaculos::Plataforma();
        if(pObstaculo)
        {
            GC->incluirObstaculo(pObstaculo);
            lista_ents.incluir(dynamic_cast<Alaska::Entidades::Entidade*>(pObstaculo));
        }
    }

    pObstaculo = nullptr;
    delete pObstaculo;
}