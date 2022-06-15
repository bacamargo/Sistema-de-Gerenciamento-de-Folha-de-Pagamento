#pragma once

#include <iostream>
#include "funcionario.h"

using namespace std;

class Gerente : public Funcionario{
    private:
        string areaSupervisao;

    public:
        Gerente(string code, string name, string address, string number, string date, double salary, string supervision);
        void setAreaSupervisao(string area);
        string getAreaSupervisao();

        void Aumento(Funcionario *func);
};