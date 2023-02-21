//
// Created by 39331 on 05/10/2021.
//

#include "list.h"

list::list(nodo * head) : header(head){}

nodo * list::getHead() { return header;}

void list::inserisciELemento( impiegato i)
{
     nodo *m = new nodo(i);  //Inserimento impiegato in un nuovo nodo
    nodo *punt = header;    //Puntatore che scorre sulla lista
    while (punt->getNext() != nullptr)  //Fino a quando l'elem non ha nessun successivo
        punt = punt->getNext();

    punt->setNext(* m);     //Inserisci il nodo al successivo

}

void list::visualizzaLista()
{
    nodo *punt = header;

    while (punt != nullptr)
    {
        punt->getValue()->print();
        punt = punt->getNext();
    }
}