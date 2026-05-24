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
                    int maldade;
                public:
                    Inimigo(float x, float y, int mal, int v);
                    ~Inimigo();
                    virtual void executar() = 0;
                    int getMaldade();
            };
        }
    }
}