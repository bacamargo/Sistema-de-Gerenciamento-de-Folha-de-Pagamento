#include <iostream>
#include "gerente.hpp"

using namespace std;

Gerente::Gerente(string code, string name, string address, string number, string date, string designation, double salary){

    setCodigo(code);
    setNome(name);
    setEndereco(address);
    setTelefone(number);
    setDesignacao(designation);
    setSalario(salary);
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

void Gerente::setAreaFormacao(string graduation){

}

void Gerente::setFormacaoMax(string max){

}

string Gerente::getAreaFormacao(){

    return "";
}

string Gerente::getFormacaoMax(){

    return "";
}