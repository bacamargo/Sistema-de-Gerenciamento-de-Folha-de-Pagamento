#pragma once

#include <iostream>
#include "funcionario.hpp"

using namespace std;

class Diretor : public Funcionario{

    private:
        string areaSupervisao;
        string areaFormacao;

    public:
        Diretor();
        void setAreaSupervisao(string area);
        void setAreaFormacao(string graduation);
        string getAreaSupervisao();
        string getAreaFormacao();
        void Aumento(Funcionario *diretor);
};