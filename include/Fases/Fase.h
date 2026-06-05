#pragma once
#include "pch.h"
#include "Ente.h"
#include "Entidade.h"
#include "Colisoes.h"
#include "ListaEntidades.h"

namespace Alaska
{
    namespace Fases
    {
        class Fase : public Ente
        {
            private:
                const int max_nevosos;
                const int max_plataformas;
            protected:
                Alaska::Gerenciadores::Colisoes* pColisoes;
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
                void criarCenario();
                void criarNevosos();
                void criarPlataformas();
                
        };
    }
}