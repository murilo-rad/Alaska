#include "Entidade.h"

Alaska::Entidades::Entidade::Entidade(float x, float y, float vX, float vY): Ente(), x(x), y(y), velX(vX), velY(vY) {}
Alaska::Entidades::Entidade::Entidade() : Ente(), x(0), y(0), velX(0), velY(0) {}

Alaska::Entidades::Entidade::~Entidade(){}

void Alaska::Entidades::Entidade::salvarDataBuffer()
{
    Entidade::coletarDados();
    std::ofstream arquivo("../save/arquivo_de_salvamento.txt", std::ios::app);

    if (arquivo.is_open())
    {
        arquivo << buffer.str() << "\n";
        arquivo.close();
    }
    else
    {
        printf("Erro: Nao foi possivel abrir o arquivo.\n");
    }

    buffer.str("");
    buffer.clear();
}


void Alaska::Entidades::Entidade::coletarDados() 
{
    buffer << x << "," << y << "," << velX << "," << velY;
}

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

void Alaska::Entidades::Entidade::gravitar()
{
    velY += GRAVIDADE;

    if (velY > 15.0f) 
        velY = 15.0f;
        
    y += velY;
    sprite.setPosition(x, y);
}

