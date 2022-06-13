#pragma once

#include <iostream>
#include "funcionario.hpp"

using namespace std;     

class Presidente : public Funcionario{
    private:
        string areaFormacao;
        string formacaoAcademicaMax;

    public:
        Presidente();
        void setAreaFormacao(string graduation);
        void setFormacaoMax(string max);
        string getAreaFormacao();
        string getFormacaoMax();
        void Aumento();
};