//
// Created by 39331 on 05/10/2021.
//

#include "nodo.h"

nodo::nodo(impiegato im)
{
    impiegato* temp = new impiegato(im.getNome(), im.getSalario());
    i = temp;
}
nodo::nodo(impiegato* im) : i(im) {}

void nodo::setValue(impiegato b) { i = &b; }

impiegato* nodo::getValue() { return i;}

void nodo::setNext(nodo &n) { next = &n ;}

nodo* nodo::getNext() { return next;}