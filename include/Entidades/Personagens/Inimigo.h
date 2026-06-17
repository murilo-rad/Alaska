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
            class Inimigo : public Personagem
            {
                protected:
                    int nivel_maldade;
                    Jogador* pJogador;
                    float velocidade;
                protected:
                    void seguirJogador();
                public:
                    Inimigo(float x, float y, short nv, Jogador* pJ);
                    Inimigo();
                    ~Inimigo();
                    void coletarDados() {};
                    virtual void executar() = 0;
                    virtual void danificar(Alaska::Entidades::Personagens::Jogador* pJ) = 0;
                    virtual void salvar() = 0;
                    virtual void mover() = 0;

                    int calcularMaldade();
                    int getMaldade();
                    sf::Vector2f normalizarVetor(sf::Vector2f v);
					void salvarDataBuffer();
					void impedirSobrePosicao(Entidade* pI);
            };
        }
    }
}
