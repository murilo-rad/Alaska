#include "Tundra.h"



Alaska::Fases::Tundra::Tundra(Entidades::Personagens::Jogador* pJ1, Entidades::Personagens::Jogador* pJ2) : Fase(MAX_INI, MAX_OBS, pJ1, pJ2), max_Lobos(MAX_INI), max_Gelos(MAX_OBS), pJogador1(pJ1), pJogador2(pJ2 ? pJ2 : nullptr)
{
 
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
    int quantidade = (rand()%max_Lobos);
    if(quantidade < MIN)
        quantidade = MIN;
    
    Alaska::Entidades::Personagens::Inimigo* pInimigo;
    pInimigo = nullptr;

    for(int i = 0; i < quantidade; i++)
    {
        pInimigo = new Alaska::Entidades::Personagens::Lobo(posicaoRandX(), posicaoRandY(), (pJogador2 ? ((rand()%2) ? pJogador1 : pJogador2) : pJogador1));
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
    int quantidade = (rand() % max_Gelos);
    if (quantidade < MIN)
        quantidade = MIN;

    Alaska::Entidades::Obstaculos::Obstaculo* pObstaculo;
    pObstaculo = nullptr;
    for(int i = 0; i < quantidade; i++)
    {
        printf("novo gelo\n");
        pObstaculo = new Alaska::Entidades::Obstaculos::Gelo(posicaoRandX(), A_MAX_GERAL);
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
