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
    int ImprimirFolhaSalarial();
    void ImprimirFolhaSalarialEmpresa();
    void ConfigurarAumento();

    string ValidaFormataData(int day, int month, int year);    //funcao pra formatar e validar a data inserida
    void EscreverArquivo(vector<Funcionario*> Func);
    void LerArquivo();

    protected:
    std::vector <Funcionario *> listaFunc;

};