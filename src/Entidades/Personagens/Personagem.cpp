#include "Personagem.h"

Alaska::Entidades::Personagens::Personagem::Personagem
(float x, float y, int v) :
Entidade(x, y), velX(0), velY(0), num_vidas(v), noChao(false), vivo(true){}

Alaska::Entidades::Personagens::Personagem::Personagem(){}

Alaska::Entidades::Personagens::Personagem::~Personagem(){}

void Alaska::Entidades::Personagens::Personagem::setMorto()
{
    vivo = false;
}

const int Alaska::Entidades::Personagens::Personagem::getVidas()const
{
    return num_vidas;
}

void Alaska::Entidades::Personagens::Personagem::setNoChao(bool c) 
{
    noChao = c;
}

const bool Alaska::Entidades::Personagens::Personagem::getNoChao()const 
{
    return noChao;
}

void Alaska::Entidades::Personagens::Personagem::operator--()
{
    if(vivo)
        num_vidas--;
}

void Alaska::Entidades::Personagens::Personagem::setVelY(const float velYy)
{
    velY = velYy;
}

void Alaska::Entidades::Personagens::Personagem::setVelX(const float velXx)
{
    velX = velXx;
	x += velX;
}

const float Alaska::Entidades::Personagens::Personagem::getVelX()const
{
    return velX;
}

const float Alaska::Entidades::Personagens::Personagem::getVelY()const
{
    return velY;
}

void Alaska::Entidades::Personagens::Personagem::aplicarGravidade()
{
    velY += GRAVIDADE;

    if (velY > 15.0f) 
        velY = 15.0f;
        
    y += velY;
}

void Alaska::Entidades::Personagens::Personagem::salvarDataBuffer()
{
    //implementar
}

const bool Alaska::Entidades::Personagens::Personagem::estaVivo()const
{
    return vivo;
}