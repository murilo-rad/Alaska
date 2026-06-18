#pragma once
#include "pch.h"
#include "Entidade.h"
#include "Jogador.h"

namespace Alaska
{
    namespace Entidades
    {
        namespace Obstaculos
        {
            class Obstaculo : public Entidade
            {
                protected:
                    bool danoso;
                    virtual void coletarDados();
                public:
                    Obstaculo(float x, float y, bool dn);
                    Obstaculo();
                    ~Obstaculo();

                    virtual void executar() = 0;
					void salvarDataBuffer();
                    virtual void salvar() = 0;

                    void setDanoso(bool d);

                    void antiGravitar();
                    virtual void obstaculizar(Alaska::Entidades::Personagens::Jogador* pJ) = 0;
					virtual void obstaculizarInimigo(Alaska::Entidades::Personagens::Inimigo* pI) = 0;
	
            };
        }
    }
}
