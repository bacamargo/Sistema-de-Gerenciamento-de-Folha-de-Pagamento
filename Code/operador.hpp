#pragma once

#include <iostream>
#include "instituicao.hpp"

using namespace std;

class Operador : public Instituicao {

    public:
        Funcionario operador;
        Operador();
        void Aumento();

};