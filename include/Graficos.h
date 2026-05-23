#pragma once
#include "pch.h"
#include "Ente.h"

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

        };
    }
}