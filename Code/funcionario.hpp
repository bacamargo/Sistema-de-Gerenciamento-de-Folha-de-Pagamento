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
        double descontoINSS;
        double descontoImposto;
        double salarioLiquido;

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
        void setDescontoINSS(double discount);
        double getDescontoINSS();
        void setDescontoImposto(double tax);
        double getDescontoImposto();
        void setSalarioLiquido(double sal);
        double getSalarioLiquido();

        //metodos que terao nas classes filhas:
        virtual void Aumento()=0;
        virtual void setAreaFormacao(string graduation);
        virtual void setFormacaoMax(string max);
        virtual string getAreaFormacao();
        virtual string getFormacaoMax();
        virtual void setAreaSupervisao(string area);
        virtual string getAreaSupervisao();
};