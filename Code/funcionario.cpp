#include <iostream>
#include "funcionario.hpp"

using namespace std;

Funcionario::Funcionario(){
    
}

void Funcionario::setCodigo(string code){
    codigo = code;
}
string Funcionario::getCodigo(){
    return codigo;
}

void Funcionario::setNome(string name){
    nome = name;
}

string Funcionario::getNome(){
    return nome;
}

void Funcionario::setEndereco(string address){
    endereco = address;
}

string Funcionario::getEndereco(){
    return endereco;
}

void Funcionario::setTelefone(string number){
    telefone = number;
}

string Funcionario::getTelefone(){
    return telefone;
}

void Funcionario::setIngresso(string date){
    dataIngresso = date;
}

string Funcionario::getIngresso(){
    return dataIngresso;
}

string Funcionario::setDesignacao(string designation){

    designacao= designation;
}

string Funcionario::getDesignacao(){
    return designacao;
}

void Funcionario::setSalario(double salary){
    salario = salary;
}

double Funcionario::getSalario(){
    return salario;
}