#include <iostream>

#include "abr.h"
#include "abr.cpp"

#define k 5
#define k1 -8
#define k2 15

int main() {

     int temp[] = {34, -2, 54, 3, 90, 0, -3};
     nodo *n1 = new nodo; n1->key = 34;
     nodo *n2 = new nodo; n2->key = -2;
     nodo *n3 = new nodo; n3->key = 54;
     nodo *n4 = new nodo; n4->key = 3;
     nodo *n5 = new nodo; n5->key = 91;
     nodo *n6 = new nodo; n6->key = 0;
     nodo *n7 = new nodo; n7->key = -3;

     abr *a = new abr;
     a->insert(a->getRoot(), n1);
     a->insert(a->getRoot(), n2);
     a->insert(a->getRoot(), n3);
     a->insert(a->getRoot(), n4);
     a->insert(a->getRoot(), n5);
     a->insert(a->getRoot(), n6);
     a->insert(a->getRoot(), n7);

     a->visitaSimmetrica(a->getRoot());

     std::cout<<"Il max dell'albero e' "<<a->maximum(a->getRoot())->key<<std::endl;
     std::cout<<"Il min dell'albero e' "<<a->minimum(a->getRoot())->key<<std::endl;

     nodo *suc = a->successor(n5);
     if ( suc != nullptr)
        std::cout<<"Il succesore di "<<n5->key<<" e' "<<suc->key<<std::endl;
     else
         std::cout<<"Il successore  di "<<n5->key<<" non esiste"<<std::endl;

    nodo *pre = a->predecessor(n5);
    if ( pre != nullptr)
        std::cout<<"Il predecessore di "<<n1->key<<" e' "<<pre->key<<std::endl;
    else
        std::cout<<"Il predecessore  di "<<n1->key<<" non esiste"<<std::endl;

    a->delet(n6);
    std::cout<<"Abr dopo eliminazione di "<<n6->key<<std::endl;
    a->visitaSimmetrica(a->getRoot());

    std::cout<<"somma delle foglie = "<<a->sumFoglie(a->getRoot())<<std::endl;
    std::cout<<"somma dei nodi minori di "<<k<<" = "<<a->sumLessk(a->getRoot(), k)<<std::endl;
    std::cout<<"somma dei nodi compresi tra "<<k1<<" e "<<k2<<" = "<<a->sumBetween(a->getRoot(), k1, k2)<<std::endl;

    nodo *sucDis = a->successorDispari(n4);
    if ( sucDis != nullptr)
        std::cout<<"successore dispari di "<<n4->key<<" = "<<sucDis->key<<std::endl;
    else
        std::cout<<"Il successore dispari di "<<n4->key<<" non esiste"<<std::endl;

    return 0;
}
