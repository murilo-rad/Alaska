#include "Fase.h"

Alaska::Fases::Fase::Fase(Alaska::Entidades::Personagens::Jogador* pJ)
{   
    if(pJ)
        pJogador = pJ;

    pColisoes = new Alaska::Gerenciadores::Colisoes(pJogador, &listaEntidades);
}

Alaska::Fases::Fase::~Fase()
{
    //Brunno, ainda não temos a classe Lista, então eu criei a lista provisoriamente aqui.
    for (int i = 0; i < listaEntidades.size(); i++) 
    if(listaEntidades[i])
        delete listaEntidades[i];

    listaEntidades.clear();
    
    delete pColisoes;
}

void Alaska::Fases::Fase::executar()
{
    pJogador->executar();

    for (int i = 0; i < listaEntidades.size(); i++) 
        listaEntidades[i]->executar();
    
    if(pColisoes)
        pColisoes->calcularColisoes();

    for (int i = 0; i < listaEntidades.size(); i++) 
        listaEntidades[i]->desenhar();
    
    pJogador->desenhar();
}