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
                    int voracidade;
                public:
                    Lobo(float x, float y, Jogador* pJ);
                    Lobo();
                    ~Lobo();

                    void executar();
                    void coletarDados();
                    void salvar();

                    void setVoracidade(int v);

                    int calcularVoracidade();
                    void danificar(Alaska::Entidades::Personagens::Jogador* pJ);
                    void mover();
            };
        }
    }
}