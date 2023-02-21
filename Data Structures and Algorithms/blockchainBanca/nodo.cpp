//
// Created by 39331 on 12/10/2021.
//

#include "nodo.h"

template<class T>
nodo<T>::nodo(T info): info(info) {}

template<class T>
T nodo<T>::getInfo() const {
    return info;
}

template<class T>
void nodo<T>::setInfo(T info){
    nodo::info = info;
}

template<class T>
 nodo<T> *nodo<T>::getPNext() const {
    return pNext;
}

template<class T>
void nodo<T>::setPNext(nodo *pNext) {
    nodo::pNext = pNext;
}

