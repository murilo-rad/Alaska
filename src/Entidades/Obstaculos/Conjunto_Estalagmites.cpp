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

 Alaska::Entidades::Obstaculos::Conjunto_Estalagmites::~Conjunto_Estalagmites()
 {

 }

 void Alaska::Entidades::Obstaculos::Conjunto_Estalagmites::executar()
{

}

 void Alaska::Entidades::Obstaculos::Conjunto_Estalagmites::obstaculizar(Alaska::Entidades::Personagens::Jogador *pJogador) {}