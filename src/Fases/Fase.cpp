#include "Fase.h"
#include "Graficos.h"

Alaska::Fases::Fase::Fase() : maxNevosos(0), max_plataformas(0), pJogador(nullptr)
{
}

Alaska::Fases::Fase::Fase(int n, int p, Alaska::Entidades::Personagens::Jogador* pJ) : maxNevosos(n), max_plataformas(p)
{
    if(pJ)
        pJogador = pJ;

    GC = new Alaska::Gerenciadores::Colisoes();
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
            lista_ents.incluir(pInimigo);
            GC->incluirInimigo(pInimigo);
        }
    }

    pInimigo = nullptr;
    delete pInimigo;
}

void Alaska::Fases::Fase::criarPlataformas()
{
    int quantidade = (rand() % max_plataformas);
    if (quantidade < MIN)
        quantidade = MIN;

    Alaska::Entidades::Obstaculos::Obstaculo* pObstaculo;
    pObstaculo = nullptr;
}
















































//void Alaska::Fases::Fase::executar()
//{
//    auto* lista = lista_ents.getLista();
//
//
//    for (auto it = lista->begin(); it != lista->end(); ++it)
//    {
//        if (*it)
//            (*it)->executar();
//    }
//
//    if(pColisoes)
//        pColisoes->executar(); 
//
//    if(pGG)
//        pGG->atualizarCamera(pJogador->getX() + 25.0f, 300.0f);
//
//
//    for (auto it = lista->begin(); it != lista->end(); ++it)
//    {
//        if (*it)
//            (*it)->desenhar();
//    }
//
//    pJogador->desenhar();
//}