//
// Created by 39331 on 12/10/2021.
//

#ifndef BLOCKCHAINBANCA_LINKEDLIST_H
#define BLOCKCHAINBANCA_LINKEDLIST_H
#include "nodo.h"

template <class T>
class linkedList {
private:
    nodo<T> *header = nullptr;
public:
    void inserisciElemento(nodo<T>*);

    nodo<T> *getHeader() const;

};


#endif //BLOCKCHAINBANCA_LINKEDLIST_H
