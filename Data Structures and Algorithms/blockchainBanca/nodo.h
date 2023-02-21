//
// Created by 39331 on 12/10/2021.
//

#ifndef BLOCKCHAINBANCA_NODO_H
#define BLOCKCHAINBANCA_NODO_H

template <class T>
class nodo {

protected:
    T info;
    nodo *pNext = nullptr;
public:
    nodo(T info);

    T getInfo() const;
    void setInfo(T info);

    nodo *getPNext() const;
    void setPNext(nodo *pNext);

};


#endif //BLOCKCHAINBANCA_NODO_H
