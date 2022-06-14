#pragma once

#include <iostream>
#include "funcionario.hpp"

using namespace std;

class Diretor : public Funcionario{

    private:
        string areaSupervisao;
        string areaFormacao;

    public:
        Diretor(string code, string name, string address, string number, string date, string designation, double salary);
        void setAreaSupervisao(string area);
        void setAreaFormacao(string graduation);
        string getAreaSupervisao();
        string getAreaFormacao();

        void setFormacaoMax(string area);    
        string getFormacaoMax();

        void Aumento(Funcionario *diretor);
};