#include "Lobo.h"

Alaska::Entidades::Personagens::Lobo::Lobo() : voracidade(), Inimigo() {}

Alaska::Entidades::Personagens::Lobo::Lobo(float xx, float yy, Jogador* pJ) : voracidade(), Inimigo(xx, yy, 1, 2, pJ) 
{
    calcularMaldade();
    velocidade *= nivel_maldade;
    voracidade = velocidade;

    pFig = new sf::Texture();
    pFig->loadFromFile("imgs/Lobo.png");
    sprite.setTexture(*pFig);
    ajustarSprite(sprite, T_LOBO, T_LOBO);
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
    printf("hit lobo\n");
    pJ->operator--();
}

void Alaska::Entidades::Personagens::Lobo::salvar() 
{
    //implementar
}