#include "Plataforma.h"

Alaska::Entidades::Obstaculos::Plataforma::Plataforma() : Obstaculo(0.0f, 500.0f), altura(50)
{
    sf::Image img;
    img.create(800, 50, sf::Color::Green);
    textura.loadFromImage(img);
    sprite.setTexture(textura);
    sprite.setPosition(x, y);
}

Alaska::Entidades::Obstaculos::Plataforma::~Plataforma() {}

void Alaska::Entidades::Obstaculos::Plataforma::executar() {}