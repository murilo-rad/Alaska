#pragma once
#include "pch.h"
#include "Fase.h"
#include "Plataforma.h"
#include "Ice_Spike.h"
#include "Nevoso.h"
#include "Lobo.h"
#include "Ente.h"
#include "Chao.h"

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
                void criarInimigos();
                void criarObstaculos();
                void criarLobos();
                void criarGelos();
                void criarChao();
                void executar();
       };
    }
}