#include <iostream>
using namespace std;

//Contare i bit 0 e 1 di una variabile int
int main() {
    int a, contatore0 = 0 , contatore1 = 0;

    //Acquisizione valore
    cout<<"Inserisci un numero:\n";
    cin>>a;

    //Variabile bitset che contiene a in bit
    bitset<8> bitA = a;

    cout<<"Il numero in bit è : "<<bitA<<endl;

    //Verifica se il bit è 1 o 0
    for (int i = 0; i < bitA.size(); i++)
        if (bitA[i] == 0)
            contatore0++;
        else
            contatore1++;

    //Visualizzazione risultati
    cout<<"Il numero di bit 0 : "<<contatore0<<endl<<"Il numero di bit 1 : "<<contatore1<<endl;

    return 0;
}
