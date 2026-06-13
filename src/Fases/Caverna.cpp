#include "Caverna.h"

Alaska::Fases::Caverna::Caverna(Alaska::Entidades::Personagens::Jogador *pJ) : max_Abominaveis(MAX_INI), max_Conjunto_Estalagmites(MAX_OBS)
{
}

Alaska::Fases::Caverna::~Caverna()
{
    lAbms.clear();
}

void Alaska::Fases::Caverna::executar()
{
    pFundo->executar();
    lista_ents.percorrer();
    if (GC)
        GC->executar();
    lista_ents.cemiterio();
}

void Alaska::Fases::Caverna::iniciarFase(short fase)
{
    criarCenario(fase);
    criarObstaculos();
    criarInimigos();
}

void Alaska::Fases::Caverna::criarInimigos()
{
    criarNevosos();
    criarAbominaveis();
}

void Alaska::Fases::Caverna::criarObstaculos()
{
    criarPlataformas();
    criarConjuntos_Estalagmites();
}

void Alaska::Fases::Caverna::criarConjuntos_Estalagmites()
{
    int quantidade = (rand() % max_Conjunto_Estalagmites);
    if (quantidade < MIN)
        quantidade = MIN;

    Alaska::Entidades::Obstaculos::Obstaculo *pObstaculo;
    pObstaculo = nullptr;
    for (int i = 0; i < quantidade; i++)
    {
        printf("novo gelo\n");
        pObstaculo = new Alaska::Entidades::Obstaculos::Conjunto_Estalagmites(posicaoRandX(), A_MAX_GERAL);
        if (pObstaculo)
        {
            lista_ents.incluir(pObstaculo);
            if (GC)
                GC->incluirObstaculo(pObstaculo);
        }
        pObstaculo = nullptr;
    }

    delete pObstaculo;
}

void Alaska::Fases::Caverna::criarAbominaveis()
{
    int quantidade = (rand() % max_Abominaveis);
    if (quantidade < MIN)
        quantidade = MIN;

    Alaska::Entidades::Personagens::Abominavel *pInimigo;
    pInimigo = nullptr;

    for (int i = 0; i < quantidade; i++)
    {
        pInimigo = new Alaska::Entidades::Personagens::Abominavel(posicaoRandX(), posicaoRandY(), pJogador);
        if (pInimigo)
        {
            lAbms.push_back(pInimigo);
            lista_ents.incluir(pInimigo);
            if (GC)
                GC->incluirInimigo(pInimigo);
        }
    }
    pInimigo = nullptr;
    delete pInimigo;

    criarBolas_de_Neve(quantidade);
}

void Alaska::Fases::Caverna::criarBolas_de_Neve(int quant)
{
    Alaska::Entidades::Bola_de_Neve *pProjetil;
    pProjetil = nullptr;
    for (int i = 0; i < quant; i++)
    {
        printf("nova bdnv\n");
        pProjetil = new Alaska::Entidades::Bola_de_Neve(lAbms[i]);
        if (pProjetil)
        {
            lista_ents.incluir(pProjetil);
            if (GC)
                GC->incluirProjetil(pProjetil);
        }
        pProjetil = nullptr;
    }
    delete pProjetil;
}