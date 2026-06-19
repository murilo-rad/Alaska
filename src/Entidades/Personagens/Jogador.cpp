#include "Jogador.h"
#include "Inimigo.h"

Alaska::Entidades::Personagens::Jogador::Jogador() : Personagem(100.0f, 500, 0.0f, 0.0f, 5), pontos(0)
{
    pFig = new sf::Texture();
    pFig->loadFromFile("imgs/Jogador01.png");
    sprite.setTexture(*pFig);
    ajustarSprite(sprite, T_JOG, T_JOG);
}

Alaska::Entidades::Personagens::Jogador::Jogador(int num) : Personagem(100.0f, 500, 0.0f, 0.0f, 5), pontos(0)
{
    pFig = new sf::Texture();
    printf("novo jogador (%d)\n", num);
    if (num == 1)
        pFig->loadFromFile("imgs/Jogador01.png");
    else
        pFig->loadFromFile("imgs/Jogador02.png");
    sprite.setTexture(*pFig);
    ajustarSprite(sprite, T_JOG, T_JOG);
}

Alaska::Entidades::Personagens::Jogador::~Jogador()
{
    pontos = -1;
    printf("morte");
}

void Alaska::Entidades::Personagens::Jogador::executar()
{
    mover();
    gravitar();
    desenhar();
    verificarSaude();
}

void Alaska::Entidades::Personagens::Jogador::salvar()
{
    buffer.str("");
    buffer.clear();

    Jogador::coletarDados();
    Personagem::salvarDataBuffer();
}


void Alaska::Entidades::Personagens::Jogador::coletarDados()
{
    buffer << IND_JOG << "," << pontos << "," << nome << "," << id << ",";
}

void Alaska::Entidades::Personagens::Jogador::setPontos(int p)
{
    pontos = p;
}

const int Alaska::Entidades::Personagens::Jogador::getPontos()const
{
    return pontos;
}

void Alaska::Entidades::Personagens::Jogador::addPontos(int qtd)
{
    pontos += qtd;
}

void Alaska::Entidades::Personagens::Jogador::setNome(std::string n)
{
    nome = n;
}

void Alaska::Entidades::Personagens::Jogador::mover()
{
    x += velX;
    sprite.setPosition(x, y);
    setNoChao(false);
}

void Alaska::Entidades::Personagens::Jogador::colidir(Inimigo *pIni)
{
    sf::FloatRect caixaIni = pIni->getSprite()->getGlobalBounds();
    sf::FloatRect caixaJog = sprite.getGlobalBounds();

    if (getVelY() > 0 && caixaJog.top < caixaIni.top && !getNoChao())
    {
        setY(caixaIni.top - caixaJog.height);
        setVelY(-11.0f);
        setNoChao(false);
        printf("hit jogador\n");
        danificar(pIni);
    }
    else if (caixaJog.top >= caixaIni.top)
    {
        sf::FloatRect inter;
        if (caixaJog.intersects(caixaIni, inter))
        {
            if (caixaJog.left < caixaIni.left)
                setX(getX() - inter.width);
            else
                setX(getX() + inter.width);
        }
        pIni->danificar(this);
    }
}

void Alaska::Entidades::Personagens::Jogador::danificar(Inimigo *pIni)
{
    pIni->operator--();
}

void Alaska::Entidades::Personagens::Jogador::resetar()
{
    setX(0.0f);
    setY(500.0f);
    setVelX(0.0f);
    setVelY(0.0f);
    num_vidas = 5;
    vivo = true;
    noChao = false;
}
