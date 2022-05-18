#pragma once

#include <iostream>

using namespace std;

class Funcionario {
    protected:
        string codigo;
        string nome;
        string endereco;
        string telefone;
        string dataIngresso;
        string designacao;
        double salario;

    public:
        Funcionario(string designation);
        void setCodigo(string code);
        string getCodigo();
        void setNome(string name);
        string getNome();
        void setEndereco(string address);
        string getEndereco();
        void setTelefone(string number);
        string getTelefone();
        void setIngresso(string date);
        string getIngresso();
        string getDesignacao();
        void setSalario(double salary);
        double getSalario();
};