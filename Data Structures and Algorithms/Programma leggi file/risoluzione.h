//
// Created by 39331 on 03/10/2021.
//

#ifndef PROGRAMMA_LEGGI_FILE_RISOLUZIONE_H
#define PROGRAMMA_LEGGI_FILE_RISOLUZIONE_H
#include <fstream>
#include <iostream>
using namespace std;

class risoluzione{

private:
    ifstream prb, sol;
    ofstream es;
    int numCifre( int a);
    bool confrontaNumeri( int a , int b , char op);


public:
    void risolvi();
    bool isAperto();
    risoluzione();
};


#endif //PROGRAMMA_LEGGI_FILE_RISOLUZIONE_H

