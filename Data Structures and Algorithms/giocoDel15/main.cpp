#include <iostream>
#include "giocoDel15.h"
#include <thread>
#include <mutex>
#include "giocoDel15.cpp"

mutex mux;

void funzione(giocoDel15 g, string s, bool *v)
{
    mux.lock();
    g.verificaConfigurazioneThred(s, v);
    mux.unlock();
}


int main() {

    giocoDel15 g("configurazione1.txt");

    if (g.verificaConfigurazione())
        cout<<"la configurazione e' corretta"<<endl;
    else
        cout<<"La configurazione e' errata";

    //Prova con i thread
    giocoDel15 gThread;
    gThread.visualizzaMatrice();
    bool v;
    thread th1 ( funzione, gThread,  "configurazione2.txt", &v);

    thread th2 ( funzione, gThread, "configurazione3.txt", &v);
    th1.join();
    th2.join();


    return 0;
}
