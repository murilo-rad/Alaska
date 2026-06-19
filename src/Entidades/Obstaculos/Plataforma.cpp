#include "Plataforma.h"

Alaska::Entidades::Obstaculos::Plataforma::Plataforma(float x, float y) : Obstaculo(x, y, false), largura(L_PLAT)
{
    pFig = new sf::Texture();
    pFig->loadFromFile("imgs/Plataforma.png");
    sprite.setTexture(*pFig);
    ajustarSprite(sprite, A_PLAT, largura);
    sprite.setPosition(x, y);
}

Alaska::Entidades::Obstaculos::Plataforma::Plataforma() : Obstaculo(0, 0, false), largura(L_PLAT)
{
    pFig = new sf::Texture();
    pFig->loadFromFile("imgs/Plataforma.png");
    sprite.setTexture(*pFig);
    ajustarSprite(sprite, A_PLAT, largura);
    sprite.setPosition(x, y);
}

Alaska::Entidades::Obstaculos::Plataforma::~Plataforma() {}

void Alaska::Entidades::Obstaculos::Plataforma::executar()
{
    gravitar();
    antiGravitar();
    desenhar();
}

void Alaska::Entidades::Obstaculos::Plataforma::salvar()
{
    coletarDados();
    Alaska::Entidades::Obstaculos::Obstaculo::salvarDataBuffer();
}

void Alaska::Entidades::Obstaculos::Plataforma::coletarDados()
{
    buffer << IND_PLAT << "," << largura << "," << id << ",";
}

void Alaska::Entidades::Obstaculos::Plataforma::setLargura(int l)
{
    largura = l;
}

void Alaska::Entidades::Obstaculos::Plataforma::obstaculizar(Alaska::Entidades::Personagens::Jogador *pJ)
{
    sf::FloatRect caixaJog = pJ->getSprite()->getGlobalBounds();
    sf::FloatRect caixaPlat = sprite.getGlobalBounds();

    float peDoJogador = caixaJog.top + caixaJog.height;
    float peNoFrameAnterior = peDoJogador - pJ->getVelY();

    if (pJ->getVelY() > 0 && peNoFrameAnterior <= caixaPlat.top)
    {
        pJ->setY(caixaPlat.top - caixaJog.height);
        pJ->setVelY(0.0f);
        pJ->setNoChao(true);
    }
}

void Alaska::Entidades::Obstaculos::Plataforma::obstaculizarInimigo(Alaska::Entidades::Personagens::Inimigo *pI)
{
    sf::FloatRect caixaIni = pI->getSprite()->getGlobalBounds();
    sf::FloatRect caixaPlat = sprite.getGlobalBounds();

    float peDoInimigo = caixaIni.top + caixaIni.height;
    float peNoFrameAnterior = peDoInimigo - pI->getVelY();

    if (pI->getVelY() > 0 && peNoFrameAnterior <= caixaPlat.top)
    {
        pI->setY(caixaPlat.top - caixaIni.height);
        pI->setVelY(0.0f);
        pI->setNoChao(true);
    }
}

