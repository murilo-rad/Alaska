#pragma once
#include "pch.h"

namespace Alaska
{
    namespace Gerenciadores
    {
        class Graficos 
        {
            private:
                sf::RenderWindow* janela;
            public:
                Graficos();
                ~Graficos();

                void desenharEnte(sf::Sprite* pSprite);
                void limpar();
                void mostrar();
                bool isJanelaAberta();
                sf::RenderWindow* getJanela();
        };
    }
}