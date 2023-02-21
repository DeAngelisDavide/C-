#include <iostream>
#include <vector>
#define n 6

int fastestWay( int a[2][n], int t[2][n-1],int *e, int *x, int l[2][n]);

int main() {

    //e = tempo entrata, x = t uscita.
    int e[2] = { 2, 4},  x[2] = {3, 2};
    //Stazioni catene di montaggio
    int a[2][n]  = {7, 9 ,3, 4, 8, 4,   8, 5, 6, 4, 5, 7};

    //Tempi di traferimento
    int t[2][n-1] = {{2, 3, 1, 1, 4}, {2, 1, 2, 2, 1}};
    //Matrice delle soluzioni, dovrebbe essere n - 1 ma nell ultima posizione mi salvo il valore che mi indica quale riga guardare, non ottima ma perchè mi annoio
    int l[2][n];

    std::cout<<"Il risultato minore e': " << fastestWay(a,t,e,x,l)<<std::endl;

    std::cout<<"Il percorso effettuato e': "<<std::endl;
    //SOLUZIONE SBOCCHEVOLE


    //tampa del valore d'ingresso e primo valore della catena e verifica se ci sta un cambio di catena con conseguente stampa del tempo di transazionr
    std::cout<<e[l[1][n - 1] - 1]<<std::endl<<a[l[1][n - 1] - 1][0]<<std::endl;
    if (l[l[1][n - 1] - 1][0] != l[l[1][n - 1] - 1][1])
        std::cout << t[l[l[1][n - 1] - 1][0] - 1][0]<<std::endl;

    //Verifica se la soluzione giusta è la prima o la secodna riga
    if (l[1][n - 1] == 1)
    {

        for (int i = 1; i < n - 1; i++)
        {
            std::cout << a[l[0][i] - 1][i] << std::endl;
            if (l[0][i-1] != l[0][i])
                std::cout << t[l[0][i] - 1][i]<<std::endl;
        }

        std::cout <<a[0][n-1]<<std::endl<<x[0]<<std::endl;
    }
    else
    {
        for (int i = 1; i < n - 1; i++) {
            std::cout << a[l[1][i] - 1][i] << std::endl;

            if (l[1][i-1] -1 != l[1][i] - 1)
                std::cout << t[l[1][i] - 1][i]<<std::endl;
        }
        std::cout <<a[1][n-1]<<std::endl<<x[1]<<std::endl;
    }

    return 0;
}


int fastestWay( int a[2][n], int t[2][n-1],int *e, int *x, int l[2][n])
{
     int f1[n], f2[n];
     f1[0] = e[0] + a[0][0]; f2[0] = e[1] + a[1][0];

    for (int i = 1; i < n; i++) {
        //Verifica se a quella stazione conviene arriarci dalla scorsa oppure dalla scorsa dell'altra catena
        if(f1[i - 1] + a[0][i] <= f2[i - 1] + t[1][i - 1] + a[0][i]) {
            f1[i] = f1[i - 1] + a[0][i];
            l[0][i - 1] = 1;
        } else {
            f1[i] = f2[i - 1] + t[1][i - 1] + a[0][i];
            l[0][i - 1] = 2;
        }

        if (f2[i - 1] + a[1][i] <= f1[i - 1] + t[0][i - 1] + a[1][i]) {
            f2[i] = f2[i - 1] + a[1][i];
            l[1][i - 1] = 2;
        } else {
            f2[i] = f1[i - 1] + t[0][i - 1] + a[1][i];
            l[1][i - 1] = 1;
        }
    }

    //All'ultima posizione abbiamo il valore finale e verifichiamo quale è minore aggiungendogli il valore d'uscita
    if (f1[n - 1] + x[0] <= f2[n - 1] + x[1])
    {
        //Spiegato sopra alla dichiarazione della matrice
        l[1][n-1] = 1;
        return f1[n - 1] + x[0];
    }
        l[1][n-1] = 2;
        return  f2[n - 1] + x[1];
}