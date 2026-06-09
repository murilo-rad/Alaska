#pragma once
#include "pch.h"
#include "Obstaculo.h"
#include "Jogador.h"
#include "Inimigo.h"

namespace Alaska
{
    namespace Entidades
    {
        namespace Obstaculos
        {
            class Plataforma : public Obstaculo
            {
                private:
                    int largura;
                public:
                    Plataforma(float x, float y);
                    Plataforma();
                    ~Plataforma();
                    void executar();
                    void obstaculizar(Alaska::Entidades::Personagens::Jogador* pJ);
                    void obstaculizarInimigo(Alaska::Entidades::Personagens::Inimigo* pI);
                    void salvar();
            };
        }
    }
}
