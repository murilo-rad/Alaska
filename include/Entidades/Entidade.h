#pragma once
#include "pch.h"
#include "Ente.h"
#include <cmath>


namespace Alaska
{
    namespace Entidades
    {
        class Entidade : public Ente
        {
            protected:
                float x;
                float y;
                float velX; 
                float velY;
                std::ostream buffer;
            protected:
                void salvarDataBuffer();
            public:
                Entidade(float x, float y, float vX, float vY);
                Entidade();
                virtual ~Entidade();
		
                void setX(const float xx);
                void setY(const float yy);
                const float getX()const;
                const float getY()const;

                void setVelX(const float velXx);
                void setVelY(const float velYy);
                const float getVelX()const;
                const float getVelY()const;
                void gravitar();

                virtual void executar() = 0;
				virtual void salvar() = 0;
        };
    }
}
