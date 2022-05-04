#pragma once

#include <iostream>
#include "funcionario.hpp"

using namespace std;

class Gerente : public Funcionario {
    private:
        string areaSupervisao;

    public:
        Gerente();
};