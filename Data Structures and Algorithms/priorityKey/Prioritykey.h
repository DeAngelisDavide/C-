//
// Created by 39331 on 20/11/2021.
//

#ifndef PRIORITYKEY_PRIORITYKEY_H
#define PRIORITYKEY_PRIORITYKEY_H


#include "maxHeap.h"
#include "maxHeap.cpp"


template<class T>
class Prioritykey : public maxHeap<T>{

public:
    T heapMaximum();
    T heapExtractMax();
    void heapIncreaseKey(int, T);
    void maxHeapInsert(T);
};



#endif //PRIORITYKEY_PRIORITYKEY_H