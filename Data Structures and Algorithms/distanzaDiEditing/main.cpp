#include <iostream>

int distanzaEditing(std::string, std::string, int **, int **);
int main() {

    std::string a = "atctgat", b = "tgcata";

    //-----Inizializzazione matrici-----
    //Aggiungo uno sia a righe che colonne perchè sono il caso base in cui o una o l'altra sono vuote
    int **tabella = new int *[a.length() + 1];
    int **soluzione = new int *[a.length() + 1];
    for (int i = 0; i < a.length() + 1; ++i)
    {
        tabella[i] = new int[b.length() + 1];
        soluzione[i] = new int[b.length() + 1];
    }
    //----------------------------------
    std::cout<<"La distanza di editing e' "<<distanzaEditing(a, b, tabella, soluzione)<<std::endl;
    std::cout<<"Le operazioni eseguite sono: "<<std::endl;

    for (int i = a.length(), j = b.length(); i >= 0 && j >= 0 ;)
        //Si aggiunge quest' and perchè altrimenti metterlo nel for avrebbe impedito di stampare quando si raggiungeva i = 0 o j= 0
        if (soluzione[i][j] == 0 && j > 0)
        {
            std::cout << "Inserimento di " <<b.at(j-1)<<std::endl;
            j--;
        }
        else if(soluzione[i][j] == 1 && i > 0)
        {
            std::cout << "Cancellazione di "<<a.at(i-1)<<std::endl;
            i--;
        }
        else
        {
            if (tabella[i][j] != tabella[i-1][j-1])
                std::cout << "Sostituzione di " <<a.at(i-1)<< " con "<<b.at(j-1)<<std::endl;
            i--;j--;
        }


    return 0;
}

//Sinitra 0(inserimento), Alto 1(cancellazione), obliquo 3(sostituzione o corrispondenza)
int distanzaEditing(std::string a, std::string b, int **t, int **s)
{

    for (int i = 0; i < b.length() + 1; i++) {
        t[0][i] = i;
        s[0][i] = 0;
    }

    for (int i = 1; i < a.length() + 1; i++) {
        t[i][0] = i;
        s[i][0] = 1;
    }

    for (int i = 1; i < a.length() + 1; i++)
        for (int j = 1; j < b.length() + 1; j++)
            //Se i due caratteri sono uguali allora il valore è 0 + t[i-1][j-1]
            if (a.at(i - 1) == b.at(j - 1))
            {
                t[i][j] = t[i-1][j-1];
                s[i][j] = 3;
            }
            //Si valuta quale dei restanti tre casi da risultato minore
            else
            {
                //Se la sostituzione <= inserimento
                if (t[i-1][j-1] <= t[i][j-1] && t[i-1][j-1] <= t[i-1][j])
                {
                    t[i][j] = 1 + t[i-1][j-1];
                    s[i][j] = 3;
                }
                //Se l'inserimento <= cancellazione
                else if (t[i][j-1] <= t[i-1][j])
                {
                    t[i][j] = 1 + t[i][j-1];
                    s[i][j] = 0;
                }
                //Se la cancellazione è minore
                else
                {
                    t[i][j] = 1 + t[i -1][j];
                    s[i][j] = 1;
                }
            }

    return t[a.length()][b.length()];
}
