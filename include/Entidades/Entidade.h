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
                //buffer
            protected:
                //void salvarDataBuffer();
            public:
                Entidade(float xx, float yy);
                Entidade();
                virtual ~Entidade();

                virtual void executar() = 0;
		
                const float getX()const;
                const float getY()const;
                
                void setX(const float xx);
                void setY(const float yy);

                void ajustarSprite(sf::Sprite& sprite, float tam);
        };
    }
}
