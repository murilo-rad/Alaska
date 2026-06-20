#pragma once
#include "pch.h"
#include "Jogador.h"
#include "Menu.h"
namespace Alaska
{
    class Menu;

    namespace Gerenciadores
    {
        class Gerenciador_Eventos
        {
        private:
            sf::RenderWindow* janela;
            Alaska::Entidades::Personagens::Jogador* pJogador1;
            Alaska::Entidades::Personagens::Jogador* pJogador2;
            Alaska::Menu* pMenu;
            bool botaoPause;
            bool botaoSalvar;

        public:
            Gerenciador_Eventos();
            ~Gerenciador_Eventos();

            void setJanela(sf::RenderWindow* pJ);
            void setJogadores(Alaska::Entidades::Personagens::Jogador* pJ, Alaska::Entidades::Personagens::Jogador* pJ2);
            void setMenu(Alaska::Menu* pM);
            void verificarEventos(bool processarInputsJogadores = true);
            bool pause();
            bool salvaEstadoAtual();
        };

    }
}