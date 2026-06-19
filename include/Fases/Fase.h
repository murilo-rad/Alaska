#pragma once
#include "pch.h"
#include "Ente.h"
#include "Entidade.h"
#include "Gerenciador_Colisoes.h"
#include "ListaEntidades.h"
#include "Nevoso.h"
#include "Plataforma.h"
#include "Inimigo.h"
#include "Obstaculo.h"
#include "Fundo.h"
#include "Chao.h"

namespace Alaska
{
    namespace Fases
    {
        class Fase : public Ente
        {
            private:
                const int max_Nevosos;
                const int max_Plataformas;
                bool concluida;

                std::vector<sf::Vector2f> posPlataformas;
                std::vector<sf::Vector2f> posNevosos;

            protected:
                Fundo* pFundo;
                Alaska::Gerenciadores::Gerenciador_Colisoes* GC;
                Alaska::Listas::ListaEntidades lista_ents;
                Alaska::Entidades::Personagens::Jogador* pJogador1;
                Alaska::Entidades::Personagens::Jogador* pJogador2;

            public:
                Fase();
                Fase(int n, int p, Alaska::Entidades::Personagens::Jogador* pJ1, Alaska::Entidades::Personagens::Jogador* pJ2);
                ~Fase();
                virtual void executar() = 0;
                virtual void iniciarFase(short fase) = 0;
                virtual bool faseTerminada() const;
                bool const terminou();
                bool const verificarJogadores() const;
                
            protected:
                virtual void criarInimigos() = 0;
                virtual void criarObstaculos() = 0;
                void criarChao(short fase);
                void criarFundo(short fase);
                void criarCenario(short fase);
                void criarNevosos();
                void criarPlataformas();
                void gerarFase();
                Alaska::Entidades::Personagens::Jogador* randJogador();
        };
    }
}