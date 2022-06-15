#include <iostream>
#include "operador.h"

using namespace std;

Operador::Operador(string code, string name, string address, string number, string date, double salary) 
    : Funcionario(code, name, address, number , date, salary){

    setDesignacao("operador");
}

void Operador::Aumento(Funcionario *func){

    double novoSalario;

    novoSalario= func->getSalario() + (func->getSalario() * 0.05);

    func->setSalario(novoSalario);
}

