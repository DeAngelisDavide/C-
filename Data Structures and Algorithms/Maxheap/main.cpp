#include <iostream>
#include "maxHeap.h"
#include "maxHeap.cpp"
#define n 8
int main() {


    maxHeap<int> *heap = new maxHeap<int>;

    int a[n];

    for (int i = 0; i < n; i++)
        a[i] = i + 1;

    heap->buildMaxHeap(a, n, n-3);
    heap->insert(10);
    heap->print();

    return 0;

}
