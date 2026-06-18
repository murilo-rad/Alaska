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
                    std::string nome;
                public:
                    Jogador(int num);
                    Jogador();
                    ~Jogador();

                    void executar();
                    void coletarDados();
                    void salvar();

                    void setPontos(int p);
                    const int getPontos() const;
                    void addPontos(int qtd);

                    void setNome(std::string n);

                    void resetar();
                    void mover();
					void colidir(Inimigo* pIni);
                    void danificar(Inimigo* pIni);
					
            };
        }
    }
}