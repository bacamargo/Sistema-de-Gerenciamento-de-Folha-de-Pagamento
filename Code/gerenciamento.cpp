#include <iostream>
#include "gerenciamento.hpp"

using namespace std;


Gerenciamento::Gerenciamento(){

}

void Gerenciamento::EditarFuncionario(int alteracao, string codigo){
    
    int indice;
    string novo;
    double novoSal;
    
    for(int i= 0; i < listaFunc.size(); i++){
        
        if(listaFunc[i].getCodigo() == codigo){
            indice= i;
            break;
        }

    }

    switch(alteracao){

        case 1:                        //alterar codigo 
            cin >> novo;
            listaFunc[indice].setCodigo(novo);
            break;

        case 2:                       //alterar dataIngresso
            cin >> novo;
            listaFunc[indice].setIngresso(novo);
            break;

        case 3:       //alterar nome
            getline(cin, novo);
            listaFunc[indice].setNome(novo);
            break;
        
        case 4:       //alterar endereco
            getline(cin, novo);
            listaFunc[indice].setEndereco(novo);
            break;

        case 5:      //alterar telefone
            getline(cin, novo);
            listaFunc[indice].setTelefone(novo);
            break;

        case 6:      //alterar designacao
            getline(cin, novo);
            listaFunc[indice].setDesignacao(novo);
            break;

        case 7:     //alterar  salario
            cin >> novoSal;
            listaFunc[indice].setSalario(novoSal);
            break;
    }
}

void Gerenciamento::ExcluirFuncionario(){

}

void Gerenciamento::ExibirFuncionario(){

}

void Gerenciamento::ExibirListaFuncionario(){

}

void Gerenciamento::ExibirTipoFuncionario(){

}

void Gerenciamento::BuscarFuncionario(){

}

void Gerenciamento::CalcularFolhaSalarial(){

}

void Gerenciamento::ImprimirFolhaSalarial(){

}

void Gerenciamento::ImprimirFolhaSalarialEmpresa(){

}

