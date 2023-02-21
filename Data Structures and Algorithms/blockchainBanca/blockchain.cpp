//
// Created by 39331 on 12/10/2021.
//

#include "blockchain.h"
#include "linkedList.cpp"
#include "nodo.cpp"


linkedList<blocchi> *blockchain::getListBlocchi() const {
    return listBlocchi;
}

void blockchain::print()
{
    nodo<blocchi> *punt = listBlocchi->getHeader();
    while (punt != nullptr)
    {
        punt->getInfo().print();
        punt = punt->getPNext();
    }
}

//Restituisce il bilancio totale della key
float blockchain::bilancio(std::string key)
{
    float bilancio = 0;
    nodo<blocchi> *punt = listBlocchi->getHeader();
    std::cout<<"Transazioni in cui e' presente "<<key<<":"<<std::endl;
    while (punt != nullptr)
    {
        //Il metodo bilancio di blocchi restituisce il bilancio del blocco
        bilancio += punt->getInfo().bilancio(key);
        punt = punt->getPNext();
    }
    return bilancio;
}
