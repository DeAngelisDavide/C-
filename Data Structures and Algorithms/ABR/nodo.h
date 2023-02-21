//
// Created by 39331 on 21/11/2021.
//

#ifndef ABR_NODO_H
#define ABR_NODO_H


class nodo {
public:
    int key;
    nodo *sx = nullptr;
    nodo *dx = nullptr;
    nodo *pa = nullptr;
    void swap(nodo *a);
};

void nodo::swap(nodo *a)
{
    nodo *temp = a;
    a->key = key;
    a->sx = sx;
    a->dx = dx;
    a->pa = pa;
    key = temp->key;
    sx = temp->sx;
    dx = temp->dx;
    pa = temp->pa;
}

#endif //ABR_NODO_H
