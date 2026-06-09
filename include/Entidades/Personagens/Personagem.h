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
                    short num_vidas;
                    bool noChao;
                    bool vivo;
                public:
                    Personagem(float x, float y, float vX, float vY, short nv);
                    Personagem();
                    ~Personagem();

                    void salvarDataBuffer();

                    void setMorto();

                    const int getVidas()const;
                    const bool estaVivo()const;

                    void setNoChao(bool c);
                    const bool getNoChao() const;

                    void operator--();

                    virtual void executar() = 0;
                    virtual void salvar() = 0;
                    virtual void mover() = 0;
            };
        }

    }
}