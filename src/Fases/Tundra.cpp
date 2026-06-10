#include "Tundra.h"



Alaska::Fases::Tundra::Tundra(int n, int p, int l, int g, Entidades::Personagens::Jogador* pJ): Fase(n, p, pJ), max_Lobos(l), max_Gelos(g), pJogador(pJ)
{
    criarCenario();
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

void Alaska::Fases::Tundra::criarCenario()
{
    criarFundo();
    criarChao();
    criarObstaculos();

    if (pJogador)
        lista_ents.incluir(pJogador);
    criarInimigos();
    
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

void Alaska::Fases::Tundra::criarChao()
{
    Alaska::Entidades::Chao* pChao;
    pChao = nullptr;
    pChao = new Alaska::Entidades::Chao(1);

    if(pChao)
    {
        GC->incluirChao(pChao);
        lista_ents.incluir(pChao);
    }
    
}

void Alaska::Fases::Tundra::criarFundo()
{
    pFundo = new Alaska::Fundo(A_FUNDO, L_FUNDO);
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
        pInimigo = new Alaska::Entidades::Personagens::Lobo(posicaoRandX(), posicaoRandY(), pJogador);
        if(pInimigo)
        {
            lista_ents.incluir(pInimigo);
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
        pObstaculo = new Alaska::Entidades::Obstaculos::Gelo(posicaoRandX(), 549.0f);
        if(pObstaculo)
        {
            lista_ents.incluir(pObstaculo);
            GC->incluirObstaculo(pObstaculo);
        }
        pObstaculo = nullptr;
    }

    delete pObstaculo;
}



/* void Alaska::Fases::Tundra::criarCenario()
{
    if (pJogador)
        lista_ents.incluir(pJogador);

    lista_ents.incluir(new Entidades::Obstaculos::Plataforma(0.0f, 550.0f));
    lista_ents.incluir(new Entidades::Obstaculos::Plataforma(1000.0f, 550.0f));
    lista_ents.incluir(new Entidades::Obstaculos::Plataforma(500.0f, 400.0f));

    lista_ents.incluir(new Entidades::Personagens::Lobo(400.0f, 100.0f, pJogador));

} */