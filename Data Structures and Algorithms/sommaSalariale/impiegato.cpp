//
// Created by 39331 on 05/10/2021.
//

#include "impiegato.h"

impiegato::impiegato(string n, float s) : nome(n), salario(s){}

void impiegato::print()  {cout<<"Nome: "<<nome <<endl<<"Salario: "<<salario<<endl;}

string impiegato::getNome() { return nome;}

float impiegato::getSalario() {return salario;}

float impiegato::operator+( impiegato i)
{
    return  salario + i.getSalario();
}



