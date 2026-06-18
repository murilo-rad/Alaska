#pragma once
#include "pch.h"
#include "Entidade.h"

namespace Alaska
{
    namespace Entidades
    {
        namespace Personagens
        {
            class Personagem : public Entidade
            {
                protected:
                    short num_vidas;
                    bool noChao;
                    bool vivo;
                protected:
                    virtual void coletarDados();
                public:
                    Personagem(float x, float y, float vX, float vY, short nv);
                    Personagem();
                    ~Personagem();

                    void salvarDataBuffer();
                    virtual void executar() = 0;
                    virtual void salvar() = 0;

                    void setVidas(int v);
                    const int getVidas()const;
                    const bool estaVivo()const;

                    void setNoChao(bool c);
                    const bool getNoChao() const;

                    void setMorto();
                    void setMorto(bool v);
                    void verificarSaude();

                    void operator++();
                    void operator++(int vida);
                    void operator--();
                    void operator--(int dano);

                    virtual void mover() = 0;
            };
        }

    }
}