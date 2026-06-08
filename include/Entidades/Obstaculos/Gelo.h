#pragma once
#include "pch.h"
#include "Obstaculo.h"
#include "Inimigo.h"

namespace Alaska
{
    namespace Entidades
    {
        namespace Obstaculos
        {
            class Gelo : public Obstaculo
            {
                private:
                    float atrito;
                public:
                    Gelo(float x, float y);
                    ~Gelo();
                    void salvar();
                    void executar();
                    void obstaculizar(Alaska::Entidades::Personagens::Jogador* pJ);
                    void obstaculizarInimigo(Alaska::Entidades::Personagens::Inimigo* pI);
            };
        }
    }
}