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
                std::ostream buffer;
            protected:
                void salvarDataBuffer();
            public:
                Entidade(float x, float y);
                Entidade();
                virtual ~Entidade();
		
                const float getX()const;
                const float getY()const;
                
                void setX(const float xx);
                void setY(const float yy);

                void ajustarSprite(sf::Sprite& sprite, float alt, float larg);

                virtual void executar() = 0;
				virtual void salvar() = 0;
        };
    }
}
