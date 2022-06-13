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
    void ExibirFuncionario(string code);
    void ExibirListaFuncionario();
    void ExibirTipoFuncionario();
    void BuscarFuncionario();
    double CalcularFolhaSalarial(int mes);
    int ImprimirFolhaSalarial();
    void ImprimirFolhaSalarialEmpresa();
    void ConfigurarAumento();

    string ValidaFormataData(int day, int month, int year);    //funcao pra formatar e validar a data inserida

    protected:
    std::vector <Funcionario *> listaFunc;

};