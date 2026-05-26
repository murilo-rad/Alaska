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
                float velX; 
                float velY;
		sf::Vector2f normalize(const sf::Vector2f vec);
            public:
                Entidade(float xx, float yy);
                virtual ~Entidade();

                virtual void executar() = 0;
		
		float length(sf::Vector2f v);
                const float getX();
                const float getY();
                
                void setX(const float xx);
                void setY(const float yy);
                void setVelY(const float velYy);
                void aplicarGravidade();
        };
    }
}
