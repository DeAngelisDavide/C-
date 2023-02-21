#include <iostream>
#include "template.h"
using namespace std;

int main() {
    int a = 5; float b = 4.3;

    int c = valGrater(a,b);

    if( c == 0)
        cout<<"Il primo valore e' il piu' grande"<<endl;
    else if( c == 1)
        cout<<"Il secondo valore e' il piu' grande"<<endl;
    else
        cout<<"I due valori sono uguali"<<endl;

    int array[] = {6, 10 , 3};

    int max =  maxArray(array, 3);
    cout<<"Il max dell'array e'"<<max<<endl;
    return 0;
}
