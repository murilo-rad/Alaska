#include "Alaskapp.h"
#include "Gerenciador_Eventos.h"
#include "Menu.h"

using namespace Alaska;

Alaska::Alaskapp::Alaskapp() : GG(), pJog1(nullptr), pJog2(nullptr), pFaseSelecionada(nullptr), pFase(nullptr), faseEscolhida(TipoFase::NENHUMA), estado(EstadoJogo::MENU), qntd_pontos(0)
{
    executar();
}

Alaska::Alaskapp::~Alaskapp() {}

//
//void Alaska::Alaskapp::executar()
//{
//    sementear();
//
//    Gerenciadores::Gerenciador_Eventos GE;
//    Ente::setGG(&GG);
//    GE.setJanela(GG.getJanela());
//
//    Alaska::Menu menu(this, &GE);
//    GE.setMenu(&menu);
//    menu.executar();
//    //printf("Menu finalizado %d\n", menu.getOpcao());
//    int faseInicial = menu.getOpcao() + 1;
//    GE.setMenu(nullptr);
//    GE.setJogadores(pJog1, pJog2);
//
//    const int totalFases = 2;
//    for (int i = faseInicial; i <= totalFases; i++)
//    {
//        if (!GG.isJanelaAberta() || !verificarJogadores()) break;
//
//        if (!pFaseSelecionada)
//            pFaseSelecionada = criarFase(i);
//
//        executarFase(GE, i);
//    }
//}

void Alaskapp::executar()
{
    sementear();

    Gerenciadores::Gerenciador_Eventos GE;
    Ente::setGG(&GG);
    Alaska::Menu menu(this, &GE);
    GE.setJanela(GG.getJanela());

    GE.setMenu(&menu);

    while (GG.isJanelaAberta())
    {
        switch (estado)
        {
        case EstadoJogo::MENU:
            executarMenu(&menu, GE);
            break;

        case EstadoJogo::FASE:
            executarFase(GE);
            break;

        case EstadoJogo::ENCERRANDO:
            return;
        }
    }
}

void Alaska::Alaskapp::sementear()
{
    srand(time(NULL));
}

void Alaska::Alaskapp::criarJogadores(int qntd)
{
	if (qntd == 1) {
		pJog1 = new Entidades::Personagens::Jogador(1);
	}
	else if (qntd == 2) {
		pJog1 = new Entidades::Personagens::Jogador(1);
		pJog2 = new Entidades::Personagens::Jogador(2);
	}
}

bool Alaska::Alaskapp::verificarJogadores() const
{
    if (pJog1 && pJog1->estaVivo() && (!pJog2 || pJog2->estaVivo()))
        return true;
    return false;
}

void Alaskapp::executarFase(Gerenciadores::Gerenciador_Eventos& GE)
{
    if (!pFase) return;

    if (pJog1) pJog1->resetar();
    if (pJog2) pJog2->resetar();

    GE.setJogadores(pJog1, pJog2);
    pFase->iniciarFase(faseEscolhida == TipoFase::CAVERNA ? 2 : 1);

    while (GG.isJanelaAberta() && verificarJogadores() && !pFase->terminou())
    {
        GE.verificarEventos();
        GG.limpar();
        pFase->executar();
        GG.mostrarPontos(qntd_pontos);
        GG.mostrar();
        qntd_pontos = pJog1->getPontos() + (pJog2 ? pJog2->getPontos() : 0);
    }

    delete pFase;
    pFase = nullptr;

    GE.setMenu(nullptr);
    estado = EstadoJogo::MENU;
}

Alaska::Fases::Fase* Alaska::Alaskapp::criarFase(short numFase)
{
    switch (numFase)
    {
    case 1: return new Fases::Tundra(pJog1, pJog2);
    case 2: return new Fases::Caverna(pJog1, pJog2);
    default: return nullptr;
    }
}

void Alaskapp::executarMenu(Alaska::Menu* pMenu, Gerenciadores::Gerenciador_Eventos& GE)
{
    GE.setMenu(pMenu);

    pMenu->reset();
    pMenu->executar();

    criarFaseSelecionada();
    estado = EstadoJogo::FASE;
}

void Alaskapp::criarFaseSelecionada()
{
    delete pFase;
    pFase = nullptr;

    switch (faseEscolhida)
    {
    case TipoFase::TUNDRA:

        pFase = new Fases::Tundra(
            pJog1,
            pJog2
        );

        break;

    case TipoFase::CAVERNA:

        pFase = new Fases::Caverna(
            pJog1,
            pJog2
        );

        break;

    default:
        break;
    }
}