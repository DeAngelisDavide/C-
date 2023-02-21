#ifndef HASHGRAPH_H
#define HASHGRAPH_H


#include "../src/hashTable.cpp"

template <class I>
class hashGraph {
private:
    hashTable<I> *T;
    void setDfsVisit();
    void dfs_visit(vertice<I> *s, int &time);
    void dfs_visit2(vertice<I> *s, linkedList<vertice<I>*> *, int &time);
public:
    hashGraph(int n);
    vertice<I> *searchVertice(I u);
    int addVertice(I u);
    int addEdge(I u, I v);
    linkedList<vertice<I>*> *componentiConnesse();

};
#endif // HASHGRAPH_H
