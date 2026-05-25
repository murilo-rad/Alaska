#include "Personagem.h"

Alaska::Entidades::Personagens::Personagem::Personagem(float x, float y, int v): Entidade(x, y), vidas(v), noChao(false){}

Alaska::Entidades::Personagens::Personagem::~Personagem(){}

void Alaska::Entidades::Personagens::Personagem::setVida(const int v)
{
    vidas = v;
}

const int Alaska::Entidades::Personagens::Personagem::getVidas()const
{
    return vidas;
}

void Alaska::Entidades::Personagens::Personagem::setNoChao(bool c) 
{
    noChao = c;
}

const bool Alaska::Entidades::Personagens::Personagem::getNoChao()const 
{
    return noChao;
}