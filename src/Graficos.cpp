#include "Graficos.h"

Alaska::Gerenciadores::Graficos::Graficos() 
{
    janela = new sf::RenderWindow(sf::VideoMode(800, 600), "Demo Alaska - Eventos");
    janela->setFramerateLimit(60);
}

Alaska::Gerenciadores::Graficos::~Graficos() 
{
    delete janela;
}

void Alaska::Gerenciadores::Graficos::limpar() 
{
    if (janela && janela->isOpen()) 
        janela->clear(sf::Color::Black);
}

void Alaska::Gerenciadores::Graficos::mostrar() 
{
    if (janela && janela->isOpen()) 
        janela->display();
}

void Alaska::Gerenciadores::Graficos::desenharEnte(sf::Sprite* pSprite) 
{
    if (pSprite && janela && janela->isOpen()) 
        janela->draw(*pSprite);
}

bool Alaska::Gerenciadores::Graficos::isJanelaAberta() 
{
    return janela->isOpen();
}

sf::RenderWindow* Alaska::Gerenciadores::Graficos::getJanela() 
{
    return janela;
}