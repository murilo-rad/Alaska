#include "ListaEntidades.h"
#include "Chao.h"
#include "Plataforma.h"
#include "Gelo.h"
#include "Conjunto_Estalagmites.h"
#include "Nevoso.h"
#include "Lobo.h"
#include "Abominavel.h"
#include "Bola_de_Neve.h"
#include "Gerenciador_Colisoes.h"



Alaska::Listas::ListaEntidades::ListaEntidades() : LEs() {}

Alaska::Listas::ListaEntidades::~ListaEntidades() {}

void Alaska::Listas::ListaEntidades::incluir(Alaska::Entidades::Entidade *pE)
{
    if (!pE)
        return;
    LEs.inserirNoFim(pE);
}

void Alaska::Listas::ListaEntidades::remover(Alaska::Entidades::Entidade *pE)
{
    if (!pE)
        return;
    LEs.removerE(pE);
}

Alaska::Listas::Lista<Alaska::Entidades::Entidade *> *Alaska::Listas::ListaEntidades::getLista()
{
    return &LEs;
}

void Alaska::Listas::ListaEntidades::percorrer()
{
    for (Lista<Alaska::Entidades::Entidade *>::Iterador it = LEs.begin(); it != LEs.end(); ++it)
    {
        if (*it)
            (*it)->executar();
    }
}

void Alaska::Listas::ListaEntidades::desenharEntidades()
{
    for (Lista<Alaska::Entidades::Entidade *>::Iterador it = LEs.begin(); it != LEs.end(); ++it)
    {
        if (*it)
            (*it)->desenhar();
    }
}

void Alaska::Listas::ListaEntidades::cemiterio()
{
    for (Lista<Alaska::Entidades::Entidade *>::Iterador it = LEs.begin(); it != LEs.end();)
    {
        auto atual = it++;

        auto *p = dynamic_cast<Entidades::Personagens::Personagem *>(*atual);
        if (p && !p->estaVivo())
        {
            Entidades::Entidade *ptr = *atual;
            LEs.removerE(ptr);
            if (!dynamic_cast<Entidades::Personagens::Jogador *>(ptr))
                delete ptr;
        }
    }
}

void Alaska::Listas::ListaEntidades::salvarEntidades()
{
    garantirPastaSaveAlaska();
    std::ofstream limpar(CAMINHO_SAVE, std::ios::trunc);
    limpar.close();

    for (Lista<Alaska::Entidades::Entidade *>::Iterador it = LEs.begin(); it != LEs.end(); ++it)
    {
        if (*it)
            (*it)->salvar();
    }
}

std::vector<std::string> Alaska::Listas::ListaEntidades::dividirPorVirgula(const std::string &linha)
{
    std::vector<std::string> dados;
    std::stringstream ss(linha);
    std::string item;

    while (std::getline(ss, item, ','))
        dados.push_back(item);

    return dados;
}

int Alaska::Listas::ListaEntidades::paraInt(const std::string &str)
{
    return std::stoi(str);
}

float Alaska::Listas::ListaEntidades::paraFloat(const std::string &str)
{
    return std::stof(str);
}

bool Alaska::Listas::ListaEntidades::paraBool(const std::string &str)
{
    return str == "1" || str == "true" || str == "True";
}

void Alaska::Listas::ListaEntidades::restaurarEntidade(
    Alaska::Entidades::Entidade *pE,
    const std::vector<std::string> &d,
    int i)
{
    if (!pE)
        return;

    pE->setX(paraFloat(d[i]));
    pE->setY(paraFloat(d[i + 1]));
    pE->setVelX(paraFloat(d[i + 2]));
    pE->setVelY(paraFloat(d[i + 3]));
}

void Alaska::Listas::ListaEntidades::restaurarPersonagem(
    Alaska::Entidades::Personagens::Personagem *pP,
    const std::vector<std::string> &d,
    int i)
{
    if (!pP)
        return;

    pP->setVidas(paraInt(d[i]));
    pP->setNoChao(paraBool(d[i + 1]));
    pP->setMorto(paraBool(d[i + 2]));
}

