#pragma once

#include <iostream>
#include "funcionario.h"

using namespace std;     

class Presidente : public Funcionario{
    private:
        string areaFormacao;
        string formacaoAcademicaMax;

    public:
        Presidente(string code, string name, string address, string number, string date, double salary, string graduation, string max);
        void setAreaFormacao(string graduation);
        void setFormacaoMax(string max);
        string getAreaFormacao();
        string getFormacaoMax();



        void Aumento(Funcionario *func);
};