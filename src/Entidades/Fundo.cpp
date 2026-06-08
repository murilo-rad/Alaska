#include "Fundo.h"

Alaska::Entidades::Fundo::Fundo() : Entidade(0.0f, 0.0f)
{
    pFig = new sf::Texture();
    pFig->loadFromFile("imgs/Tundra.png");
    sprite.setTexture(*pFig);
    ajustarSprite(sprite, A_FUNDO, L_FUNDO);
    sprite.setPosition(x, y);
}

Alaska::Entidades::Fundo::~Fundo(){}

void Alaska::Entidades::Fundo::executar()
{
    desenhar();
}

void Alaska::Entidades::Fundo::salvar()
{

}

