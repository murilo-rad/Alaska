#pragma once
#include "pch.h"
#include "Ente.h"
#include <functional>

namespace Alaska
{
    class Alaskapp;
    namespace Gerenciadores
    {
        class Gerenciador_Eventos;
    }

    enum class EstadoMenu
    {
        Principal,
        EscolherFase,
        NomeJogador1,
        NomeJogador2,
        Leaderboard
    };

    struct OpcaoMenu;

    class Menu : public Ente
    {
    private:
        Alaska::Alaskapp *pAlaskapp;
        Alaska::Gerenciadores::Gerenciador_Eventos *pEventos;
        std::vector<OpcaoMenu> opcoes;
        std::vector<std::string> linhasLeaderboard;
        EstadoMenu estadoMenu;
        std::string textoDigitado;
        std::string mensagemRodape;
        sf::Texture texturaFundo;
        sf::Sprite spriteFundo;
        bool fundoCarregado;
        int opcaoSelecionada;
        int quantidadeJogadoresSelecionada;
        bool ativo;

    public:
        Menu(Alaska::Alaskapp *pAlaskapp, Alaska::Gerenciadores::Gerenciador_Eventos *pEventos);
        ~Menu();
        void executar();
        void confirmarOpcao();
        void mudarOpcao(int direcao);
        int getOpcao() const { return opcaoSelecionada; }
        void reset();
        void desenhar();
        void carregarMenuPrincipal();
        void carregarMenuFases();
        void carregarMenuLeaderboard();
        void adicionarOpcao(const std::string &texto, void (Menu::*acao)());

        bool estaDigitandoNome() const;
        void receberTexto(sf::Uint32 unicode);
        void apagarCaractere();
        void confirmarNomeDigitado();

        void subir();
        void descer();

        void acaoUmJogador();
        void acaoDoisJogadores();
        void acaoCarregarJogo();

        void acaoTundra();
        void acaoCaverna();

        void acaoScoreboard();
        void acaoVoltarPrincipal();

        void acaoSair();

    private:
        void carregarFundo();
        void desenharFundo();
        void carregarTelaNomeJogador(int indiceJogador);
        void desenharInputNome();
        void desenharLeaderboard();
    };

    struct OpcaoMenu
    {
        std::string texto;
        void (Menu::*acao)();
    };

}
