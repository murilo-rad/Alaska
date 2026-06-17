#pragma once
#include "pch.h"
#include "Entidade.h"
#include "Personagem.h"

namespace Alaska
{
    namespace Entidades
    {
        class Chao : public Entidade
        {
            private:
                short fase;
            public:
                Chao(short f);
                Chao();
                ~Chao();
                void executar();
                void salvar();

                void coletarDados() {};
                void empurrar(Alaska::Entidades::Personagens::Personagem* pP);
        };
    }
}