#pragma once
#include "pch.h"
#include "Ente.h"
#include <SFML/System/String.hpp>

namespace Alaska { 
    class Ente; //pra declarar só
}

namespace Alaska
{
    namespace Gerenciadores
    {
        class Gerenciador_Grafico
        {
        private:
            sf::RenderWindow* janela;
            sf::View camera;
            sf::Text text;
			sf::Font fontMenu;
        public:
            Gerenciador_Grafico();
            ~Gerenciador_Grafico();

            void desenharEnte(Ente* pEnte);
            void desenharTexto(sf::Text* pTexto);
			void desenharTituloMenu(const sf::String& pStrTitulo);
			void desenharOpcaoMenu(const sf::String& pStrOpcao, int indice, bool selecionado);
            void limpar();
            void mostrar();
            bool isJanelaAberta();
            sf::RenderWindow* getJanela();

            void atualizarCamera(float x, float y);
        };
    }
}