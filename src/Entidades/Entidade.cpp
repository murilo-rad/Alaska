#include "Entidade.h"

Alaska::Entidades::Entidade::Entidade(float x, float y, float vX, float vY): Ente(), x(x), y(y), velX(vX), velY(vY), buffer(NULL) {}
Alaska::Entidades::Entidade::Entidade() : Ente(), x(0), y(0), buffer(NULL) {}

Alaska::Entidades::Entidade::~Entidade(){}

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

void Alaska::Entidades::Entidade::setVelY(const float velYy)
{
    velY = velYy;
}

void Alaska::Entidades::Entidade::setVelX(const float velXx)
{
    velX = velXx;
    x+= velX;
}

const float Alaska::Entidades::Entidade::getVelX()const
{
    return velX;
}

const float Alaska::Entidades::Entidade::getVelY()const
{
    return velY;
}

void Alaska::Entidades::Entidade::gravitar()
{
    velY += GRAVIDADE;

    if (velY > 15.0f) 
        velY = 15.0f;
        
    y += velY;
    sprite.setPosition(x, y);
}