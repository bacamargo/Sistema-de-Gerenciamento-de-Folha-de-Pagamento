#include <iostream>
#include "presidente.hpp"

using namespace std;

Presidente::Presidente(){

    setDesignacao("presidente");
}

void Presidente::setAreaFormacao(string graduation){

    areaFormacao= graduation;
}

string Presidente::getAreaFormacao(){

    return areaFormacao;
} 

void Presidente::Aumento(Funcionario *func){

    double novoSalario;

    novoSalario= func->getSalario() + (func->getSalario() * 0.3);

    func->setSalario(novoSalario);
}