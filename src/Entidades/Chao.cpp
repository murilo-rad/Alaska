#include "Chao.h"

Alaska::Entidades::Chao::Chao(short f) : Entidade(0, A_MAX_GERAL+1, 0, 0), fase(f)
{
    pFig = new sf::Texture();
    if (fase == 1) {
        pFig->loadFromFile("imgs/ChaoTundra.png");
    }
    else if (fase == 2) {
        pFig->loadFromFile("imgs/ChaoTundra.png");
    }
    sprite.setTexture(*pFig);
    ajustarSprite(sprite, A_CHAO, L_CHAO);
    sprite.setPosition(x, y);
}

Alaska::Entidades::Chao::Chao() : Entidade(0, 0, 0, 0), fase(0) 
{
    pFig = new sf::Texture();
    if (fase == 1) {
        pFig->loadFromFile("imgs/ChaoTundra.png");
    }
    else if (fase == 2) {
        pFig->loadFromFile("imgs/ChaoTundra.png");
    }
    sprite.setTexture(*pFig);
    ajustarSprite(sprite, A_CHAO, L_CHAO);
    sprite.setPosition(x, y);
}

Alaska::Entidades::Chao::~Chao() {}

void Alaska::Entidades::Chao::executar()
{
    desenhar();
}

void Alaska::Entidades::Chao::salvar()
{
    buffer.str("");
    buffer.clear();

    Chao::coletarDados();
    Entidade::salvarDataBuffer();
}


void Alaska::Entidades::Chao::coletarDados()
{
    buffer << IND_CHAO << "," << fase << "," << id << ",";
}


void Alaska::Entidades::Chao::setFase(short f)
{
    fase = f;
}

const short Alaska::Entidades::Chao::getFase()const
{
    return fase;
}

void Alaska::Entidades::Chao::empurrar(Alaska::Entidades::Personagens::Personagem *pP)
{
    sf::FloatRect caixaEnti = pP->getSprite()->getGlobalBounds();
    sf::FloatRect caixaChao = sprite.getGlobalBounds();

    sf::FloatRect inter;
    if (caixaEnti.intersects(caixaChao, inter))
    {
        if (inter.width > inter.height)
        {
            if (pP->getVelY() > 0 && caixaEnti.top < caixaChao.top)
            {
                pP->setY(caixaChao.top - caixaEnti.height);
                pP->setVelY(0.0f);
                pP->setNoChao(true);
            }
            else if (pP->getVelY() < 0 && caixaEnti.top > caixaChao.top)
            {
                pP->setY(caixaChao.top + caixaChao.height);
                pP->setVelY(0.0f);
            }
        }
        else
        {
            if (caixaEnti.left < caixaChao.left)
                pP->setX(pP->getX() - inter.width);
            else
                pP->setX(pP->getX() + inter.width);
        }
    }
}

