#include <iostream>
#include <fstream>

#include "risoluzione.h"

using namespace std;
int main()
{
    risoluzione r;
    if (!r.isAperto())
    {
        cout<<"Errore nell'apertura del file";
        return 1;
    }
    r.risolvi();
    return 0;
}
