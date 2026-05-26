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

    for (int k = 0; k < (int)listaEntidades->size(); k++)
    {
        Entidades::Personagens::Inimigo* pIni =
            dynamic_cast<Entidades::Personagens::Inimigo*>((*listaEntidades)[k]);
        if (pIni != NULL) pIni->setNoChao(false);
    }

    for (int i = 0; i < (int)listaEntidades->size(); i++) 
    {
        Entidades::Entidade* pEntidade = (*listaEntidades)[i];
        sf::FloatRect caixaEntidade = pEntidade->getSprite()->getGlobalBounds();
        sf::FloatRect intersecao;

        if (caixaJogador.intersects(caixaEntidade, intersecao)) 
        {
            Entidades::Obstaculos::Plataforma* pPlataforma =
                dynamic_cast<Entidades::Obstaculos::Plataforma*>(pEntidade);
            Entidades::Obstaculos::Ice_Spike* pEspinho =
                dynamic_cast<Entidades::Obstaculos::Ice_Spike*>(pEntidade);

            if (pPlataforma != NULL) 
            {
                if (intersecao.width > intersecao.height) 
                {
                    if (pJogador->getY() < pPlataforma->getY()) 
                    {
                        pJogador->setY(pJogador->getY() - intersecao.height);
                        pJogador->Entidade::setVelY(0.0); 
                        pJogador->setNoChao(true);
                    }
                    else 
                    {
                        pJogador->setY(pJogador->getY() + intersecao.height);
                        pJogador->Entidade::setVelY(0.0); 
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
            else if (pEspinho != NULL) 
            {
                std::cout << "Ai!" << std::endl;
            }
        }

        Entidades::Personagens::Inimigo* pInimigo =
            dynamic_cast<Entidades::Personagens::Inimigo*>(pEntidade);

        if (pInimigo != NULL)
        {
            sf::FloatRect caixaInimigo = pInimigo->getSprite()->getGlobalBounds();

            for (int j = 0; j < (int)listaEntidades->size(); j++)
            {
                Entidades::Obstaculos::Plataforma* pPlat =
                    dynamic_cast<Entidades::Obstaculos::Plataforma*>((*listaEntidades)[j]);

                if (pPlat == NULL) continue;

                sf::FloatRect caixaPlat = pPlat->getSprite()->getGlobalBounds();
                sf::FloatRect inter;

                if (caixaInimigo.intersects(caixaPlat, inter))
                {
                    if (inter.width > inter.height)
                    {
                        if (pInimigo->getY() < pPlat->getY())
                        {
                            pInimigo->setY(pInimigo->getY() - inter.height);
                            pInimigo->setVelY(0.0f);
                            pInimigo->setNoChao(true);
                        }
                        else
                        {
                            pInimigo->setY(pInimigo->getY() + inter.height);
                            pInimigo->setVelY(0.0f);
                        }
                    }
                    else
                    {
                        if (pInimigo->getX() < pPlat->getX())
                            pInimigo->setX(pInimigo->getX() - inter.width);
                        else
                            pInimigo->setX(pInimigo->getX() + inter.width);
                    }

                    caixaInimigo = pInimigo->getSprite()->getGlobalBounds();
                }
            }
        }
    }
}
