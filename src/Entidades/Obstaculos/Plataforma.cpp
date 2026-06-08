#include "Plataforma.h"
#include "Inimigo.h"

Alaska::Entidades::Obstaculos::Plataforma::Plataforma(float x, float y) : Obstaculo(x, y), largura()
{
    pFig = new sf::Texture();
    pFig->loadFromFile("imgs/Plataforma.png");
    sprite.setTexture(*pFig);
    ajustarSprite(sprite, A_PLAT, L_PLAT);
    sprite.setPosition(x, y);
}

Alaska::Entidades::Obstaculos::Plataforma::Plataforma()
{
}

Alaska::Entidades::Obstaculos::Plataforma::~Plataforma() {}

void Alaska::Entidades::Obstaculos::Plataforma::executar() 
{
    desenhar();
}

void Alaska::Entidades::Obstaculos::Plataforma::obstaculizar(Alaska::Entidades::Personagens::Jogador* pJ) 
{
    sf::FloatRect caixaJog = pJ->getSprite()->getGlobalBounds();
    sf::FloatRect caixaPlat = sprite.getGlobalBounds();
    
    if (pJ->getVelY() > 0 && caixaJog.top < caixaPlat.top)
    {
        pJ->setY(caixaPlat.top - caixaJog.height);
        pJ->setVelY(0.0f);
        pJ->setNoChao(true);
    }
}

void Alaska::Entidades::Obstaculos::Plataforma::obstaculizarInimigo(Alaska::Entidades::Personagens::Inimigo* pI)
{
	sf::FloatRect caixaIni = pI->getSprite()->getGlobalBounds();
    sf::FloatRect caixaPlat = sprite.getGlobalBounds();

    if (pI->getVelY() > 0 && caixaIni.top < caixaPlat.top)
    {
        pI->setY(caixaPlat.top - caixaIni.height);
        pI->setVelY(0.0f);
        pI->setNoChao(true);
    }
}
    //sf::FloatRect inter;

    //if (caixaJog.intersects(caixaPlat, inter))
    //{
    //    if (inter.width > inter.height)
    //    {
    //        if (pJ->getVelY() > 0 && caixaJog.top < caixaPlat.top)
    //        {
    //            pJ->setY(caixaPlat.top - caixaJog.height);
    //            pJ->setVelY(0.0f);
    //            pJ->setNoChao(true);
    //        }
    //        else if (pJ->getVelY() < 0 && caixaJog.top > caixaPlat.top)
    //        {
    //            pJ->setY(caixaPlat.top + caixaPlat.height);
    //            pJ->setVelY(0.0f);
    //        }
    //    }
    //    else
    //    {
    //        if (caixaJog.left < caixaPlat.left)
    //            pJ->setX(pJ->getX() - inter.width);
    //        else
    //            pJ->setX(pJ->getX() + inter.width);
    //    }
    //}
//}

void Alaska::Entidades::Obstaculos::Plataforma::salvar()
{
	//implementar
}