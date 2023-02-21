//
// Created by 39331 on 28/12/2021.
//
#include <vector>
#include "nodo.h"
#ifndef GRAFI_GRAFO_H
#define GRAFI_GRAFO_H


class grafo {
private:
    int n_vertici;
    std::vector<nodo> v;
    int **ad = new int*[n_vertici];

public:
    grafo(int n_vertici);
    void insertVertice();
};


#endif //GRAFI_GRAFO_H
