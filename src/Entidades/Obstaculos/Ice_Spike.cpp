#include "Ice_Spike.h"

Alaska::Entidades::Obstaculos::Ice_Spike::Ice_Spike() : danosidade(0), Obstaculo() {}

Alaska::Entidades::Obstaculos::Ice_Spike::Ice_Spike(float x, float y, bool d, short int dano)
    : Obstaculo(x, y), danosidade(dano)
{
    pFig = new sf::Texture();
    sf::Image img;
    img.create(30, 50, sf::Color::Cyan);
    pFig->loadFromImage(img);
    sprite.setTexture(*pFig);
    sprite.setPosition(x, y);
    danoso = d;
}

Alaska::Entidades::Obstaculos::Ice_Spike::~Ice_Spike(){}

void Alaska::Entidades::Obstaculos::Ice_Spike::executar(){}

void Alaska::Entidades::Obstaculos::Ice_Spike::obstaculizar(Alaska::Entidades::Personagens::Jogador* pJogador){}