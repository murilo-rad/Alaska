#pragma once
#include "pch.h"
#include "Ente.h"

namespace Alaska {
	class Alaskapp;
	namespace Gerenciadores { class Eventos; }

	class Menu : public Ente
	{
	private:
		Alaska::Alaskapp* pAlaskapp;
		Alaska::Gerenciadores::Eventos* pEventos;
		int opcao;
		bool ativo;

	public:
		Menu(Alaska::Alaskapp* pAlaskapp, Alaska::Gerenciadores::Eventos* pEventos);
		~Menu();
		void executar();
		void confirmarOpcao();
		void mudarOpcao(int direcao);
	};
}
