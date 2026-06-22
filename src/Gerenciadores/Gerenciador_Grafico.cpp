#include "Gerenciador_Grafico.h"

Alaska::Gerenciadores::Gerenciador_Grafico::Gerenciador_Grafico()
{
    janela = new sf::RenderWindow(sf::VideoMode(static_cast<int>(L_TELA), static_cast<int>(A_TELA)), "Alaska");
    janela->setFramerateLimit(60);
    janela->setKeyRepeatEnabled(false);

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
    text.setFillColor(sf::Color::Black);
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
    text.setFillColor(selecionado ? sf::Color::Cyan : sf::Color::Black);
    text.setPosition(340.f, BASE_Y + indice * ESPACAMENTO);
    if (janela && janela->isOpen())
        janela->draw(text);
}

void Alaska::Gerenciadores::Gerenciador_Grafico::mostrarPontos(int pontos) {
    sf::String strPontos = ("Pontos: " + std::to_string(pontos));
    text.setString(strPontos);
    text.setCharacterSize(36);
    text.setFillColor(sf::Color::White);
    text.setPosition(1.f, 10.f);
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


void Alaska::Gerenciadores::Gerenciador_Grafico::desenharTextoMenu(const sf::String& textoMenu, float x, float y, unsigned int tamanho, sf::Color cor)
{
    text.setString(textoMenu);
    text.setCharacterSize(tamanho);
    text.setFillColor(cor);
    text.setPosition(x, y);

    if (janela && janela->isOpen())
        janela->draw(text);
}

void Alaska::Gerenciadores::Gerenciador_Grafico::desenharOverlayPausa()
{
    if (!janela || !janela->isOpen())
        return;

    sf::RectangleShape overlay(sf::Vector2f(L_TELA, A_TELA));
    overlay.setFillColor(sf::Color(0, 0, 0, 140));
    overlay.setPosition(0.f, 0.f);
    janela->draw(overlay);

    text.setString("PAUSE");
    text.setCharacterSize(86);
    text.setFillColor(sf::Color::White);
    text.setPosition(530.f, 300.f);
    janela->draw(text);

    text.setString("Pressione P para continuar");
    text.setCharacterSize(28);
    text.setFillColor(sf::Color::White);
    text.setPosition(500.f, 405.f);
    janela->draw(text);
}
