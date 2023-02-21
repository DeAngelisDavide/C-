//
// Created by 39331 on 21/11/2021.
//

#ifndef ABR_ABR_H
#define ABR_ABR_H
#include "nodo.h"

class abr : protected nodo{
private:
    nodo *root = nullptr;
    void transplant(nodo *a, nodo *b);
public:
    nodo* search(nodo *rt, int key);
    nodo* minimum( nodo *rt);
    nodo* maximum( nodo *rt);
    nodo* predecessor(nodo *x);
    nodo* successor(nodo *x);
    void insert(nodo *rt, nodo *x);
    void delet(nodo *x);
    void visitaSimmetrica( nodo *rt);
    nodo* getRoot();
    void setRoot(nodo *n);

    int sumFoglie(nodo *rt);
    int sumLessk(nodo *rt, int k);
    int sumBetween(nodo *rt, int a, int b);
    nodo* successorDispari(nodo *x);
};


#endif //ABR_ABR_H
