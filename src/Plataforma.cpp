#include "Plataforma.h"

Alaska::Entidades::Obstaculos::Plataforma::Plataforma(float x, float y) : Obstaculo(x, y), altura(50)
{
    sf::Image img;
    img.create(800, 50, sf::Color::Green);
    textura.loadFromImage(img);
    sprite.setTexture(textura);
    sprite.setPosition(x, y);
}

Alaska::Entidades::Obstaculos::Plataforma::~Plataforma() {}

void Alaska::Entidades::Obstaculos::Plataforma::executar() {}