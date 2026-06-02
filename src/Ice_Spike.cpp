#include "Ice_Spike.h"

Alaska::Entidades::Obstaculos::Ice_Spike::Ice_Spike(bool d, short int dano): Obstaculo(400.0f, 450.0f), danosidade(dano) 
{   
    sf::Image img;
    img.create(30, 50, sf::Color::Cyan);
    textura.loadFromImage(img);
    sprite.setTexture(textura);
    sprite.setPosition(x, y);
    danoso = d;
}

Alaska::Entidades::Obstaculos::Ice_Spike::~Ice_Spike(){}

void Alaska::Entidades::Obstaculos::Ice_Spike::executar(){}

void Alaska::Entidades::Obstaculos::Ice_Spike::obstaculizar(Alaska::Entidades::Personagens::Jogador* pJogador){}