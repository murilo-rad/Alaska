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
                    float tamanho;
                public:
                    Nevoso(float vx, float vy, int v, int mal, Jogador* pJ, float vel);
                    Nevoso();
                    ~Nevoso();
                    void danificar();
                    void executar();
                    void salvar();
                    void mover();
            };
        }
    }
}