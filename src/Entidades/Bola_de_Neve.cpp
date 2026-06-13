#include "Bola_de_Neve.h"
#include "Abominavel.h"

Alaska::Entidades::Bola_de_Neve::Bola_de_Neve(Alaska::Entidades::Personagens::Abominavel* pA) : 
                                    ativo(false), pAbm(nullptr), Entidade()
{
    if(pA)
    {
        pAbm = pA;
        pAbm->setBola(this);
        x = pAbm->getX();
        y = pAbm->getY();
    }
    pFig = new sf::Texture();
    pFig->loadFromFile("imgs/BolaDeNeve.png");
    sprite.setTexture(*pFig);
    ajustarSprite(sprite, T_BOLA, T_BOLA);
}

Alaska::Entidades::Bola_de_Neve::~Bola_de_Neve()
{
    pAbm = nullptr;
}

void Alaska::Entidades::Bola_de_Neve::executar()
{
    if(ativo)
    {
        mover();
        gravitar();
        antiGravitar();
        desenhar();
    }
}

void Alaska::Entidades::Bola_de_Neve::mover()
{
    if(ativo)
    {
        if(getY() > A_MAX_GERAL + 200.0f)
        {
            ativo = false;
            setVelX(0.0f);
            if(pAbm)
            {
                x = pAbm->getX();
                y = pAbm->getY();
            }
        }
        x -= velX;
        sprite.setPosition(x,y);
    }
}

void Alaska::Entidades::Bola_de_Neve::setAtivo()
{
    ativo = true;
}

const bool Alaska::Entidades::Bola_de_Neve::getAtivo()const
{
    return ativo;
}

void Alaska::Entidades::Bola_de_Neve::antiGravitar() 
{
    velY *= 0.8f;
}


void Alaska::Entidades::Bola_de_Neve::salvar()
{

}