#include <iostream>

#define n 5

int percorsoMigliore(int c[n][n], int s[n][n]);


int main() {

    int caselle[n][n] = { {6 ,7 ,4 ,7 ,8},
                          {7, 6, 1 ,1 ,4},
                          {3, 5, 7, 8, 2},
                          {2, 6, 7, 0, 2},
                          {7, 3, 5, 6, 1}};

    int soluzioni[n][n];

    std::cout<<"Il valore massimo del percorso e': "<< percorsoMigliore(caselle, soluzioni)<<std::endl;

    std::cout<<"il percorso effettuato e'"<<std::endl;
    for (int i = n-1, j = i; i >=0 && j>=0 ;)
    {
        std::cout<<caselle[i][j]<<std::endl;

        if (soluzioni[i][j] == 1)
            j--;
        else
            i--;

    }
}


//sinistra = 1 , alto = 2  ,
int percorsoMigliore(int c[n][n], int s[n][n])
{
    int p[n][n];
    //Inserimento primo valore
    p[0][0] = c[0][0];

    //Inizializzazione prima riga e prima colonna
    for (int i = 1; i < n; i++) {
          p[0][i] = p[0][i-1] + c[0][i];
          s[0][i] = 1;
          p[i][0] = p[i - 1][0] + c[i][0];
          s[i][0] = 2;
    }

    for (int i = 1; i < n; i++)
        for (int j = 1; j < n; j++)
        {
            //Se la soluzione a sinistra più l'elem corrente è >= della soluzione in alto più l'elem corrente
            if(p[i][j-1] + c[i][j] >= p[i-1][j] + c[i][j])
            {
                //scelta di andare a sinistra
                p[i][j] = p[i][j-1] + c[i][j];
                s[i][j] = 1;
            }
            else
            {
                //Scelta di andare in alto
                p[i][j] = p[i-1][j] + c[i][j];
                s[i][j] = 2;
            }
        }

    //Qui sarà contenuto il valore finale
    return p[n-1][n-1];
}