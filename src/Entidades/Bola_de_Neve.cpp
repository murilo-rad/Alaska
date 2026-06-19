#include "Bola_de_Neve.h"
#include "Abominavel.h"

Alaska::Entidades::Bola_de_Neve::Bola_de_Neve(Alaska::Entidades::Personagens::Abominavel* pA) :
                                    Entidade(0, 0, 0, 0), pAbm(nullptr), ativo(false), idAbm(0)
{
    if(pA)
    {
        pAbm = pA;
        pAbm->setBola(this);
        setIdAbominavel(pAbm->getID());
        x = pAbm->getX();
        y = pAbm->getY();
    }
    pFig = new sf::Texture();
    pFig->loadFromFile("imgs/BolaDeNeve.png");
    sprite.setTexture(*pFig);
    ajustarSprite(sprite, T_BOLA, T_BOLA);
}

Alaska::Entidades::Bola_de_Neve::Bola_de_Neve() : Entidade(0,0,0,0), pAbm(nullptr), ativo(false), idAbm(0)
{
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

void Alaska::Entidades::Bola_de_Neve::salvar()
{
    buffer.str("");
    buffer.clear();

    Bola_de_Neve::coletarDados();
    Entidade::salvarDataBuffer();
}


void Alaska::Entidades::Bola_de_Neve::coletarDados()
{
    buffer << IND_BOLA << "," << idAbm << "," << ativo << "," << id << ",";
}

void Alaska::Entidades::Bola_de_Neve::setAtivo(bool a)
{
    ativo = a;
}

void Alaska::Entidades::Bola_de_Neve::setAbominavel(Alaska::Entidades::Personagens::Abominavel* pAbo)
{
    pAbm = pAbo;
    idAbm = pAbo ? pAbo->getID() : 0;
}


void Alaska::Entidades::Bola_de_Neve::setIdAbominavel(int i)
{
    idAbm = i;
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
        printf("bola y = %f\n", getY());
        sprite.setPosition(x,y);
    }
}


const bool Alaska::Entidades::Bola_de_Neve::getAtivo()const
{
    return ativo;
}

void Alaska::Entidades::Bola_de_Neve::antiGravitar() 
{
    velY *= 0.8f;
}

void Alaska::Entidades::Bola_de_Neve::acertar(Alaska::Entidades::Personagens::Jogador* pJ)
{
    sf::FloatRect caixaJogador = pJ->getSprite()->getGlobalBounds();
    sf::FloatRect caixaBola = sprite.getGlobalBounds();
    sf::FloatRect inter;

    if (caixaJogador.intersects(caixaBola, inter))
    {
        pJ->operator--();

        pJ->setY(pJ->getY() - 50.0f);

        pJ->setVelY(-11.0f);

        pJ->setNoChao(false);
    }    
}