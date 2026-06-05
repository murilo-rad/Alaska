#pragma once
#include "pch.h"
#include "Inimigo.h"

namespace Alaska
{
    namespace Entidades
    {
        namespace Personagens
        {
            class Lobo : public Inimigo
            {
                private:
                    int raio;    //atributo iunico da classe q tem q te
                public:
                    Lobo();
                    Lobo(float x, float y, Jogador* pJ);
                    ~Lobo();
                    void danificar();
                    void executar();
                    void salvar();
                    void mover();
            };
        }
    }
}