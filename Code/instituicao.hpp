#pragma once

#include <iostream>
#include "funcionario.hpp"
#include <vector>

using namespace std;

class Instituicao{

    public:
    Instituicao();
    virtual void InserirFuncionario()= 0;
    void EditarFuncionario(int change, string code);
    void ExcluirFuncionario(string code);
    int ExibirFuncionario(string code);
    void ExibirListaFuncionario();
    void ExibirTipoFuncionario(string designation);
    void BuscarFuncionario(string search);
    virtual void Aumento()= 0;
    double CalcularFolhaSalarial(int mes);
    void ImprimirFolhaSalarial();
    void ImprimirFolhaSalarialEmpresa();
    

    protected:
    std::vector <Funcionario> listaFunc;

};