#pragma once
#include "pch.h"
#include "Gerenciador_Grafico.h"

namespace Alaska { 
    namespace Gerenciadores { 
        class Gerenciador_Grafico; //pra declarar só
    } 
}

namespace Alaska
{
    class Ente
    {
    private:
        static int I;
    protected:
        int id;
        static Alaska::Gerenciadores::Gerenciador_Grafico* pGG;
        sf::Texture* pFig;
        sf::Sprite sprite;
    public:
        Ente();
        virtual ~Ente();

        virtual void executar() = 0;

        void desenhar();
        const int getID()const;

        static void setGG(Alaska::Gerenciadores::Gerenciador_Grafico* pG);

        sf::Sprite* getSprite();
        void ajustarSprite(sf::Sprite& sprite, float alt, float larg);
        void setTexture(sf::Texture& tx);

    };

}