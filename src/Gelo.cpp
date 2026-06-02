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
    pJ->setNoChao(false); 
    
    if(pJ->getVelX() > 0) 
        pJ->setVelX(pJ->getVelX() + 0.1f);
    else if(pJ->getVelX() < 0) 
        pJ->setVelX(pJ->getVelX() - 0.1f);
}