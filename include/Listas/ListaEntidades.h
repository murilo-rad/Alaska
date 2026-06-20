#pragma once
#include "pch.h"
#include "Lista.h"
#include "Entidade.h"
#include "Obstaculo.h"
#include "Plataforma.h"
#include "Gelo.h"
#include "Conjunto_Estalagmites.h"
#include "Personagem.h"
#include "Jogador.h"
#include "Inimigo.h"
#include "Abominavel.h"
#include "Bola_de_Neve.h"

namespace Alaska
{
    namespace Gerenciadores
    {
        class Gerenciador_Colisoes;
    }

    namespace Listas
    {
        class ListaEntidades
        {
            private:
                struct RelacaoInimigoJogador
                {
                    Alaska::Entidades::Personagens::Inimigo* pInimigo;
                    int idJogador;
                };

                struct RelacaoAbominavelBola
                {
                    Alaska::Entidades::Personagens::Abominavel* pAbominavel;
                    int idBola;
                };

                struct RelacaoBolaAbominavel
                {
                    Alaska::Entidades::Bola_de_Neve* pBola;
                    int idAbominavel;
                };

            private:
                Lista<Alaska::Entidades::Entidade*> LEs;

                std::vector<std::string> dividirPorVirgula(const std::string& linha);
                int paraInt(const std::string& str);
                float paraFloat(const std::string& str);
                bool paraBool(const std::string& str);

                void restaurarEntidade(
                    Alaska::Entidades::Entidade* pE,
                    const std::vector<std::string>& dados,
                    int indiceInicial
                );

                void restaurarPersonagem(
                    Alaska::Entidades::Personagens::Personagem* pP,
                    const std::vector<std::string>& dados,
                    int indiceInicial
                );

                void restaurarInimigo(
                    Alaska::Entidades::Personagens::Inimigo* pI,
                    const std::vector<std::string>& dados,
                    int indiceInicial,
                    int& idJogador
                );

                void registrarNoGerenciador(
                    Alaska::Entidades::Entidade* pE,
                    Alaska::Gerenciadores::Gerenciador_Colisoes* pGC
                );

            public:
                ListaEntidades();
                ~ListaEntidades();

                void incluir(Entidades::Entidade* pE);
                void percorrer();
                void desenharEntidades();
                void cemiterio();
                void salvarEntidades();
                void remover(Entidades::Entidade* pE);

                void carregarEntidades(
                    Alaska::Entidades::Personagens::Jogador* pJogador1,
                    Alaska::Entidades::Personagens::Jogador* pJogador2 = nullptr,
                    Alaska::Gerenciadores::Gerenciador_Colisoes* pGC = nullptr
                );

                Lista<Alaska::Entidades::Entidade*>* getLista();
        };
    }
}
