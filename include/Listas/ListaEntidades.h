#pragma once
#include "pch.h"
#include "Lista.h"
#include "Entidade.h"
#include "Personagem.h"

namespace Alaska
{
    namespace Listas
    {
        class ListaEntidades
        {
            private:
                Lista<Alaska::Entidades::Entidade*> LEs;
            public:
                ListaEntidades();
                ~ListaEntidades();
                void incluir(Entidades::Entidade* pE);
                void percorrer();
                void cemiterio();
                void salvarEntidades();
                void remover(Entidades::Entidade* pE);
                Lista<Alaska::Entidades::Entidade*>* getLista();
        };
    }
}