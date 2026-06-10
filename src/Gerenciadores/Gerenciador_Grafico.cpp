#include "Gerenciador_Grafico.h"

Alaska::Gerenciadores::Gerenciador_Grafico::Gerenciador_Grafico()
{
    janela = new sf::RenderWindow(sf::VideoMode(800, 600), "Demo Alaska");
    janela->setFramerateLimit(60);

    camera.setSize(800.0f, 600.0f);

    fontMenu.loadFromFile("fonts/Roboto/static/Roboto-Regular.ttf");
    text.setFont(fontMenu);
}

Alaska::Gerenciadores::Gerenciador_Grafico::~Gerenciador_Grafico()
{
    delete janela;
}

void Alaska::Gerenciadores::Gerenciador_Grafico::limpar()
{
    if (janela && janela->isOpen()) 
        janela->clear();
}

void Alaska::Gerenciadores::Gerenciador_Grafico::mostrar()
{
    if (janela && janela->isOpen())
        janela->display();
}

void Alaska::Gerenciadores::Gerenciador_Grafico::desenharEnte(Alaska::Ente* pEnte)
{
    if (pEnte && janela && janela->isOpen())
        janela->draw(*(pEnte->getSprite()));
}

void Alaska::Gerenciadores::Gerenciador_Grafico::desenharTexto(sf::Text* pTexto)
{
    if (pTexto && janela && janela->isOpen())
        janela->draw(*pTexto);
}
void Alaska::Gerenciadores::Gerenciador_Grafico::desenharTituloMenu(const sf::String& pStrTitulo)
{
    text.setString(pStrTitulo);
    text.setCharacterSize(72);
    text.setFillColor(sf::Color::White);
    text.setPosition(300.f, 150.f);
    if (janela && janela->isOpen())
        janela->draw(text);
}
void Alaska::Gerenciadores::Gerenciador_Grafico::desenharOpcaoMenu(const sf::String& pStrOpcao, int indice, bool selecionado)
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

bool Alaska::Gerenciadores::Gerenciador_Grafico::isJanelaAberta()
{
    return janela->isOpen();
}

sf::RenderWindow* Alaska::Gerenciadores::Gerenciador_Grafico::getJanela()
{
    return janela;
}

void Alaska::Gerenciadores::Gerenciador_Grafico::atualizarCamera(float x, float y)
{
    camera.setCenter(x, y);
    if (janela && janela->isOpen())
    {
        sf::View visualizacaoAtual = camera;
        janela->setView(camera);
    }
}
