#pragma once
#include "pch.h"


namespace Alaska
{
    namespace Listas
    {
        template <class TL>
        class Lista
        {
            private:
                template <class TE>
                class Elemento
                {
                    private:
                        TE l_dado;
                        Elemento<TE>* l_proximo;
                    public:
                        Elemento();
                        Elemento(TE dado, Elemento<TE>* proximo);
                        ~Elemento();
                        void setDado(TE dado);
                        void setProximo(Elemento<TE>* proximo);
                        TE getDado() const;
                        Elemento<TE>* getProximo()const;
                };
            private:
                Elemento<TL>* l_primeiro;
                Elemento<TL>* l_ultimo;
            public:
                class Iterador
                {
                    private:
                        Elemento<TL>* l_posicao;
                    public:
                        Iterador(Elemento<TL>* posicao = nullptr);
                        ~Iterador();
                        TL operator*();
                        Iterador proximo();
                        Iterador operator++();
                        Iterador operator++(int);
                        bool operator!=(const Iterador& it);
                };

            public:
                Lista();
                ~Lista();
                void inserirNoFim(TL elemento);
                void removerE(TL elemento);
				void limpar();
                Elemento<TL>* getPrimeiro()const;
                Elemento<TL>* getUltimo()const;
                Iterador begin();
                Iterador end();
        };
    }
}


template <class TL>
template <class TE>
Alaska::Listas::Lista<TL>::Elemento<TE>::Elemento(): l_dado(), l_proximo(nullptr){}

template <class TL>
template <class TE>
Alaska::Listas::Lista<TL>::Elemento<TE>::Elemento(TE dado, Elemento<TE>* proximo): l_dado(dado), l_proximo(proximo){}

template <class TL>
template <class TE>
Alaska::Listas::Lista<TL>::Elemento<TE>::~Elemento() 
{
    l_proximo = nullptr;
}

template <class TL>
template <class TE>
void Alaska::Listas::Lista<TL>::Elemento<TE>::setDado(TE dado) 
{
    l_dado = dado;
}

template <class TL>
template <class TE>
void Alaska::Listas::Lista<TL>::Elemento<TE>::setProximo(Elemento<TE>* proximo) 
{
    l_proximo = proximo;
}

template <class TL>
template <class TE>
TE Alaska::Listas::Lista<TL>::Elemento<TE>::getDado()const 
{
    return l_dado;
}

template <class TL>
template <class TE>
typename Alaska::Listas::Lista<TL>::template Elemento<TE>* Alaska::Listas::Lista<TL>::Elemento<TE>::getProximo()const 
{
    return l_proximo;
}

template <class TL>
Alaska::Listas::Lista<TL>::Iterador::Iterador(Alaska::Listas::Lista<TL>::Elemento<TL>* posicao): l_posicao(posicao){}

template <class TL>
Alaska::Listas::Lista<TL>::Iterador::~Iterador() 
{
    l_posicao = nullptr;
}

template <class TL>
TL Alaska::Listas::Lista<TL>::Iterador::operator*()
{
    return l_posicao->getDado();
}

template <class TL>
typename Alaska::Listas::Lista<TL>::Iterador Alaska::Listas::Lista<TL>::Iterador::proximo()
{
    Lista<TL>::Iterador aux(this->l_posicao->getProximo());
    return aux;
}

template <class TL>
typename Alaska::Listas::Lista<TL>::Iterador Alaska::Listas::Lista<TL>::Iterador::operator++() 
{
    l_posicao = l_posicao->getProximo();
    return *this;
}

template <class TL>
typename Alaska::Listas::Lista<TL>::Iterador Alaska::Listas::Lista<TL>::Iterador::operator++(int) 
{
    Iterador temporario = *this;
    l_posicao = l_posicao->getProximo();
    return temporario;
}

template <class TL>
bool Alaska::Listas::Lista<TL>::Iterador::operator!=(const Alaska::Listas::Lista<TL>::Iterador& it)
{
    return this->l_posicao != it.l_posicao;
}

template <class TL>
typename Alaska::Listas::Lista<TL>::Iterador Alaska::Listas::Lista<TL>::begin()
{
    return Iterador(l_primeiro);
}

template <class TL>
typename Alaska::Listas::Lista<TL>::Iterador Alaska::Listas::Lista<TL>::end()
{
    return Iterador(nullptr);
}


template <class TL>
Alaska::Listas::Lista<TL>::Lista(): l_primeiro(nullptr), l_ultimo(nullptr){}

template <class TL>
Alaska::Listas::Lista<TL>::~Lista() 
{
    limpar();
}

template <class TL>
void Alaska::Listas::Lista<TL>::limpar()
{
    Elemento<TL>* atual = l_primeiro;
    while (atual)
    {
        Elemento<TL>* tmp = atual;
        atual = atual->getProximo();
        delete tmp;
    }
    l_primeiro = nullptr;
    l_ultimo = nullptr;
}

template <class TL>
void Alaska::Listas::Lista<TL>::inserirNoFim(TL elemento) 
{
    Elemento<TL>* temporario = new Elemento<TL>;
    temporario->setDado(elemento);
    temporario->setProximo(nullptr);

    if (l_primeiro == nullptr) 
        l_primeiro = temporario;
    else 
    l_ultimo->setProximo(temporario);

    l_ultimo = temporario;
}

template <class TL>
void Alaska::Listas::Lista<TL>::removerE(TL elemento) 
{
    Elemento<TL>* atual = l_primeiro;
    Elemento<TL>* anterior = nullptr;


    while (atual != nullptr && atual->getDado() != elemento) 
    {
        anterior = atual;
        atual = atual->getProximo();
    }

    if (atual == nullptr)
        return;

    if (atual == l_primeiro) 
        l_primeiro = atual->getProximo();
    else 
        anterior->setProximo(atual->getProximo());

    if (atual == l_ultimo) 
        l_ultimo = anterior;

    delete atual; 
}

template <class TL>
typename Alaska::Listas::Lista<TL>::template Elemento<TL>* Alaska::Listas::Lista<TL>::getPrimeiro()const 
{
    return l_primeiro;
}

template <class TL>
typename Alaska::Listas::Lista<TL>::template Elemento<TL>* Alaska::Listas::Lista<TL>::getUltimo()const 
{
    return l_ultimo;
}