#pragma once
#include "pch.h"
#include "Fase.h"

namespace Alaska
{
    namespace Fases
    {
       class FaseNoite : public Fase
       {
            private:
                const int maxLobos;
                const int maxGelos;
            public:
                FaseNoite(int n, int p, int l, int g, Entidades::Personagens::Jogador* pJ);
                ~FaseNoite();
                void criarChao();
                void criarInimigos();
                void criarObstaculos();
                void criarLobos();
                void criarGelos();
                void executar();
                
       };
    }
}