#include "Gelo.h"

Alaska::Entidades::Obstaculos::Gelo::Gelo(float x, float y) : Obstaculo(x, y) 
{
    //Configurar
}

Alaska::Entidades::Obstaculos::Gelo::~Gelo()
{
}

void Alaska::Entidades::Obstaculos::Gelo::executar() 
{
}

void Alaska::Entidades::Obstaculos::Gelo::obstaculizar(Alaska::Entidades::Personagens::Jogador* pJ) 
{
    sf::FloatRect caixaJog = pJ->getSprite()->getGlobalBounds();
    sf::FloatRect caixaGelo = sprite.getGlobalBounds();
    sf::FloatRect inter;

    if (caixaJog.intersects(caixaGelo, inter))
    {
        if (inter.width > inter.height && pJ->getVelY() >= 0
            && caixaJog.top < caixaGelo.top)
        {
            pJ->setY(caixaGelo.top - caixaJog.height);
            pJ->setVelY(0.0f);
            pJ->setNoChao(true);

            if (pJ->getVelX() > 0)
                pJ->setVelX(pJ->getVelX() + 0.1f);
            else if (pJ->getVelX() < 0)
                pJ->setVelX(pJ->getVelX() - 0.1f);
        }
    }
}