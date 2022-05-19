#include <iostream>
#include "presidente.hpp"

using namespace std;

Presidente::Presidente(){
    
}

void Presidente::setAreaFormacao(string graduation){

    areaFormacao= graduation;
}

string Presidente::getAreaFormacao(){

    return areaFormacao;
} 

void Presidente::Aumento(){

    double novoSalario;

    novoSalario= presidente.getSalario() + (presidente.getSalario() * 0.3);

    presidente.setSalario(novoSalario);
}