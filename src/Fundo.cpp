#include "Fundo.h"

Alaska::Fundo::Fundo(float altr, float largr, short f) : Ente(), altura(altr), largura(largr), fase(f)
{
    if (fase == 1)
    {
        pFig = new sf::Texture();
        pFig->loadFromFile("imgs/Tundra.png");
        sprite.setTexture(*pFig);
        ajustarSprite(sprite, altura, largura);
        sprite.setPosition(0, 0);
    }
}

Alaska::Fundo::Fundo() : Ente(), altura(A_FUNDO), largura(L_FUNDO) {}

Alaska::Fundo::~Fundo(){}

void Alaska::Fundo::executar()
{
    desenhar();
}


