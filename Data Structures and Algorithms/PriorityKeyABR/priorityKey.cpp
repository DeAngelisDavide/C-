//
// Created by 39331 on 23/11/2021.
//

#include "priorityKey.h"

nodo* priorityKey::abrMaximum()
{
    return pk->maximum(pk->getRoot());
}

nodo* priorityKey::abrExtractMax()
{
    nodo *max = pk->maximum(pk->getRoot());
    pk->delet(max);
    return max;
}

void priorityKey::abrInsert(nodo *n)
{
    pk->insert(pk->getRoot(), n);
}

void priorityKey::abrIncreseKey( nodo *n,  int k)
{
    if (n->key > k)
    {
        std::cout<<"Il dato non e' valido"<<std::endl;
        return;
    }

    pk->delet(n);
    n->key = k;
    pk->insert(pk->getRoot(), n);
}

void priorityKey::vistaSimmetrica()
{
    pk->visitaSimmetrica(pk->getRoot());
}

