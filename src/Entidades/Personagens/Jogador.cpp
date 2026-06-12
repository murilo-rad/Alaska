#include "Jogador.h"
#include "Inimigo.h"

Alaska::Entidades::Personagens::Jogador::Jogador() : Personagem(100.0f, A_MAX_GERAL, 0.0f, 0.0f, 5)
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
    
    if (getVelY() > 0 && caixaJog.top < caixaIni.top && !getNoChao())
    {
        setY(caixaIni.top - caixaJog.height);
        setVelY(-11.0f);
        setNoChao(false);
        printf("hit jogador\n");
        danificar(pIni);
    }
    else if(caixaJog.top >= caixaIni.top)
    {
        sf::FloatRect inter;
        if (caixaJog.intersects(caixaIni, inter))
        {
            if (caixaJog.left < caixaIni.left)
                setX(getX() - inter.width);
            else
                setX(getX() + inter.width);
        }
        pIni->danificar(this);
    }
}

void Alaska::Entidades::Personagens::Jogador::danificar(Inimigo* pIni)
{
    pIni->operator--();
    if(pIni->getVidas() == 0)
        pIni->setMorto();
}