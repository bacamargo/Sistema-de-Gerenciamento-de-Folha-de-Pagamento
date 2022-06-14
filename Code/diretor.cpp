#include <iostream>
#include "diretor.hpp"

using namespace std;

Diretor::Diretor(string code, string name, string address, string number, string date, string designation, double salary){

    setCodigo(code);
    setNome(name);
    setEndereco(address);
    setTelefone(number);
    setDesignacao(designation);
    setSalario(salary);
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

void Diretor::setFormacaoMax(string area){

}    

string Diretor::getFormacaoMax(){

    return "";
}