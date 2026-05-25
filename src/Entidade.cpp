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

void Alaska::Entidades::Entidade::setVelY(const float velYy)
{
    velY = velYy;
}

void Alaska::Entidades::Entidade::aplicarGravidade()
{
    velY += GRAVIDADE;

    if (velY > 15.0f) 
        velY = 15.0f;
        
    y += velY;
}