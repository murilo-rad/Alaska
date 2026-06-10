#include "Gerenciador_Colisoes.h"

// Alaska::Gerenciadores::Gerenciador_Colisoes::Gerenciador_Colisoes() : pJog1(nullptr), pListaEntidades(nullptr) {}
// usado para testes

Alaska::Gerenciadores::Gerenciador_Colisoes::Gerenciador_Colisoes() : LIs(), LOs(), pJog1(), pChao()
{
}

Alaska::Gerenciadores::Gerenciador_Colisoes::~Gerenciador_Colisoes() {}

void Alaska::Gerenciadores::Gerenciador_Colisoes::executar()
{
    tratarColisoesChao();
    tratarColisoesJogsObstacs();
    tratarColisoesJogsInimigs();
    tratarColisoesInimigosObstacs();
    limparMortos();
}

const bool Alaska::Gerenciadores::Gerenciador_Colisoes::verificarColisao(Alaska::Entidades::Entidade *pE1, Alaska::Entidades::Entidade *pE2)const
{
    if(pE1 && pE2)
    {
        sf::FloatRect caixa1 = pE1->getSprite()->getGlobalBounds();
        sf::FloatRect caixa2 = pE2->getSprite()->getGlobalBounds();
        return caixa1.intersects(caixa2);
    }
    return false;
}

void Alaska::Gerenciadores::Gerenciador_Colisoes::incluirInimigo(Alaska::Entidades::Personagens::Inimigo *pIni)
{
    if (pIni)
        LIs.push_back(pIni);
}

void Alaska::Gerenciadores::Gerenciador_Colisoes::incluirObstaculo(Alaska::Entidades::Obstaculos::Obstaculo *pObs)
{
    if (pObs)
        LOs.push_back(pObs);
}

void Alaska::Gerenciadores::Gerenciador_Colisoes::setJogadorUm(Alaska::Entidades::Personagens::Jogador *pJ1)
{
    pJog1 = pJ1;
}

void Alaska::Gerenciadores::Gerenciador_Colisoes::incluirChao(Alaska::Entidades::Chao *pCh)
{
    if (pCh)
        pChao = pCh;
}

void Alaska::Gerenciadores::Gerenciador_Colisoes::tratarColisoesJogsObstacs()
{
    if (!LOs.empty())
    {
        Alaska::Entidades::Obstaculos::Obstaculo *pObs;
        pObs = nullptr;

        std::list<Alaska::Entidades::Obstaculos::Obstaculo *>::iterator it;
        it = LOs.begin();

        while (it != LOs.end())
        {
            pObs = (*it);
            if (pObs)
                if (verificarColisao(pJog1, pObs))
                    pObs->obstaculizar(pJog1);
            pObs = nullptr;
            it++;
        }
        delete pObs;
    }
}

void Alaska::Gerenciadores::Gerenciador_Colisoes::tratarColisoesInimigosObstacs()
{
    if (!LIs.empty() && !LOs.empty())
    {
        Alaska::Entidades::Obstaculos::Obstaculo *pObs;
        pObs = nullptr;
        std::list<Alaska::Entidades::Obstaculos::Obstaculo *>::iterator itObs;

        Alaska::Entidades::Personagens::Inimigo *pIni;
        pIni = nullptr;
        std::vector<Alaska::Entidades::Personagens::Inimigo *>::iterator itIni;

        itObs = LOs.begin();
        while (itObs != LOs.end())
        {
            itIni = LIs.begin();
            pObs = (*itObs);
            if (pObs)
                while (itIni != LIs.end())
                {

                    pIni = (*itIni);
                    if (pIni)
                    {
                        if (verificarColisao(pIni, pObs))
                            pObs->obstaculizarInimigo(pIni);
                    }
                    pIni = nullptr;
                    itIni++;
                }
            pObs = nullptr;
            itObs++;
        }
        delete pIni;
        delete pObs;
    }
}

void Alaska::Gerenciadores::Gerenciador_Colisoes::tratarColisoesJogsInimigs()
{
    if (!LIs.empty())
    {
        Alaska::Entidades::Personagens::Inimigo *pIni;
        pIni = nullptr;

        std::vector<Alaska::Entidades::Personagens::Inimigo *>::iterator it;
        it = LIs.begin();

        while (it != LIs.end())
        {
            pIni = (*it);
            if (pIni)
                if (verificarColisao(pJog1, pIni))
                    pJog1->colidir(pIni);
            pIni = nullptr;
            it++;
        }
        delete pIni;
    }
}

void Alaska::Gerenciadores::Gerenciador_Colisoes::tratarColisoesChao()
{
    if (pChao)
    {
        if (pJog1)
            if (verificarColisao(pJog1, pChao))
                pChao->empurrar(pJog1);

        if (!LIs.empty())
        {
            Alaska::Entidades::Personagens::Inimigo *pIni;
            pIni = nullptr;

            std::vector<Alaska::Entidades::Personagens::Inimigo *>::iterator it;
            it = LIs.begin();

            while (it != LIs.end())
            {
                pIni = (*it);
                if (pIni)
                    if (verificarColisao(pIni, pChao))
                        pChao->empurrar(pIni);
                pIni = nullptr;
                it++;
            }
            delete pIni;
        }
    }
}

void Alaska::Gerenciadores::Gerenciador_Colisoes::removerInimigo(Alaska::Entidades::Personagens::Inimigo *pIni)
{
    for (auto it = LIs.begin(); it != LIs.end();)
    {
        if (*it == pIni)
            it = LIs.erase(it);
        else
            ++it;
    }
}

void Alaska::Gerenciadores::Gerenciador_Colisoes::limparMortos()
{
    for (auto it = LIs.begin(); it != LIs.end(); )
    {
        if (*it == nullptr || !(*it)->estaVivo())
            it = LIs.erase(it);
        else
            ++it;
    }
}