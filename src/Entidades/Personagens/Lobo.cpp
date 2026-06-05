#include "Lobo.h"

Alaska::Entidades::Personagens::Lobo::Lobo() : voracidade(), Inimigo() {}

Alaska::Entidades::Personagens::Lobo::Lobo(float x, float y, Jogador* pJ) : voracidade(), Inimigo(x, y, 1, 1, pJ) 
{
    pFig = new sf::Texture();
    sf::Image img;
    img.create(50, 50, sf::Color::Red);
    pFig->loadFromImage(img);
    sprite.setTexture(*pFig);
    sprite.setPosition(x, y);

    velX = 0.0f;
    velY = 0.0f;
}

Alaska::Entidades::Personagens::Lobo::~Lobo() {}

void Alaska::Entidades::Personagens::Lobo::executar()
{
    mover();
}

void Alaska::Entidades::Personagens::Lobo::mover()
{
    seguirJogador();
    aplicarGravidade();
    sprite.setPosition(x, y);
}

void Alaska::Entidades::Personagens::Lobo::danificar(Alaska::Entidades::Personagens::Jogador* pJ)
{
    sf::FloatRect caixaJog = pJ->getSprite()->getGlobalBounds();
    sf::FloatRect caixaIni = sprite.getGlobalBounds();
    
    if (caixaJog.top < caixaIni.top) 
    {
        pJ->setY(caixaIni.top - caixaJog.height);
        pJ->setVelY(-8.0f);
        pJ->setNoChao(false);
        operator--();
        recuar();
    }
    else
    {
        float centroJog = caixaJog.left + caixaJog.width / 2.f;
        float centroIni = caixaIni.left + caixaIni.width / 2.f;

        const float empurrao = 8.0f;

        if (centroJog < centroIni)
            pJ->setVelX(-empurrao);
        else
            pJ->setVelX(empurrao);
        
        pJ->operator--();
    }
}

void Alaska::Entidades::Personagens::Lobo::salvar() {
    //implementar
}