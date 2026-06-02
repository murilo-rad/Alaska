#pragma once
#include "pch.h"
#include "Lista.h"
#include "Entidade.h"

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
                void incluir(Entidades::Entidade* pEnti);
                void remover(Entidades::Entidade* pEnti);
                Lista<Alaska::Entidades::Entidade*>* getLista();
                int getTamanho();
                Alaska::Entidades::Entidade* operator[](int indice);
        };
    }
}