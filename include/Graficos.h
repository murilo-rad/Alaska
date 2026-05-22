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

                void desenharEnte(Alaska::Ente* pEnte);
                
                void limpar();
                void mostrar();

        };
    }
}