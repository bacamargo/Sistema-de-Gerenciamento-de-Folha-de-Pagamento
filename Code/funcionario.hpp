#include <iostream>

using namespace std;

class Funcionario {
    private:
        int codigo;
        string nome;
        string endereco;
        string telefone;
        string ingresso;
        string designacao;
        double salario;

    public:
        Funcionario();
        void setCodigo(int code);
        int getCodigo();
        void setNome(string name);
        string getNome();
        void setEndereco(string address);
        string getEndereco();
        void setIngresso(string date);
        string getIngresso();
        void setDesignacao(string position);
        string getDesignacao();
        void setSalario(double salary);
        double getSalario();
};