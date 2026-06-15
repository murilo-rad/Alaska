#pragma once
#include "pch.h"
#include "Gerenciador_Grafico.h"
#include "Personagem.h"
#include "Jogador.h"
#include "Fase.h"
#include "Tundra.h"
#include "Caverna.h"
#include "Menu.h"

namespace Alaska
{
    namespace Gerenciadores {
        class Gerenciador_Eventos;
    }
    class Alaskapp
    {
    private:
        Alaska::Gerenciadores::Gerenciador_Grafico GG;
        Alaska::Entidades::Personagens::Jogador* pJog1;
        Alaska::Entidades::Personagens::Jogador* pJog2;
		Alaska::Fases::Fase* faseSelecionada;
        int qntd_pontos;
    public:
        Alaskapp();
        ~Alaskapp();
        void executar();
        void sementear();
		void setFaseSelecionada(Alaska::Fases::Fase* fase) { faseSelecionada = fase; }
        Alaska::Entidades::Personagens::Jogador* getPJog1() const { return pJog1; }
        Alaska::Entidades::Personagens::Jogador* getPJog2() const { return pJog2; }
        void criarJogadores(int qntd);
        bool verificarJogadores() const;
    private:
        void executarFase(Alaska::Gerenciadores::Gerenciador_Eventos& GE, short numFase);
        Fases::Fase* criarFase(int numFase);
    };
}
