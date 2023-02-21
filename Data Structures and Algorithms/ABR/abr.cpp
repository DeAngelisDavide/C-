 //
// Created by 39331 on 21/11/2021.
//

#include "abr.h"


nodo* abr::search(nodo *rt, int key)
{
    if (rt == nullptr || rt->key == key)
        return rt;

    if( rt->key > key)
        return search(rt->sx, key);
    else
        return search(rt->dx, key);
}

nodo* abr::minimum(nodo *rt)
{
    if (rt->sx == nullptr)
        return rt;

    return minimum(rt->sx);
}

nodo* abr::maximum(nodo *rt)
{
    if (rt->dx == nullptr)
        return rt;

    return maximum(rt->dx);
}

nodo* abr::successor(nodo *x)
{
    if (x->dx != nullptr )
        return minimum(x->dx);


    nodo *y = x->pa;
    nodo *temp = x;
    while (y != nullptr && temp == y->dx)
    {
        temp = y;
        y = y->pa;
    }

    return y;

}

 nodo* abr::predecessor(nodo *x)
 {
     if (x->sx != nullptr)
         return maximum(x->sx);

     nodo *y = x->pa;
     nodo *temp = x;

     while (y != nullptr && temp == y->sx)
     {
         temp = y;
         y = y->pa;
     }
     return y;
 }

 void abr::insert(nodo *rt, nodo *nw) {

    nodo *x = rt;
    nodo *y = nullptr;
     while ( x != nullptr)
     {
         y = x;
         if (x->key > nw->key)
             x = x->sx;
         else
             x = x->dx;
     }

     nw->pa = y;
     if (y == nullptr)
         root = nw;
     else if(nw->key > y->key)
         y->dx = nw;
     else
         y->sx = nw;
}

void abr::transplant(nodo *a, nodo *b)
{
    if (a->pa == nullptr)
        root = b;
    else if(a->pa->sx == a)
        a->pa->sx = b;
    else
        a->pa->dx = b;

    if (b != nullptr)
        b->pa = a->pa;

}

void abr::delet(nodo *x) {

    //Se np ha figli
    if (x->sx == nullptr)
        transplant(x, x->dx);
    else if (x->dx == nullptr)
        transplant(x, x->sx);
    else {
        nodo *y = successor(x);
        if (y->pa != x)
        {
            transplant(y, y->dx); //Elimina il successore
            y->dx = x->dx;   //Qcollega il sottoalbero dx del successsore a quello del nodo da cancellare
            y->dx->pa = y;   //colleghiamo anche dal basso
        }
        transplant(x,y); //Se andassimo a fare la transplant i collegamenti di sopra non verrebbero considerati dei nodi
        y->sx = x->sx;  //Sempre per la transplant perdiamo il collegamento a sinistra
        y->sx->pa = y;
    }

}

 void abr::visitaSimmetrica( nodo *rt)
{
    if(rt == nullptr)
        return;
    visitaSimmetrica(rt->sx);
    std::cout<<rt->key<<std::endl;
    visitaSimmetrica(rt->dx);

}

int abr::sumFoglie(nodo *rt)
{
    if (rt == nullptr)
        return 0;
    if (rt->sx == nullptr && rt->dx == nullptr)
        return rt->key;

    return sumFoglie(rt->sx)+sumFoglie(rt->dx);
}

int abr::sumLessk(nodo *rt, int k)
{
    if (rt == nullptr)
        return 0;

    if (rt->key > k)
      return sumLessk(rt->sx, k);
    else
        return rt->key+sumLessk(rt->sx, k)+sumLessk(rt->dx, k);
}

int abr::sumBetween(nodo *rt, int a, int b) {

    if (rt == nullptr || b < a)
        return 0;

    if (rt->key < a)
        return sumBetween(rt->dx, a, b);
    else if (rt->key > b)
        return sumBetween(rt->sx, a , b);
    else
        return rt->key+sumBetween(rt->sx, a, b)+sumBetween(rt->dx, a, b);
}

nodo* abr::successorDispari(nodo *x)
{

    nodo *suc = successor(x);
    if (suc == nullptr || suc->key % 2 == 1)
        return  suc;

    return successorDispari(suc);

    return suc;
   /* if (x->dx == nullptr && x->sx == nullptr)
        return NULL; */
    /*if (x->dx != nullptr) {
        nodo *suc = successor(x->dx);
        while (suc->key % 2 == 0 && suc != nullptr)
             suc = minimum(suc);
        return suc;
    }

    nodo *y = x->pa;
    nodo *temp = x;
    while (y != nullptr && (x == y->dx || y->key %2 == 0))
    {
        temp = y;
        y = y->pa;
    }

    return y;
     */
}

nodo* abr::getRoot() { return root;}

void abr::setRoot(nodo *n)
{
    root = n;
}