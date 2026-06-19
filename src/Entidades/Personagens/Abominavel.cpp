#include "Abominavel.h"
#include "Bola_de_Neve.h"

Alaska::Entidades::Personagens::Abominavel::Abominavel(float x, float y, Alaska::Entidades::Personagens::Jogador* pJ)
: Inimigo(x, y, 3, pJ), forca(calcularForca()), pBola(nullptr), idBola(pBola->getID())
{
    pFig = new sf::Texture();
    pFig->loadFromFile("imgs/Yeti.png");
    sprite.setTexture(*pFig);
    ajustarSprite(sprite, T_ABO, T_ABO);
}

Alaska::Entidades::Personagens::Abominavel::Abominavel() : Inimigo(0, 0, 3, nullptr), forca(0), pBola(nullptr), idBola(0)
{
    pFig = new sf::Texture();
    pFig->loadFromFile("imgs/Yeti.png");
    sprite.setTexture(*pFig);
    ajustarSprite(sprite, T_ABO, T_ABO);
}

Alaska::Entidades::Personagens::Abominavel::~Abominavel()
{
    if(pJogador)
    {
        pJogador->addPontos(5);
        pJogador = nullptr;
    }

    if(pBola)
        pBola = nullptr;
}

void Alaska::Entidades::Personagens::Abominavel::executar()
{
    gravitar();
    arremessar();
    mover();
    desenhar();
    verificarSaude();
}

void Alaska::Entidades::Personagens::Abominavel::salvar()
{
    coletarDados();
    Inimigo::salvarDataBuffer();
}

void Alaska::Entidades::Personagens::Abominavel::coletarDados()
{
    buffer << IND_ABM << "," << pBola->getID() << "," << forca << "," << id << ",";
}

void Alaska::Entidades::Personagens::Abominavel::setIdBola(int i)
{
    idBola = i;
}

void Alaska::Entidades::Personagens::Abominavel::setBola(Alaska::Entidades::Bola_de_Neve* pProj) 
{
	pBola = pProj;
}

void Alaska::Entidades::Personagens::Abominavel::setForca(int f) 
{
	forca = f;
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

    float xJog = pJ->getSprite()->getPosition().x;

    if (centroJog < centroAbm)
        pJ->setX(xJog - 40.f);
    else
        pJ->setX(xJog + 40.f);
    pJ->setY(forca*30.0f);
}

int Alaska::Entidades::Personagens::Abominavel::calcularForca()
{
    forca = nivel_maldade * 2;
    velocidade /= forca;
    return forca;
}

const int Alaska::Entidades::Personagens::Abominavel::getForca()const
{
    return forca;
}

void Alaska::Entidades::Personagens::Abominavel::arremessar()
{
    if(pBola)
        if(!pBola->getAtivo())
        {
            printf("bola arremssada\n");
            pBola->setAtivo(true);
            pBola->setVelX((float)(getForca() * 5));
        }
}

