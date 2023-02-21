//
// Created by 39331 on 05/10/2021.
//

#ifndef SOMMASALARIALE_NODO_H
#define SOMMASALARIALE_NODO_H
#include "impiegato.h"

class nodo {
protected:
    impiegato *i;
    nodo *next = nullptr;
public:
    nodo(impiegato);
    nodo(impiegato*);
    void setValue(impiegato);
    impiegato* getValue();
    void setNext( nodo &);
    nodo* getNext();


};


#endif //SOMMASALARIALE_NODO_H
