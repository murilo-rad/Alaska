#pragma once
#include "pch.h"
#include "Inimigo.h"

namespace Alaska
{
    namespace Entidades
    {
        namespace Personagens
        {
            class Nevoso : public Inimigo
            {
                private:
				    int tamanho;    //atributo iunico da classe q tem q ter
                public:
					Nevoso();
                    Nevoso(float x, float y, Jogador* pJ);
                    ~Nevoso();
                    void danificar();
                    void executar();
                    void salvar();
                    void mover();
            };
        }
    }
}