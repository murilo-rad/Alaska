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
                private:
                    float voracidade;
                public:
                    Lobo();
                    Lobo(float xx, float yy, Jogador* pJ);
                    ~Lobo();
                    void danificar(Alaska::Entidades::Personagens::Jogador* pJ);
                    void executar();
                    void salvar();
                    void mover();
            };
        }
    }
}