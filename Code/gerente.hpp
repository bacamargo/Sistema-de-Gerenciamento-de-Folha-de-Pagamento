#pragma once

#include <iostream>
#include "funcionario.hpp"

using namespace std;

class Gerente : public Funcionario{
    private:
        string areaSupervisao;

    public:
        Gerente(string code, string name, string address, string number, string date, string designation, double salary);
        void setAreaSupervisao(string area);
        string getAreaSupervisao();

        void setAreaFormacao(string graduation);
        void setFormacaoMax(string max);
        string getAreaFormacao();
        string getFormacaoMax();

        void Aumento(Funcionario *func);
};