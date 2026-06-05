#include "Nevoso.h"

Alaska::Entidades::Personagens::Nevoso::Nevoso
(float vx, float vy, int v, int mal, Alaska::Entidades::Personagens::Jogador* pJ, float vel) : 
Inimigo(vx, vy, v, mal, pJ, vel), tamanho()
{
    if (!textura.loadFromFile("assets/img/Nevoso.png"))
    {
        std::cerr << "Erro ao carregar a textura do Inimigo!" << std::endl;
        sf::Image img;
        img.create(T_NEVOSO, T_NEVOSO, sf::Color::White);
        textura.loadFromImage(img);
    }

    float aux = 1.0f + (rand() % 101) / 100.0f;
    float tamanho = T_NEVOSO * aux;
    
    sprite.setTexture(textura);
    ajustarSprite(sprite, tamanho);
    sprite.setPosition(x, y);
}

Alaska::Entidades::Personagens::Nevoso::Nevoso(){}

Alaska::Entidades::Personagens::Nevoso::~Nevoso() {}

void Alaska::Entidades::Personagens::Nevoso::executar()
{
    seguirJogador();
    aplicarGravidade();
    sprite.setPosition(x, y);
}

void Alaska::Entidades::Personagens::Nevoso::salvar()
{
  
}

void Alaska::Entidades::Personagens::Nevoso::mover()
{

}

void Alaska::Entidades::Personagens::Nevoso::danificar()
{

}