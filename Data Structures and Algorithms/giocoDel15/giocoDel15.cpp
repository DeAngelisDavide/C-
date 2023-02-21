//
// Created by 39331 on 16/10/2021.
//

#include <iostream>
#include "giocoDel15.h"

giocoDel15::giocoDel15(string p)
{
    f.open(p);

    //creazione della matrice. E? fatto cosi solo per esercitazione ma si può accedere con [][]
    vector<int> righe;
    for (int i = 1; i < n*n; i += n)
    {
        for (int j = i; j < n + i; j++)
            righe.push_back(j);

        m.push_back(righe);
        righe.clear();
    }
    m[3][3] = 0;
}

void giocoDel15::visualizzaMatrice()
{
    cout<<"Visualizzazione matrice: "<<endl;
    for (auto x: m)
    {
        cout<<"[ ";
        for (auto y: x)
            cout << y << "  ";
        cout<<"]"<<endl;
    }

}

bool giocoDel15::verificaConfigurazione()
{
    string read;
    for ( auto x: m)
    {
        for (auto y:x)
        {
            f >> read;
            if (y != stoi(read))
                return false;
        }
    }
    return true;
}

//Costruttore e Metodo per i thred
giocoDel15::giocoDel15()
{
    //creazione della matrice. E? fatto cosi solo per esercitazione ma si può accedere con [][]
    vector<int> righe;
    for (int i = 1; i < n*n; i += n)
    {
        for (int j = i; j < n + i; j++)
            righe.push_back(j);

        m.push_back(righe);
        righe.clear();
    }
    m[3][3] = 0;
}


void giocoDel15::verificaConfigurazioneThred(string p, bool *r)
{
    f.open(p);
    *r = true;
    string read;
    for ( auto x: m)
    {
        for (auto y:x)
        {
            f >> read;
            if (y != stoi(read))
                *r = false;
        }
    }
    f.close();
}