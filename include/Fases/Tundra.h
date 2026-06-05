#pragma once
#include "pch.h"
#include "Fase.h"

namespace Alaska
{
    namespace Fases
    {
       class Tundra : public Fase
       {
            private:
                const int maxLobos;
                const int maxGelos;
            public:
                Tundra(int n, int p, int l, int g, Entidades::Personagens::Jogador* pJ);
                ~Tundra();
                void criarChao();
                void criarInimigos();
                void criarObstaculos();
                void criarLobos();
                void criarGelos();
                void executar();
       };
    }
}