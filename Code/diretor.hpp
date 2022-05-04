#pragma once

#include <iostream>
#include "funcionario.hpp"

using namespace std;

class Diretor : public Funcionario {
    private:
        string areaSupervisao;
        string areaFormacao;

    public:
        Diretor();
};