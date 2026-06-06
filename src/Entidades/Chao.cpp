#include "Chao.h"

Alaska::Entidades::Chao::Chao(sf::Texture &chao)
{

}

Alaska::Entidades::Chao::~Chao(){}

void Alaska::Entidades::Chao::executar()
{
}

void Alaska::Entidades::Chao::empurrar(Alaska::Entidades::Personagens::Personagem* pP)
{
    sf::FloatRect caixaEnti = pP->getSprite()->getGlobalBounds();
    sf::FloatRect caixaChao = sprite.getGlobalBounds();

    sf::FloatRect inter;
    if (caixaEnti.intersects(caixaChao))
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

void Alaska::Entidades::Chao::salvar()
{
    
}