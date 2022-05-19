#pragma once

#include <iostream>
#include "funcionario.hpp"
#include <vector>

using namespace std;

class Gerenciamento{

    public:
    Gerenciamento();
    void EditarFuncionario(int change, string code);
    void ExcluirFuncionario(string code);
    int ExibirFuncionario(string code);
    void ExibirListaFuncionario();
    void ExibirTipoFuncionario();
    void Aumento();
    void CalcularFolhaSalarial();
    void ImprimirFolhaSalarial();
    void ImprimirFolhaSalarialEmpresa();
    void BuscarFuncionario();

    private:
    std::vector <Funcionario> listaFunc;

};