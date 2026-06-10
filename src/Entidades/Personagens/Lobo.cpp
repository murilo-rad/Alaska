#include "Lobo.h"

Alaska::Entidades::Personagens::Lobo::Lobo() : voracidade(), Inimigo() {}

Alaska::Entidades::Personagens::Lobo::Lobo(float x, float y, Jogador* pJ) : Inimigo(x, y, 2, pJ), voracidade(calcularVoracidade())
{
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
    gravitar();
    sprite.setPosition(x, y);
}

void Alaska::Entidades::Personagens::Lobo::danificar(Alaska::Entidades::Personagens::Jogador* pJ)
{
    printf("hit lobo\n");
    pJ->operator--();
    if(pJ->getVidas() == 0)
        pJ->setMorto();
    pJ->setX(10.0f);
    pJ->setY(500.0f);
}

float Alaska::Entidades::Personagens::Lobo::calcularVoracidade()
{
    float aux = velocidade * nivel_maldade;
    velocidade = aux;
    return aux;
}

void Alaska::Entidades::Personagens::Lobo::salvar() 
{
    //implementar
}