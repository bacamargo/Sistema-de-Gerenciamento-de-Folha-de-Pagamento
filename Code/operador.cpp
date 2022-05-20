#include <iostream>
#include "operador.hpp"

using namespace std;

Operador::Operador(){

    setDesignacao("operador");
}

void Operador::Aumento(Funcionario *operad){

    double novoSalario;

    novoSalario= operad->getSalario() + (operad->getSalario() * 0.05);

    operad->setSalario(novoSalario);
}