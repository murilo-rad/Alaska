#pragma once
#include "pch.h"
#include "Inimigo.h"

namespace Alaska
{
    namespace Entidades
    {
        class Bola_de_Neve;
        namespace Personagens
        {
            class Abominavel : public Inimigo
            {
                private:
                    Alaska::Entidades::Bola_de_Neve* pBola;
                    float forca;
                public:
                    Abominavel(float x, float y, Jogador* pJ);
                    Abominavel();
                    ~Abominavel();
                    float calcularForca();
                    void danificar(Alaska::Entidades::Personagens::Jogador* pJ);
                    void executar();
                    void salvar();
                    void mover();
                    //void setPBola(Alaska::Entidades::Bola_de_Neve* pProj);
            };
        }
    }
}