void Alaska::Listas::ListaEntidades::restaurarInimigo(
    Alaska::Entidades::Personagens::Inimigo *pI,
    const std::vector<std::string> &d,
    int i,
    int &idJogador)
{
    if (!pI)
        return;

    pI->setMaldade(paraInt(d[i]));
    idJogador = paraInt(d[i + 1]);
    pI->setIdJogador(idJogador);
    pI->setVelocidade(paraFloat(d[i + 2]));
}

void Alaska::Listas::ListaEntidades::registrarNoGerenciador(
    Alaska::Entidades::Entidade *pE,
    Alaska::Gerenciadores::Gerenciador_Colisoes *pGC)
{
    if (!pE || !pGC)
        return;

    if (auto *pChao = dynamic_cast<Alaska::Entidades::Chao *>(pE))
    {
        pGC->incluirChao(pChao);
    }
    else if (auto *pInimigo = dynamic_cast<Alaska::Entidades::Personagens::Inimigo *>(pE))
    {
        pGC->incluirInimigo(pInimigo);
    }
    else if (auto *pBola = dynamic_cast<Alaska::Entidades::Bola_de_Neve *>(pE))
    {
        pGC->incluirProjetil(pBola);
    }
    else if (auto *pObstaculo = dynamic_cast<Alaska::Entidades::Obstaculos::Obstaculo *>(pE))
    {
        pGC->incluirObstaculo(pObstaculo);
    }
}

