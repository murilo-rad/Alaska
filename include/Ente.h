#pragma once
#include "pch.h"
#include "Graficos.h"

namespace Alaska
{
    class Ente
    {
        protected:
            static int I;
            const int id;
            static Alaska::Gerenciadores::Graficos * pGG;
            sf::Texture textura;
            sf::Sprite sprite;
        public:
            Ente();
            virtual ~Ente();

            virtual void executar() = 0;
            void desenhar();
            static void setGG(Alaska::Gerenciadores::Graficos* pG);
            sf::Sprite* getSprite(); 
    };

}