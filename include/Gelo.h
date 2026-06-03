#pragma once
#include "pch.h"
#include "Obstaculo.h"

namespace Alaska
{
    namespace Entidades
    {
        namespace Obstaculos
        {
            class Gelo : public Obstaculo
            {
                private:
                    float largura;
                public:
                    Gelo(float x, float y);
                    ~Gelo();
                    void executar();
                    void obstaculizar(Alaska::Entidades::Personagens::Jogador* pJ);
            };
        }
    }
}