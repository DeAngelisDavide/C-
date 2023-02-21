//
// Created by 39331 on 20/11/2021.
//

#include "Prioritykey.h"


template<class T>
T Prioritykey<T>::heapMaximum()
{
    return Prioritykey<T>::heap[0];
}

template<class T>
T Prioritykey<T>::heapExtractMax() {
    if (Prioritykey<T>::heapSize == 0)
    {
        std::cout<<"Coda vuota";
        exit(0);
    }

    T max = Prioritykey<T>::heap[0];

    std::swap(Prioritykey<T>::heap[0], Prioritykey<T>::heap[Prioritykey<T>::heapSize-1]);
    Prioritykey<T>::heapSize--;
    Prioritykey<T>::maxHeapify(0);

    return max;
}

template<class T>
void Prioritykey<T>::heapIncreaseKey(int pos, T key){

    if (key <= Prioritykey<T>::heap[pos])
    {
        std::cout << "Dato npn valido" << std::endl;
        return;
    }

    Prioritykey<T>::heap[pos] = key;

    for (int i = pos; i > 0 && Prioritykey<T>::heap[(i-1)/2] < Prioritykey<T>::heap[i]; i = (i-1)/2 )
        std::swap(Prioritykey<T>::heap[(i-1)/2], Prioritykey<T>::heap[i]);

}

template<class T>
void Prioritykey<T>::maxHeapInsert(T key){

    T *a = new T[Prioritykey<T>::heapSize++];
    for (int i = 0 ; i < Prioritykey<T>::heapSize - 1; i++)
        a[i] = Prioritykey<T>::heap[i];

    //Valore sicuramente minore per effettuare l'increase key
    a[Prioritykey<T>::heapSize - 1] = key - 1;
    delete [] Prioritykey<T>::heap;
    Prioritykey<T>::heap = a;

    heapIncreaseKey(Prioritykey<T>::heapSize - 1, key);



}