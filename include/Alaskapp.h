#pragma once
#include "pch.h"
#include "Graficos.h"
#include "Personagem.h"
#include "Eventos.h"
#include "Jogador.h"
#include "Fase.h"
#include "Tundra.h"
#include "Menu.h"

namespace Alaska
{
    class Alaskapp
    {
    private:
        Alaska::Gerenciadores::Graficos GG;
        Alaska::Entidades::Personagens::Jogador* pJog1;
    public:
        Alaskapp();
        ~Alaskapp();
        void executar();
        void sementear();
    };
}