void Alaska::Listas::ListaEntidades::carregarEntidades(
    Alaska::Entidades::Personagens::Jogador *pJogador1,
    Alaska::Entidades::Personagens::Jogador *pJogador2,
    Alaska::Gerenciadores::Gerenciador_Colisoes *pGC)
{
    std::ifstream arquivo(CAMINHO_SAVE);

    if (!arquivo.is_open())
    {
        printf("Erro: arquivo de salvamento nao encontrado.\n");
        return;
    }

    std::map<int, Alaska::Entidades::Entidade *> entidadesPorId;
    std::vector<RelacaoInimigoJogador> relacoesInimigoJogador;
    std::vector<RelacaoAbominavelBola> relacoesAbominavelBola;
    std::vector<RelacaoBolaAbominavel> relacoesBolaAbominavel;

    if (pJogador1)
        entidadesPorId[pJogador1->getID()] = pJogador1;
    if (pJogador2)
        entidadesPorId[pJogador2->getID()] = pJogador2;

    std::string linha;
    int jogadoresCarregados = 0;

    while (std::getline(arquivo, linha))
    {
        if (linha.empty())
            continue;

        std::vector<std::string> d = dividirPorVirgula(linha);

        if (d.empty())
            continue;

        try
        {
            const int tipo = paraInt(d[0]);
            int id = 0;
            Alaska::Entidades::Entidade *pEntidade = nullptr;

            switch (tipo)
            {
            case IND_CHAO:
            {
                // IND_CHAO, fase, id, x, y, velX, velY
                if (d.size() < 7)
                {
                    printf("Erro: dados incompletos para Chao.\n");
                    break;
                }

                const short fase = static_cast<short>(paraInt(d[1]));
                id = paraInt(d[2]);

                auto *pChao = new Alaska::Entidades::Chao(fase);
                pChao->setID(id);
                restaurarEntidade(pChao, d, 3);

                pEntidade = pChao;
                break;
            }

            case IND_PLAT:
            {
                // IND_PLAT, largura, id, danoso, x, y, velX, velY
                if (d.size() < 8)
                {
                    printf("Erro: dados incompletos para Plataforma.\n");
                    break;
                }

                id = paraInt(d[2]);

                auto *pPlat = new Alaska::Entidades::Obstaculos::Plataforma();
                pPlat->setLargura(paraInt(d[1]));
                pPlat->setID(id);
                pPlat->setDanoso(paraBool(d[3]));
                restaurarEntidade(pPlat, d, 4);

                pEntidade = pPlat;
                break;
            }

            case IND_GELO:
            {
                // IND_GELO, atrito, id, danoso, x, y, velX, velY
                if (d.size() < 8)
                {
                    printf("Erro: dados incompletos para Gelo.\n");
                    break;
                }

                id = paraInt(d[2]);

                auto *pGelo = new Alaska::Entidades::Obstaculos::Gelo();
                pGelo->setAtrito(paraFloat(d[1]));
                pGelo->setID(id);
                pGelo->setDanoso(paraBool(d[3]));
                restaurarEntidade(pGelo, d, 4);

                pEntidade = pGelo;
                break;
            }

            case IND_MITE:
            {
                // IND_MITE, danosidade, id, danoso, x, y, velX, velY
                if (d.size() < 8)
                {
                    printf("Erro: dados incompletos para Conjunto_Estalagmites.\n");
                    break;
                }

                id = paraInt(d[2]);

                auto *pMite = new Alaska::Entidades::Obstaculos::Conjunto_Estalagmites();
                pMite->setDanosidade(static_cast<short int>(paraInt(d[1])));
                pMite->setID(id);
                pMite->setDanoso(paraBool(d[3]));
                restaurarEntidade(pMite, d, 4);

                pEntidade = pMite;
                break;
            }

            case IND_NEV:
            {
                // Formato atual:
                // IND_NEV, acumulacao, id, nivel_maldade, idJogador, velocidade,
                // num_vidas, noChao, vivo, x, y, velX, velY
                if (d.size() < 10)
                {
                    printf("Erro: dados incompletos para Nevoso.\n");
                    break;
                }

                id = paraInt(d[2]);
                int idJogador = 0;

                auto *pNevoso = new Alaska::Entidades::Personagens::Nevoso();
                pNevoso->setAcumulacao(paraFloat(d[1]));
                pNevoso->setID(id);

                restaurarInimigo(pNevoso, d, 3, idJogador);

                if (d.size() >= 13)
                {
                    restaurarPersonagem(pNevoso, d, 6);
                    restaurarEntidade(pNevoso, d, 9);
                }
                else
                {
                    restaurarEntidade(pNevoso, d, 6);
                }

                const float tamanho = paraFloat(d[1]);
                if (tamanho > 0.0f)
                    pNevoso->ajustarSprite(*pNevoso->getSprite(), tamanho, tamanho);

                relacoesInimigoJogador.push_back({pNevoso, idJogador});
                pEntidade = pNevoso;
                break;
            }

            case IND_LOBO:
            {
                // Formato atual:
                // IND_LOBO, voracidade, id, nivel_maldade, idJogador, velocidade,
                // num_vidas, noChao, vivo, x, y, velX, velY
                // Formato antigo quebrado: sem num_vidas/noChao/vivo.
                if (d.size() < 10)
                {
                    printf("Erro: dados incompletos para Lobo.\n");
                    break;
                }

                id = paraInt(d[2]);
                int idJogador = 0;

                auto *pLobo = new Alaska::Entidades::Personagens::Lobo();
                pLobo->setVoracidade(paraInt(d[1]));
                pLobo->setID(id);

                restaurarInimigo(pLobo, d, 3, idJogador);

                if (d.size() >= 13)
                {
                    restaurarPersonagem(pLobo, d, 6);
                    restaurarEntidade(pLobo, d, 9);
                }
                else
                {
                    restaurarEntidade(pLobo, d, 6);
                }

                relacoesInimigoJogador.push_back({pLobo, idJogador});
                pEntidade = pLobo;
                break;
            }

            case IND_ABM:
            {
                // Formato atual:
                // IND_ABM, idBola, forca, id, nivel_maldade, idJogador, velocidade,
                // num_vidas, noChao, vivo, x, y, velX, velY
                // Formato antigo quebrado: sem num_vidas/noChao/vivo.
                if (d.size() < 11)
                {
                    printf("Erro: dados incompletos para Abominavel.\n");
                    break;
                }

                const int idBola = paraInt(d[1]);
                id = paraInt(d[3]);
                int idJogador = 0;

                auto *pAbo = new Alaska::Entidades::Personagens::Abominavel();
                pAbo->setIdBola(idBola);
                pAbo->setForca(paraInt(d[2]));
                pAbo->setID(id);

                restaurarInimigo(pAbo, d, 4, idJogador);

                if (d.size() >= 14)
                {
                    restaurarPersonagem(pAbo, d, 7);
                    restaurarEntidade(pAbo, d, 10);
                }
                else
                {
                    restaurarEntidade(pAbo, d, 7);
                }

                relacoesInimigoJogador.push_back({pAbo, idJogador});
                relacoesAbominavelBola.push_back({pAbo, idBola});
                pEntidade = pAbo;
                break;
            }

            case IND_BOLA:
            {
                // IND_BOLA, idAbominavel, ativo, id, x, y, velX, velY
                if (d.size() < 8)
                {
                    printf("Erro: dados incompletos para Bola_de_Neve.\n");
                    break;
                }

                const int idAbominavel = paraInt(d[1]);
                id = paraInt(d[3]);

                auto *pBola = new Alaska::Entidades::Bola_de_Neve();
                pBola->setIdAbominavel(idAbominavel);
                pBola->setAtivo(paraBool(d[2]));
                pBola->setID(id);
                restaurarEntidade(pBola, d, 4);

                relacoesBolaAbominavel.push_back({pBola, idAbominavel});
                pEntidade = pBola;
                break;
            }

            case IND_JOG:
            {
                // IND_JOG, pontos, nome, id,
                // num_vidas, noChao, vivo,
                // x, y, velX, velY
                if (d.size() < 11)
                {
                    printf("Erro: dados incompletos para Jogador.\n");
                    break;
                }

                Alaska::Entidades::Personagens::Jogador *pJogador = nullptr;

                if (jogadoresCarregados == 0)
                    pJogador = pJogador1;
                else if (jogadoresCarregados == 1)
                    pJogador = pJogador2;

                jogadoresCarregados++;

                if (!pJogador)
                {
                    printf("Aviso: jogador salvo ignorado, pois nao existe jogador correspondente.\n");
                    break;
                }

                id = paraInt(d[3]);
                pJogador->setPontos(paraInt(d[1]));
                pJogador->setNome(d[2]);
                pJogador->setID(id);

                restaurarPersonagem(pJogador, d, 4);
                restaurarEntidade(pJogador, d, 7);

                entidadesPorId[id] = pJogador;
                break;
            }

            default:
                printf("Aviso: tipo de entidade desconhecido: %d\n", tipo);
                break;
            }

            if (pEntidade)
            {
                entidadesPorId[id] = pEntidade;
                incluir(pEntidade);
                registrarNoGerenciador(pEntidade, pGC);
            }
        }
        catch (const std::exception &e)
        {
            printf("Erro ao carregar linha do save: %s\n", e.what());
        }
    }

    arquivo.close();

    for (auto &rel : relacoesInimigoJogador)
    {
        if (!rel.pInimigo)
            continue;

        auto it = entidadesPorId.find(rel.idJogador);
        if (it != entidadesPorId.end())
        {
            auto *pJogador = dynamic_cast<Alaska::Entidades::Personagens::Jogador *>(it->second);
            if (pJogador)
            {
                rel.pInimigo->setJogador(pJogador);
                continue;
            }
        }

        rel.pInimigo->setJogador(pJogador1);
    }

    for (auto &rel : relacoesBolaAbominavel)
    {
        if (!rel.pBola)
            continue;

        auto it = entidadesPorId.find(rel.idAbominavel);
        if (it != entidadesPorId.end())
        {
            auto *pAbo = dynamic_cast<Alaska::Entidades::Personagens::Abominavel *>(it->second);
            if (pAbo)
            {
                rel.pBola->setAbominavel(pAbo);
                pAbo->setBola(rel.pBola);
            }
        }
    }

    for (auto &rel : relacoesAbominavelBola)
    {
        if (!rel.pAbominavel)
            continue;

        auto it = entidadesPorId.find(rel.idBola);
        if (it != entidadesPorId.end())
        {
            auto *pBola = dynamic_cast<Alaska::Entidades::Bola_de_Neve *>(it->second);
            if (pBola)
            {
                rel.pAbominavel->setBola(pBola);
                pBola->setAbominavel(rel.pAbominavel);
            }
        }
    }
    printf("Entidades carregadas com sucesso.\n");
}