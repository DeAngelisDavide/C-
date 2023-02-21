#include <iostream>
#include "Prioritykey.h"
#include "Prioritykey.cpp"


#define n 8

int main() {

    maxHeap<int> *heap = new maxHeap<int>;

    int a[n];
    for (int i = 0; i < n; i++)
        a[i] = i + 1;

    heap->buildMaxHeap(a, n, n);
    heap->print();

    heap->heapSort();

    heap->printArray();

    if (heap->verificaMaxHeap(0))
        std::cout<<"E' un heap"<<std::endl;
    else
        std::cout<<"Non e' un heap"<<std::endl;

    Prioritykey<int> *prioritykey = new Prioritykey<int>;

    prioritykey->buildMaxHeap(a, n , n);
    prioritykey->heapExtractMax();
    std::cout<<"Priority dopo estrazione del massimo"<<std::endl;
    prioritykey->print();
    prioritykey->heapIncreaseKey(6, 2);
    std::cout<<"Priority dopo increase key di 3"<<std::endl;
    prioritykey->print();
    prioritykey->maxHeapInsert(10);
    std::cout<<"Priority dopo insert"<<std::endl;
    prioritykey->print();

    return 0;
}
