#include <iostream>
#include "gerenciamento.hpp"

using namespace std;


Gerenciamento::Gerenciamento(){

}

void Gerenciamento::EditarFuncionario(int change, string code){
    
    int indice;
    string novo;
    double novoSal;
    
    for(int i= 0; i < listaFunc.size(); i++){
        
        if(listaFunc[i].getCodigo() == code){
            indice= i;
            break;
        }
    }

    switch(change){
        case 1:                        //alterar codigo 
            cin >> novo;
            listaFunc[indice].setCodigo(novo);
            break;

        case 2:                       //alterar dataIngresso
            cin >> novo;
            listaFunc[indice].setIngresso(novo);
            break;

        case 3:                         //alterar nome
            getline(cin, novo);
            listaFunc[indice].setNome(novo);
            break;
        
        case 4:                         //alterar endereco
            getline(cin, novo);
            listaFunc[indice].setEndereco(novo);
            break;

        case 5:                         //alterar telefone
            getline(cin, novo);
            listaFunc[indice].setTelefone(novo);
            break;

        case 6:                         //alterar designacao
            getline(cin, novo);
            listaFunc[indice].setDesignacao(novo);
            break;

        case 7:                         //alterar  salario
            cin >> novoSal;
            listaFunc[indice].setSalario(novoSal);
            break;
    }
}

void Gerenciamento::ExcluirFuncionario(string code){

    string desigRemovida;
    int indRemovido;
    bool existeCod= false;
    char confirmacao;


    for(int i= 0; i < listaFunc.size(); i++){

        if(listaFunc[i].getCodigo() == code){

            existeCod= true;
            desigRemovida= listaFunc[i].getDesignacao();

            if(desigRemovida == "diretor" || desigRemovida == "Diretor" || desigRemovida == "supervisor" || desigRemovida == "Supervisor"){

                throw "nao pode ser apagado"; 

            }else{
                indRemovido= i;
                break;
            }
        }
    }

    if(existeCod == 1){

        cout << "Você tem certeza que quer apagar o funcionário " << listaFunc[indRemovido].getNome() << "?   (Digite 's' para SIM e 'n' para NÃO)" << endl;
        
        while(1){
            cin >> confirmacao;
            cin.ignore();

            if(confirmacao != 's' || confirmacao != 'n'){
                
                cout << "Digite o caractere certo: ";

            }else{
                listaFunc.erase(listaFunc.begin()+ indRemovido);  //apaga o funcioanario
                
                cout << endl << "Funcionario removido com sucesso!" << endl; 
                break;
            }
        }
        
    }else{

        cout << "O funcionario de código " << code << " não existe." << endl;
    }

}

int Gerenciamento::ExibirFuncionario(string code){

    int indImprimir;
    bool existeFunc= false;

    for(int i= 0; i < listaFunc.size(); i++){

        if(listaFunc[i].getCodigo() == code){

            existeFunc= true;
            indImprimir= i;
            break;
        }
    }

    if(existeFunc){
    
    return indImprimir;

    }else{
        cout << "O funcionario de código " << code << " não existe." << endl;
    }

}

void Gerenciamento::ExibirListaFuncionario(){


    for(int i= 0; i < listaFunc.size(); i++){

        cout << "-----------------Funcionario " << i+1 << "-----------------" << endl;

        cout << "Código: " << listaFunc[i].getCodigo() << "\pNome: " << listaFunc[i].getNome() << endl;
        cout << "Endereço: " << listaFunc[i].getEndereco() << "\pTelefone: " << listaFunc[i].getTelefone() << endl; 
        cout << "Data de Ingresso: " << listaFunc[i].getIngresso() << "\pDesignação: " << listaFunc[i].getDesignacao() << endl;  
        cout << "Salário: " << listaFunc[i].getSalario() << endl;  
    }

}

void Gerenciamento::ExibirTipoFuncionario(string designation){

    if(designation == "operador"){

        cout << "Lista de " << designation << "(es): ";
    }else{

        cout << "Lista de " << designation << "(s): ";
    }
    

    for(int i= 0; i < listaFunc.size(); i++){

        if(listaFunc[i].getDesignacao() == designation){
        
        cout << "-----------------Funcionário-----------------" << endl;
        cout << "Código: " << listaFunc[i].getCodigo() << "\pNome: " << listaFunc[i].getNome() << endl;
        cout << "Endereço: " << listaFunc[i].getEndereco() << "\pTelefone: " << listaFunc[i].getTelefone() << endl; 
        cout << "Data de Ingresso: " << listaFunc[i].getIngresso() << "\pSalário: " << listaFunc[i].getSalario() << endl;  

        }
    }
}

void Gerenciamento::BuscarFuncionario(string search){

    int indBuscado;
    bool existeFunc= false;

    for(int i= 0; i < listaFunc.size(); i++){

        if(listaFunc[i].getNome() == search || listaFunc[i].getIngresso() == search || listaFunc[i].getEndereco()== search){

            existeFunc= true;
            indBuscado= i;
            break;
        }
    }

    if(existeFunc){
        cout << "O funcionário existe. Seu código é " << listaFunc[indBuscado].getCodigo() << "." << endl;  

    }else{

        cout << "Não existe nenhum funcionário com a informacao \" "<< search << " \" fornecida." << endl;
    }

}

void Gerenciamento::CalcularFolhaSalarial(){

}

void Gerenciamento::ImprimirFolhaSalarial(){

}

void Gerenciamento::ImprimirFolhaSalarialEmpresa(){

}

