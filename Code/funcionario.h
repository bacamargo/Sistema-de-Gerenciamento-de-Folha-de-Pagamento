#pragma once

#include <iostream>
#include <vector>

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
        vector<string> folhasMensais= {"","", "","","","","","","","","",""};

    public:
        Funcionario(string code, string name, string address, string number, string date, double salary);

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
        void setDesignacao(string designation);
        string getDesignacao();
        void setSalario(double salary);
        double getSalario();
        void setDescontoINSS(double discount);
        double getDescontoINSS();
        void setDescontoImposto(double tax);
        double getDescontoImposto();
        void setSalarioLiquido(double sal);
        double getSalarioLiquido();

        void setFolhaMensal(string paper, int month);
        string getFolhaMensal(int month);

        //metodos que terao nas classes filhas:
        virtual void Aumento(Funcionario *func)=0;
        
        // virtual void setAreaFormacao(string graduation);
        // virtual void setFormacaoMax(string max);
        // virtual void setAreaSupervisao(string area);
        // virtual string getAreaFormacao();
        // virtual string getFormacaoMax();
        // virtual string getAreaSupervisao();
};