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
                    Lobo(float x, float y, Jogador* pJ);
                    Lobo();
                    ~Lobo();
                    float calcularVoracidade();
                    void danificar(Alaska::Entidades::Personagens::Jogador* pJ);
                    void executar();
                    void salvar();
                    void mover();
            };
        }
    }
}