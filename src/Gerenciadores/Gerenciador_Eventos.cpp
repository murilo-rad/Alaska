#include "Gerenciador_Eventos.h"

Alaska::Gerenciadores::Gerenciador_Eventos::Gerenciador_Eventos() : janela(nullptr), pJogador1(nullptr), pJogador2(nullptr), pMenu(nullptr) {}

Alaska::Gerenciadores::Gerenciador_Eventos::~Gerenciador_Eventos(){}

void Alaska::Gerenciadores::Gerenciador_Eventos::setJanela(sf::RenderWindow* pJ) 
{
    janela = pJ;
}

void Alaska::Gerenciadores::Gerenciador_Eventos::setJogadores(Alaska::Entidades::Personagens::Jogador* pJ1, Alaska::Entidades::Personagens::Jogador* pJ2)
{
    pJogador1 = pJ1;
    if(pJ2)
	    pJogador2 = pJ2;
}

void Alaska::Gerenciadores::Gerenciador_Eventos::setMenu(Alaska::Menu* pM)
{
    pMenu = pM;
}

void Alaska::Gerenciadores::Gerenciador_Eventos::verificarEventos()
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

    if (pJogador1)
    {
        float velocidadeAndar = 1.5f;
        float velocidadeX = 0.0f;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            velocidadeX += velocidadeAndar;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            velocidadeX -= velocidadeAndar;

        pJogador1->setVelX(velocidadeX);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && pJogador1->getNoChao())
        {
            pJogador1->setVelY(-14.0f);
            pJogador1->setNoChao(false);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
            pJogador1->salvar();
    }
    if (pJogador2)
    {
        float velocidadeAndar = 1.5f;
        float velocidadeX = 0.0f;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            velocidadeX += velocidadeAndar;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            velocidadeX -= velocidadeAndar;

        pJogador2->setVelX(velocidadeX);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && pJogador2->getNoChao())
        {
            pJogador2->setVelY(-14.0f);
            pJogador2->setNoChao(false);
        }
    }
}
