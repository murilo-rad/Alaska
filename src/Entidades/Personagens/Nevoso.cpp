#include "Nevoso.h"


Alaska::Entidades::Personagens::Nevoso::Nevoso
(float vx, float vy, int v, int mal, Alaska::Entidades::Personagens::Jogador* pJ, float vel) : 
Inimigo(vx, vy, mal, v, pJ), tamanho()
{
    pFig = new sf::Texture();
    sf::Image img;
    img.create(50, 50, sf::Color::White);
    pFig->loadFromImage(img);
    sprite.setTexture(*pFig);
    sprite.setPosition(x, y);
}

Alaska::Entidades::Personagens::Nevoso::Nevoso(){}

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