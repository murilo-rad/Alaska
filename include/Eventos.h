#pragma once
#include "pch.h"
#include "Jogador.h"

namespace Alaska 
{
    namespace Gerenciadores 
    {
        
        class Eventos 
        {
        private:
            sf::RenderWindow* janela;
            Alaska::Entidades::Personagens::Jogador* pJogador;

        public:
            Eventos();
            ~Eventos();

            void setJanela(sf::RenderWindow* pJ);
            void setJogador(Alaska::Entidades::Personagens::Jogador* pJ);
            void verificarEventos();
        };

    }
}