#include "Gerenciador_Eventos.h"
#include "Menu.h"

Alaska::Gerenciadores::Gerenciador_Eventos::Gerenciador_Eventos()
    : janela(nullptr), pJogador1(nullptr), pJogador2(nullptr), pMenu(nullptr),
      botaoPause(false), botaoSalvar(false) {}

Alaska::Gerenciadores::Gerenciador_Eventos::~Gerenciador_Eventos(){}

void Alaska::Gerenciadores::Gerenciador_Eventos::setJanela(sf::RenderWindow* pJ) 
{
    janela = pJ;
}

void Alaska::Gerenciadores::Gerenciador_Eventos::setJogadores(Alaska::Entidades::Personagens::Jogador* pJ1, Alaska::Entidades::Personagens::Jogador* pJ2)
{
    pJogador1 = pJ1;
    pJogador2 = pJ2;
}

void Alaska::Gerenciadores::Gerenciador_Eventos::setMenu(Alaska::Menu* pM)
{
    pMenu = pM;
}

void Alaska::Gerenciadores::Gerenciador_Eventos::verificarEventos(bool processarInputsJogadores)
{
    if (!janela) return;

    sf::Event evento;
    while (janela->pollEvent(evento))
    {
        if (evento.type == sf::Event::Closed)
            janela->close();

        if (pMenu && evento.type == sf::Event::TextEntered)
            pMenu->receberTexto(evento.text.unicode);

        if (evento.type == sf::Event::KeyPressed)
        {
            if (evento.key.code == sf::Keyboard::Escape)
                janela->close();

            if (pMenu)
            {
                if (pMenu->estaDigitandoNome())
                {
                    if (evento.key.code == sf::Keyboard::BackSpace)
                        pMenu->apagarCaractere();
                    else if (evento.key.code == sf::Keyboard::Enter)
                        pMenu->confirmarNomeDigitado();
                }
                else
                {
                    if (evento.key.code == sf::Keyboard::Up)
                        pMenu->mudarOpcao(-1);
                    else if (evento.key.code == sf::Keyboard::Down)
                        pMenu->mudarOpcao(1);
                    else if (evento.key.code == sf::Keyboard::Enter)
                        pMenu->confirmarOpcao();
                }
            }
            else 
            {
                if (evento.key.code == sf::Keyboard::P)
                    botaoPause = true;
                else if (evento.key.code == sf::Keyboard::M)
                    botaoSalvar = true;
            }
        }
    }

    if (!processarInputsJogadores || pMenu)
        return;

    if (pJogador1)
    {
        float velocidadeAndar = 3.0f;
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
    }
    if (pJogador2)
    {
        float velocidadeAndar = 3.0f;
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

bool Alaska::Gerenciadores::Gerenciador_Eventos::pause()
{
    const bool valor = botaoPause;
    botaoPause = false;
    return valor;
}

bool Alaska::Gerenciadores::Gerenciador_Eventos::salvaEstadoAtual()
{
    const bool valor = botaoSalvar;
    botaoSalvar = false;
    return valor;
}
