#include <iostream>
#include "gerente.hpp"

using namespace std;

Gerente::Gerente(){
    
    setDesignacao("gerente");
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