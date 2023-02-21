//
// Created by 39331 on 05/10/2021.
//

#ifndef SOMMASALARIALE_MANAGER_H
#define SOMMASALARIALE_MANAGER_H
#include "impiegato.h"

class manager: public impiegato{
private:
    float bonus;

public:
    manager( string , float , float);
    void print();



};


#endif //SOMMASALARIALE_MANAGER_H
