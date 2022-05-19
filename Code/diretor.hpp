#pragma once

#include <iostream>
#include "instituicao.hpp"

using namespace std;

class Diretor : public Instituicao{

    private:
        string areaSupervisao;
        string areaFormacao;

    public:
        Funcionario diretor;
        void setAreaSupervisao(string area);
        void setAreaFormacao(string graduation);
        string getAreaSupervisao();
        string getAreaFormacao();
        void Aumento();
};