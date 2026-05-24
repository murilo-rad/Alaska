#pragma once
#include "pch.h"
#include "Graficos.h"
#include "Personagem.h"

namespace Alaska
{
    class JogoAlaska
    {
        private:
            Alaska::Gerenciadores::Graficos* pGrafico;
            std::vector<Alaska::Entidades::Personagens::Personagem*> personagens;
        public:
            JogoAlaska();
            ~JogoAlaska();

    };
}
