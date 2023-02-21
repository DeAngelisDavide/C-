#include <iostream>
#include <fstream>
#include <map>

//E' fatto tutto in un file per motivi di sfasteriamneto --> Da migliorare
using namespace std;

void wordscount(map<string,int> &, string);
void visualizzaMap(map<string,int>);

int main() {

    map<string,int> ws;
    wordscount(ws, "testo.txt");
    visualizzaMap(ws);
    return 0;
}


void wordscount(map<string,int> &m, string const path)
{
    //Apertura e creazione file
    ifstream f;
    f.open(path);

    //Conterrà le parole del file
    string word;
    //conterrà il risultato della ricerca
    map<string, int>::iterator it;
    while (f >> word)
    {
        //Ritorna un iteratore all'elemento se trova il corrispondente altrimenti iter alla fine della lista
        it = m.find(word);

        if (it == m.end())
            m.insert(make_pair(word, 1));
        else
            it->second++;
    }

    f.close();
}

void visualizzaMap(map<string,int> m)
{
    cout<<"Visualizzazione ricorrenze parole: "<<endl;
        for (auto x:m)
        cout<<'['<<x.first<<']'<<'='<<x.second<<endl;

}

