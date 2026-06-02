#include "Fase.h"
#include "Graficos.h"

Alaska::Fases::Fase::Fase(Alaska::Entidades::Personagens::Jogador* pJ)
{
    if(pJ)
        pJogador = pJ;

    pColisoes = new Alaska::Gerenciadores::Colisoes(pJogador, &lista_ents);
}

Alaska::Fases::Fase::~Fase()
{
    auto* lista = lista_ents.getLista();
    for (auto it = lista->begin(); it != lista->end(); ++it)
    {
        if (*it)
            delete *it;
    }
    //Como é uma lista encadeada própria, 
    // a liberação dos nós deve ser feita no próprio destruidor da classe Lista)

    delete pColisoes;
}









/* void Alaska::Fases::Fase::executar()
{
    auto* lista = lista_ents.getLista();

    for (auto it = lista->begin(); it != lista->end(); ++it)
    {
        if (*it)
            (*it)->executar();
    }

    if(pColisoes)
        pColisoes->executar(); 

    if(pGG)
        pGG->atualizarCamera(pJogador->getX() + 25.0f, 300.0f);


    for (auto it = lista->begin(); it != lista->end(); ++it)
    {
        if (*it)
            (*it)->desenhar();
    }

    pJogador->desenhar();
} */