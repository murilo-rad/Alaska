#pragma once
#include "pch.h"
#include "Inimigo.h"
#include "Jogador.h"

namespace Alaska
{
    namespace Entidades
    {
        namespace Personagens
        {
            class Nevoso : public Inimigo
            {
                private:
                    float acumulacao;
                public:
                    Nevoso(float x, float y, Jogador* pJ);
                    Nevoso();
                    ~Nevoso();

                    void executar();
                    void coletarDados();
                    void salvar();

                    void setAcumulacao(float ac);

                    int calcularAcumulacao();
                    void danificar(Alaska::Entidades::Personagens::Jogador* pJ);
                    void mover();
            };
        }
    }
}