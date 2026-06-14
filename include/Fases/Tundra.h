#pragma once
#include "pch.h"
#include "Fase.h"
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
            
            Entidades::Personagens::Jogador *pJogador1;
            Entidades::Personagens::Jogador *pJogador2;

            std::vector<sf::Vector2f> posLobos;
            std::vector<sf::Vector2f> posGelos;

        public:
            Tundra(Entidades::Personagens::Jogador *pJ1, Entidades::Personagens::Jogador *pJ2);
            ~Tundra();
            void executar();
            void iniciarFase(short fase);

        protected:
            void criarInimigos();
            void criarObstaculos();
            void criarLobos();
            void criarGelos();
        };
    }
}