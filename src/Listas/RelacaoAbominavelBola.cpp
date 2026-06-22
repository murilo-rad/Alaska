#include "ListaEntidades.h"

Alaska::Listas::ListaEntidades::RelacaoAbominavelBola::RelacaoAbominavelBola()
    : pAbominavel(nullptr), idBola(0)
{
}

Alaska::Listas::ListaEntidades::RelacaoAbominavelBola::RelacaoAbominavelBola(
    Alaska::Entidades::Personagens::Abominavel* pAbominavel,
    int idBola
)
    : pAbominavel(pAbominavel), idBola(idBola)
{
}

Alaska::Listas::ListaEntidades::RelacaoAbominavelBola::~RelacaoAbominavelBola()
{
}

Alaska::Entidades::Personagens::Abominavel* Alaska::Listas::ListaEntidades::RelacaoAbominavelBola::getAbominavel() const
{
    return pAbominavel;
}

int Alaska::Listas::ListaEntidades::RelacaoAbominavelBola::getIdBola() const
{
    return idBola;
}
