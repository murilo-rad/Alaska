#include "Entidade.h"
#include <cmath>

Alaska::Entidades::Entidade::Entidade(float xx, float yy): Ente(), x(xx), y(yy), velX(0.0f), velY(0.0f){}

Alaska::Entidades::Entidade::~Entidade(){}

const float Alaska::Entidades::Entidade::getX()
{
    return x;
}

const float Alaska::Entidades::Entidade::getY()
{
    return y;
}

float Alaska::Entidades::Entidade::length(sf::Vector2f v)
{
    return std::sqrt(v.x * v.x + v.y * v.y);
}

sf::Vector2f Alaska::Entidades::Entidade::normalize(sf::Vector2f v)
{
    float len = length(v);

    if (len != 0.f)
        return v / len;

    return sf::Vector2f(0.f, 0.f);
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

void Alaska::Entidades::Entidade::setVelY(const float velYy)
{
    velY = velYy;
}

void Alaska::Entidades::Entidade::setVelX(const float velXx)
{
    velX = velXx;
}

const float Alaska::Entidades::Entidade::getVelX()const
{
    return velX;
}

const float Alaska::Entidades::Entidade::getVelY()const
{
    return velY;
}

void Alaska::Entidades::Entidade::aplicarGravidade()
{
    velY += GRAVIDADE;

    if (velY > 15.0f) 
        velY = 15.0f;
        
    y += velY;
}
