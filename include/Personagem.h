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
                    int vidas;
                public:
                    Personagem(float x, float y, int v);
                    ~Personagem();

                    virtual void executar() = 0;
                    void setVida(const int v);
                    const int getVidas()const;
            };
        }

    }
}