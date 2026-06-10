#pragma once
#include "pch.h"
#include "Gerenciador_Grafico.h"
#include "Personagem.h"
#include "Gerenciador_Eventos.h"
#include "Jogador.h"
#include "Fase.h"
#include "Tundra.h"
#include "Menu.h"

namespace Alaska
{
    class Alaskapp
    {
    private:
        Alaska::Gerenciadores::Gerenciador_Grafico GG;
        Alaska::Entidades::Personagens::Jogador* pJog1;
    public:
        Alaskapp();
        ~Alaskapp();
        void executar();
        void sementear();
    };
}
