//
// Created by 39331 on 30/09/2021.
//
#include "Contenitore.h"
#ifndef PROGRAMMAANFORE_ANFORA_H
#define PROGRAMMAANFORE_ANFORA_H

class anfora: public contenitore{
private:
    int capacita;

public:
    anfora( int cp);
    void riempi();
    void svuota();
    bool isVuota();
    bool isPiena();
    void spostaContenutoAnfora( anfora &a);



};
#endif //PROGRAMMAANFORE_ANFORA_H
