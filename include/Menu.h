#pragma once
#include "pch.h"
#include "Ente.h"
#include "Alaskapp.h"
#include "Gerenciador_Eventos.h"
#include <functional>

namespace Alaska {
	class Alaskapp;
	namespace Gerenciadores { class Gerenciador_Eventos; }

	enum class EstadoMenu {
		EscolherJogadores,
		EscolherFase,
		NomeJogador1,
		NomeJogador2
	};

	struct OpcaoMenu;

	class Menu : public Ente
	{
	private:
		Alaska::Alaskapp* pAlaskapp;
		Alaska::Gerenciadores::Gerenciador_Eventos* pEventos;
		std::vector<OpcaoMenu> opcoes;
		int opcaoSelecionada;
		bool ativo;

	public:
		Menu(Alaska::Alaskapp* pAlaskapp, Alaska::Gerenciadores::Gerenciador_Eventos* pEventos);
		~Menu();
		void executar();
		void confirmarOpcao();
		void mudarOpcao(int direcao);
		int getOpcao() const { return opcaoSelecionada; }
		void reset();
		void desenharEstagio();
		void desenhar();
		void carregarMenuPrincipal();
		void carregarMenuFases();
		void adicionarOpcao(const std::string& texto, void (Menu::*acao)());

		void subir();
		void descer();

		void acaoUmJogador();
		void acaoDoisJogadores();

		void acaoTundra();
		void acaoCaverna();

		void acaoScoreboard();
		void acaoVoltarPrincipal();

		void acaoSair();

	};

	struct OpcaoMenu
	{
		std::string texto;
		void (Menu::* acao)();
	};

}

