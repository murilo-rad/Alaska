#pragma once
#include "pch.h"
#include "Entidade.h"
#include "Jogador.h"

namespace Alaska
{
    namespace Entidades
    {
        namespace Obstaculos
        {
            class Obstaculo : public Entidade
            {
                protected:
                    bool danoso;
                public:
                    Obstaculo(float x, float y);
                    Obstaculo();
                    ~Obstaculo();
                    virtual void executar() = 0;
                    virtual void obstaculizar(Alaska::Entidades::Personagens::Jogador* pJ) = 0;
            };
        }
    }
}
