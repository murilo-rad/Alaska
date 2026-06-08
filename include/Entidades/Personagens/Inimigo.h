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
            class Jogador;   //pra n dar pau
            class Inimigo : public Personagem
            {
                protected:
                    float nivel_maldade;
                    Jogador* pJogador;
                    float velocidade;
                protected:
                    void seguirJogador();
                public:
                    Inimigo();
                    Inimigo(float xx, float yy, int mal, int v, Jogador* pJ);
                    virtual ~Inimigo();
                    virtual void executar() = 0;
                    virtual void danificar(Alaska::Entidades::Personagens::Jogador* pJ) = 0;
                    virtual void salvar() = 0;
                    virtual void mover() = 0;

                    void calcularMaldade();
                    int getMaldade();
                    sf::Vector2f normalizarVetor(sf::Vector2f v);
					void salvarDataBuffer();

            };
        }
    }
}
