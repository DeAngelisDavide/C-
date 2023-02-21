#include <iostream>
#include <fstream>
#include <sstream>
#include "src/hashGraph.cpp"


//Inizializza l'hashtable con il file di input
hashGraph<int> *inizializza();
void printArchiDaCostruire(linkedList<vertice<int>*> *compConnesse, vertice<int> *s);

int main() {

    hashGraph<int> *T = inizializza();
    if (T == nullptr) {
        std::cout << "Errore nell'apertura del file";
        return -1;
    }

    linkedList<vertice<int>*> *compConnesse = T->componentiConnesse();
    printArchiDaCostruire(compConnesse, T->searchVertice(0));
    return 0;

}

//Inizializza l'hashtable con il file di input
hashGraph<int> *inizializza(){

    //Inizializzazione del file
    std::string path =  "../T2/Q2/input0_2_2.txt", choice;
    std::cout<<"1 per inserire il path del percorso file\nUn altro valore per "<<path<<std::endl;
    std::cin>>choice;

    if (choice == "1" )
    {
        std::cout<<"Inserire il path"<<std::endl;
        std::cin>>path;
    }

    std::ifstream f (path);

    if(f.fail())
        return nullptr;

    //u e v conteranno gli identificativi dei vertici
    std::string buffer, u, v;
    std::getline(f, buffer);
    int n = std::stoi(buffer)+1;
    hashGraph<int> *T = new hashGraph<int>(n);

    for (int i = 0; i < n; i++)
        T->addVertice(i);

    //r conterrà il risultato della funzione addEdge
    int r;

    std::getline(f, buffer);
    while (buffer.length() != 0 && !f.eof()) {
        std::stringstream s(buffer);
        s>>u>>v;
        int a = std::stoi(u), b = std::stoi(v);

        if (a < n && b < n) {
            //Se u era già esistente
            if (T->addEdge(a, b) == 0)
                std::cout << "Non e' stato inserito l'arco " << u << "-" << v << " perche' esiste gia\n'";
        } else
            std::cout << "Non e' stato possibile creare l'arco " << u << "-" << v
                      << ". Uno o entrambi i vertici non sono presenti nell'grafo" << std::endl;

        std::getline(f, buffer);
        }
    return T;
}

void printArchiDaCostruire(linkedList<vertice<int>*> *compConnesse, vertice<int> *s){
    std::cout<<"Le condotte da costruire sono : "<<compConnesse->getLenght()<<std::endl;

    nodo<vertice<int>*> *x = compConnesse->getHeader();
    while (x != nullptr) {
        std::cout << s->getData() << "-" << x->getInfo()->getData()<<std::endl;
        x = x->getPNext();
    }
}
