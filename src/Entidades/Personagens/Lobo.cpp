#include "Lobo.h"

Alaska::Entidades::Personagens::Lobo::Lobo(float x, float y, Jogador* pJ) : Inimigo(x, y, 2, pJ), voracidade(calcularVoracidade())
{
    pFig = new sf::Texture();
    pFig->loadFromFile("imgs/Lobo.png");
    sprite.setTexture(*pFig);
    ajustarSprite(sprite, T_LOBO, T_LOBO);
}

Alaska::Entidades::Personagens::Lobo::Lobo() : Inimigo(0, 0, 2, nullptr), voracidade(0) 
{
    pFig = new sf::Texture();
    pFig->loadFromFile("imgs/Lobo.png");
    sprite.setTexture(*pFig);
    ajustarSprite(sprite, T_LOBO, T_LOBO);  
}

Alaska::Entidades::Personagens::Lobo::~Lobo() 
{
    if(pJogador)
    {
        pJogador->addPontos(3);
        pJogador = nullptr;
    }
}

void Alaska::Entidades::Personagens::Lobo::executar()
{
    mover();
    gravitar();
    desenhar();
    verificarSaude();
}

void Alaska::Entidades::Personagens::Lobo::salvar() 
{
    coletarDados();
    Inimigo::salvarDataBuffer();
}

void Alaska::Entidades::Personagens::Lobo::coletarDados()
{
    buffer << IND_LOBO << "," << voracidade << "," << id << ",";
}

void Alaska::Entidades::Personagens::Lobo::setVoracidade(int v)
{
    voracidade = v;
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

    operator++(voracidade);

    float xJog = pJ->getSprite()->getPosition().x;
    float xLobo = sprite.getPosition().x;

    if(xJog < xLobo)
        pJ->setX(xJog - 40.f);
    else
        pJ->setX(xJog + 40.f);
}

int Alaska::Entidades::Personagens::Lobo::calcularVoracidade()
{
    voracidade = velocidade * nivel_maldade;
    velocidade = voracidade;
    return voracidade;
}