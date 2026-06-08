#include "Inimigo.h"
#include "Jogador.h"

Alaska::Entidades::Personagens::Inimigo::Inimigo() : Personagem(0.0f, 0.0f, 1), nivel_maldade(0), pJogador(nullptr), velocidade(0.0f) {}


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
        velY = -11.0f;
        setNoChao(false);
    }
    x += velX;
}


 Alaska::Entidades::Personagens::Inimigo::Inimigo(
    float xx, float yy, int mal, int v, Jogador* pJ)
    : Personagem(xx, yy, v)
    , nivel_maldade()
    , pJogador(pJ)
    , velocidade(2.0f)
{
    velX = 0.0f;
    velY = 0.0f;
    pFig = new sf::Texture();

    //sf::Image img;
    //img.create(50, 50, sf::Color::Red);
    //pFig->loadFromImage(img);
    //sprite.setTexture(*pFig);

    sprite.setPosition(this->getX(), this->getY());
}

void Alaska::Entidades::Personagens::Inimigo::calcularMaldade()
{   
    float aux = (((rand() % 100)/100.0f)+1.0f);
    nivel_maldade = aux;
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
