#include "Entidade.h"

Alaska::Entidades::Entidade::Entidade(float xx, float yy): Ente(), x(xx), y(yy){}

Alaska::Entidades::Entidade::~Entidade(){}

const float Alaska::Entidades::Entidade::getX()
{
    return x;
}

const float Alaska::Entidades::Entidade::getY()
{
    return y;
}

void Alaska::Entidades::Entidade::setX(const float xx)
{
    x = xx;
}

void Alaska::Entidades::Entidade::setY(const float yy)
{
    y = yy;
}