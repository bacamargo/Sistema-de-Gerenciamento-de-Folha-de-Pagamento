#include <iostream>
#include "presidente.h"

using namespace std;

Presidente::Presidente(string code, string name, string address, string number, string date, double salary, string graduation, string max) 
    :Funcionario(code, name, address, number, date, salary){

    setDesignacao("presidente");
    areaFormacao= graduation;
    formacaoAcademicaMax= max;
}

void Presidente::setAreaFormacao(string graduation){

    areaFormacao= graduation;
}

string Presidente::getAreaFormacao(){

    return areaFormacao;
} 

void Presidente::setFormacaoMax(string max){

    formacaoAcademicaMax= max;
}

string Presidente::getFormacaoMax(){

    return formacaoAcademicaMax;
} 

void Presidente::Aumento(Funcionario *func){

    double novoSalario;

    novoSalario= func->getSalario() + (func->getSalario() * 0.3);

    func->setSalario(novoSalario);
}

