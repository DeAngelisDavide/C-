//
// Created by 39331 on 05/10/2021.
//

#include "manager.h"

manager::manager(string n, float s, float b):impiegato(n,s), bonus(b) {}

void manager::print() {cout<<"Nome: "<<nome <<endl<<"Salario: "<<salario<<endl<<"Bonus "<<bonus<<endl; }

