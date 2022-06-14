#pragma once

#include <iostream>
#include "funcionario.hpp"

using namespace std;     

class Presidente : public Funcionario{
    private:
        string areaFormacao;
        string formacaoAcademicaMax;

    public:
        Presidente(string code, string name, string address, string number, string date, string designation, double salary);
        void setAreaFormacao(string graduation);
        void setFormacaoMax(string max);
        string getAreaFormacao();
        string getFormacaoMax();

        void setAreaSupervisao(string area);
        string getAreaSupervisao();

        void Aumento(Funcionario *func);
};