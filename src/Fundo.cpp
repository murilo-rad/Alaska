#include "Fundo.h"

Alaska::Fundo::Fundo(float altr, float largr, short f) : Ente(), altura(altr), largura(largr), fase(f)
{
    pFig = new sf::Texture();
    if (fase == 1)
    {
        pFig->loadFromFile("imgs/Tundra.png");
    }
    else if (fase == 2) {
        pFig->loadFromFile("imgs/Caverna.png");
    }
    sprite.setTexture(*pFig);
    ajustarSprite(sprite, altura, largura);
    sprite.setPosition(0, 0);
}

Alaska::Fundo::Fundo() : Ente(), altura(A_FUNDO), largura(L_FUNDO) {}

Alaska::Fundo::~Fundo(){}

void Alaska::Fundo::executar()
{
    desenhar();
}


