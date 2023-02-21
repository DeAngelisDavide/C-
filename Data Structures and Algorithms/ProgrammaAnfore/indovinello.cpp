//
// Created by 39331 on 30/09/2021.
//

#include "indovinello.h"
#include <iostream>
using namespace std;

void indovinello::risolviIndovinello()
{

    while ( a.getQt() != 4){   //Fino a quando l'indovinello non è risolto
        if (a.isVuota())
        {
            a.riempi();
            cout << "a = " << a.getQt() << "; b = " << b.getQt() << endl;
        }
        else
            {
            b.svuota();
            cout << "a = " << a.getQt() << "; b = " << b.getQt() << endl;
            }
        a.spostaContenutoAnfora(b);
        cout<< "a = " << a.getQt() << "; b = "<< b.getQt() << endl;
    }
}