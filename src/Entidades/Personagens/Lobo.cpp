#include "Lobo.h"

Alaska::Entidades::Personagens::Lobo::Lobo() : voracidade(), Inimigo() {}

Alaska::Entidades::Personagens::Lobo::Lobo(float x, float y, Jogador* pJ) : voracidade(), Inimigo(x, y, 1, 1, pJ) 
{
    calcularMaldade();
    pFig = new sf::Texture();
    pFig->loadFromFile("imgs/Nevoso.png");
    sprite.setTexture(*pFig);
    sprite.setPosition(x, y);
}

Alaska::Entidades::Personagens::Lobo::~Lobo() {}

void Alaska::Entidades::Personagens::Lobo::executar()
{
    mover();
    desenhar();
}

void Alaska::Entidades::Personagens::Lobo::mover()
{
    seguirJogador();
    aplicarGravidade();
    sprite.setPosition(x, y);
}

void Alaska::Entidades::Personagens::Lobo::danificar(Alaska::Entidades::Personagens::Jogador* pJ)
{
    pJ->operator--();
}

void Alaska::Entidades::Personagens::Lobo::salvar() 
{
    //implementar
}