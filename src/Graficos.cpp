#include "Graficos.h"

Alaska::Gerenciadores::Graficos::Graficos() 
{
    janela = new sf::RenderWindow(sf::VideoMode(800, 600), "Demo Alaska");
    janela->setFramerateLimit(60);

    camera.setSize(800.0f, 600.0f);
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

void Alaska::Gerenciadores::Graficos::atualizarCamera(float x, float y)
{
    camera.setCenter(x, y);
    if (janela && janela->isOpen())
    {
        sf::View visualizacaoAtual = camera;
        janela->setView(camera);
    }
}