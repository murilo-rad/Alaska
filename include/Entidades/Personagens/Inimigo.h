#pragma once
#include "pch.h"
#include "Personagem.h"
#include "Jogador.h"
#include <cmath>


namespace Alaska
{
    namespace Entidades
    {
        namespace Personagens
        {
            class Jogador;
            class Inimigo : public Personagem
            {
                protected:
                    int nivel_maldade;
                    Jogador* pJogador;
                    float velocidade;
                    void seguirJogador();
                public:
                    Inimigo(float vx, float vy, int v, int mal, Jogador* pJ, float vel);
                    Inimigo();
                    virtual ~Inimigo();
                    virtual void executar() = 0;
                    virtual void danificar() = 0;
            };
        }
    }
}
