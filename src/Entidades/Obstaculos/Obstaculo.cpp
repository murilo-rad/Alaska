#include "Obstaculo.h"

Alaska::Entidades::Obstaculos::Obstaculo::Obstaculo() : Entidade() {
	danoso = false;
}

Alaska::Entidades::Obstaculos::Obstaculo::Obstaculo(float x, float y) : Entidade(x, y) {
    danoso = false;
}

Alaska::Entidades::Obstaculos::Obstaculo::~Obstaculo() {
}

void Alaska::Entidades::Obstaculos::Obstaculo::salvarDataBuffer() {
	//implementar
}