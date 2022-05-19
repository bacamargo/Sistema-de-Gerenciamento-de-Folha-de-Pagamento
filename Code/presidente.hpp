#pragma once

#include <iostream>
#include "instituicao.hpp"

using namespace std;

class Presidente : public Instituicao{
    private:
        string areaFormacao;
        string formacaoAcademicaMax;

    public:
        Presidente();
        void setAreaFormacao(string graduation);
        string getAreaFormacao();
        void Aumento();
};