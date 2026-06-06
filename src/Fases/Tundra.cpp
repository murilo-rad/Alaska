#include "Tundra.h"



Alaska::Fases::Tundra::Tundra(int n, int p, int l, int g, Entidades::Personagens::Jogador* pJ): Fase(n, p, pJ), maxLobos(l), maxGelos(g)
{
    criarCenario();
}

Alaska::Fases::Tundra::~Tundra()
{

}

void Alaska::Fases::Tundra::executar() 
{

}

void Alaska::Fases::Tundra::criarInimigos()
{

}

void Alaska::Fases::Tundra::criarObstaculos()
{

}

void Alaska::Fases::Tundra::criarChao()
{
    sf::Texture t_chao;
    t_chao.loadFromFile("imgs/ChaoTundra.png");
    Alaska::Entidades::Chao* pChao = nullptr;
    pChao = new Alaska::Entidades::Chao(t_chao);

    if(pChao)
    {
        GC->setChao(pChao);
        lista_ents.incluir(pChao);
    }
    
}

void Alaska::Fases::Tundra::criarLobos() 
{
    int quantidade = (rand()%maxLobos);
    if(quantidade < MIN)
        quantidade = MIN;
    
    Alaska::Entidades::Personagens::Inimigo* pInimigo;
    pInimigo = nullptr;

    for(int i = 0; i < quantidade; i++)
    {
        pInimigo = new Alaska::Entidades::Personagens::Lobo();
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