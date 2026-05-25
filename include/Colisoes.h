#pragma once
#include "pch.h"
#include "Jogador.h"
#include "Entidade.h"

namespace Alaska 
{
    namespace Gerenciadores 
    {
        class Colisoes 
        {
        private:
            Entidades::Personagens::Jogador* pJogador;
            std::vector<Entidades::Entidade*>* listaEntidades;

        public:
            Colisoes(Entidades::Personagens::Jogador* pJ, std::vector<Entidades::Entidade*>* listaEnt);
            ~Colisoes();

            void calcularColisoes();
        };
    }
}