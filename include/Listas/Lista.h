#pragma once
#include "pch.h"


namespace Alaska
{
    namespace Listas
    {
        template <class T>
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
                Elemento<T>* l_primeiro;
                Elemento<T>* l_ultimo;
            public:
                class Iterador
                {
                    private:
                        Elemento<T>* l_posicao;
                    public:
                        Iterador(Elemento<T>* posicao = nullptr);
                        ~Iterador();
                        T operator*();
                        Iterador proximo();
                        Iterador operator++();
                        Iterador operator++(int);
                        bool operator!=(const Iterador& it);
                };

            private:
                Elemento<T>* buscar(T elemento);
            public:
                Lista();
                ~Lista();
                void inserirNoFim(T elemento);
                void removerE(T elemento);
				void limpar();
                bool contem(T elemento);
                Elemento<T>* getPrimeiro()const;
                Elemento<T>* getUltimo()const;
                Iterador begin();
                Iterador end();
        };
    }
}


template <class T>
template <class TE>
Alaska::Listas::Lista<T>::Elemento<TE>::Elemento(): l_dado(), l_proximo(nullptr){}

template <class T>
template <class TE>
Alaska::Listas::Lista<T>::Elemento<TE>::Elemento(TE dado, Elemento<TE>* proximo): l_dado(dado), l_proximo(proximo){}

template <class T>
template <class TE>
Alaska::Listas::Lista<T>::Elemento<TE>::~Elemento() 
{
    l_proximo = nullptr;
}

template <class T>
template <class TE>
void Alaska::Listas::Lista<T>::Elemento<TE>::setDado(TE dado) 
{
    l_dado = dado;
}

template <class T>
template <class TE>
void Alaska::Listas::Lista<T>::Elemento<TE>::setProximo(Elemento<TE>* proximo) 
{
    l_proximo = proximo;
}

template <class T>
template <class TE>
TE Alaska::Listas::Lista<T>::Elemento<TE>::getDado()const 
{
    return l_dado;
}

template <class T>
template <class TE>
typename Alaska::Listas::Lista<T>::template Elemento<TE>* Alaska::Listas::Lista<T>::Elemento<TE>::getProximo()const 
{
    return l_proximo;
}

template <class T>
Alaska::Listas::Lista<T>::Iterador::Iterador(Alaska::Listas::Lista<T>::Elemento<T>* posicao): l_posicao(posicao){}

template <class T>
Alaska::Listas::Lista<T>::Iterador::~Iterador() 
{
    l_posicao = nullptr;
}

template <class T>
T Alaska::Listas::Lista<T>::Iterador::operator*()
{
    return l_posicao->getDado();
}

template <class T>
typename Alaska::Listas::Lista<T>::Iterador Alaska::Listas::Lista<T>::Iterador::proximo()
{
    Lista<T>::Iterador aux(this->l_posicao->getProximo());
    return aux;
}

template <class T>
typename Alaska::Listas::Lista<T>::Iterador Alaska::Listas::Lista<T>::Iterador::operator++() 
{
    l_posicao = l_posicao->getProximo();
    return *this;
}

template <class T>
typename Alaska::Listas::Lista<T>::Iterador Alaska::Listas::Lista<T>::Iterador::operator++(int) 
{
    Iterador temporario = *this;
    l_posicao = l_posicao->getProximo();
    return temporario;
}

template <class T>
bool Alaska::Listas::Lista<T>::Iterador::operator!=(const Alaska::Listas::Lista<T>::Iterador& it)
{
    return this->l_posicao != it.l_posicao;
}

template <class T>
typename Alaska::Listas::Lista<T>::Iterador Alaska::Listas::Lista<T>::begin()
{
    return Iterador(l_primeiro);
}

template <class T>
typename Alaska::Listas::Lista<T>::Iterador Alaska::Listas::Lista<T>::end()
{
    return Iterador(nullptr);
}


template <class T>
Alaska::Listas::Lista<T>::Lista(): l_primeiro(nullptr), l_ultimo(nullptr){}

template <class T>
Alaska::Listas::Lista<T>::~Lista() 
{
    Elemento<T>* elementoAtual = this->getPrimeiro(); 
    Elemento<T>* temporario;

    while (elementoAtual != nullptr) 
    {
        temporario = elementoAtual;
        elementoAtual = elementoAtual->getProximo();
        delete temporario;
    }
}


//implementar limpar

template <class T>
typename Alaska::Listas::Lista<T>::template Elemento<T>* Alaska::Listas::Lista<T>::buscar(T elemento) 
{
    Elemento<T>* temporario = l_primeiro;

    while (temporario != nullptr) 
    {
        if (temporario->getDado() == elemento)
            return temporario;
        temporario = temporario->getProximo();
    }
    return nullptr;
}

template <class T>
void Alaska::Listas::Lista<T>::inserirNoFim(T elemento) 
{
    Elemento<T>* temporario = new Elemento<T>;
    temporario->setDado(elemento);
    temporario->setProximo(nullptr);

    if (l_primeiro == nullptr) 
        l_primeiro = temporario;
    else 
    l_ultimo->setProximo(temporario);

    l_ultimo = temporario;
}

template <class T>
void Alaska::Listas::Lista<T>::removerE(T elemento) 
{
    Elemento<T>* atual = l_primeiro;
    Elemento<T>* anterior = nullptr;


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

template <class T>
bool Alaska::Listas::Lista<T>::contem(T elemento) 
{
    Elemento<T>* temporario = buscar(elemento);
    return temporario != nullptr;
}

template <class T>
typename Alaska::Listas::Lista<T>::template Elemento<T>* Alaska::Listas::Lista<T>::getPrimeiro()const 
{
    return l_primeiro;
}

template <class T>
typename Alaska::Listas::Lista<T>::template Elemento<T>* Alaska::Listas::Lista<T>::getUltimo()const 
{
    return l_ultimo;
}

template <class T>
void Alaska::Listas::Lista<T>::limpar()
{
    Elemento<T>* atual = l_primeiro;
    while (atual)
    {
        Elemento<T>* tmp = atual;
        atual = atual->getProximo();
        delete tmp;
    }
    l_primeiro = nullptr;
    l_ultimo = nullptr;
}
