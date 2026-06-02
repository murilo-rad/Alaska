#pragma once
#include "pch.h"
#include "Entidade.h"
#include "Jogador.h"


namespace Alaska
{
	namespace Entidades
	{
		class Chao : public Entidade
		{
			private:
				int altura;
				int largura;
				Alaska::Entidades::Personagens::Jogador* pJ;
			public:
				Chao(float x, float y, Alaska::Entidades::Personagens::Jogador* pJ);
				~Chao();
				void executar();
		};
	}
}