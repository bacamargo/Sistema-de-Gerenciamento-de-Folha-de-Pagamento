#include <iostream>
#include "diretor.hpp"

using namespace std;

Diretor::Diretor(){

    setDesignacao("diretor");
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

