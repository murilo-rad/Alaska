#pragma once
#include "pch.h"
#include "Jogador.h"
#include "Inimigo.h"
#include "Obstaculo.h"

namespace Alaska
{
    namespace Entidades
    {
        namespace Obstaculos
        {
            class Conjunto_Estalagmites : public Obstaculo
            {
                private:
                    short int danosidade;
                public:
                    Conjunto_Estalagmites();
                    Conjunto_Estalagmites(float x, float y);
                    ~Conjunto_Estalagmites();
                    void salvar();
                    void coletarDados() {};
                    void executar();
                    void obstaculizar(Alaska::Entidades::Personagens::Jogador* pJogador);
                    void obstaculizarInimigo(Alaska::Entidades::Personagens::Inimigo* pI);
            };
        }
    }
}