#include "Abominavel.h"
//#include "Bola_de_Neve.h"

Alaska::Entidades::Personagens::Abominavel::Abominavel(float x, float y, Alaska::Entidades::Personagens::Jogador* pJ)
: Inimigo(x, y, 3, pJ), forca(calcularForca())
{

}

Alaska::Entidades::Personagens::Abominavel::Abominavel()
{

}

Alaska::Entidades::Personagens::Abominavel::~Abominavel()
{

}

void Alaska::Entidades::Personagens::Abominavel::executar()
{
    gravitar();
    mover();
    desenhar();
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

    if(pJ->getVidas() == 0)
        pJ->setMorto();

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

void Alaska::Entidades::Personagens::Abominavel::salvar()
{

}

//
//void Alaska::Entidades::Personagens::Abominavel::setPBola(Alaska::Entidades::Bola_de_Neve* pProj) {
//	pBola = pProj;
//}