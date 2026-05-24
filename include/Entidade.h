#pragma once
#include "pch.h"
#include "Ente.h"

namespace Alaska
{
    namespace Entidades
    {
        class Entidade : public Ente
        {
            protected:
                float x;
                float y;
            public:
                Entidade(float xx, float yy);
                virtual ~Entidade();

                virtual void executar() = 0;

                const float getX();
                const float getY();
                
                void setX(const float xx);
                void setY(const float yy);
        };
    }
}