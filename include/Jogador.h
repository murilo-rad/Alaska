#pragma once
#include "pch.h"
#include "Personagem.h"
#include "Inimigo.h"

namespace Alaska
{
    namespace Entidades
    {
        namespace Personagens
        {
            class Jogador : public Personagem
            {
                protected:
                    int pontos;
                public:
                    Jogador();
                    ~Jogador();
            };
        }
    }
}