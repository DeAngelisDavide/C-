#include <iostream>
using namespace std;
//Invertire i bits di un valore

int main() {
    bitset<16> a = 34, revA = 0;

    for (int i = 0, j = 15; i < 16; i++, j-- )
        revA[j] = a[i];

    cout<<"a : "<<a<<endl<<"a reverso : "<<revA<<endl;

    return 0;
}
