#include "Colisoes.h"
#include "Plataforma.h"
#include "Ice_Spike.h"

Alaska::Gerenciadores::Colisoes::Colisoes(Entidades::Personagens::Jogador* pJ, std::vector<Entidades::Entidade*>* listaEnt) 
    : pJogador(pJ), listaEntidades(listaEnt) {}

Alaska::Gerenciadores::Colisoes::~Colisoes() {}

void Alaska::Gerenciadores::Colisoes::calcularColisoes() 
{
    if (!pJogador || !listaEntidades) return;

    sf::FloatRect caixaJogador = pJogador->getSprite()->getGlobalBounds();

    for (int i = 0; i < listaEntidades->size(); i++) 
    {
        Entidades::Entidade* pEntidade = (*listaEntidades)[i];
        sf::FloatRect caixaEntidade = pEntidade->getSprite()->getGlobalBounds();
        sf::FloatRect intersecao;

        if (caixaJogador.intersects(caixaEntidade, intersecao)) 
        {
            auto* pPlataforma = dynamic_cast<Entidades::Obstaculos::Plataforma*>(pEntidade);
            auto* pEspinho = dynamic_cast<Entidades::Obstaculos::Ice_Spike*>(pEntidade);

            if (pPlataforma != nullptr) 
            {
                if (intersecao.width > intersecao.height) 
                {
                    if (pJogador->getY() < pPlataforma->getY()) 
                    {
                        pJogador->setY(pJogador->getY() - intersecao.height);
                        pJogador->Entidade::setVelY(0.0); 
                        pJogador->setNoChao(true);
                    }
                    else if (pJogador->getY() > pPlataforma->getY()) 
                    {
                        pJogador->setY(pJogador->getY() + intersecao.height);
                        pJogador->Entidade::setVelY(0.0); 
                        pJogador->setNoChao(false);
                    }
                }
                else 
                {
                    if (pJogador->getX() < pPlataforma->getX())
                        pJogador->setX(pJogador->getX() - intersecao.width); 
                    else
                        pJogador->setX(pJogador->getX() + intersecao.width);
                }
                
                caixaJogador = pJogador->getSprite()->getGlobalBounds(); 
            }
            
            else if (pEspinho != nullptr) 
            {
                std::cout << "Ai!" << std::endl;
            }
        }
    }
}