#include "Fase.h"
#include "Gerenciador_Grafico.h"

Alaska::Fases::Fase::Fase() : max_Nevosos(0), max_Plataformas(0), pJogador(nullptr)
{
}

Alaska::Fases::Fase::Fase(int n, int p, Alaska::Entidades::Personagens::Jogador* pJ) : max_Nevosos(n), max_Plataformas(p)
{

    if(pJ)
        pJogador = pJ;

    GC = new Alaska::Gerenciadores::Gerenciador_Colisoes();
    GC->setJogadorUm(pJogador);
	lista_ents.incluir(pJogador);
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

void Alaska::Fases::Fase::criarNevosos()
{
    int quantidade = (rand()%max_Nevosos);
    if(quantidade < MIN)
        quantidade = MIN;

    Alaska::Entidades::Personagens::Inimigo* pInimigo;
    pInimigo = nullptr;

    for(int i = 0; i < quantidade; i++)
    {
        pInimigo = new Alaska::Entidades::Personagens::Nevoso(posicaoRandX(), posicaoRandY(), pJogador);
        if(pInimigo)
        {
            lista_ents.incluir(pInimigo);
            if(GC)
                GC->incluirInimigo(pInimigo);
        }
        pInimigo = nullptr;
    }
    delete pInimigo;
}

void Alaska::Fases::Fase::criarPlataformas()
{
    int quantidade = (rand() % max_Plataformas);
    if (quantidade < MIN)
        quantidade = MIN;

    Alaska::Entidades::Obstaculos::Obstaculo* pObstaculo;
    pObstaculo = nullptr;
    for(int i = 0; i < quantidade; i++)
    {
        pObstaculo = new Alaska::Entidades::Obstaculos::Plataforma(posicaoRandX(), posicaoRandY());
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

void Alaska::Fases::Fase::criarCenario(short fase)
{
    criarFundo(fase);
	criarChao(fase);
}

float Alaska::Fases::Fase::posicaoRandX()
{
    float pos_x;
    pos_x = (rand()%1800) + 200;
    return pos_x;
}

float Alaska::Fases::Fase::posicaoRandY()
{
    float pos_y;
    pos_y = (rand()%300) + 200.0f;
    return pos_y;
}


void Alaska::Fases::Fase::criarChao(short fase)
{
	Alaska::Entidades::Chao* pChao;
	pChao = nullptr;
	pChao = new Alaska::Entidades::Chao(fase);
	if (pChao)
	{
		lista_ents.incluir(pChao);
        if(GC)
            GC->incluirChao(pChao);
	}
}

void Alaska::Fases::Fase::criarFundo(short fase)
{
    pFundo = new Alaska::Fundo(A_FUNDO, L_FUNDO, fase);
}