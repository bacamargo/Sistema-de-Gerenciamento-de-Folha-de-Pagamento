#pragma once

#include <iostream>
#include "funcionario.h"

using namespace std;

class Diretor : public Funcionario{

    private:
        string areaSupervisao;
        string areaFormacao;

    public:
        Diretor(string code, string name, string address, string number, string date, double salary, string supervision, string graduation);
        void setAreaSupervisao(string area);
        void setAreaFormacao(string graduation);
        string getAreaSupervisao();
        string getAreaFormacao();

        void Aumento(Funcionario *diretor);
};