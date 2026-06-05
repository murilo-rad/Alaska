#pragma once
#include "pch.h"
#include "Personagem.h"
#include <cmath>


namespace Alaska
{
    namespace Entidades
    {
        namespace Personagens
        {
            class Jogador;   //pra n dar pau
            class Inimigo : public Personagem
            {
                protected:
                    int nivel_maldade;
                    Jogador* pJogador;
                    float velocidade;
                protected:
                    void seguirJogador();
                public:
                    Inimigo();
                    Inimigo(float x, float y, int mal, int v, Jogador* pJ);
                    virtual ~Inimigo();
                    virtual void executar() = 0;
                    virtual void danificar() = 0;
                    int getMaldade();
                    sf::Vector2f normalizarVetor(sf::Vector2f v);
					void salvarDataBuffer();
                    virtual void salvar() = 0;
            };
        }
    }
}
