#include "Personagem.h"

Alaska::Entidades::Personagens::Personagem::Personagem(float x, float y, int v): Entidade(x, y), vidas(v){}

Alaska::Entidades::Personagens::Personagem::~Personagem(){}

void Alaska::Entidades::Personagens::Personagem::setVida(const int v)
{
    vidas = v;
}

const int Alaska::Entidades::Personagens::Personagem::getVidas()const
{
    return vidas;
}