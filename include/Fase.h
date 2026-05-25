#pragma once
#include "pch.h"
#include "Ente.h"
#include "Entidade.h"
#include "Jogador.h"
#include "Colisoes.h"

namespace Alaska
{
    namespace Fases
    {
        class Fase : public Ente
        {
            protected:
                Entidades::Personagens::Jogador* pJogador;
                Alaska::Gerenciadores::Colisoes* pColisoes;
                std::vector<Entidades::Entidade*> listaEntidades;
            public:
                Fase(Entidades::Personagens::Jogador* pJ);
                virtual ~Fase();
                virtual void criarCenario() = 0;
                void executar();
        };
    }
}