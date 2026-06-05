#include "Nevoso.h"


Alaska::Entidades::Personagens::Nevoso::Nevoso
(float vx, float vy, int v, int mal, Alaska::Entidades::Personagens::Jogador* pJ, float vel) : 
Inimigo(vx, vy, mal, v, pJ), acumulacao()
{
    calcularMaldade();
    pFig = new sf::Texture();
    sf::Image img;
    img.create(50, 50, sf::Color::White);
    pFig->loadFromImage(img);
    sprite.setTexture(*pFig);
    sprite.setPosition(x, y);
}

Alaska::Entidades::Personagens::Nevoso::Nevoso(){}

Alaska::Entidades::Personagens::Nevoso::~Nevoso() {}

void Alaska::Entidades::Personagens::Nevoso::executar()
{
    mover();
}

void Alaska::Entidades::Personagens::Nevoso::salvar()
{
  
}

void Alaska::Entidades::Personagens::Nevoso::mover()
{
    seguirJogador();
    aplicarGravidade();
    sprite.setPosition(x, y);
}

void Alaska::Entidades::Personagens::Nevoso::danificar(Alaska::Entidades::Personagens::Jogador* pJ)
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
