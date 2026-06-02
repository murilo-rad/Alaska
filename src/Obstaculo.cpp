#include "Obstaculo.h"

Alaska::Entidades::Obstaculos::Obstaculo::Obstaculo(float x, float y) : Entidade(x, y) {
    danoso = false;
}

Alaska::Entidades::Obstaculos::Obstaculo::~Obstaculo() {
}

void Alaska::Entidades::Obstaculos::Obstaculo::obstaculizar(Alaska::Entidades::Personagens::Jogador* pJ)
{}