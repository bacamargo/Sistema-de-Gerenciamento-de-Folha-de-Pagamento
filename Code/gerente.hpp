#pragma once

#include <iostream>
#include "funcionario.hpp"

using namespace std;

class Gerente : public Funcionario{
    private:
        string areaSupervisao;

    public:
        Funcionario gerente;
        Gerente();
        void setAreaSupervisao(string area);
        string getAreaSupervisao();
        void Aumento();
};