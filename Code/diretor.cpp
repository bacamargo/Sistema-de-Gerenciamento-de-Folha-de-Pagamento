#include <iostream>
#include "diretor.h"

using namespace std;

Diretor::Diretor(string code, string name, string address, string number, string date, double salary, string supervision, string graduation) 
    : Funcionario(code, name, address, number, date, salary){

    setDesignacao("diretor");
    areaSupervisao= supervision;
    areaFormacao= graduation;
}


void Diretor::setAreaSupervisao(string area){

    areaSupervisao= area;
}

void Diretor::setAreaFormacao(string graduation){

    areaFormacao= graduation;
}

string Diretor::getAreaSupervisao(){

    return areaSupervisao;
}

string Diretor::getAreaFormacao(){

    return areaFormacao;
} 

void Diretor::Aumento(Funcionario *diretor){

    double novoSalario;

    novoSalario= diretor->getSalario() + (diretor->getSalario() * 0.2);

    diretor->setSalario(novoSalario);
}
