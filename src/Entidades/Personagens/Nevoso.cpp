#include "Nevoso.h"


Alaska::Entidades::Personagens::Nevoso::Nevoso
(float xx, float yy, Alaska::Entidades::Personagens::Jogador* pJ) : 
Inimigo(xx, yy, 1, 1, pJ), acumulacao()
{
    calcularMaldade();
    acumulacao = (float)(T_NEVOSO * nivel_maldade);
    pFig = new sf::Texture();
    pFig->loadFromFile("imgs/Nevoso.png");
    sprite.setTexture(*pFig);
    sprite.setColor(sf::Color::White);
    ajustarSprite(sprite, acumulacao, acumulacao);
    sprite.setPosition(x, y);
}

Alaska::Entidades::Personagens::Nevoso::Nevoso(){}

Alaska::Entidades::Personagens::Nevoso::~Nevoso(){}

void Alaska::Entidades::Personagens::Nevoso::executar()
{
    mover();
    desenhar();
}

void Alaska::Entidades::Personagens::Nevoso::salvar()
{
  
}

void Alaska::Entidades::Personagens::Nevoso::mover()
{
    seguirJogador();
    aplicarGravidade();
    sprite.setPosition(x, y);
}

void Alaska::Entidades::Personagens::Nevoso::danificar(Alaska::Entidades::Personagens::Jogador* pJ)
{
    pJ->operator--();
}
