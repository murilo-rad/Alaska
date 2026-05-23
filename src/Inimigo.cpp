#include "Inimigo.h"

Alaska::Entidades::Personagens::Inimigo::Inimigo(float x, float y, int mal, int v): Personagem(x, y, v), maldade(mal){}

Alaska::Entidades::Personagens::Inimigo::~Inimigo(){}

int Alaska::Entidades::Personagens::Inimigo::getMaldade()
{
    return maldade;
}
