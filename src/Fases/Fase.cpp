#include "Fase.h"
#include "Gerenciador_Grafico.h"

Alaska::Fases::Fase::Fase() : max_Nevosos(0), max_Plataformas(0), pJogador1(nullptr), pJogador2(nullptr), GC(nullptr), pFundo(nullptr)
{
}

Alaska::Fases::Fase::Fase(int n, int p, Alaska::Entidades::Personagens::Jogador* pJ1, Alaska::Entidades::Personagens::Jogador* pJ2)
    : max_Nevosos(n), max_Plataformas(p), pJogador1(nullptr), pJogador2(nullptr), GC(nullptr), pFundo(nullptr)
{
    if(pJ1)
        pJogador1 = pJ1;
    GC = new Alaska::Gerenciadores::Gerenciador_Colisoes();
    GC->setJogadorUm(pJogador1);
	lista_ents.incluir(pJogador1);

    if (pJ2) {
		pJogador2 = pJ2;
		GC->setJogadorDois(pJ2);
		lista_ents.incluir(pJ2);
    }

    posPlataformas =
    {
        {100.f, 580.f},
        {350.f, 470.f},
        {650.f, 360.f},
        {950.f, 470.f},
        {1150.f, 300.f}
    };

    posNevosos =
    {
        {350.f, 370.f},   // plataforma {350,470}
        {1150.f, 200.f},  // plataforma {1150,300}
        {850.f, 668.f},
        {1080.f, 668.f},
        {1280.f, 668.f}
    };
}

Alaska::Fases::Fase::~Fase()
{
    auto* lista = lista_ents.getLista();

    for (auto it = lista->begin(); it != lista->end(); ++it)
    {
        if (*it && *it != pJogador1 && *it != pJogador2)
            delete *it;
    }

    delete GC;
    GC = nullptr;

    delete pFundo;
    pFundo = nullptr;

    pJogador1 = nullptr;
    pJogador2 = nullptr;
}

void Alaska::Fases::Fase::criarNevosos()
{
    int quantidade = ((rand()%max_Nevosos) + 1);
    if(quantidade < MIN)
        quantidade = MIN;

    Alaska::Entidades::Personagens::Inimigo* pInimigo;
    pInimigo = nullptr;

    for(int i = 0; i < quantidade; i++)
    {
        pInimigo = new Alaska::Entidades::Personagens::Nevoso(posNevosos[i].x, posNevosos[i].y, randJogador());
        if(pInimigo)
        {
            lista_ents.incluir(pInimigo);
            if(GC)
                GC->incluirInimigo(pInimigo);
        }
        pInimigo = nullptr;
    }
    delete pInimigo;
}

void Alaska::Fases::Fase::criarPlataformas()
{
    int quantidade = ((rand() % max_Plataformas) + 1);
    if (quantidade < MIN)
        quantidade = MIN;

    Alaska::Entidades::Obstaculos::Obstaculo* pObstaculo;
    pObstaculo = nullptr;
    for(int i = 0; i < quantidade; i++)
    {
        pObstaculo = new Alaska::Entidades::Obstaculos::Plataforma(posPlataformas[i].x, posPlataformas[i].y);
        if(pObstaculo)
        {
            lista_ents.incluir(pObstaculo);
            if(GC)
                GC->incluirObstaculo(pObstaculo);
        }
        pObstaculo = nullptr;
    }

    delete pObstaculo;
}

void Alaska::Fases::Fase::criarCenario(short fase)
{
    criarFundo(fase);
	criarChao(fase);
}

void Alaska::Fases::Fase::carregarFaseSalva(short fase)
{
    criarFundo(fase);
    lista_ents.carregarEntidades(pJogador1, pJogador2, GC);
}

void Alaska::Fases::Fase::desenharEstadoAtual()
{
    if (pFundo)
        pFundo->executar();
    lista_ents.desenharEntidades();
}

void Alaska::Fases::Fase::salvarEstado()
{
    lista_ents.salvarEntidades();
}

void Alaska::Fases::Fase::criarChao(short fase)
{
	Alaska::Entidades::Chao* pChao;
	pChao = nullptr;
	pChao = new Alaska::Entidades::Chao(fase);
	if (pChao)
	{
		lista_ents.incluir(pChao);
        if(GC)
            GC->incluirChao(pChao);
	}
}

void Alaska::Fases::Fase::criarFundo(short fase)
{
    pFundo = new Alaska::Fundo(A_FUNDO, L_FUNDO, fase);
}

void Alaska::Fases::Fase::gerarFase() {
	criarCenario(2);
	criarNevosos();
	criarPlataformas();
}

Alaska::Entidades::Personagens::Jogador* Alaska::Fases::Fase::randJogador()
{
    return (pJogador2 ? (rand() % 2) ? pJogador1 : pJogador2 : pJogador1);
}

bool Alaska::Fases::Fase::faseTerminada() const
{
    if (!GC) return false;
    return GC->getQtdInimigos() == 0;
}

const bool Alaska::Fases::Fase::terminou() {
    if (!GC || GC->getQtdInimigos() == 0 || !verificarJogadores())
        concluida = true;
    else
        concluida = false;

    return concluida;
}

const bool Alaska::Fases::Fase::verificarJogadores() const
{
    if (pJogador1 && pJogador1->estaVivo() && (!pJogador2 || pJogador2->estaVivo()))
        return true;
    return false;
}
