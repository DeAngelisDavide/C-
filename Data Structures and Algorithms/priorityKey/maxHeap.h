//
// Created by 39331 on 20/11/2021.
//

#ifndef PRIORITYKEY_MAXHEAP_H
#define PRIORITYKEY_MAXHEAP_H
#include <vector>

template <class T>
class maxHeap {
protected:
        int lenght = 0, heapSize = 0;
        T *heap = new T;
        void maxHeapify(int);
    public:
        bool buildMaxHeap(T *, int , int );
        void print();
        void printArray();
        bool verificaMaxHeap(int);
        void heapSort();
};


#endif //PRIORITYKEY_MAXHEAP_H
