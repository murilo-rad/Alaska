#pragma once
#include "pch.h"
#include "Graficos.h"

namespace Alaska { 
    namespace Gerenciadores { 
        class Graficos; //pra declarar só
    } 
}

namespace Alaska
{
    class Ente
    {
    protected:
        static int I;
        const int id;
        static Alaska::Gerenciadores::Graficos* pGG;
        sf::Texture* pFig;
        sf::Sprite sprite;
    public:
        Ente();
        virtual ~Ente();

        virtual void executar() = 0;

        void desenhar();
        const int getID()const;

        static void setGG(Alaska::Gerenciadores::Graficos* pG);

        sf::Sprite* getSprite();
        void ajustarSprite(sf::Sprite& sprite, float alt, float larg);
        void setTexture(sf::Texture& tx);

    };

}