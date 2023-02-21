//
// Created by 39331 on 12/10/2021.
//

#ifndef BLOCKCHAINBANCA_BLOCKCHAIN_H
#define BLOCKCHAINBANCA_BLOCKCHAIN_H

#include "blocchi.h"

class blockchain {

private:
    linkedList<blocchi> *listBlocchi= new linkedList<blocchi>();
public:
    linkedList<blocchi> *getListBlocchi() const;

    void print();

    float bilancio(std::string);

};


#endif //BLOCKCHAINBANCA_BLOCKCHAIN_H
