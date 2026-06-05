#include "Ente.h"
#include "Graficos.h"

int Alaska::Ente::I = 0;
Alaska::Gerenciadores::Graficos* Alaska::Ente::pGG = nullptr;

Alaska::Ente::Ente(): id(I++), pFig(nullptr), sprite(){}

Alaska::Ente::~Ente(){}

void Alaska::Ente::desenhar()
{
    if(pGG)
        pGG->desenharEnte(this);
}

void Alaska::Ente::setGG(Alaska::Gerenciadores::Graficos* pG)
{
    if(pG)
        pGG = pG;
}

sf::Sprite* Alaska::Ente::getSprite()
{
    if (pFig) {
		sprite.setTexture(*pFig);
    }
    return &sprite;
}