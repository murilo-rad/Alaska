#include "ListaEntidades.h"

Alaska::Listas::ListaEntidades::RelacaoBolaAbominavel::RelacaoBolaAbominavel()
    : pBola(nullptr), idAbominavel(0)
{
}

Alaska::Listas::ListaEntidades::RelacaoBolaAbominavel::RelacaoBolaAbominavel(
    Alaska::Entidades::Bola_de_Neve* pBola,
    int idAbominavel
)
    : pBola(pBola), idAbominavel(idAbominavel)
{
}

Alaska::Listas::ListaEntidades::RelacaoBolaAbominavel::~RelacaoBolaAbominavel()
{
}

Alaska::Entidades::Bola_de_Neve* Alaska::Listas::ListaEntidades::RelacaoBolaAbominavel::getBola() const
{
    return pBola;
}

int Alaska::Listas::ListaEntidades::RelacaoBolaAbominavel::getIdAbominavel() const
{
    return idAbominavel;
}
