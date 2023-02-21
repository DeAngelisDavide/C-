//
// Created by 39331 on 23/11/2021.
//

#ifndef PRIORITYKEYABR_PRIORITYKEY_H
#define PRIORITYKEYABR_PRIORITYKEY_H

#include "..\ABR\abr.h"
#include "..\ABR\abr.cpp"

class priorityKey {
protected:
    abr *pk = new abr;
public:
    void abrIncreseKey(nodo *n, int k);
    void abrInsert(nodo *n);

    nodo* abrMaximum ();
    nodo* abrExtractMax();
    void vistaSimmetrica();

};


#endif //PRIORITYKEYABR_PRIORITYKEY_H
