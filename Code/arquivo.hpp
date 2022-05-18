#pragma once

#include <iostream>

using namespace std;

class Arquivo{

 public:
    Arquivo();
    void EditarFuncionario();
    void ExcluirFuncionario();
    void ExibirFuncionario();
    void ExibirListaFuncionario();
    void ExibirTipoFuncionario();
    void Aumento();
    void CalcularFolhaSalarial();
    void ImprimirFolhaSalarial();
    void ImprimirFolhaSalarialEmpresa();
    void BuscarFuncionario();
};