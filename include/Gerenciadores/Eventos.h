#pragma once
#include "pch.h"
//#include "Menu.h"
#include "Jogador.h"

namespace Alaska
{
    class Menu;

    namespace Gerenciadores
    {
        class Eventos
        {
        private:
            sf::RenderWindow* janela;
            Alaska::Entidades::Personagens::Jogador* pJogador;
			Alaska::Menu* pMenu;

        public:
            Eventos();
            ~Eventos();

            void setJanela(sf::RenderWindow* pJ);
            void setJogador(Alaska::Entidades::Personagens::Jogador* pJ);
            void setMenu(Alaska::Menu* pM);
            void verificarEventos();
        };

    }
}