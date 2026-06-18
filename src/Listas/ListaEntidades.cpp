#include "ListaEntidades.h"
#include <Jogador.h>

Alaska::Listas::ListaEntidades::ListaEntidades() : LEs() {}

Alaska::Listas::ListaEntidades::~ListaEntidades() {}

void Alaska::Listas::ListaEntidades::incluir(Alaska::Entidades::Entidade *pE)
{
    if (!pE)
        return;
    LEs.inserirNoFim(pE);
}

void Alaska::Listas::ListaEntidades::remover(Alaska::Entidades::Entidade *pE)
{
    if (!pE)
        return;
    LEs.removerE(pE);
}

Alaska::Listas::Lista<Alaska::Entidades::Entidade *> *Alaska::Listas::ListaEntidades::getLista()
{
    return &LEs;
}

void Alaska::Listas::ListaEntidades::percorrer()
{
    for (Lista<Alaska::Entidades::Entidade *>::Iterador it = LEs.begin(); it != LEs.end(); ++it)
    {
        if (*it)
            (*it)->executar();
    }
}

void Alaska::Listas::ListaEntidades::cemiterio()
{
    for (Lista<Alaska::Entidades::Entidade *>::Iterador it = LEs.begin(); it != LEs.end();)
    {
        auto atual = it++;

        auto *p = dynamic_cast<Entidades::Personagens::Personagem *>(*atual);
        if (p && !p->estaVivo())
        {
            Entidades::Entidade *ptr = *atual;
            LEs.removerE(ptr);
            if (!dynamic_cast<Entidades::Personagens::Jogador *>(ptr))
                delete ptr;
        }
    }
}

void Alaska::Listas::ListaEntidades::salvarEntidades()
{
    for (Lista<Alaska::Entidades::Entidade *>::Iterador it = LEs.begin(); it != LEs.end(); ++it)
    {
        if (*it)
            (*it)->salvar();
    }
}