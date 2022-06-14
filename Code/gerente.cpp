#include <iostream>
#include "gerente.h"

using namespace std;

Gerente::Gerente(string code, string name, string address, string number, string date, double salary, string supervision) 
    : Funcionario(code, name, address, number , date, salary){

    setDesignacao("gerente");
    areaSupervisao= supervision;
}


void Gerente::setAreaSupervisao(string area){

    areaSupervisao= area;
}

string Gerente::getAreaSupervisao(){

    return areaSupervisao;
}

void Gerente::Aumento(Funcionario *func){

    double novoSalario;

    novoSalario= func->getSalario() + (func->getSalario() * 0.1);

    func->setSalario(novoSalario);
}
