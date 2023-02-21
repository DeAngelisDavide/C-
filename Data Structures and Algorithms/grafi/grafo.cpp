//
// Created by 39331 on 28/12/2021.
//

#include "grafo.h"

grafo::grafo(int _n_vertici) {
    n_vertici = _n_vertici;
    for (int i = 0; i < n_vertici; i++)
        ad[i] = new int [n_vertici];

}
