#pragma once
#include "Entidade.h"
#include "Abominavel.h"
#include "Jogador.h"

namespace Alaska
{
    namespace Entidades
    {
        class Bola_de_Neve : public Entidade
        {
            private:
                Alaska::Entidades::Personagens::Abominavel* pAbm;
                bool ativo;
            public:
                Bola_de_Neve(Alaska::Entidades::Personagens::Abominavel* pA);
                ~Bola_de_Neve();
                void setAtivo();
                const bool getAtivo()const;
                void executar();
                void mover();
                void antiGravitar();
                void salvar();
                
                void coletarDados() {};
                void acertar(Alaska::Entidades::Personagens::Jogador* pJ);
        };
    }
}