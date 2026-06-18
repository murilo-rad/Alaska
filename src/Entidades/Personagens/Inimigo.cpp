#include "Inimigo.h"

Alaska::Entidades::Personagens::Inimigo::Inimigo(float x, float y, short nv, Jogador* pJ) 
: Personagem(x, y, 0.0f, 0.0f, nv), nivel_maldade(calcularMaldade()), pJogador(nullptr), velocidade(1.0f)
{
    if(pJ)
      pJogador = pJ;
}

Alaska::Entidades::Personagens::Inimigo::Inimigo() : Personagem(), nivel_maldade(1), pJogador(nullptr), velocidade(1.0f) {}

Alaska::Entidades::Personagens::Inimigo::~Inimigo()
{
    if(pJogador)
        pJogador = nullptr;
}

void Alaska::Entidades::Personagens::Inimigo::salvarDataBuffer()
{
    coletarDados();
    Personagem::salvarDataBuffer();
}

void Alaska::Entidades::Personagens::Inimigo::coletarDados()
{
    buffer << nivel_maldade << "," << pJogador->getID() << "," << velocidade << ",";
}

void Alaska::Entidades::Personagens::Inimigo::setMaldade(int m)
{
    nivel_maldade = m;
}

int Alaska::Entidades::Personagens::Inimigo::getMaldade()
{
    return nivel_maldade;
}

void Alaska::Entidades::Personagens::Inimigo::setJogador(Alaska::Entidades::Personagens::Jogador* pJ)
{
    pJogador = pJ;
}

void Alaska::Entidades::Personagens::Inimigo::setVelocidade(float vel)
{
    velocidade = vel;
}

void Alaska::Entidades::Personagens::Inimigo::seguirJogador()
{
    if (!pJogador)
        return;

    sf::Vector2f direcao(pJogador->getX() - x, pJogador->getY() - y);

    sf::Vector2f dir = normalizarVetor(direcao);
    velX = dir.x * velocidade;

    if (pJogador->getY() < y - 80.0f && noChao)
    {
        velY = -12.0f;
        setNoChao(false);
    }
    x += velX;
}

int Alaska::Entidades::Personagens::Inimigo::calcularMaldade()
{   
    int aux = (rand() % 2) + 1;
    return aux;
}

sf::Vector2f Alaska::Entidades::Personagens::Inimigo::normalizarVetor(sf::Vector2f v)
{
    double tamVetorV = std::sqrt(std::pow(v.x, 2) + std::pow(v.y, 2));

    sf::Vector2f vetorNormalizado(v.x/tamVetorV, v.y/tamVetorV);

    return vetorNormalizado;
}

void Alaska::Entidades::Personagens::Inimigo::impedirSobrePosicao(Entidade* pI)
{
	if (pI && pI != this)
	{
		sf::FloatRect caixaIni1 = getSprite()->getGlobalBounds();
		sf::FloatRect caixaIni2 = pI->getSprite()->getGlobalBounds();
		if (caixaIni1.intersects(caixaIni2))
		{
			if (caixaIni1.left < caixaIni2.left)
				setX(caixaIni2.left - caixaIni1.width);
			else
				setX(caixaIni2.left + caixaIni2.width);
		}
	}
}