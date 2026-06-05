#pragma once
#include "pch.h"
#include "Inimigo.h"
#include "Jogador.h"

namespace Alaska
{
    namespace Entidades
    {
        namespace Personagens
        {
            class Nevoso : public Inimigo
            {
                private:
                    float acumulacao;
                public:
                    Nevoso(float vx, float vy, int v, int mal, Jogador* pJ, float vel);
                    Nevoso();
                    ~Nevoso();
                    void danificar(Alaska::Entidades::Personagens::Jogador* pJ);
                    void executar();
                    void salvar();
                    void mover();
            };
        }
    }
}