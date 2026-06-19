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
                Bola_de_Neve();
                ~Bola_de_Neve();

                void executar();
                void coletarDados();
                void salvar();

                void setAtivo(bool a);
                const bool getAtivo()const;
                void setAbominavel(Alaska::Entidades::Personagens::Abominavel* pAbo);
                
                void mover();
                void antiGravitar();
                void acertar(Alaska::Entidades::Personagens::Jogador* pJ);
        };
    }
}