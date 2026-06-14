#pragma once
#include "pch.h"
#include "Fase.h"
#include "Abominavel.h"
#include "Bola_de_Neve.h"
#include "Conjunto_Estalagmites.h"
#include "Chao.h"
#include "Fundo.h"

namespace Alaska
{
    namespace Fases
    {
        class Caverna : public Fase
        {
            private:
                const int max_Abominaveis;
                const int max_Conjunto_Estalagmites;

                std::vector<Entidades::Personagens::Abominavel*>lAbms;
                std::vector<sf::Vector2f> posEstalagmites;
                std::vector<sf::Vector2f> posAbominaveis;
            public:
                Caverna(Entidades::Personagens::Jogador* pJ1, Entidades::Personagens::Jogador* pJ2);
                ~Caverna();
                void executar();
                void iniciarFase(short fase);
            protected:
                void criarInimigos();
                void criarObstaculos();
                void criarAbominaveis();
                void criarConjuntos_Estalagmites();
                void criarBolas_de_Neve(int quant);
        };
    }
}