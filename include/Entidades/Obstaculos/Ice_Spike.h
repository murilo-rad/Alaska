#pragma once
#include "pch.h"
#include "Jogador.h"
#include "Obstaculo.h"

namespace Alaska
{
    namespace Entidades
    {
        namespace Obstaculos
        {
            class Ice_Spike : public Obstaculo
            {
                private:
                    short int danosidade;
                public:
                    Ice_Spike();
                    Ice_Spike(float x, float y, bool d, short int dano);
                    ~Ice_Spike();
                    void executar();
                    void obstaculizar(Alaska::Entidades::Personagens::Jogador* pJogador);
            };
        }
    }
}