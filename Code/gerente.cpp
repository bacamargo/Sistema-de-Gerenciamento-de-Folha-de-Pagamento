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

void Gerente::Aumento(Funcionario *gerente){

    double novoSalario;

    novoSalario= gerente->getSalario() + (gerente->getSalario() * 0.1);

    gerente->setSalario(novoSalario);
}