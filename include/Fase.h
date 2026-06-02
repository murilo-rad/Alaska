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
            protected:
                Alaska::Gerenciadores::Colisoes* pColisoes;
                Alaska::Listas::ListaEntidades lista_ents;
                Alaska::Entidades::Personagens::Jogador* pJogador;
            public:
                Fase(Alaska::Entidades::Personagens::Jogador* pJ);
                ~Fase();
                virtual void executar();
            protected:
                virtual void criarInimigos() = 0;
                virtual void criarObstaculos() = 0;
                void criarCenario();
                void criarInimiFaceis();
                void criarPlataformas();
        };
    }
}