 #include "Conjunto_Estalagmites.h"

 Alaska::Entidades::Obstaculos::Conjunto_Estalagmites::Conjunto_Estalagmites() : danosidade(0), Obstaculo() {}

 Alaska::Entidades::Obstaculos::Conjunto_Estalagmites::Conjunto_Estalagmites(float x, float y, bool d, short int dano)
     : Obstaculo(x, y, true), danosidade(dano)
 {
     pFig = new sf::Texture();

     sprite.setPosition(x, y);
     danoso = d;
 }

 Alaska::Entidades::Obstaculos::Conjunto_Estalagmites::~Conjunto_Estalagmites() {}

 void Alaska::Entidades::Obstaculos::Conjunto_Estalagmites::executar() {}

 void Alaska::Entidades::Obstaculos::Conjunto_Estalagmites::obstaculizar(Alaska::Entidades::Personagens::Jogador *pJogador) {}