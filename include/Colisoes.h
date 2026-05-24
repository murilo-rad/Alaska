#pragma once
#include "pch.h"
#include "Jogador.h"
#include "Plataforma.h"
#include "Ice_Spike.h"

namespace Alaska 
{
    namespace Gerenciadores 
    {
        class Colisoes 
        {
        private:
            Entidades::Personagens::Jogador* pJogador;
            Entidades::Obstaculos::Plataforma* pPlataforma;
            Entidades::Obstaculos::Ice_Spike* pEspinho;

        public:
            Colisoes(Entidades::Personagens::Jogador* j, 
                     Entidades::Obstaculos::Plataforma* p, 
                     Entidades::Obstaculos::Ice_Spike* e);
            ~Colisoes();

            void calcularColisoes();
        };
    }
}