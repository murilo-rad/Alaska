#include "Graficos.h"

Alaska::Gerenciadores::Graficos::Graficos()
{
    janela = new sf::RenderWindow(sf::VideoMode(800, 600), "Demo Alaska");
    janela->setFramerateLimit(60);

    camera.setSize(800.0f, 600.0f);

    fontMenu.loadFromFile("assets/fonts/Roboto-VariableFont_wdth,wght.ttf");
    text.setFont(fontMenu);
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

void Alaska::Gerenciadores::Graficos::desenharEnte(Alaska::Ente* pEnte)
{
    if (pEnte && janela && janela->isOpen())
        janela->draw(*pEnte->getSprite());
}

void Alaska::Gerenciadores::Graficos::desenharTexto(sf::Text* pTexto)
{
    if (pTexto && janela && janela->isOpen())
        janela->draw(*pTexto);
}
void Alaska::Gerenciadores::Graficos::desenharTituloMenu(const sf::String& pStrTitulo)
{
    text.setString(pStrTitulo);
    text.setCharacterSize(72);
    text.setFillColor(sf::Color::White);
    text.setPosition(300.f, 150.f);
    if (janela && janela->isOpen())
        janela->draw(text);
}
void Alaska::Gerenciadores::Graficos::desenharOpcaoMenu(const sf::String& pStrOpcao, int indice, bool selecionado)
{
    const float BASE_Y      = 300.f;
    const float ESPACAMENTO = 60.f;

    text.setString(pStrOpcao);
    text.setCharacterSize(36);
    text.setFillColor(selecionado ? sf::Color::Yellow : sf::Color::White);
    text.setPosition(340.f, BASE_Y + indice * ESPACAMENTO);
    if (janela && janela->isOpen())
        janela->draw(text);
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