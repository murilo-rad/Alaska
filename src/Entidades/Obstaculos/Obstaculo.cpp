#include "Obstaculo.h"

Alaska::Entidades::Obstaculos::Obstaculo::Obstaculo(float x, float y, bool dn) : 
													Entidade(x, y, 0, 0), danoso(dn){}

Alaska::Entidades::Obstaculos::Obstaculo::Obstaculo() : Entidade(), danoso(false){}

Alaska::Entidades::Obstaculos::Obstaculo::~Obstaculo(){}

void Alaska::Entidades::Obstaculos::Obstaculo::salvarDataBuffer() 
{
	coletarDados();
	Entidade::salvarDataBuffer();
}

void Alaska::Entidades::Obstaculos::Obstaculo::coletarDados()
{
	buffer << danoso << "," << id << ",";
}

void Alaska::Entidades::Obstaculos::Obstaculo::setDanoso(bool d)
{
	danoso = d;
}

void Alaska::Entidades::Obstaculos::Obstaculo::antiGravitar() 
{
    y -= velY;
    velY = 0.0f;

	sprite.setPosition(x,y);
}