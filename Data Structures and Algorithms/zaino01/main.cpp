#include <iostream>
#include <fstream>

const int punt_min = 5;

void inizializza(std::ifstream *, int *, int *);
int sumArray (int *, int);
void calcolaPunteggio( int *, int * , int **, int , int);

int main() {


    std::ifstream *f = new std::ifstream ("dati.txt");

    if(f->fail())
        return 1;

    const int n = 11;
    int *valori = new int[n];
    int *tempo = new int [n];
    inizializza( f, valori, tempo);

    int tempoTotale = sumArray(tempo, n);

    int **soluzione = new int *[n];
    for (int i = 0; i < n; i++)
        soluzione[i] = new int [tempoTotale + 1];

    calcolaPunteggio(valori, tempo, soluzione, n, tempoTotale + 1);

    //Scorre per colonne
    for (int i = 0; i < tempoTotale + 1; i++)
        for (int j = 0; j < n; ++j)
            //Quando trova il primo valore che rispetta il criterio
            //Visto che le colonne rappresentano i vari tempi
            if (soluzione[j][i] >= punt_min){
                std::cout<<"La soluione e' composta dagli elementi : "<<std::endl;
                //Va a ritroso per cercre tutti icomponenti della soluzione
                while (soluzione[j][i] != 0)
                {
                    std::cout<<j<<std::endl;
                    j -= 1; i = i - tempo[j];
                }
                i = tempoTotale;
                j = n;
            }
    return 0;
}

//Inizializza i deu array
void inizializza(std::ifstream *f, int *valori, int *tempo)
{
    std::string buffer, buffer2;
    std::getline(*f, buffer);
    std::getline(*f, buffer2);


    for (int i = 0, j = 0; i < buffer.length() ; i++)
        if (buffer[i] != ' ')
        {
            valori[j] = std::stoi(buffer.substr(i));
            tempo[j] = std::stoi(buffer2.substr(i));
            j++;
        }
}

//somma tutti gli elementi dell'array
int sumArray (int *a, int n )
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += *(a + i);

    return sum;
}

//zaino 01
void calcolaPunteggio( int *v, int *t , int **s, int n , int m)
{
    //caso banale oggetto 0
    for (int i = 0; i < m; i++)
        s[0][i] = 0;

    //Caso banale zaino peso 0
    for (int i = 0; i <  n; i++) {
        s[i][0] = 0;
    }

    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++) {
            //Se la capienza è minore della capienza massimo dello zaino
            if (t[i] <= j)
                s[i][j] = std::max(s[i-1][j], s[i-1][j-t[i]] + v[i]);
            else
                s[i][j] =  s[i-1][j];
        } 
}
