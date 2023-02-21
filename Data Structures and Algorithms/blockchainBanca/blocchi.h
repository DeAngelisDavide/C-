//
// Created by 39331 on 12/10/2021.
//

#ifndef BLOCKCHAINBANCA_BLOCCHI_H
#define BLOCKCHAINBANCA_BLOCCHI_H
#include "transazioni.h"
#include "linkedList.h"


class blocchi {
protected:
    linkedList<transazioni> *listTransazioni = new linkedList<transazioni>();
    std::string data;
public:
    blocchi(std::string);

    linkedList<transazioni> *getListTransazioni() const;
    const std::string &getData() const;

    void print();

    float bilancio(std::string);


};


#endif //BLOCKCHAINBANCA_BLOCCHI_H
