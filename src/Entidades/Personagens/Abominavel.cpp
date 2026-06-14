#include "Abominavel.h"
#include "Bola_de_Neve.h"

Alaska::Entidades::Personagens::Abominavel::Abominavel(float x, float y, Alaska::Entidades::Personagens::Jogador* pJ)
: Inimigo(x, y, 3, pJ), forca(calcularForca())
{
    pFig = new sf::Texture();
    pFig->loadFromFile("imgs/Yeti.png");
    sprite.setTexture(*pFig);
    ajustarSprite(sprite, T_ABO, T_ABO);
}

Alaska::Entidades::Personagens::Abominavel::Abominavel()
{
}

Alaska::Entidades::Personagens::Abominavel::~Abominavel(){}

void Alaska::Entidades::Personagens::Abominavel::executar()
{
    gravitar();
    arremessar();
    mover();
    desenhar();
    verificarSaude();
}

void Alaska::Entidades::Personagens::Abominavel::mover()
{
    seguirJogador();
    sprite.setPosition(x, y);
}

void Alaska::Entidades::Personagens::Abominavel::danificar(Alaska::Entidades::Personagens::Jogador* pJ)
{
    printf("hit abominavel\n");

    pJ->operator--(forca);


    sf::FloatRect caixaJog = pJ->getSprite()->getGlobalBounds();
    sf::FloatRect caixaAbm = sprite.getGlobalBounds();

    float centroJog = caixaJog.left + caixaJog.width / 2.f;
    float centroAbm = caixaAbm.left + caixaAbm.width / 2.f;

    if (centroJog < centroAbm)
        pJ->setVelX(-forca*20.0f);
    else
        pJ->setVelX(forca*20.0f);
    pJ->setVelY(forca*5.0f);
}

int Alaska::Entidades::Personagens::Abominavel::calcularForca()
{
    forca = nivel_maldade * 2;
    velocidade /= forca;
    return forca;
}

int Alaska::Entidades::Personagens::Abominavel::getForca()
{
    return forca;
}

void Alaska::Entidades::Personagens::Abominavel::arremessar()
{
    if(pBola)
        if(!pBola->getAtivo())
        {
            pBola->setAtivo();
            pBola->setVelX((float)(getForca() * 5));
        }
}

void Alaska::Entidades::Personagens::Abominavel::setBola(Alaska::Entidades::Bola_de_Neve* pProj) 
{
	pBola = pProj;
}

void Alaska::Entidades::Personagens::Abominavel::salvar()
{

}

