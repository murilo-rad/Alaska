#pragma once
#include "pch.h"
#include "Personagem.h"
#include "Jogador.h"


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
                    Inimigo(float x, float y, int mal, int v, Jogador* pJ);
                    virtual ~Inimigo();
                    virtual void executar() = 0;
                    virtual void danificar() = 0;
                    int getMaldade();
            };
        }
    }
}
