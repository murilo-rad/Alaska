#include "Colisoes.h"

Alaska::Gerenciadores::Colisoes::Colisoes(Entidades::Personagens::Jogador* j, 
                                          Entidades::Obstaculos::Plataforma* p, 
                                          Entidades::Obstaculos::Ice_Spike* e) 
    : pJogador(j), pPlataforma(p), pEspinho(e) {}

Alaska::Gerenciadores::Colisoes::~Colisoes() {}

void Alaska::Gerenciadores::Colisoes::calcularColisoes() 
{
    sf::FloatRect caixaJogador = pJogador->getSprite()->getGlobalBounds();
    sf::FloatRect caixaPlataforma = pPlataforma->getSprite()->getGlobalBounds();
    sf::FloatRect caixaEspinho = pEspinho->getSprite()->getGlobalBounds();

    sf::FloatRect intersecao;

    if (caixaJogador.intersects(caixaPlataforma, intersecao)) 
        if (intersecao.width > intersecao.height) 
            if (pJogador->getY() < pPlataforma->getY()) 
                pJogador->setY(pJogador->getY() - intersecao.height);
        else 
            if (pJogador->getX() < pPlataforma->getX())
                pJogador->setX(pJogador->getX() - intersecao.width);
            else
                pJogador->setX(pJogador->getX() + intersecao.width);

    caixaJogador = pJogador->getSprite()->getGlobalBounds(); 

}