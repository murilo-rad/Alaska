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
                public:
                    Gelo(float x, float y);
                    ~Gelo();
                    void executar();
                    virtual void obstaculizar(Alaska::Entidades::Personagens::Jogador* pJ);
            };
        }
    }
}