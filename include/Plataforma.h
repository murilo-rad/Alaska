#pragma once
#include "pch.h"
#include "Obstaculo.h"

namespace Alaska
{
    namespace Entidades
    {
        namespace Obstaculos
        {
            class Plataforma : public Obstaculo
            {
                private:
                    int altura;
                public:
                    Plataforma(float x, float y);
                    ~Plataforma();
                    void executar();
                    
            };
        }

    }
}
