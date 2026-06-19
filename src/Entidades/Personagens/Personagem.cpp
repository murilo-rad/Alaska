#include "Personagem.h"

Alaska::Entidades::Personagens::Personagem::Personagem
(float x, float y, float vX, float vY, short nv) :
Entidade(x, y, vX, vY), num_vidas(nv), noChao(false), vivo(true) {}

Alaska::Entidades::Personagens::Personagem::Personagem() : Entidade(0,0,0,0), num_vidas(1), noChao(false), vivo(true){}

Alaska::Entidades::Personagens::Personagem::~Personagem(){}


void Alaska::Entidades::Personagens::Personagem::salvarDataBuffer()
{
    Personagem::coletarDados();
    Entidade::salvarDataBuffer();
}

void Alaska::Entidades::Personagens::Personagem::coletarDados() 
{
    buffer << num_vidas << "," << noChao << "," << vivo << ",";
}

void Alaska::Entidades::Personagens::Personagem::setVidas(int v)
{
    num_vidas = v;
}

const int Alaska::Entidades::Personagens::Personagem::getVidas()const
{
    return num_vidas;
}

const bool Alaska::Entidades::Personagens::Personagem::estaVivo()const
{
    return vivo;
}

void Alaska::Entidades::Personagens::Personagem::setMorto()
{
    vivo = false;
}

void Alaska::Entidades::Personagens::Personagem::setMorto(bool v)
{
    vivo = v;
}

void Alaska::Entidades::Personagens::Personagem::verificarSaude()
{
	if (num_vidas <= 0)
		setMorto();
}

void Alaska::Entidades::Personagens::Personagem::setNoChao(bool c) 
{
    noChao = c;
}

const bool Alaska::Entidades::Personagens::Personagem::getNoChao()const 
{
    return noChao;
}

void Alaska::Entidades::Personagens::Personagem::operator++()
{
    if(vivo)
        num_vidas++;
}

void Alaska::Entidades::Personagens::Personagem::operator++(int vida)
{
    if(vivo)
        num_vidas += vida;
}


void Alaska::Entidades::Personagens::Personagem::operator--()
{
    if(vivo)
        num_vidas--;
    if(num_vidas < 0)
        num_vidas = 0;
	printf("-1 vida\nvida: %d\n", num_vidas);
}

void Alaska::Entidades::Personagens::Personagem::operator--(int dano)
{
    if(vivo)
        num_vidas -= dano;
    if(num_vidas < 0)
        num_vidas = 0;
}

