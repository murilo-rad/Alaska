#include "Inimigo.h"


Alaska::Entidades::Personagens::Inimigo::Inimigo(
    float x, float y, int mal, int v, Jogador* pJ)
    : Personagem(x, y, v)
    , nivel_maldade(mal)
    , pJogador(pJ)
    , velocidade(2.0f)
{
    velX = 0.0f;
    velY = 0.0f;

    if (!textura.loadFromFile("assets/im/JogadorAlaska.png"))
    {
        std::cerr << "Erro ao carregar a textura do Inimigo!" << std::endl;
        sf::Image img;
        img.create(50, 50, sf::Color::Red);
        textura.loadFromImage(img);
    }

    sprite.setTexture(textura);
    sprite.setPosition(this->x, this->y);
}

Alaska::Entidades::Personagens::Inimigo::~Inimigo() {}

int Alaska::Entidades::Personagens::Inimigo::getMaldade()
{
    return nivel_maldade;
}

void Alaska::Entidades::Personagens::Inimigo::seguirJogador()
{
    if (!pJogador)
        return;

    sf::Vector2f direcao(pJogador->getX() - x, pJogador->getY() - y);

    sf::Vector2f dir = normalize(direcao);
    velX = dir.x * velocidade;

    if (pJogador->getY() < y - 110.0f && noChao)
    {
        velY = -11.0f;
        setNoChao(false);
    }

    x += velX;
}



