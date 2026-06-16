#include "Alaskapp.h"
#include "Gerenciador_Eventos.h"

using namespace Alaska;

Alaska::Alaskapp::Alaskapp() : GG(), pJog1(nullptr), pJog2(nullptr), pFaseSelecionada(nullptr), qntd_pontos(0)
{
    executar();
}

Alaska::Alaskapp::~Alaskapp() {}


void Alaska::Alaskapp::executar()
{
    sementear();

    Gerenciadores::Gerenciador_Eventos GE;
    Ente::setGG(&GG);
    GE.setJanela(GG.getJanela());

    Alaska::Menu menu(this, &GE);
    GE.setMenu(&menu);
    menu.executar();
    printf("Menu finalizado %d\n", menu.getOpcao());
    int faseInicial = menu.getOpcao() + 1;
    GE.setMenu(nullptr);
    GE.setJogadores(pJog1, pJog2);

    const int totalFases = 2;
    for (int i = faseInicial; i <= totalFases; i++)
    {
        if (!GG.isJanelaAberta() || !verificarJogadores()) break;

        if (!pFaseSelecionada)
            pFaseSelecionada = criarFase(i);

        executarFase(GE, i);
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

void Alaska::Alaskapp::executarFase(Gerenciadores::Gerenciador_Eventos& GE, short numFase)
{
    if (!pFaseSelecionada) return;

    if (pJog1) pJog1->resetar();
    if (pJog2) pJog2->resetar();

    pFaseSelecionada->iniciarFase(numFase);

    while (GG.isJanelaAberta() && verificarJogadores() && !pFaseSelecionada->faseTerminada()) {
        GE.verificarEventos();
        GG.limpar();
        pFaseSelecionada->executar();
        GG.mostrarPontos(qntd_pontos);
        GG.mostrar();
        qntd_pontos = pJog1->getPontos() + (pJog2 ? pJog2->getPontos() : 0);
    }
    
    delete pFaseSelecionada;
    pFaseSelecionada = nullptr;
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