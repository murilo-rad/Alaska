#pragma once
#include "pch.h"
#include "Fase.h"

namespace Alaska
{
    namespace Fases
    {
       class FaseNoite : public Fase
       {
            public:
                FaseNoite(Entidades::Personagens::Jogador* pJ);
                ~FaseNoite();
                void criarCenario();
                void criarInimigos();
                void criarObstaculos();
       };
    }
}