#include <iostream>
#include <vector>
using namespace std;

#define n 2
#define m 3

int main() {

    //Con il vector funziona come una realloc in c che possiamo aggiungere nuovi elementi
    vector<int> v{ 3, 6, 9};
    v.pop_back();
    v.push_back(5);

    cout<< "Matrice v:\n";
    //Range-based ( come for in )
    for (auto &elem: v)
        cout<< "Elemento di v = " <<  elem << "\n";
//----------------------------------------------------------------

    //Matrice allocata dinamicamente come puntatori ad array
    int **a = new int* [n];
    for (int i = 0; i < n; i++)
    a[i] = new int [m];

    a[1][2] = 5;
    cout << "Elemento a di [1][2]" << a[1][2]<<"\n";

    //deallocamento
    for ( int i = 0; i < n; i++)
        delete[] a[i] ;
//----------------------------------------------

    //matrice allocata dinamicamente come vettore , il programmatore stabilisce gli indici
    int *b = new int [2*3];
//-------------------------------------

    //Matrice allocata dinamicamente come vector di vector
    vector< vector<int>> c { {3,6,7}, {5,4}, {54,234,6}};
    cout << "Elemento c di [2][2]" << c[2][2]<<"\n";

    for (auto &elem: c)
        for (int j = 0 ; j < elem.size(); j++)
        cout<< "Elemento di c = " <<  elem[j] << "\n";


    //Matrice di vector allocata per righe e colonne tramite il resize
    vector<vector<int>> d;
    //essendo n una dimensione più grande di quella originale, ogni elemento nuovo viene impostato come vector<int>(m)
    d.resize(n, vector<int> (m));
//-------------------------------------------

    vector<string> nomi (3);
    nomi.push_back("Ciro");
    nomi.push_back("Gennaro");
    nomi.push_back("Pasquale");

    //iteratore
    vector<string>::iterator it;
    for (it = nomi.begin(); it < nomi.end(); it++)
        cout<<"Elemento di nomi: " << *it << "\n";

    return 0;
}
