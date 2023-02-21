//
// Created by 39331 on 16/10/2021.
//
#ifndef GIOCODEL15_GIOCODEL15_H
#define GIOCODEL15_GIOCODEL15_H

#include <fstream>
#include <vector>


using namespace std;

class giocoDel15 {
//La matrice deve avere stesso numero di righe e colonne

private:
    vector<vector<int>> m;
    int n=4;
    ifstream f;

public:
    giocoDel15(string);
    giocoDel15();
    void visualizzaMatrice();
    bool verificaConfigurazione();
    void verificaConfigurazioneThred(string, bool*);

};
#endif //GIOCODEL15_GIOCODEL15_H
