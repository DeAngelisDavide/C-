//
// Created by 39331 on 12/10/2021.
//

#include "blocchi.h"
#include "nodo.cpp"
#include "linkedList.cpp"


blocchi::blocchi(std::string data): data(data) {}

linkedList<transazioni> *blocchi::getListTransazioni() const {
    return listTransazioni;
}

const std::string &blocchi::getData() const {
    return data;
}

void blocchi::print()
{
    std::cout<<"La data e':"<<data<<std::endl;
    nodo<transazioni> *punt = listTransazioni->getHeader();
    std::cout<<"Le transazioni sono:"<<std::endl;
    while (punt != nullptr)
    {
        punt->getInfo().print();
        punt = punt->getPNext();
    }

}

//Restituisce il bilancio del blocco (visto il print non è la soluzione più corretta)
float blocchi::bilancio(std::string key)
{
    std::cout<<"Le transazioni interessate del giorno "<< data << " sono: "<<std::endl;
    nodo<transazioni> *punt = listTransazioni->getHeader();
    float bilancio = 0;
    while (punt != nullptr)
    {
        if (punt->getInfo().getFrom() == key)
        {
            bilancio -= punt->getInfo().getQt();
            punt->getInfo().print();
        }
        else if (punt->getInfo().getTo() == key)
        {
            bilancio += punt->getInfo().getQt();
            punt->getInfo().print();
        }

        punt = punt->getPNext();
    }
    return bilancio;
}