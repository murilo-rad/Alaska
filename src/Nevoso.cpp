#include "Nevoso.h"

Alaska::Entidades::Personagens::Nevoso::Nevoso(float x, float y, Jogador* pJ) : Inimigo(x, y, 1, 1, pJ) 
{
    sf::Image img;
    img.create(50, 50, sf::Color::White);
    textura.loadFromImage(img);
    sprite.setTexture(textura);
    sprite.setPosition(x, y);

    velX = 0.0f;
    velY = 0.0f;
}

Alaska::Entidades::Personagens::Nevoso::~Nevoso() {}

void Alaska::Entidades::Personagens::Nevoso::executar()
{
    seguirJogador();
    aplicarGravidade();
    sprite.setPosition(x, y);
}

void Alaska::Entidades::Personagens::Nevoso::salvar()
{
  
}

void Alaska::Entidades::Personagens::Nevoso::mover()
{

}

void Alaska::Entidades::Personagens::Nevoso::danificar()
{

}