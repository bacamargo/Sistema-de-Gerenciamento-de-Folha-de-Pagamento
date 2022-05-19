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

    // novoSalario= diretor.getSalario() + (diretor.getSalario() * 0.2);

    // diretor.setSalario(novoSalario);
}