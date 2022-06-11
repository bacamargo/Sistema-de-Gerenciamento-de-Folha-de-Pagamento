#pragma once

#include <iostream>
#include "funcionario.hpp"
#include "operador.hpp"
#include "gerente.hpp"
#include "presidente.hpp"
#include <vector>

using namespace std;

class Gerenciamento{

    public:
    Gerenciamento();
    void InserirFuncionario();
    void EditarFuncionario();
    void ExcluirFuncionario();
    int ExibirFuncionario();
    void ExibirListaFuncionario();
    void ExibirTipoFuncionario();
    void BuscarFuncionario();
    double CalcularFolhaSalarial(int mes);
    int ImprimirFolhaSalarial();
    void ImprimirFolhaSalarialEmpresa();
    void ConfigurarAumento();

    protected:
    std::vector <Funcionario *> listaFunc;

};