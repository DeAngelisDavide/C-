//
// Created by 39331 on 13/10/2021.
//
#include "linkedList.h"


template<class T>
void linkedList<T>::inserisciElemento(nodo<T> *n)
{
    n->setPNext(header);
    header = n;
}

template <class T>
nodo<T> *linkedList<T>::getHeader() const { return header;}