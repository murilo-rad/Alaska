#pragma once
#include "pch.h"
#include "Personagem.h"

namespace Alaska
{
    namespace Entidades
    {
        namespace Personagens
        {
			class Inimigo;   //pra n dar pau
            class Jogador : public Personagem
            {
                protected:
                    int pontos;
                public:
                    Jogador(float x, float y);
                    Jogador();
                    ~Jogador();
                    void executar();
                    void salvar();
                    void mover();
					void colidir(Inimigo* pIni);
                    void danificar(Inimigo* pIni);
            };
        }
    }
}