#include "Jogador.h"
#include "Inimigo.h"

Alaska::Entidades::Personagens::Jogador::Jogador() : Personagem(100.0f, 500.0f, 0.0f, 0.0f, 3)
{
    pFig = new sf::Texture();
    pFig->loadFromFile("imgs/Jogador01.png");
    sprite.setTexture(*pFig);
    ajustarSprite(sprite, T_JOG, T_JOG);
    sprite.setPosition(x, y); 
	pontos = 0;
}

Alaska::Entidades::Personagens::Jogador::~Jogador() 
{
	pontos = -1;
    printf("morte");
}

void Alaska::Entidades::Personagens::Jogador::executar() 
{
    mover();
    gravitar();
    desenhar();
}

void Alaska::Entidades::Personagens::Jogador::salvar() 
{
    
}

void Alaska::Entidades::Personagens::Jogador::mover() 
{
    x += velX;
    sprite.setPosition(x, y);
    setNoChao(false);
}

int Alaska::Entidades::Personagens::Jogador::getPontos()
{
    return pontos;
}

void Alaska::Entidades::Personagens::Jogador::colidir(Inimigo* pIni)
{
	sf::FloatRect caixaIni = pIni->getSprite()->getGlobalBounds();
    sf::FloatRect caixaJog = sprite.getGlobalBounds();
    
    if (caixaJog.top < caixaIni.top && !getNoChao())
    {
        setY(caixaIni.top - caixaJog.height);
        setVelY(-8.0f);
        setNoChao(false);
        printf("hit jogador\n");
        danificar(pIni);
    }
    else if(caixaJog.top >= caixaIni.top)
    {

        float centroJog = caixaJog.left + caixaJog.width / 2.f;
        float centroIni = caixaIni.left + caixaIni.width / 2.f;

        const float empurrao = 30.0f;

        if (centroJog < centroIni)
            setVelX(-empurrao);
        else
            setVelX(empurrao);

        pIni->danificar(this);
    }
}

void Alaska::Entidades::Personagens::Jogador::danificar(Inimigo* pIni)
{
    pIni->operator--();
    if(pIni->getVidas() == 0)
        pIni->setMorto();
}