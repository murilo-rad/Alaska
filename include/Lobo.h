#pragma once
#include "pch.h"
#include "Inimigo.h"

namespace Alaska
{
    namespace Entidades
    {
        namespace Personagens
        {
            class Lobo : public Inimigo
            {
                public:
                    Lobo(float x, float y, Jogador* pJ);
                    ~Lobo();
                    void danificar();
                    void executar();
                    void salvar();
                    void mover();
            };
        }
    }
}