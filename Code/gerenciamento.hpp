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
    void ExibirTipoFuncionario(string designation);
    void BuscarFuncionario(string search);
    virtual void Aumento()= 0;
    void CalcularFolhaSalarial();
    void ImprimirFolhaSalarial();
    void ImprimirFolhaSalarialEmpresa();
    

    private:
    std::vector <Funcionario> listaFunc;

};