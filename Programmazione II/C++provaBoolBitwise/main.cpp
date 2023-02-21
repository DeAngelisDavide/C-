#include <iostream>
#include <bitset>
using namespace std;

int main() {
    bool isTrue = true;
    //Bool vale 0 se falso, > 0 vero
    isTrue = 100;

    //1
    cout<<isTrue<< endl;
    //true
    cout<<boolalpha<<isTrue<<endl;


    char r = 'B'^'a';

    cout<<"B^a: "<<r<<endl;
    cout<<"B^a int: "<<(int)r<<endl;

    bitset<8> xr = 'B'^'a';

    cout<<"B^a con bitset: "<<xr<<endl;
    cout<<"B^a con bitset.to_ulong(): "<<xr.to_ulong()<<endl;

    bitset<8> zero = 0 ;

    //ATTENZIONE: i risultati delle funzioni vengono salvati anche senza fare zero = ...
    //Abbiamo sia il set che il reset
    cout<< "0 con set al 4 bit: "<<zero.set(3)<<endl;
    //Flip: 1 se è 0 ; 0 se è 1;
    cout<<"Valore precedente con flip a tutti i bit: "<<zero.flip()<<endl;
    //Setta tutti i bit
    cout<<"Valore precedente con set di tutti i bit: "<<zero.set()<<endl;

    zero[3] = 0;
    cout<<"settaggio del 4 bit del valore precedente con array: "<<zero<<endl;
    return 0;
}
