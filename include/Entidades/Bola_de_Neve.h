#pragma once
#include "Entidade.h"
#include "Abominavel.h"

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
                Bola_de_Neve(short f);
                Bola_de_Neve();
                ~Bola_de_Neve();
                void executar();
                void salvar();
                //void setPAbm(Alaska::Entidades::Personagens::Abominavel* Ab);
        };
    }
}