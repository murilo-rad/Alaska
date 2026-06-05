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

    if (pJogador->getY() < y - 110.0f && noChao)
    {
        velY = -11.0f;
        setNoChao(false);
    }
    x += velX;
}


 Alaska::Entidades::Personagens::Inimigo::Inimigo(
    float x, float y, int mal, int v, Jogador* pJ)
    : Personagem(x, y, v)
    , nivel_maldade()
    , pJogador(pJ)
    , velocidade(2.0f)
{
    velX = 0.0f;
    velY = 0.0f;
    pFig = new sf::Texture();

    
    std::cerr << "Erro ao carregar a textura do Inimigo!" << std::endl;
    sf::Image img;
    img.create(50, 50, sf::Color::Red);
    pFig->loadFromImage(img);
    

    sprite.setTexture(*pFig);
    sprite.setPosition(this->x, this->y);
}

void Alaska::Entidades::Personagens::Inimigo::calcularMaldade()
{
    float aux = 1.0f + (rand() % 51) / 100.0f;
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

void Alaska::Entidades::Personagens::Inimigo::recuar()
{
    setVelX(20.0f);
}
