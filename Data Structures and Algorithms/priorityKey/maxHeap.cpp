//
// Created by 39331 on 20/11/2021.
//

#include "maxHeap.h"

template<class T>
bool maxHeap<T>::buildMaxHeap(T *a, int len, int hs)
{
    if(hs>len)
        return false;

    delete [] heap;
    heap = new T[len];

    lenght = len;
    heapSize = hs;

    for(int i = 0; i < len; i++)
        heap[i] = a[i];

    for (int i = (heapSize-1) /2; i >= 0 ; i--)
        maxHeapify(i);

}

template <class T>
void maxHeap<T>::maxHeapify(int i) {
    int max = i;

    if (heap[max] < heap[2 * i + 1] && 2 * i + 1 < heapSize)
        max = 2 * i + 1;
    if (heap[max] < heap[2 * i + 2] && 2 * i + 2 < heapSize)
        max = 2 * i + 2;

    if (max != i) {
        std::swap(heap[max], heap[i]);
        maxHeapify(max);
    }
}

template<class T>
//La i rappresenta un contatore;
//In questo caso non ha senso perche' heap sarà sempre un max heap. Bisognerebbe mettere un costruttore che accetta qualsiasi array
bool maxHeap<T>::verificaMaxHeap(int i){

    if (i > (heapSize-1)/2)
        return true;


    bool result = true;
    if (i*2+1 < heapSize)
        if (heap[i] < heap[i*2+1])
            result = false;

    if (i*2+2 < heapSize)
        if (heap[i] < heap[i*2+2])
            result = false;

    return (result && verificaMaxHeap(i+1));
}

template<class T>
void  maxHeap<T>::heapSort(){

    for(int i = heapSize - 1; i>= 1; i--)
    {
        std::swap(heap[0], heap[i]);
        heapSize--;
        maxHeapify(0);
    }
}


template<class T>
void maxHeap<T>::print()
{

    int ind;
    for (int i = 0; i <heapSize/2 ; i++)
    {
        std::cout<<"Padre: "<<heap[i]<<std::endl;
        ind = 2*i+1;
        if (ind < heapSize)
            std::cout<<"Figlio sinistro: "<<heap[ind]<<std::endl;
        ind = 2*i+2;
        if (ind < heapSize)
            std::cout<<"Figlio destro: "<<heap[ind]<<std::endl;
    }

}


template<class T>
void maxHeap<T>::printArray(){

    std::cout<<"L'array e' :"<<std::endl;
    for (int i = 0; i < lenght; i++)
        std::cout<<"["<<i<<"] = "<< heap[i]<<std::endl;
}
