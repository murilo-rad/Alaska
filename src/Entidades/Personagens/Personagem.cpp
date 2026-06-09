#include "Personagem.h"

Alaska::Entidades::Personagens::Personagem::Personagem
(float x, float y, float vX, float vY, short nv) :
Entidade(x, y, vX, vY), num_vidas(nv), noChao(false), vivo(true) {}

Alaska::Entidades::Personagens::Personagem::Personagem() : Entidade(), num_vidas(1), noChao(false), vivo(true){}

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

void Alaska::Entidades::Personagens::Personagem::salvarDataBuffer()
{
    //implementar
}

const bool Alaska::Entidades::Personagens::Personagem::estaVivo()const
{
    return vivo;
}