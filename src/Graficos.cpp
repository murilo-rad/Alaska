#include "Graficos.h"

Alaska::Gerenciadores::Graficos::Graficos()
{

}

Alaska::Gerenciadores::Graficos::~Graficos()
{

}

void Alaska::Gerenciadores::Graficos::desenharEnte(sf::Sprite* pSprite)
{
    if(pSprite && janela && janela->isOpen())
        janela->draw(*pSprite);        
}