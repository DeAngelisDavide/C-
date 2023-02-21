//
// Created by 39331 on 05/10/2021.
//

#ifndef SOMMASALARIALE_LIST_H
#define SOMMASALARIALE_LIST_H

#include "nodo.h"

class list {
private:
    nodo *header;
public:

    list(nodo*);
    nodo* getHead();
    void inserisciELemento(impiegato);
    void visualizzaLista();


};


#endif //SOMMASALARIALE_LIST_H
