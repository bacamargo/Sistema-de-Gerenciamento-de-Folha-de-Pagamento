#pragma once

#include <iostream>
#include "instituicao.hpp"

using namespace std;

class Gerente : public Instituicao{
    private:
        string areaSupervisao;

    public:
        Funcionario gerente;
        Gerente();
        void setAreaSupervisao(string area);
        string getAreaSupervisao();
        void Aumento();
};