//
// Created by 39331 on 24/10/2021.
//

#include "merge.h"
//----------MERGE SEMPLICE---------
void mergesort(int a[ ], int left, int right) {
    if (left<right) {
        int center = (left+right)/2;
        mergesort(a, left, center);
        mergesort(a, center+1, right);
        merge(a, left, center, right);
    }
}


void merge(int a[], int left, int center, int right) {
    int aux[ right+1];
    int i,j;
    for (i = center+1; i > left; i--)
        aux[i-1] = a[i-1];
    for (j = center; j < right; j++)
        aux[right+center-j] = a[j+1];

    for (int k = left; k <= right; k++)
        if (aux[j] < aux[i])
            a[k] = aux[j--];
        else
            a[k] = aux[i++];
}


//------MERGE CON VECTOR----------------------------
void mergesort(std::vector<int> &v, std::vector<int>::iterator left, std::vector<int>::iterator right)
{
    if (left<right)
    {
        std::vector<int>::iterator center = it_center(left, right) ;
        mergesort(v, left, center);
        mergesort(v, center+1, right);
        merge(v, left, center, right);
    }

}


void merge(std::vector<int> &a, std::vector<int>::iterator left, std::vector<int>::iterator center, std::vector<int>::iterator right)
{
    std::vector<int> aux;
    std::vector<int>::iterator i,j;
    for (i = center+1; i > left; i--)
        aux.push_back(*(i - 1));
    for (j = center; j < right; j++)
        aux.push_back(*(j + 1));

    i = aux.begin(); j = aux.end() - 1;

    //std::cout<<" j: "<<*j<<std::endl;
    //for ( auto x:aux)
    //{
     //   std::cout<<" x: "<<x<<std::endl;
   // }
    for (std::vector<int>::iterator k = left; k < right; k++)
        if ( *j < *i )
        {
            *k= *j;
            j--;
        }
        else{
            *k=*i;
            i++;
        }
}

//Trova il centro restituendo l'iteratore che ci punta;
std::vector<int>::iterator it_center(std::vector<int>::iterator left, std::vector<int>::iterator right)
{
    int center =(std::distance(left,right)/2);
    std::advance(left,center);

    return left;
}

//-------MERGE RICORSIVO--------
void mergesortRI(int a[ ], int left, int right) {
    if (left<right) {
        int center = (left+right)/2;
        mergesortRI(a, left, center);
        mergesortRI(a, center+1, right);
        mergeRI(a, left, center, right);
    }
}


void mergeRI(int a[], int left, int center, int right) {

    if ( a[left] < a[center + 1])


}