#pragma once
#include "pch.h"
#include "Personagem.h"

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
                    int maldade;
                    Jogador* pJogador;
                    float velocidade;

                    void seguirJogador();

                public:
                    Inimigo(float x, float y, int mal, int v, Jogador* pJ);
                    virtual ~Inimigo();
                    virtual void executar() = 0;
                    int getMaldade();
            };

            class InimigoSimples : public Inimigo
            {
                public:
                    InimigoSimples(float x, float y, Jogador* pJ);
                    ~InimigoSimples();
                    void executar();
            };
        }
    }
}
