#include "Jogador.h"

Alaska::Entidades::Personagens::Jogador::Jogador(): Personagem(100.0f, 100.0f, 3), pontos(0) 
{
    sf::Image img;
    img.create(50, 50, sf::Color::Blue);
    textura.loadFromImage(img);
    sprite.setTexture(textura);
    sprite.setPosition(x, y);

    velX = 0.0f;
    velY = 0.0f;
}

Alaska::Entidades::Personagens::Jogador::~Jogador() {}

void Alaska::Entidades::Personagens::Jogador::executar() 
{
    x += velX;
    aplicarGravidade();
    sprite.setPosition(x, y);
    setNoChao(false);
}

void Alaska::Entidades::Personagens::Jogador::salvar() 
{
    
}

void Alaska::Entidades::Personagens::Jogador::mover() 
{
  
}
