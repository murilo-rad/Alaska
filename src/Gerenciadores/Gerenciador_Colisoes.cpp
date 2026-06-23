#include "Gerenciador_Colisoes.h"

// Alaska::Gerenciadores::Gerenciador_Colisoes::Gerenciador_Colisoes() : pJog1(nullptr), pListaEntidades(nullptr) {}
// usado para testes

Alaska::Gerenciadores::Gerenciador_Colisoes::Gerenciador_Colisoes() : LIs(), LOs(), pJog1(nullptr), pJog2(nullptr), pChao(nullptr)
{
}

Alaska::Gerenciadores::Gerenciador_Colisoes::~Gerenciador_Colisoes()
{
    pJog1 = nullptr;
    LIs.clear();
    LOs.clear();
    LPs.clear();
}

void Alaska::Gerenciadores::Gerenciador_Colisoes::executar()
{
    tratarColisoesChao();
    tratarColisoesJogsObstacs();
    tratarColisoesJogsInimigs();
    tratarColisoesJogsProjeteis();
    tratarColisoesInimigosObstacs();
    tratarColisoesInimigosInimigos();
    tratarColisoesParedeInvisivel();
    limparMortos();
}

const bool Alaska::Gerenciadores::Gerenciador_Colisoes::verificarColisao(Alaska::Entidades::Entidade *pE1, Alaska::Entidades::Entidade *pE2) const
{
    if (pE1 && pE2)
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

void Alaska::Gerenciadores::Gerenciador_Colisoes::incluirProjetil(Alaska::Entidades::Bola_de_Neve *pProj)
{
    if (pProj)
        LPs.insert(pProj);
}

void Alaska::Gerenciadores::Gerenciador_Colisoes::setJogadorUm(Alaska::Entidades::Personagens::Jogador *pJ1)
{
    pJog1 = pJ1;
}

void Alaska::Gerenciadores::Gerenciador_Colisoes::setJogadorDois(Alaska::Entidades::Personagens::Jogador *pJ2)
{
    pJog2 = pJ2;
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
            {
                if (pJog1)
                    if (verificarColisao(pJog1, pObs))
                        pObs->obstaculizar(pJog1);

                if (pJog2)
                    if (verificarColisao(pJog2, pObs))
                        pObs->obstaculizar(pJog2);
            }
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
                        if (dynamic_cast<Alaska::Entidades::Personagens::Abominavel *>(pIni) &&
                            dynamic_cast<Alaska::Entidades::Obstaculos::Conjunto_Estalagmites *>(pObs))
                        {}  // nao acontece a colisao
                        else
                        {
                            if (verificarColisao(pIni, pObs))
                                pObs->obstaculizarInimigo(pIni);
                        }
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
            {
                if (pJog1)
                    if (verificarColisao(pJog1, pIni))
                        pJog1->colidir(pIni);

                if (pJog2)
                    if (verificarColisao(pJog2, pIni))
                        pJog2->colidir(pIni);
                pIni = nullptr;
                it++;
            }
            delete pIni;
        }
    }
}

void Alaska::Gerenciadores::Gerenciador_Colisoes::tratarColisoesJogsProjeteis()
{
    if (!LPs.empty())
    {
        Alaska::Entidades::Bola_de_Neve *pBola;
        pBola = nullptr;

        std::set<Alaska::Entidades::Bola_de_Neve *>::iterator it;
        it = LPs.begin();

        while (it != LPs.end())
        {
            pBola = (*it);
            if (pBola)
            {
                if (pJog1)
                    if (verificarColisao(pJog1, pBola))
                        pBola->acertar(pJog1);

                if (pJog2)
                    if (verificarColisao(pJog2, pBola))
                        pBola->acertar(pJog2);
            }
            pBola = nullptr;
            it++;
        }
        delete pBola;
    }
}

void Alaska::Gerenciadores::Gerenciador_Colisoes::tratarColisoesInimigosInimigos()
{
    if (!LIs.empty())
    {
        Alaska::Entidades::Personagens::Inimigo *pIni1;
        pIni1 = nullptr;
        std::vector<Alaska::Entidades::Personagens::Inimigo *>::iterator itIni1;
        Alaska::Entidades::Personagens::Inimigo *pIni2;
        pIni2 = nullptr;
        std::vector<Alaska::Entidades::Personagens::Inimigo *>::iterator itIni2;
        itIni1 = LIs.begin();
        while (itIni1 != LIs.end())
        {
            itIni2 = LIs.begin();
            pIni1 = (*itIni1);
            if (pIni1)
                while (itIni2 != LIs.end())
                {
                    pIni2 = (*itIni2);
                    if (pIni2 && pIni1 != pIni2)
                    {
                        if (verificarColisao(pIni1, pIni2))
                        {
                            pIni1->impedirSobrePosicao(pIni2);
                        }
                    }
                    pIni2 = nullptr;
                    itIni2++;
                }
            pIni1 = nullptr;
            itIni1++;
        }
        delete pIni1;
        delete pIni2;
    }
}

void Alaska::Gerenciadores::Gerenciador_Colisoes::tratarColisoesChao()
{
    if (pChao)
    {
        if (pJog1)
            if (verificarColisao(pJog1, pChao))
                pChao->empurrar(pJog1);
        if (pJog2)
            if (verificarColisao(pJog2, pChao))
                pChao->empurrar(pJog2);

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

void Alaska::Gerenciadores::Gerenciador_Colisoes::limparMortos()
{
    for (auto it = LIs.begin(); it != LIs.end();)
    {
        if (*it == nullptr || !(*it)->estaVivo())
            it = LIs.erase(it);
        else
            ++it;
    }
}

void Alaska::Gerenciadores::Gerenciador_Colisoes::tratarColisoesParedeInvisivel()
{
    for (auto *pIni : LIs)
    {
        if (!pIni)
            continue;
        if (pIni->getX() < 0)
            pIni->setX(1);
        else if (pIni->getX() + pIni->getSprite()->getGlobalBounds().width > L_TELA)
            pIni->setX(L_TELA - pIni->getSprite()->getGlobalBounds().width);
    }

    if (pJog1)
    {
        if (pJog1->getX() <= 0)
            pJog1->setX(1);
        else if (pJog1->getX() + pJog1->getSprite()->getGlobalBounds().width > L_TELA)
            pJog1->setX(L_TELA - pJog1->getSprite()->getGlobalBounds().width);
    }

    if (pJog2)
    {
        if (pJog2->getX() <= 0)
            pJog2->setX(1);
        else if (pJog2->getX() + pJog2->getSprite()->getGlobalBounds().width > L_TELA)
            pJog2->setX(L_TELA - pJog2->getSprite()->getGlobalBounds().width);
    }
}

int Alaska::Gerenciadores::Gerenciador_Colisoes::getQtdInimigos() const
{ 
    return (int)LIs.size(); 
}
