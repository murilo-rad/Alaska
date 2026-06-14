#include "Tundra.h"



Alaska::Fases::Tundra::Tundra(Entidades::Personagens::Jogador* pJ1, Entidades::Personagens::Jogador* pJ2) : Fase(MAX_INI, MAX_OBS, pJ1, pJ2), max_Lobos(MAX_INI), max_Gelos(MAX_OBS), pJogador1(pJ1), pJogador2(pJ2 ? pJ2 : nullptr)
{
    posGelos =
    {
        {0.f,   718.f},
        {300.f, 718.f},
        {600.f, 718.f},
        {900.f, 718.f},
        {988.f, 718.f}
    };

    posLobos =
    {
        {950.f, 410.f},  // em cima da plataforma {950,470}
        {500.f, 658.f},
        {720.f, 658.f},
        {1160.f, 658.f},
        {1300.f, 658.f}
    };
}

Alaska::Fases::Tundra::~Tundra()
{

}

void Alaska::Fases::Tundra::executar() 
{
    pFundo->executar();
    lista_ents.percorrer();
    if (GC)
        GC->executar();
    lista_ents.cemiterio();
}

void Alaska::Fases::Tundra::criarInimigos()
{
    criarNevosos();
    criarLobos();
}

void Alaska::Fases::Tundra::criarObstaculos()
{
    criarPlataformas();
    criarGelos();
}


void Alaska::Fases::Tundra::criarLobos()
{
    int quantidade = ((rand()%max_Lobos) + 1);
    if(quantidade < MIN)
        quantidade = MIN;
    
    Alaska::Entidades::Personagens::Inimigo* pInimigo;
    pInimigo = nullptr;

    for(int i = 0; i < quantidade; i++)
    {
        pInimigo = new Alaska::Entidades::Personagens::Lobo(posLobos[i].x, posLobos[i].y, randJogador());
        if(pInimigo)
        {
            lista_ents.incluir(pInimigo);
            if(GC)
                GC->incluirInimigo(pInimigo);
        }
    }

    pInimigo = nullptr;
    delete pInimigo;
}

void Alaska::Fases::Tundra::criarGelos() 
{
    int quantidade = ((rand() % max_Gelos) + 1);
    if (quantidade < MIN)
        quantidade = MIN;

    Alaska::Entidades::Obstaculos::Obstaculo* pObstaculo;
    pObstaculo = nullptr;
    for(int i = 0; i < quantidade; i++)
    {
        printf("novo gelo\n");
        pObstaculo = new Alaska::Entidades::Obstaculos::Gelo(100 + posGelos[i].x, posGelos[i].y);
        if(pObstaculo)
        {
            lista_ents.incluir(pObstaculo);
            if(GC)
                GC->incluirObstaculo(pObstaculo);
        }
        pObstaculo = nullptr;
    }

    delete pObstaculo;
}

void Alaska::Fases::Tundra::iniciarFase(short fase)
{
	criarCenario(fase);
    criarObstaculos();
    criarInimigos();
}
