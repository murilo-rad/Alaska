#include "Conjunto_Estalagmites.h"

Alaska::Entidades::Obstaculos::Conjunto_Estalagmites::Conjunto_Estalagmites() : danosidade(0), Obstaculo() {}

Alaska::Entidades::Obstaculos::Conjunto_Estalagmites::Conjunto_Estalagmites(float x, float y)
    : Obstaculo(x, y, true), danosidade(1)
{
   pFig = new sf::Texture();
   pFig->loadFromFile("imgs/Estalagmites.png");
   sprite.setTexture(*pFig);
   ajustarSprite(sprite, A_MITE, L_MITE);
   sprite.setPosition(x, y);
}

Alaska::Entidades::Obstaculos::Conjunto_Estalagmites::~Conjunto_Estalagmites() {}

void Alaska::Entidades::Obstaculos::Conjunto_Estalagmites::executar()
{
   gravitar();
   antiGravitar();
   desenhar();
}

void Alaska::Entidades::Obstaculos::Conjunto_Estalagmites::obstaculizar(Alaska::Entidades::Personagens::Jogador *pJ)
{
   sf::FloatRect caixaJogador = pJ->getSprite()->getGlobalBounds();
   sf::FloatRect caixaEstalagmites = sprite.getGlobalBounds();
   sf::FloatRect inter;

   if (caixaJogador.intersects(caixaEstalagmites, inter))
   {
      if (inter.width > inter.height)
      {
         if (caixaJogador.top < caixaEstalagmites.top)
         {
			 printf("hit estalagmites\n");
             
            pJ->setY(caixaEstalagmites.top - caixaJogador.height);
            pJ->setVelY(0.0f);
            pJ->setVelY(-11.0f);
            pJ->operator--();
            pJ->setNoChao(false);
         }
         else if (pJ->getVelY() < 0 && caixaJogador.top > caixaEstalagmites.top)
         {
            pJ->setY(caixaEstalagmites.top + caixaEstalagmites.height);
            pJ->setVelY(0.0f);
         }
      }
      else
      {
         if (caixaJogador.left < caixaEstalagmites.left)
            pJ->setX(pJ->getX() - inter.width);
         else
            pJ->setX(pJ->getX() + inter.width);
      }
   }
}

void Alaska::Entidades::Obstaculos::Conjunto_Estalagmites::obstaculizarInimigo(Alaska::Entidades::Personagens::Inimigo *pI)
{
   sf::FloatRect caixaInimigo = pI->getSprite()->getGlobalBounds();
   sf::FloatRect caixaEstalagmites = sprite.getGlobalBounds();
   sf::FloatRect inter;

   if (caixaInimigo.intersects(caixaEstalagmites, inter))
   {
      if (inter.width > inter.height)
      {
         if (caixaInimigo.top < caixaEstalagmites.top)
         {
            pI->setY(caixaEstalagmites.top - caixaInimigo.height);
            pI->setVelY(0.0f);
            pI->setNoChao(true);
         }
         else if (pI->getVelY() < 0 && caixaInimigo.top > caixaEstalagmites.top)
         {
            pI->setY(caixaEstalagmites.top + caixaEstalagmites.height);
            pI->setVelY(0.0f);
         }
      }
      else
      {
         if (caixaInimigo.left < caixaEstalagmites.left)
            pI->setX(pI->getX() - inter.width);
         else
            pI->setX(pI->getX() + inter.width);
      }
   }
}

void Alaska::Entidades::Obstaculos::Conjunto_Estalagmites::salvar()
{
   
}