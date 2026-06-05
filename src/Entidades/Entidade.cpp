#include "Entidade.h"
#include <cmath>

Alaska::Entidades::Entidade::Entidade(float xx, float yy): Ente(), x(xx), y(yy), buffer(NULL) {}
Alaska::Entidades::Entidade::Entidade() : Ente(), x(0), y(0), buffer(NULL) {}

//Alaska::Entidades::Entidade::~Entidade(){}

const float Alaska::Entidades::Entidade::getX()const
{
    return x;
}

const float Alaska::Entidades::Entidade::getY()const
{
    return y;
}

void Alaska::Entidades::Entidade::setX(const float xx)
{
    x = xx;
    sprite.setPosition(x, y);
}

void Alaska::Entidades::Entidade::setY(const float yy)
{
    y = yy;
    sprite.setPosition(x, y);
}

void Alaska::Entidades::Entidade::salvarDataBuffer()
{
    //implementar
}
