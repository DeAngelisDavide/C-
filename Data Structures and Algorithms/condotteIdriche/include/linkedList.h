#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "../src/nodo.cpp"

template <class T>
class linkedList {
private:
    nodo<T> *header = nullptr;
    int lenght = 0;
public:
    nodo<T> *getHeader() const;
    void setHeader(nodo<T> *header);

    void push(T v);
    nodo<T>* search(T v);
    bool removeNode(T v);

    int getLenght() const;

};

#endif // LINKEDLIST_H
