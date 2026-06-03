#pragma once
#include "pch.h"
#include "Entidade.h"

namespace Alaska
{
    namespace Entidades
    {
        namespace Personagens
        {
            class Personagem : public Entidade
            {
                protected:
                    int num_vidas;
                    bool noChao;
                    float velX; 
                    float velY;
                public:
                    Personagem(float x, float y, int v);
                    Personagem(float x, float y, float vX, float vY, int v);
                    ~Personagem();

                    //void salvarDataBuffer();

                    virtual void executar() = 0;
                    virtual void salvar() = 0;
                    virtual void mover() = 0;

                    void setVida(const int v);
                    const int getVidas()const;

                    void setNoChao(bool c);
                    const bool getNoChao() const;

                    void setVelX(const float velXx);
                    void setVelY(const float velYy);
                    const float getVelX()const;
                    const float getVelY()const;
                    void aplicarGravidade();

                    Personagem& operator--();
            };
        }

    }
}