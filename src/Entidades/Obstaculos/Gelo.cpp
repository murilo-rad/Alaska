#include "Gelo.h"

Alaska::Entidades::Obstaculos::Gelo::Gelo(float x, float y) : Obstaculo(x, y), atrito(0.1f)
{
    pFig = new sf::Texture();
    pFig->loadFromFile("imgs/Gelo.png");
    sprite.setTexture(*pFig);
    ajustarSprite(sprite, A_GELO, L_GELO);
    sprite.setPosition(x, y);
}

Alaska::Entidades::Obstaculos::Gelo::~Gelo()
{
}

void Alaska::Entidades::Obstaculos::Gelo::executar()
{
    desenhar();
}

void Alaska::Entidades::Obstaculos::Gelo::obstaculizar(Alaska::Entidades::Personagens::Jogador *pJ)
{

    sf::FloatRect caixaJogador = pJ->getSprite()->getGlobalBounds();
    sf::FloatRect caixaGelo = sprite.getGlobalBounds();

    sf::FloatRect inter;
    if (caixaJogador.intersects(caixaGelo, inter))
    {
        if (inter.width > inter.height)
        {
            if (caixaJogador.top < caixaGelo.top)
            {
                pJ->setY(caixaGelo.top - caixaJogador.height);
                pJ->setVelY(0.0f);
                if (pJ->getVelX() > 0)
                    pJ->setVelX(pJ->getVelX() + atrito);
                else if (pJ->getVelX() < 0)
                    pJ->setVelX(pJ->getVelX() - atrito);
                pJ->setNoChao(false);
            }
            else if (pJ->getVelY() < 0 && caixaJogador.top > caixaGelo.top)
            {
                pJ->setY(caixaGelo.top + caixaGelo.height);
                pJ->setVelY(0.0f);
            }
        }
        else
        {
            if (caixaJogador.left < caixaGelo.left)
                pJ->setX(pJ->getX() - inter.width);
            else
                pJ->setX(pJ->getX() + inter.width);
        }
    }
}

void Alaska::Entidades::Obstaculos::Gelo::obstaculizarInimigo(Alaska::Entidades::Personagens::Inimigo *pI)
{
    sf::FloatRect caixaInimigo = pI->getSprite()->getGlobalBounds();
    sf::FloatRect caixaGelo = sprite.getGlobalBounds();

    sf::FloatRect inter;
    if (caixaInimigo.intersects(caixaGelo, inter))
    {
        if (inter.width > inter.height)
        {
            if (caixaInimigo.top < caixaGelo.top)
            {
                pI->setY(caixaGelo.top - caixaInimigo.height);
                pI->setVelY(0.0f);
                if (pI->getVelX() > 0)
                    pI->setVelX(pI->getVelX() + atrito);
                else if (pI->getVelX() < 0)
                    pI->setVelX(pI->getVelX() - atrito);
                pI->setNoChao(false);
            }
            else if (pI->getVelY() < 0 && caixaInimigo.top > caixaGelo.top)
            {
                pI->setY(caixaGelo.top + caixaGelo.height);
                pI->setVelY(0.0f);
            }
        }
        else
        {
            if (caixaInimigo.left < caixaGelo.left)
            {
                pI->setX(pI->getX() - inter.width);
            }
            else
                pI->setX(pI->getX() + inter.width);
        }
    }
}

void Alaska::Entidades::Obstaculos::Gelo::salvar()
{
}
