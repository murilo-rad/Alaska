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
                    Nevoso(float x, float y, Jogador* pJ);
                    Nevoso();
                    ~Nevoso();
                    int calcularAcumulacao();
                    void danificar(Alaska::Entidades::Personagens::Jogador* pJ);
                    void executar();
                    void salvar();
                    void mover();
            };
        }
    }
}