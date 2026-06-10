#pragma once
#include "pch.h"
#include "Ente.h"

namespace Alaska
{

    class Fundo : public Ente
    {
          private:
            float altura;
            float largura;
            short fase;
        public:
            Fundo(float altr, float largr, short f);
            Fundo();
            ~Fundo();
            void executar();
    };
}