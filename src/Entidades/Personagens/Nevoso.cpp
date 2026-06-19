#include "Nevoso.h"


Alaska::Entidades::Personagens::Nevoso::Nevoso(float x, float y, Jogador* pJ) : Inimigo(x, y, 1, pJ), acumulacao(calcularAcumulacao())
{
    pFig = new sf::Texture();
    pFig->loadFromFile("imgs/Nevoso.png");
    sprite.setTexture(*pFig);
    ajustarSprite(sprite, acumulacao, acumulacao);
}

Alaska::Entidades::Personagens::Nevoso::Nevoso() : Inimigo(0, 0, 1, nullptr), acumulacao(0)
{
    pFig = new sf::Texture();
    pFig->loadFromFile("imgs/Nevoso.png");
    sprite.setTexture(*pFig);
}

Alaska::Entidades::Personagens::Nevoso::~Nevoso()
{
    if(pJogador)
    {
        pJogador->addPontos(1);
        pJogador = nullptr;
    }
}

void Alaska::Entidades::Personagens::Nevoso::executar()
{
    mover();
    gravitar();
    desenhar();
    verificarSaude();
}

void Alaska::Entidades::Personagens::Nevoso::salvar()
{
    buffer.str("");
    buffer.clear();

    Nevoso::coletarDados();
    Inimigo::salvarDataBuffer();
}


void Alaska::Entidades::Personagens::Nevoso::coletarDados()
{
    buffer << IND_NEV << "," << acumulacao << "," << id << ",";
}

void Alaska::Entidades::Personagens::Nevoso::setAcumulacao(float ac)
{
    acumulacao = ac;
}

void Alaska::Entidades::Personagens::Nevoso::mover()
{
    seguirJogador();
    sprite.setPosition(x, y);
}

void Alaska::Entidades::Personagens::Nevoso::danificar(Alaska::Entidades::Personagens::Jogador* pJ)
{
    printf("hit nevoso\n");

    pJ->operator--();

    sf::FloatRect caixaJog = pJ->getSprite()->getGlobalBounds();
    sf::FloatRect caixaNev = sprite.getGlobalBounds();

    float centroJog = caixaJog.left + caixaJog.width / 2.f;
    float centroNev = caixaNev.left + caixaNev.width / 2.f;

    if (centroJog < centroNev)
        pJ->setVelX(-acumulacao*2);
    else
        pJ->setVelX(acumulacao*2);
}

int Alaska::Entidades::Personagens::Nevoso::calcularAcumulacao()
{
    acumulacao = nivel_maldade * T_NEVOSO;
    return acumulacao;
}