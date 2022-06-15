#pragma once

#include <iostream>
#include "funcionario.h"

using namespace std;

class Operador : public Funcionario {

    public:
        Operador(string code, string name, string address, string number, string date, double salary);

        void Aumento(Funcionario *func);

};
