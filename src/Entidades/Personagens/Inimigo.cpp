#include "Inimigo.h"

Alaska::Entidades::Personagens::Inimigo::Inimigo(float x, float y, short nv, Jogador* pJ) 
: Personagem(x, y, 0.0f, 0.0f, nv), nivel_maldade(calcularMaldade()), pJogador(nullptr), velocidade(1.0f)
{
    if(pJ)
      pJogador = pJ;
}

Alaska::Entidades::Personagens::Inimigo::Inimigo() : Personagem(), nivel_maldade(1), pJogador(nullptr), velocidade(1.0f) {}

Alaska::Entidades::Personagens::Inimigo::~Inimigo(){}

void Alaska::Entidades::Personagens::Inimigo::seguirJogador()
{
    if (!pJogador)
        return;

    sf::Vector2f direcao(pJogador->getX() - x, pJogador->getY() - y);

    sf::Vector2f dir = normalizarVetor(direcao);
    velX = dir.x * velocidade;

    if (pJogador->getY() < y - 80.0f && noChao)
    {
        velY = -12.0f;
        setNoChao(false);
    }
    x += velX;
}

float Alaska::Entidades::Personagens::Inimigo::calcularMaldade()
{   
    float aux = ((rand() % 100) / 100.0f) + 1.0f;
    return aux;
}


int Alaska::Entidades::Personagens::Inimigo::getMaldade()
{
    return nivel_maldade;
}

sf::Vector2f Alaska::Entidades::Personagens::Inimigo::normalizarVetor(sf::Vector2f v)
{
    double tamVetorV = std::sqrt(std::pow(v.x, 2) + std::pow(v.y, 2));

    sf::Vector2f vetorNormalizado(v.x/tamVetorV, v.y/tamVetorV);

    return vetorNormalizado;
}

void Alaska::Entidades::Personagens::Inimigo::salvarDataBuffer()
{
    //implementar
}

// void Alaska::Entidades::Personagens::Inimigo::recuar()
// {
//     setVelX(100.0f);
// }
