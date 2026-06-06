#include "Nevoso.h"


Alaska::Entidades::Personagens::Nevoso::Nevoso
(float vx, float vy, int v, int mal, Alaska::Entidades::Personagens::Jogador* pJ, float vel) : 
Inimigo(vx, vy, mal, v, pJ), acumulacao()
{
    calcularMaldade();
    acumulacao = (T_NEVOSO * nivel_maldade);
    pFig = new sf::Texture();
    pFig->loadFromFile("imgs/Nevoso.png");
    sprite.setTexture(*pFig);
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
