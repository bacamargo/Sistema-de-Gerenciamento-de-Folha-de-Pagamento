#include <iostream>
#include "operador.hpp"

using namespace std;

Operador::Operador(){

    setDesignacao("operador");
}

void Operador::Aumento(Funcionario *func){

    double novoSalario;

    novoSalario= func->getSalario() + (func->getSalario() * 0.05);

    func->setSalario(novoSalario);
}