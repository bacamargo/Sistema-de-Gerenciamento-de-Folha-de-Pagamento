#include <iostream>
#include "operador.hpp"

using namespace std;

Operador::Operador(string code, string name, string address, string number, string date, string designation, double salary){

    setCodigo(code);
    setNome(name);
    setEndereco(address);
    setTelefone(number);
    setDesignacao(designation);
    setSalario(salary);
}

void Operador::Aumento(Funcionario *func){

    double novoSalario;

    novoSalario= func->getSalario() + (func->getSalario() * 0.05);

    func->setSalario(novoSalario);
}

void Operador::setAreaFormacao(string graduation){

}

void Operador::setFormacaoMax(string max){

}

void Operador::setAreaSupervisao(string area){

}

string Operador::getAreaFormacao(){
    
    return "";
}

string Operador::getFormacaoMax(){

    return "";
}

string Operador::getAreaSupervisao(){

    return "";
}