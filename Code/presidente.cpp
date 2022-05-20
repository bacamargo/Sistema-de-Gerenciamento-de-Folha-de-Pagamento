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

void Presidente::Aumento(Funcionario *presid){

    double novoSalario;

    novoSalario= presid->getSalario() + (presid->getSalario() * 0.3);

    presid->setSalario(novoSalario);
}