#pragma once
#include "pch.h"
#include "Ente.h"
#include "Alaskapp.h"
#include "Gerenciador_Eventos.h"

namespace Alaska {
	class Alaskapp;
	namespace Gerenciadores { class Gerenciador_Eventos; }

	class Menu : public Ente
	{
	private:
		Alaska::Alaskapp* pAlaskapp;
		Alaska::Gerenciadores::Gerenciador_Eventos* pEventos;
		int opcao;
		bool ativo;

	public:
		Menu(Alaska::Alaskapp* pAlaskapp, Alaska::Gerenciadores::Gerenciador_Eventos* pEventos);
		~Menu();
		void executar();
		void confirmarOpcao();
		void mudarOpcao(int direcao);
		int getOpcao() const { return opcao; }
		void reset();
	};
}
