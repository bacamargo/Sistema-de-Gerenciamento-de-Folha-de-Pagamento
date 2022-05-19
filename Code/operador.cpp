#include <iostream>
#include "operador.hpp"

using namespace std;

Operador::Operador(){

}

void Operador::Aumento(){

    double novoSalario;

    novoSalario= operador.getSalario() + (operador.getSalario() * 0.1);

    operador.setSalario(novoSalario);
}