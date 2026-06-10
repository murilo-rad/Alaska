#include "Obstaculo.h"

Alaska::Entidades::Obstaculos::Obstaculo::Obstaculo(float x, float y, bool dn) : 
													Entidade(x, y, 0, 0), danoso(dn){}

Alaska::Entidades::Obstaculos::Obstaculo::Obstaculo() : Entidade(), danoso(false){}

Alaska::Entidades::Obstaculos::Obstaculo::~Obstaculo(){}

void Alaska::Entidades::Obstaculos::Obstaculo::salvarDataBuffer() 
{
	//implementar
}

void Alaska::Entidades::Obstaculos::Obstaculo::antiGravitar() 
{
	velY -= GRAVIDADE;
	if (velY < -15.0f) 
        velY = -15.0f;
    y -= velY;
}
