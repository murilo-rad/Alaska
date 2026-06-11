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
    gravitar();
    desenhar();
}

void Alaska::Entidades::Personagens::Lobo::mover()
{
    seguirJogador();
    sprite.setPosition(x, y);
}

void Alaska::Entidades::Personagens::Lobo::danificar(Alaska::Entidades::Personagens::Jogador* pJ)
{
    printf("hit lobo\n");
    pJ->operator--(voracidade);
    if(pJ->getVidas() == 0)
        pJ->setMorto();
    operator++(voracidade);
    pJ->setX(10.0f);
    pJ->setY(A_MAX_GERAL);
}

int Alaska::Entidades::Personagens::Lobo::calcularVoracidade()
{
    voracidade = velocidade * nivel_maldade;
    velocidade = voracidade;
    return voracidade;
}

void Alaska::Entidades::Personagens::Lobo::salvar() 
{
    //implementar
}