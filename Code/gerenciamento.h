#pragma once

#include <iostream>
#include "funcionario.h"
#include "operador.h"
#include "gerente.h"
#include "presidente.h"
#include "diretor.h"
#include <vector>

using namespace std;

class Gerenciamento{

    public:
    Gerenciamento();

    void InserirFuncionario();
    void EditarFuncionario();
    void ExcluirFuncionario();
    void ExibirFuncionario(string code);
    void ExibirListaFuncionario();
    void ExibirTipoFuncionario();
    void BuscarFuncionario();
    double CalcularFolhaSalarial(int mes);
    void ImprimirFolhaSalarial();
    void ImprimirFolhaSalarialEmpresa();
    void ConfigurarAumento();

    string FormataData(int day, int month, int year);
    

    protected:
    std::vector <Funcionario *> listaFunc;

};