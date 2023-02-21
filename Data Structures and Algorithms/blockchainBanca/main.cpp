#include <iostream>
#include "blockchain.h"

#include "nodo.cpp"
#include "linkedList.cpp"


int main() {

    //Devo creare una serie di transazioni da passare nel costruttore di nodi transazioni che a loro volta vanno passati
    //nelle linked list della classe blocchi. I vari blocchi vanno poi inseriti nella linked list blocchi di blockchain

    transazioni t1 ("A", "B", 230.45);
    transazioni t2 ("C", "B", 30.432);
    transazioni t3 ("B", "A", 252.25);
    transazioni t4 ("A", "B", 12.55);
    transazioni t5 ("B", "C", 4320.432);
    transazioni t6 ("B", "A", 221.25);

    //nodo<transazioni> *te = new nodo<transazioni>()<;
    nodo<transazioni> *nt1 = new nodo<transazioni>(t1);
    nodo<transazioni> *nt2 = new nodo<transazioni>(t2);
    nodo<transazioni> *nt3 = new nodo<transazioni>(t3);
    nodo<transazioni> *nt4 = new nodo<transazioni>(t4);
    nodo<transazioni> *nt5 = new nodo<transazioni>(t5);
    nodo<transazioni> *nt6 = new nodo<transazioni>(t6);

    //nodi1 -> b1 , nodi2 -> b2 , nodi3 -> b3 ecc
    blocchi b1("21/05/2021");
    b1.getListTransazioni()->inserisciElemento(nt1);
    b1.getListTransazioni()->inserisciElemento(nt2);
    b1.getListTransazioni()->inserisciElemento(nt3);
    nodo<blocchi> *nb1= new nodo<blocchi>(b1);

    blocchi b2("22/05/2021");
    b2.getListTransazioni()->inserisciElemento(nt4);
    b2.getListTransazioni()->inserisciElemento(nt5);
    b2.getListTransazioni()->inserisciElemento(nt6);
    nodo<blocchi> *nb2 = new nodo<blocchi>(b2);

    //b2 -> insElemBlockch
    blockchain *bk = new blockchain();
    bk->getListBlocchi()->inserisciElemento(nb1);
    bk->getListBlocchi()->inserisciElemento(nb2);

    bk->print();

    float bilancio = bk->bilancio("A");
    std::cout<<"Il bilancio e': "<<bilancio<<std::endl;

    return 0;
}
