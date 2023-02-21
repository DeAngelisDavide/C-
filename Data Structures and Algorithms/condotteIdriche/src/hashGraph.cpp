#include "hashGraph.h"


template <class I>
hashGraph<I>::hashGraph(int n){
    T = new hashTable<I>(n);
}

template <class I>
vertice<I> *hashGraph<I>::searchVertice(I u) {
    return T->hashSearch(u);
}

template <class I>
int hashGraph<I>::addVertice(I u)
{
    if (searchVertice(u) == nullptr)
    {
        vertice<I> *a = new vertice<I>(u);
        if (T->hashInsert(a) != -1)
            //Vertice inserito
            return 0;
        else {
            //L'hashtable è piena
            a->~vertice();
            return -1;
        }
    }
    //Il vertice esiste già
    return -2;
}

template <class I>
int hashGraph<I>::addEdge(I u, I v) {
    vertice<I> *a = searchVertice(u);
    vertice<I> *b = searchVertice(v);

    //se i vertici non esistono nell'hash table allora li crea
    if (a != nullptr && b != nullptr)
        if (!a->searchEdge(b)) {
            a->addEdge(b);
            return 1;
        }
        else //L'arco gia esiste
            return 0;
    //Uno dei due vertici non esiste
    return -1;
}



template<class I>
void hashGraph<I>::setDfsVisit() {
    enum {white, gray, black};

    for (int i = 0; i < T->getDim(); i++) {
        vertice<I> *u = T->getVertice(i);
        if ( u != nullptr)
            if (u->getColor()!= white)
                u->setVisit();
    }
}


template <class I>
void hashGraph<I>::dfs_visit(vertice<I> *s, int &time) {
    enum {white, gray, black};
    s->setColor(gray);
    s->setD(time++);

    nodo<vertice<I>*> *u = s->getAdj()->getHeader();
    while (u != nullptr) {
        if (u->getInfo()->getColor() == white) {
            u->getInfo()->setP(s);
            dfs_visit(u->getInfo(), time);
        }
        u= u->getPNext();
    }
    s->setColor(black);
    s->setF(time++);
}


template<class I>
void hashGraph<I>::dfs_visit2(vertice<I> *s, linkedList<vertice<I>*> *L, int &time) {
    enum {white, gray, black};
    s->setColor(gray);
    s->setD(time++);

    nodo<vertice<I>*> *u = s->getAdj()->getHeader();
    while (u != nullptr) {
        if (u->getInfo()->getColor() == white) {
            u->getInfo()->setP(s);
            dfs_visit(u->getInfo(), time);
        }
        u= u->getPNext();
    }
    s->setColor(black);
    s->setF(time++);
    L->push(s);

}

template<class I>
linkedList<vertice<I>*> *hashGraph<I>::componentiConnesse() {
    enum {white, gray, black};

    setDfsVisit();

    //Dfs solo sula sorgente
    vertice<I> *u = T->hashSearch(0);
    int time = 0;
    dfs_visit(u,time);

    //ordinamento topologico sui restanti vertici
    time = 0;
    linkedList<vertice<I>*> *compConnesse = new linkedList<vertice<I>*>;
    for (int i = 0; i < T->getDim(); i++) {
        u = T->getVertice(i);
        if ( u != nullptr)
            if (u->getColor() == white)
                dfs_visit2(u, compConnesse, time);
    }


    //Set della visita solo sui vertici presenti nella lista
    nodo<vertice<I>*> *x = compConnesse->getHeader();
    while ( x != nullptr){
        x->getInfo()->setVisit();
        x = x->getPNext();
    }
    //Dfs sui vertici presenti nella lista

    x = compConnesse->getHeader();
    nodo<vertice<I>*> *y;
    while ( x != nullptr){
        y = x->getPNext();
        if (x->getInfo()->getColor() == white)
            dfs_visit(x->getInfo(), time);
        else
            //rimozione degli elementi già scoperti
            compConnesse->removeNode(x->getInfo());

        x = y;
    }

    return compConnesse;
}









