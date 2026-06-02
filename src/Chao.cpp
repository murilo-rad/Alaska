#include "Chao.h"

Alaska::Entidades::Chao::Chao(float x, float y, Alaska::Entidades::Personagens::Jogador* pJ) :
	Entidade(x, y), altura(50), largura(2000), pJ(pJ)
{
	sf::Image img;
	img.create(largura, altura, sf::Color::Green);
	textura.loadFromImage(img);
	sprite.setTexture(textura);
	sprite.setPosition(x, y);
}

Alaska::Entidades::Chao::~Chao() {}

void Alaska::Entidades::Chao::executar()
{
    sf::FloatRect caixaJog = pJ->getSprite()->getGlobalBounds();
    sf::FloatRect caixaChao = sprite.getGlobalBounds();

    if (pJ->getVelY() > 0 && caixaJog.top < caixaChao.top)
    {
        pJ->setY(caixaChao.top - caixaJog.height);
        pJ->setVelY(0.0f);
        pJ->setNoChao(true);
    }
}