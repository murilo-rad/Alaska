#include "Graficos.h"

Alaska::Gerenciadores::Graficos::Graficos()
{

}

Alaska::Gerenciadores::Graficos::~Graficos()
{

}

void Alaska::Gerenciadores::Graficos::desenharEnte(Alaska::Ente* pEnte)
{
    if(pEnte && janela && janela->isOpen())
        janela->draw(*(pEnte->getSprite()));
}