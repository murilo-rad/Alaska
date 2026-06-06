#pragma once
#include "pch.h"
#include "Entidade.h"
#include "Personagem.h"

namespace Alaska
{
    namespace Entidades
    {
        class Chao : public Entidade
        {
            private:
                int fase;
            public:
                Chao(sf::Texture &chao);
                ~Chao();
                void executar();
                void salvar();
                void empurrar(Alaska::Entidades::Personagens::Personagem* pP);
        };
    }
}