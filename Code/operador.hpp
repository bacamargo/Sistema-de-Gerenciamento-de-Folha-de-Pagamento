#pragma once

#include <iostream>
#include "funcionario.hpp"

using namespace std;

class Operador : public Funcionario {

    public:
        Funcionario operador;
        Operador();
        void Aumento();

};