#include "pch.h"
#include "Graficos.h"
#include "Eventos.h"
#include "Jogador.h"
#include "FaseNoite.h" 

using namespace Alaska;

int main() 
{
    Gerenciadores::Graficos graficos;
    Gerenciadores::Eventos eventos;
    
    Ente::setGG(&graficos);
    eventos.setJanela(graficos.getJanela());

    Entidades::Personagens::Jogador jogador;
    eventos.setJogador(&jogador);

    Fases::FaseNoite fasePrimeira(&jogador);

    while (graficos.isJanelaAberta()) 
    {
        eventos.verificarEventos();
        
        graficos.limpar();

        fasePrimeira.executar();

        graficos.mostrar();
    }

    return 0;
}