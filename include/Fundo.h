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
        public:
            Fundo(float altr, float largr);
            Fundo();
            ~Fundo();
            void executar();
    };
}