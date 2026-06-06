#include "Jogador.h"
#include "Inimigo.h"

Alaska::Entidades::Personagens::Jogador::Jogador(): Personagem(100.0f, 100.0f, 3), pontos(0) 
{
    pFig = new sf::Texture();
    sf::Image img;
    img.create(50, 50, sf::Color::Blue);
    pFig->loadFromImage(img);
    sprite.setTexture(*pFig);
    sprite.setPosition(x, y);

    velX = 0.0f;
    velY = 0.0f;
}

Alaska::Entidades::Personagens::Jogador::~Jogador() {}

void Alaska::Entidades::Personagens::Jogador::executar() 
{
    mover();
    desenhar();
}

void Alaska::Entidades::Personagens::Jogador::salvar() 
{
    
}

void Alaska::Entidades::Personagens::Jogador::mover() 
{
    x += velX;
    aplicarGravidade();
    sprite.setPosition(x, y);
    setNoChao(false);
}

void Alaska::Entidades::Personagens::Jogador::colidir(Inimigo* pIni)
{
	sf::FloatRect caixaIni = pIni->getSprite()->getGlobalBounds();
    sf::FloatRect caixaJog = sprite.getGlobalBounds();
    
    if (caixaJog.top < caixaIni.top)
    {
        setY(caixaIni.top - caixaJog.height);
        setVelY(-8.0f);
        setNoChao(false);
        pIni->recuar();
        pIni->operator--();
    }
    else
    {

        float centroJog = caixaJog.left + caixaJog.width / 2.f;
        float centroIni = caixaIni.left + caixaIni.width / 2.f;

        const float empurrao = 8.0f;

        if (centroJog < centroIni)
            setVelX(-empurrao);
        else
            setVelX(empurrao);

        pIni->danificar(this);
    }
}