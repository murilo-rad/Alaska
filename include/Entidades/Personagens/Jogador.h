#pragma once
#include "pch.h"
#include "Personagem.h"

namespace Alaska
{
    namespace Entidades
    {
        namespace Personagens
        {
			class Inimigo;
            class Jogador : public Personagem
            {
                protected:
                    int pontos;
                public:
                    Jogador();
                    Jogador(int num);
                    ~Jogador();
                    void executar();
                    void salvar();
                    void resetar();
                    void mover();
					void colidir(Inimigo* pIni);
                    void danificar(Inimigo* pIni);
					int getPontos();
                    void addPontos(int qtd);
            };
        }
    }
}