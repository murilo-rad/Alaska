#include "Nevoso.h"

Alaska::Entidades::Personagens::Nevoso::Nevoso() : tamanho(0), Inimigo() {}

Alaska::Entidades::Personagens::Nevoso::Nevoso(float x, float y, Jogador* pJ) : tamanho(y), Inimigo(x, y, 1, 1, pJ) 
{
    pFig = new sf::Texture();
    sf::Image img;
    img.create(50, 50, sf::Color::White);
    pFig->loadFromImage(img);
    sprite.setTexture(*pFig);
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