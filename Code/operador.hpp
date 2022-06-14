#pragma once

#include <iostream>
#include "funcionario.hpp"

using namespace std;

class Operador : public Funcionario {

    public:
        Operador(string code, string name, string address, string number, string date, string designation, double salary);
        void Aumento(Funcionario *func);


        void setAreaFormacao(string graduation);
        void setFormacaoMax(string max);
        void setAreaSupervisao(string area);
        string getAreaFormacao();
        string getFormacaoMax();
        string getAreaSupervisao();
};
