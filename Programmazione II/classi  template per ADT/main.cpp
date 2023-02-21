#include <iostream>

#include <stack>
#include <queue>
#include <forward_list>
#include <iterator>
#include <list>

using namespace std;

void visualizza_stack( stack <int>);
void visualizza_coda( queue <int>);
void visualizza_lista_uni(forward_list<int>);

int main() {
    //STACK
    stack<int>  stk;

    stk.push(5);
    stk.push(3);

    cout<<"Visualizzazione stack"<<endl;
    visualizza_stack(stk);

    //CODA
    queue<int> que;

    que.push(5);
    que.push(3);

    cout<<"visualizzazione coda"<<endl;
    visualizza_coda(que);


    //FORWARD LIST
    forward_list<int> flist;
    forward_list<int>::iterator it;

    flist.push_front(5);
    it = flist.begin();
    it = flist.insert_after(it, {3 , 5 ,7});
    it = flist.begin();
    advance(it, 2 ); //Può andare solo avanti

    cout<<"Nodo puntato da it: "<<*it<<endl;

    cout<<"Visualizzazione lista unidirezionale"<<endl;
    visualizza_lista_uni(flist);

    //LISTA BIDEREZIONALE
    list<int> listaBid;
    list<int>::iterator itB;

    listaBid.push_front(5);
    itB = listaBid.begin();
    itB = listaBid.insert(itB, 3 , 4);
    advance(itB, -2); //Può tornare indietro

    cout<<"Nodo puntato da itB: "<<*itB<<endl;

    return 0;

}

//STACK
void visualizza_stack( stack<int> s)
{
    while (!s.empty())
    {
        cout<<s.top();
        s.pop();
    }
}

//CODA
void  visualizza_coda(queue<int> q)
{
    while (!q.empty())
    {
        cout<<q.front()<<endl;
        q.pop();
    }

}

void visualizza_lista_uni(forward_list<int> fl)
{
    forward_list<int>::iterator it;
    forward_list<int>::iterator fIt;

    it = fl.begin();
    fIt = fl.end();

    while (it != fIt)
    cout<<*it++<<endl;


}
