#include "ListaEntidades.h"

Alaska::Listas::ListaEntidades::ListaEntidades(): LEs(){}

Alaska::Listas::ListaEntidades::~ListaEntidades(){}

void Alaska::Listas::ListaEntidades::incluir(Alaska::Entidades::Entidade* pEnti)
{
    if(!pEnti)
        return;
    LEs.inserirNoFim(pEnti);
}

void Alaska::Listas::ListaEntidades::remover(Alaska::Entidades::Entidade* pEnti)
{
    if(!pEnti)
        return;
    LEs.removerE(pEnti);
}

Alaska::Listas::Lista<Alaska::Entidades::Entidade*>* Alaska::Listas::ListaEntidades::getLista() 
{
    return &LEs;
}

int Alaska::Listas::ListaEntidades::getTamanho() 
{
    int cont = 0;
    Lista<Alaska::Entidades::Entidade*>::Iterador it = LEs.getPrimeiro();
    return cont;
}

