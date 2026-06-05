#include "Lobo.h"

Alaska::Entidades::Personagens::Lobo::Lobo() : raio(0), Inimigo() {}

Alaska::Entidades::Personagens::Lobo::Lobo(float x, float y, Jogador* pJ) : raio(x), Inimigo(x, y, 1, 1, pJ) 
{
    pFig = new sf::Texture();
    sf::Image img;
    img.create(50, 50, sf::Color::Red);
    pFig->loadFromImage(img);
    sprite.setTexture(*pFig);
    sprite.setPosition(x, y);

    velX = 0.0f;
    velY = 0.0f;
}

Alaska::Entidades::Personagens::Lobo::~Lobo() {}

void Alaska::Entidades::Personagens::Lobo::executar()
{
    seguirJogador();
    aplicarGravidade();
    sprite.setPosition(x, y);
}

void Alaska::Entidades::Personagens::Lobo::mover()
{

}

void Alaska::Entidades::Personagens::Lobo::danificar()
{

}

void Alaska::Entidades::Personagens::Lobo::salvar() {
    //implementar
}