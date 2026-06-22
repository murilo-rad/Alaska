#include "ListaEntidades.h"

Alaska::Listas::ListaEntidades::RelacaoInimigoJogador::RelacaoInimigoJogador()
    : pInimigo(nullptr), idJogador(0)
{
}

Alaska::Listas::ListaEntidades::RelacaoInimigoJogador::RelacaoInimigoJogador(
    Alaska::Entidades::Personagens::Inimigo* pInimigo,
    int idJogador
)
    : pInimigo(pInimigo), idJogador(idJogador)
{
}

Alaska::Listas::ListaEntidades::RelacaoInimigoJogador::~RelacaoInimigoJogador()
{
}

Alaska::Entidades::Personagens::Inimigo* Alaska::Listas::ListaEntidades::RelacaoInimigoJogador::getInimigo() const
{
    return pInimigo;
}

int Alaska::Listas::ListaEntidades::RelacaoInimigoJogador::getIdJogador() const
{
    return idJogador;
}
