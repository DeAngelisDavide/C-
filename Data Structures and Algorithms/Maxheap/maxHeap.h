//
// Created by 39331 on 17/11/2021.
//

#ifndef MAXHEAP_MAXHEAP_H
#define MAXHEAP_MAXHEAP_H
//#include "maxHeap.cpp"

template<class T>
class maxHeap{
private:
    int lenght = 0, heapSize = 0;
    T *heap = new T[lenght];
    void maxHeapify(int );
 public:
    bool buildMaxHeap(T *, int , int );
    void insert(T);
    bool verificaMaxHeap(int);
    void print();
};



#endif //MAXHEAP_MAXHEAP_H
