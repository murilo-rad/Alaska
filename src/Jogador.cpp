#include "Jogador.h"

Alaska::Entidades::Personagens::Jogador::Jogador(): Personagem(100.0f, 100.0f, 3), pontos(0) 
{
    //Como ainda não temos sprites, estaremos criando corpos básicos para a demo.
    sf::Image img;
    img.create(50, 50, sf::Color::Blue);
    textura.loadFromImage(img);
    sprite.setTexture(textura);
    sprite.setPosition(x, y);
}

Alaska::Entidades::Personagens::Jogador::~Jogador() {}

void Alaska::Entidades::Personagens::Jogador::executar() 
{
    aplicarGravidade();
    sprite.setPosition(x, y);
    setNoChao(false);
}
