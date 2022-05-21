#pragma once

#include <iostream>
#include "funcionario.hpp"
#include <vector>

using namespace std;

class Gerenciamento{

    public:
    Gerenciamento();
    void InserirFuncionario(Funcionario *newFunc);
    void EditarFuncionario(int change, string code);
    void ExcluirFuncionario(string code);
    int ExibirFuncionario(string code);
    void ExibirListaFuncionario();
    void ExibirTipoFuncionario(string designation);
    void BuscarFuncionario(string search);
    double CalcularFolhaSalarial(int mes);
    void ImprimirFolhaSalarial(string searched);
    void ImprimirFolhaSalarialEmpresa();
    

    protected:
    std::vector <Funcionario *> listaFunc;

};