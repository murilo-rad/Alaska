#pragma once
#include "pch.h"
#include "Jogador.h"
#include "Inimigo.h"
#include "Entidade.h"
#include "ListaEntidades.h"
#include "Obstaculo.h"
#include "Personagem.h"
#include "Chao.h"
#include "Plataforma.h"
#include "Nevoso.h"
#include "Bola_de_Neve.h"

namespace Alaska 
{
    namespace Gerenciadores 
    {
        class Gerenciador_Colisoes
        {
        private:
            std::vector<Alaska::Entidades::Personagens::Inimigo*> LIs;
            std::list<Alaska::Entidades::Obstaculos::Obstaculo*> LOs;
            std::set<Alaska::Entidades::Bola_de_Neve*> LPs;
            Alaska::Entidades::Personagens::Jogador* pJog1;
            //Alaska::Entidades::Personagens::Jogador* pJog2;
            Alaska::Entidades::Chao* pChao;
        private:
            const bool verificarColisao(Alaska::Entidades::Entidade* pE1, Alaska::Entidades::Entidade* pE2)const;
            void tratarColisoesJogsObstacs();
            void tratarColisoesJogsInimigs();
            //void tratarColisoesJogsProjeteis();
            void tratarColisoesInimigosObstacs();
			void tratarColisoesInimigosInimigos();
            void tratarColisoesChao();
        public:
            Gerenciador_Colisoes();
            ~Gerenciador_Colisoes();
			void incluirInimigo(Alaska::Entidades::Personagens::Inimigo* pIni);
			void incluirObstaculo(Alaska::Entidades::Obstaculos::Obstaculo* pObs);
            void incluirProjetil(Alaska::Entidades::Bola_de_Neve* pProj);
            void setJogadorUm(Alaska::Entidades::Personagens::Jogador* pJ1);
            //void setJogadorDois(Alaska::Entidades::Personagens::Jogador* pJ2);
            void limparMortos();
            void incluirChao(Alaska::Entidades::Chao* pCh);
            void executar();
        };
    }
}