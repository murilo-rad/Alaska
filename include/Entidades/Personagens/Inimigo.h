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
                    int idJogador;
                protected:
                    void seguirJogador();
                    virtual void coletarDados();
                public:
                    Inimigo(float x, float y, short nv, Jogador* pJ);
                    Inimigo();
                    ~Inimigo();

                    virtual void executar() = 0;
                    void salvarDataBuffer();
                    virtual void salvar() = 0;

                    void setMaldade(int m);
                    int getMaldade();

                    void setJogador(Alaska::Entidades::Personagens::Jogador* pJ);
                    void setIdJogador(int i);

                    void setVelocidade(float vel);

                    virtual void danificar(Alaska::Entidades::Personagens::Jogador* pJ) = 0;
                    virtual void mover() = 0;
                    int calcularMaldade();
                    sf::Vector2f normalizarVetor(sf::Vector2f v);
					void impedirSobrePosicao(Entidade* pI);
            };
        }
    }
}
