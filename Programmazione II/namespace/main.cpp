#include <iostream>
#include "namespace.h"
using  std::cout;
using  namespace funzioniUtili;

int main() {
    cout << "Hello, World!" << std::endl;

    float val = 54.3; int rangeS = 50, rangeE = 100;
    if (isInRange(val, rangeS, rangeE))
        cout<<"Il valore e' nel range"<<std::endl;
    else
        cout<<"Il valore non e' nel range"<<std::endl;

    int n = 6, *a = new int[n];

    for (int i = 0; i < n; i++)
        a[i] = i + 1;

    cout<<"La somma degli elementi dell'array e' : "<<sumOfArray(a,n)<<std::endl;

    return 0;
}

