#include "Eventos.h"

Alaska::Gerenciadores::Eventos::Eventos() : janela(nullptr), pJogador(nullptr){}

Alaska::Gerenciadores::Eventos::~Eventos(){}

void Alaska::Gerenciadores::Eventos::setJanela(sf::RenderWindow* pJ) {
    janela = pJ;
}

void Alaska::Gerenciadores::Eventos::setJogador(Alaska::Entidades::Personagens::Jogador* pJ) 
{
    pJogador = pJ;
}

void Alaska::Gerenciadores::Eventos::verificarEventos() 
{
    if (!janela) return;

    sf::Event evento;
    while (janela->pollEvent(evento)) 
    {
        if (evento.type == sf::Event::Closed)
            janela->close();
        
        if (evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::Escape)
            janela->close();
    }

    if (pJogador) 
    {
        float vel = 2.0f;
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) 
            pJogador->setX(pJogador->getX() + vel);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) 
            pJogador->setX(pJogador->getX() - vel);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) 
            pJogador->setY(pJogador->getY() + vel);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) 
            pJogador->setY(pJogador->getY() - vel);
    }
}