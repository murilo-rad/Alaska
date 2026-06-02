#pragma once
#include "pch.h"
#include "Inimigo.h"

namespace Alaska
{
    namespace Entidades
    {
        namespace Personagens
        {
            class Nevoso : public Inimigo
            {
                public:
                    Nevoso(float x, float y, Jogador* pJ);
                    ~Nevoso();
                    void danificar();
                    void executar();
                    void salvar();
                    void mover();
            };
        }
    }
}