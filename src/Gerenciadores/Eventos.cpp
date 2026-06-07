#include "Eventos.h"
#include "Menu.h"

Alaska::Gerenciadores::Eventos::Eventos() : janela(nullptr), pJogador(nullptr), pMenu(nullptr) {}

Alaska::Gerenciadores::Eventos::~Eventos(){}

void Alaska::Gerenciadores::Eventos::setJanela(sf::RenderWindow* pJ) 
{
    janela = pJ;
}

void Alaska::Gerenciadores::Eventos::setJogador(Alaska::Entidades::Personagens::Jogador* pJ)
{
    pJogador = pJ;
}

void Alaska::Gerenciadores::Eventos::setMenu(Alaska::Menu* pM)
{
    pMenu = pM;
}

void Alaska::Gerenciadores::Eventos::verificarEventos()
{
    if (!janela) return;

    sf::Event evento;
    while (janela->pollEvent(evento))
    {
        if (evento.type == sf::Event::Closed)
            janela->close();

        if (evento.type == sf::Event::KeyPressed)
        {
            if (evento.key.code == sf::Keyboard::Escape)
                janela->close();

            if (pMenu)
            {
                if (evento.key.code == sf::Keyboard::Up)
                    pMenu->mudarOpcao(-1);

                if (evento.key.code == sf::Keyboard::Down)
                    pMenu->mudarOpcao(1);

                if (evento.key.code == sf::Keyboard::Enter)
                    pMenu->confirmarOpcao();
            }
        }
    }

    if (pJogador)
    {
        float velocidadeAndar = 4.0f;
        float velocidadeX = 0.0f;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            velocidadeX += velocidadeAndar;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            velocidadeX -= velocidadeAndar;

        pJogador->setVelX(velocidadeX);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && pJogador->getNoChao())
        {
            pJogador->setVelY(-11.0f);
            pJogador->setNoChao(false);
        }
    }
}
