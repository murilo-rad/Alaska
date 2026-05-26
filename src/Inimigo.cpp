#include "Inimigo.h"
#include "Jogador.h"


Alaska::Entidades::Personagens::Inimigo::Inimigo(
    float x, float y, int mal, int v, Jogador* pJ)
    : Personagem(x, y, v)
    , maldade(mal)
    , pJogador(pJ)
    , velocidade(2.0f)
{
    sf::Image img;
    img.create(50, 50, sf::Color::Red);
    textura.loadFromImage(img);
    sprite.setTexture(textura);
    sprite.setPosition(x, y);
}

Alaska::Entidades::Personagens::Inimigo::~Inimigo() {}

int Alaska::Entidades::Personagens::Inimigo::getMaldade()
{
    return maldade;
}

void Alaska::Entidades::Personagens::Inimigo::seguirJogador()
{
    if (!pJogador)
        return;

    sf::Vector2f direcao(pJogador->getX() - x, pJogador->getY() - y);

    sf::Vector2f dir = normalize(direcao);
    velX = dir.x * velocidade;

    if (pJogador->getY() < y - 10.0f && noChao)
    {
        velY = -10.0f;
	noChao = false;
    }

    x += velX;
    sprite.setPosition(x, y);
}


Alaska::Entidades::Personagens::InimigoSimples::InimigoSimples(
    float x, float y, Jogador* pJ)
    : Inimigo(x, y, 1, 1, pJ)
{
}

Alaska::Entidades::Personagens::InimigoSimples::~InimigoSimples() {}

void Alaska::Entidades::Personagens::InimigoSimples::executar()
{
    aplicarGravidade();
    seguirJogador();
    sprite.setPosition(x, y);
}
