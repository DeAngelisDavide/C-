//
// Created by 39331 on 03/10/2021.
//

#include "risoluzione.h"
 risoluzione::risoluzione() {
     prb.open("Problema.txt", ios::in);
     sol.open("Soluzione.txt", ios::in);
     es.open("Esito.txt", ios::out);

}

bool risoluzione::isAperto()
{
    if(prb.fail() || sol.fail() || es.fail())
        return false;
    return true;
}

void risoluzione::risolvi ()
{
    string buffer1, buffer2;
    int number1, number2 ;
    bool esito;

    while (!prb.eof() || !sol.eof() )
    {
        getline(prb, buffer1);
        getline( sol, buffer2);
        number1 = stoi(buffer2);
        esito = true;                                                                                     //Per trovarci con l'indice sul simbolo
        for (int i = 0, j = numCifre(number1); (i < buffer1.length() && j < buffer2.length()) && esito; i++, j += numCifre(number2) + 1)
        {
            //Se i simboli sono uguali
            if (buffer2[j] == buffer1[i])
            {
                //Prendi il numero dopo il simbolo
                number2 = stoi(buffer2.substr(j + 1));
                if (!confrontaNumeri(number1, number2, buffer1[i]))
                    esito = false;

                number1 = number2;
            } else esito = false;


        }
        if (esito)
            es<<"Corretta"<<endl;
        else
            es<<"Sbagliata"<<endl;


    }
}

int risoluzione::numCifre(int a)
{
    int i = 0;
    while (a >= 1)
    {
        a /= 10;
        i++;
    }
    return i;
}


bool risoluzione::confrontaNumeri(int a, int b, char op)
{
    switch (op)
    {
        case '<':
            if (a < b)
                return true;
            return false;

        case '>':
            if (a > b)
                return true;
            return false;

    }
    return false;
}