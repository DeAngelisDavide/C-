//
// Created by 39331 on 05/10/2021.
//

#ifndef SOMMASALARIALE_IMPIEGATO_H
#define SOMMASALARIALE_IMPIEGATO_H

#include <iostream>
#include <string>

using namespace std;

class impiegato {
protected:
    string nome;
    float salario;
public:
    impiegato( string, float);
    string getNome();
    float getSalario();
    void virtual print();
    float operator+( impiegato i);

};


#endif //SOMMASALARIALE_IMPIEGATO_H
