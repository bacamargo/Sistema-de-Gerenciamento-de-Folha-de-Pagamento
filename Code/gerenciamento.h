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
    ~Gerenciamento();

    void InserirFuncionario();
    void EditarFuncionario();
    void ExcluirFuncionario();
    void ExibirFuncionario(string code);
    void ExibirListaFuncionario();
    void ExibirTipoFuncionario();
    void BuscarFuncionario(string search);

    double CalcularFolhaSalarial(int mes);
    void ImprimirFolhaSalarial();
    void ImprimirFolhaSalarialEmpresa();
    void ConfigurarAumento();
    void SalvarFolhaSalarial(int mes);
    void ConfereCodigo(string code);
    void ExistePresid();

    string FormataData(int day, int month, int year);
    void ValidaAno(int year);
    void ValidaMes(int month);
    void ValidaDia(int day, int month);
  
    void EscreverArquivoFuncionario(vector<Funcionario*> Func);
    void LerArquivoFuncionario();
    void EscreverArquivoFolhaSalarial(int indice);
    void LerArquivoFolhaSalarial();

    protected:
    std::vector <Funcionario *> listaFunc;

};