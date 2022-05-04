#include <iostream>
#include "funcionario.hpp"

using namespace std;

Funcionario::Funcionario(string designation){
    designacao = designation;
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
    ingresso = date;
}

string Funcionario::getIngresso(){
    return ingresso;
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