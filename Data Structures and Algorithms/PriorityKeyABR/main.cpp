#include <iostream>

#include "priorityKey.cpp"
#define k1 92

int main() {
    nodo *n1 = new nodo; n1->key = 34;
    nodo *n2 = new nodo; n2->key = -2;
    nodo *n3 = new nodo; n3->key = 54;
    nodo *n4 = new nodo; n4->key = 3;
    nodo *n5 = new nodo; n5->key = 91;
    nodo *n6 = new nodo; n6->key = 0;
    nodo *n7 = new nodo; n7->key = -3;

    priorityKey *a = new priorityKey;
    a->abrInsert(n1);
    a->abrInsert(n2);
    a->abrInsert(n3);
    a->abrInsert(n4);
    a->abrInsert(n5);
    a->abrInsert(n6);
    a->abrInsert(n7);

    std::cout<<"Massimo = "<<a->abrMaximum()->key<<std::endl;
    std::cout<<"estrazione massimo "<< a->abrExtractMax()->key<<std::endl;
    a->vistaSimmetrica();
    std::cout<<"Incremento di "<<n7->key<< " in "<<k1<<std::endl;
    a->abrIncreseKey(n7, k1);
    a->vistaSimmetrica();

    return 0;

}
