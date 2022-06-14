#include <iostream>
#include "presidente.hpp"

using namespace std;

Presidente::Presidente(string code, string name, string address, string number, string date, string designation, double salary){

    setCodigo(code);
    setNome(name);
    setEndereco(address);
    setTelefone(number);
    setDesignacao(designation);
    setSalario(salary);
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

void Presidente::setAreaSupervisao(string area){

}

string Presidente::getAreaSupervisao(){

    return "";
}