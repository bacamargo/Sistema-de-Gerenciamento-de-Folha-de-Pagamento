#pragma once

#include <iostream>
#include "funcionario.hpp"
#include <vector>

using namespace std;

class Gerenciamento{

    public:
    Gerenciamento();
    void EditarFuncionario(int alteracao, string atributo);
    void ExcluirFuncionario();
    void ExibirFuncionario();
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