#pragma once
#include "pch.h"
#include "Jogador.h"
#include "Inimigo.h"
#include "Entidade.h"
#include "ListaEntidades.h"
#include "Obstaculo.h"
#include "Personagem.h"
#include "Plataforma.h"
#include "Inimigo.h"
#include "Nevoso.h"


namespace Alaska 
{
    namespace Gerenciadores 
    {
        class Colisoes
        {
        private:
            std::vector<Alaska::Entidades::Personagens::Inimigo*> LIs;
            std::list<Alaska::Entidades::Obstaculos::Obstaculo*> LOs;
            //std::set<Alaska::Entidades::Projetil*> LPs;
            Alaska::Entidades::Personagens::Jogador* pJog1;
            //Alaska::Entidades::Personagens::Jogador* pJog2;
            Alaska::Listas::ListaEntidades* pListaEntidades;
        private:
            const bool verificarColisao(Alaska::Entidades::Entidade* pE1, Alaska::Entidades::Entidade* pE2)const;
            void tratarColisoesJogsObstacs();
            void tratarColisoesJogsInimigs();
            //void tratarColisoesJogsProjeteis();
        public:
            Colisoes(Entidades::Personagens::Jogador* pJ, Listas::ListaEntidades* lista);
            ~Colisoes();
            void incluirInimigo(Alaska::Entidades::Personagens::Inimigo* pIni);
            void incluirObstaculo(Alaska::Entidades::Obstaculos::Obstaculo* pObs);
            //void incluirProjetil();
            void executar();
        };
    }
}