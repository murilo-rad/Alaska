#include "pch.h"
#include "Graficos.h"
#include "Eventos.h"
#include "Jogador.h"
#include "Plataforma.h"
#include "Ice_Spike.h"
#include "Colisoes.h" 

using namespace Alaska;

int main() 
{
    Gerenciadores::Graficos graficos;
    Gerenciadores::Eventos eventos;
    Ente::setGG(&graficos);
    eventos.setJanela(graficos.getJanela());

    Entidades::Personagens::Jogador jogador;
    Entidades::Obstaculos::Plataforma chao;
    Entidades::Obstaculos::Ice_Spike espinho(true, 10);

    eventos.setJogador(&jogador);

    Gerenciadores::Colisoes colisoes(&jogador, &chao, &espinho);

    while (graficos.isJanelaAberta()) 
    {
        eventos.verificarEventos();
        
        jogador.setY(jogador.getY() + 1.5f); 

        colisoes.calcularColisoes();

        jogador.executar();
        chao.executar();
        espinho.executar();

        graficos.limpar();
        chao.desenhar();
        espinho.desenhar();
        jogador.desenhar();
        graficos.mostrar();
    }

    return 0;
}