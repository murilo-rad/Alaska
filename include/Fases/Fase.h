#pragma once
#include "pch.h"
#include "Ente.h"
#include "Entidade.h"
#include "Colisoes.h"
#include "ListaEntidades.h"
#include "Nevoso.h"
#include "Plataforma.h"
#include "Inimigo.h"
#include "Obstaculo.h"

namespace Alaska
{
    namespace Fases
    {
        class Fase : public Ente
        {
            private:
                const int maxNevosos;
                const int max_plataformas;
            protected:
                Alaska::Gerenciadores::Colisoes* GC;
                Alaska::Listas::ListaEntidades lista_ents;
                Alaska::Entidades::Personagens::Jogador* pJogador;
            public:
                Fase();
                Fase(int n, int p, Alaska::Entidades::Personagens::Jogador* pJ);
                ~Fase();
                virtual void executar() = 0;
            protected:
                virtual void criarInimigos() = 0;
                virtual void criarObstaculos() = 0;
                virtual void criarChao() = 0;
                virtual void criarCenario() = 0;
                void criarNevosos();
                void criarPlataformas();
        };
    }
}