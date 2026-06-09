#include "Colisoes.h"

// Alaska::Gerenciadores::Colisoes::Colisoes() : pJog1(nullptr), pListaEntidades(nullptr) {}
// usado para testes

Alaska::Gerenciadores::Colisoes::Colisoes() : LIs(), LOs(), pJog1(), pChao()
{
}

Alaska::Gerenciadores::Colisoes::~Colisoes() {}

void Alaska::Gerenciadores::Colisoes::executar()
{
    limparMortos();
    tratarColisoesChao();
    tratarColisoesJogsObstacs();
    tratarColisoesJogsInimigs();
    tratarColisoesInimigosObstacs();
}

const bool Alaska::Gerenciadores::Colisoes::verificarColisao(Alaska::Entidades::Entidade *pE1, Alaska::Entidades::Entidade *pE2)const
{
    if(pE1 && pE2)
    {
        sf::FloatRect caixa1 = pE1->getSprite()->getGlobalBounds();
        sf::FloatRect caixa2 = pE2->getSprite()->getGlobalBounds();
        return caixa1.intersects(caixa2);
    }
    return false;
}

void Alaska::Gerenciadores::Colisoes::incluirInimigo(Alaska::Entidades::Personagens::Inimigo *pIni)
{
    if (pIni)
        LIs.push_back(pIni);
}

void Alaska::Gerenciadores::Colisoes::incluirObstaculo(Alaska::Entidades::Obstaculos::Obstaculo *pObs)
{
    if (pObs)
        LOs.push_back(pObs);
}

void Alaska::Gerenciadores::Colisoes::setJogadorUm(Alaska::Entidades::Personagens::Jogador *pJ1)
{
    pJog1 = pJ1;
}

void Alaska::Gerenciadores::Colisoes::setChao(Alaska::Entidades::Chao *pCh)
{
    if (pCh)
        pChao = pCh;
}

void Alaska::Gerenciadores::Colisoes::tratarColisoesJogsObstacs()
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

void Alaska::Gerenciadores::Colisoes::tratarColisoesInimigosObstacs()
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

void Alaska::Gerenciadores::Colisoes::tratarColisoesJogsInimigs()
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

void Alaska::Gerenciadores::Colisoes::tratarColisoesChao()
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

void Alaska::Gerenciadores::Colisoes::removerInimigo(Alaska::Entidades::Personagens::Inimigo *pIni)
{
    for (auto it = LIs.begin(); it != LIs.end();)
    {
        if (*it == pIni)
            it = LIs.erase(it);
        else
            ++it;
    }
}

void Alaska::Gerenciadores::Colisoes::limparMortos()
{
    for (auto it = LIs.begin(); it != LIs.end(); )
    {
        if (*it == nullptr || !(*it)->estaVivo())
            it = LIs.erase(it);
        else
            ++it;
    }
}

// void Alaska::Gerenciadores::Colisoes::tratarColisoesJogsProjeteis()
// {
// 	// Implementar
// }
//
// void Alaska::Gerenciadores::Colisoes::incluirProjetil()
//{
// Implementar
//}

// void Alaska::Gerenciadores::Colisoes::tratarColisoesJogsObstacs()
//  {
//      if(!pJog1) return;

//     auto lista = pListaEntidades->getLista();
//     for (auto it = lista->begin(); it != lista->end(); ++it)
//     {
//         Entidades::Entidade* pEnt = *it;
//         Entidades::Obstaculos::Obstaculo* pObs = dynamic_cast<Entidades::Obstaculos::Obstaculo*>(pEnt);

//         if (pObs && verificarColisao(pJog1, pObs))
//             pObs->obstaculizar(pJog1);
//     }
// }

// void Alaska::Gerenciadores::Colisoes::tratarColisoesJogsInimigs()
// {
//     if(!pJog1) return;

//     if (!pListaEntidades) return;

//     auto lista = pListaEntidades->getLista();

//     for (auto it1 = lista->begin(); it1 != lista->end(); ++it1)
//     {
//         Entidades::Entidade* pEnt1 = *it1;
//         Entidades::Personagens::Inimigo* pIni = dynamic_cast<Entidades::Personagens::Inimigo*>(pEnt1);

//         if (!pIni)
//             continue;

//         for (auto it2 = lista->begin(); it2 != lista->end(); ++it2)
//         {
//             Entidades::Entidade* pEnt2 = *it2;
//             Entidades::Obstaculos::Obstaculo* pObs = dynamic_cast<Entidades::Obstaculos::Obstaculo*>(pEnt2);

//             if (!pObs) continue;

//             sf::FloatRect caixaIni = pIni->getSprite()->getGlobalBounds();
//             sf::FloatRect caixaObs = pObs->getSprite()->getGlobalBounds();
//             sf::FloatRect inter;
//             if (caixaIni.intersects(caixaObs, inter))
//             {
//                 if (inter.width > inter.height)
//                     if (pIni->getVelY() > 0.0f)
//                         if (pIni->getY() < pObs->getY())
//                         {
//                             pIni->setY(pIni->getY() - inter.height);
//                             pIni->setVelY(0.0f);
//                             pIni->setNoChao(true);
//                         }
//             }
//         }
//     }

//     for (auto it = lista->begin(); it != lista->end(); ++it) {
//         Entidades::Entidade* pEnt = *it;
//         Entidades::Personagens::Inimigo* pIni = dynamic_cast<Entidades::Personagens::Inimigo*>(pEnt);

//         if (pIni && verificarColisao(pJog1, pIni))
//         {
//             sf::FloatRect caixaJog = pJog1->getSprite()->getGlobalBounds();
//             sf::FloatRect caixaIni = pIni->getSprite()->getGlobalBounds();

//             if(caixaJog.top + caixaJog.height < caixaIni.top + (caixaIni.height / 2.0f) && pJog1->getVelY() > 0.0f)
//             {
//                 pIni->setVida(0);
//                 pJog1->setVelY(-10.0f);
//             }
//             else
//                 pIni->danificar(pJog1);
//         }
//     }
// }