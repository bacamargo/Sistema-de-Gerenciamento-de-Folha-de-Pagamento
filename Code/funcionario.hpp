#pragma once

#include <iostream>

using namespace std;

class Funcionario{
    private:
        string codigo;
        string nome;
        string endereco;
        string telefone;
        string dataIngresso;
        string designacao;
        double salario;

    public:
        Funcionario();
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
        string setDesignacao(string designation);
        string getDesignacao();
        void setSalario(double salary);
        double getSalario();
        virtual void Aumento()=0
};