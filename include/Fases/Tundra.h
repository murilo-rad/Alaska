#pragma once
#include "pch.h"
#include "Fase.h"
#include "Ente.h"
#include "Plataforma.h"
#include "Nevoso.h"
#include "Lobo.h"
#include "Chao.h"
#include "Fundo.h"
#include "Gelo.h"

namespace Alaska
{
    namespace Fases
    {
       class Tundra : public Fase
       {
            private:
                const int max_Lobos;
                const int max_Gelos;
                Entidades::Personagens::Jogador* pJogador;
            public:
                Tundra(int n, int p, int l, int g, Entidades::Personagens::Jogador* pJ);
                ~Tundra();
                void criarInimigos();
                void criarObstaculos();
                void criarLobos();
                void criarGelos();
                void executar();
                void inicarFase(short fase);
       };
    }
}