#pragma once
#include "pch.h"
#include "Obstaculo.h"
#include "Jogador.h"

namespace Alaska
{
    namespace Entidades
    {
        namespace Obstaculos
        {
            class Plataforma : public Obstaculo
            {
                private:
                    int altura;
                public:
                    Plataforma(float x, float y);
                    ~Plataforma();
                    void executar();
                    void obstaculizar(Alaska::Entidades::Personagens::Jogador* pJ);
            };
        }

    }
}
