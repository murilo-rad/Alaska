#include "ListaEntidades.h"

Alaska::Listas::ListaEntidades::ListaEntidades(): LEs(){}

Alaska::Listas::ListaEntidades::~ListaEntidades(){}

void Alaska::Listas::ListaEntidades::incluir(Alaska::Entidades::Entidade* pE)
{
    if(!pE)
        return;
    LEs.inserirNoFim(pE);
}

void Alaska::Listas::ListaEntidades::remover(Alaska::Entidades::Entidade* pE)
{
    if(!pE)
        return;
    LEs.removerE(pE);
}

Alaska::Listas::Lista<Alaska::Entidades::Entidade*>* Alaska::Listas::ListaEntidades::getLista() 
{
    return &LEs;
}

void Alaska::Listas::ListaEntidades::percorrer()
{
    for (Lista<Alaska::Entidades::Entidade*>::Iterador it = LEs.begin(); it != LEs.end(); ++it)
    {
        if (*it)
            (*it)->executar();
    }
}
