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
    return &sprite;
}

const int Alaska::Ente::getID()const
{
    return id;
}

void Alaska::Ente::setTexture(sf::Texture& tx)
{
    pFig = &tx;
}

void Alaska::Ente::ajustarSprite(sf::Sprite& sprite, float alt, float larg)
{
    sf::FloatRect bounds = sprite.getLocalBounds();

    sprite.setScale
    (
        larg / bounds.width,
        alt / bounds.height
    );
}