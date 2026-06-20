#pragma once
#include "pch.h"
#include "Gerenciador_Grafico.h"
#include "Personagem.h"
#include "Jogador.h"
#include "Fase.h"
#include "Tundra.h"
#include "Caverna.h"

namespace Alaska
{
    namespace Gerenciadores {
        class Gerenciador_Eventos;
    }
    class Menu;

    enum class EstadoJogo
    {
        MENU,
        FASE,
        ENCERRANDO
    };

    enum class TipoFase
    {
        NENHUMA,
        TUNDRA,
        CAVERNA
    };

    class Alaskapp
    {
    private:
        Alaska::Gerenciadores::Gerenciador_Grafico GG;
        Alaska::Entidades::Personagens::Jogador* pJog1;
        Alaska::Entidades::Personagens::Jogador* pJog2;
        Alaska::Fases::Fase* pFase;
        TipoFase faseEscolhida;
        EstadoJogo estado;
        int qntd_pontos;
        int qntdJogadores;
        bool pausado;
        bool faseCarregadaDeSave;
        float tempoPartidaSegundos;

    public:
        Alaskapp();
        ~Alaskapp();
        Alaska::Fases::Fase* pFaseSelecionada;
        void executar();
        void setFaseEscolhida(Alaska::TipoFase fase) { faseEscolhida = fase; }
        void sementear();
        void setFaseSelecionada(Alaska::Fases::Fase* fase) { pFaseSelecionada = fase; }
        Alaska::Entidades::Personagens::Jogador* getPJog1() const { return pJog1; }
        Alaska::Entidades::Personagens::Jogador* getPJog2() const { return pJog2; }
        void criarJogadores(int qntd);
        void setNomeJogador(int indice, const std::string& nome);
        bool verificarJogadores() const;
        void executarMenu(Alaska::Menu* pMenu, Alaska::Gerenciadores::Gerenciador_Eventos& GE);
        void criarFaseSelecionada();
        bool salvarJogoAtual();
        bool carregarJogoSalvo();
        std::vector<std::string> carregarLeaderboardTexto(int limite = MAX_LEADERBOARD) const;

    private:
        void executarFase(Alaska::Gerenciadores::Gerenciador_Eventos& GE);
        Fases::Fase* criarFase(short numFase);
        void registrarResultadoLeaderboard();
        int getNumeroFaseAtual() const;
        void limparJogadores();
    };
}
