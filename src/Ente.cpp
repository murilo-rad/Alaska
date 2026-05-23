#include "Ente.h"

int Alaska::Ente::I = 0;
Alaska::Gerenciadores::Graficos* Alaska::Ente::pGG = nullptr;

Alaska::Ente::Ente(): id(I++){}

Alaska::Ente::~Ente(){}

void Alaska::Ente::desenhar()
{
    if(pGG)
        pGG->desenharEnte(&sprite);
}

void Alaska::Ente::setGG(Alaska::Gerenciadores::Graficos* pG)
{
    if(pG)
        pGG = pG;
}

sf::Sprite* Alaska::Ente::getSprite()
{
    return &sprite;
}