#include <iostream>

#include "list.h"
#include "impiegato.h"
#include "manager.h"

using namespace std;

#define n 4

int main() {
    //Creazione dati
    impiegato* m = new manager("Paolo", 4300.54, 243.5);
    impiegato i[] =  {{"Dario", 2300.43}, {"Michele", 1340.34} , {"Giuseppe", 1640.34}, {"Simone", 840.34}};
    //creazione ed inseriemnto testa
    nodo *head = new nodo(m);
    list l(head);

    //Inserimento lista
    for (int j = 0; j < n; j++)
        l.inserisciELemento(i[j]);

    l.visualizzaLista();

    float sommaSalariale = l.getHead()->getValue()->getSalario();
    //Somma di tutti i salari
    for (int j = 0; j < n - 1; j+= 2 )
        sommaSalariale+= i[j] + i[j + 1];

    cout<< "La somma salariale e': "<<sommaSalariale<<endl;



    return 0;
}
