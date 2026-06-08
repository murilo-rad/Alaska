#pragma once
#include "pch.h"
#include "Entidade.h"

namespace Alaska
{
    namespace Entidades
    {
        class Fundo : public Entidade
        {
            private:
                float altura;
                float largura;
            public:
                Fundo();
                ~Fundo();
                void executar();
                void salvar();
        };
    }
}