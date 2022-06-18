#include <iostream>
#include <unistd.h>
#include "gerenciamento.h"
#include "funcionario.h"
#include "diretor.h"
#include "gerente.h"
#include "operador.h"
#include "presidente.h"

using namespace std;
 

void ExibirMenuPrincipal(string interprise){

    cout << "---------Bem-vindo ao Sistema de Gerenciamento da Empresa " << interprise << " ---------" << endl << endl;

    cout << "Funcionário: " << endl;
    cout << " 1 - Cadastrar Funcionário" << endl; 
    cout << " 2 - Editar Funcionário" << endl; 
    cout << " 3 - Exibir Funcionário" << endl;
    cout << " 4 - Excluir Funcionário" << endl;
    cout << " 5 - Listar Funcionários Existentes" << endl; 
    cout << " 6 - Buscar Funcionário (Nome/Data de Ingresso/Endereço)" << endl; 
    cout << " 7 - Aumentar salário" << endl << endl; 

    cout << "Folha salarial: " << endl;
    cout << " 8 - Calcular Folha Salarial" << endl;
    cout << " 9 - Imprimir Folha Salarial Funcionário" << endl;
    cout << "10 - Imprimir Folha Salarial Empresa " << endl;

    cout << "Arquivo: " << endl;
    
    cout << "11 - Salvar dados em arquivo" << endl;
    cout << "12 - Arquivo 2" << endl << endl;

    cout << " 0 - Encerrar Programa" << endl << endl;
    
    cout << "No menu de opções acima, selecione a tarefa a ser realizada: "; 
}


int main(){

    string empresa;
    int opcao_menu_principal;
    Gerenciamento sistema;

    int mes;
    string procurado;


    cout << endl << "<><><><><><><><><><><><> Sistema de Gerenciamento de Folha de Pagamento <><><><><><><><><><><><>" << endl << endl << endl;

    cout << "Antes de começarmos, precisamos saber o nome da sua empresa: " << endl;

    getline(cin >> ws, empresa);  //recebe o nome da empresa
   

    while(1){

        system("clear");
        ExibirMenuPrincipal(empresa);

        cin >> opcao_menu_principal;

        cin.ignore();

        if(opcao_menu_principal == 0){
            break;
        }

        switch(opcao_menu_principal){
            
            case 1:
                try{
                    sistema.InserirFuncionario();

                }catch(int erro){

                    if(erro == 2){
                        cout << endl << "ERRO 2: MÊS INVÁLIDO" << endl << endl;
                        cout << "Retornando ao menu..." << endl;
                    }

                    if(erro == 3){
                        cout << endl << "ERRO 3: DIA INVÁLIDO" << endl << endl;
                        cout << "Retornando ao menu..." << endl;
                    }

                    if(erro == 4){
                        cout << endl << "ERRO 4: ANO INVÁLIDO" << endl << endl;
                        cout << "Retornando ao menu..." << endl;
                    }

                    if(erro == 5){
                        cout << endl << "ERRO 5: DIA INVÁLIDO PARA O MÊS" << endl << endl;
                        cout << "Retornando ao menu..." << endl;
                    }

                    if(erro == 6){
                        cout << endl << "ERRO 6: CÓDIGO JÁ EXISTENTE" << endl << endl;
                        cout << "Retornando ao menu..." << endl;
                    }

                    if(erro == 7){
                        cout << endl << "ERRO 7: DESIGNAÇÃO NÃO EXISTENTE" << endl << endl;
                        cout << "Retornando ao menu..." << endl;
                    }

                    if(erro == 6){
                        cout << endl << "ERRO 8: PRESIDENTE JÁ EXISTENTE" << endl << endl;
                        cout << "Retornando ao menu..." << endl;
                    }
                }
                sleep(3);
                break;

            case 2: 
                try{
                    sistema.EditarFuncionario();

                }catch(int erro){

                    if(erro == 1){
                        cout << "ERRO 1: FUNCIONÁRIO NÃO EXISTENTE " << endl << endl;
                        cout << "Retornando ao menu..." << endl;
                    }

                    if(erro == 2){
                        cout << "ERRO 2: MÊS INVÁLIDO" << endl << endl;
                        cout << "Retornando ao menu..." << endl;
                    }

                    if(erro == 3){
                        cout << "ERRO 3: DIA INVÁLIDO" << endl << endl;
                        cout << "Retornando ao menu..." << endl;
                    }

                    if(erro == 4){
                        cout << "ERRO 4: ANO INVÁLIDO" << endl << endl;
                        cout << "Retornando ao menu..." << endl;
                    }

                    if(erro == 5){
                        cout << "ERRO 5: DIA INVÁLIDO PARA O MÊS" << endl << endl;
                        cout << "Retornando ao menu..." << endl;
                    }

                    if(erro == 6){
                        cout << endl << "ERRO 6: CÓDIGO JÁ EXISTENTE" << endl << endl;
                        cout << "Retornando ao menu..." << endl;
                    }

                }
                sleep(3);
                break;

            case 3: 
                cout << "Digite o código de qual funcionário vocẽ quer exibir: " << endl;
                getline(cin, procurado);

                try{
                    sistema.ExibirFuncionario(procurado);

                }catch(int erro){

                    if(erro == 1){
                        cout << "ERRO 1: FUNCIONÁRIO NÃO EXISTENTE " << endl << endl;
                        cout << "Retornando ao menu..." << endl;
                    }
                }
                
                sleep(3);
                break;

            case 4: 
                try{
                    sistema.ExcluirFuncionario();

                }catch(int erro){

                    if(erro == 1){
                        cout << "ERRO 1: FUNCIONÁRIO NÃO EXISTENTE " << endl << endl;
                        cout << "Retornando ao menu..." << endl;
                    }
                }
                sleep(3);
                break;

            case 5:
                sistema.ExibirListaFuncionario(); 
                break;

            case 6:
                cout << "Qual funcionário você quer buscar? Pesquise pelo nome, data de ingresso (dd/mm/aaaa) ou endereço: " << endl;
                getline(cin, procurado);

                try{
                    sistema.BuscarFuncionario();

                }catch(int erro){

                    if(erro == 1){
                        cout << "ERRO 1: FUNCIONÁRIO NÃO EXISTENTE " << endl << endl;
                        cout << "Retornando ao menu..." << endl;
                    }
                }
                sleep(3);
                break;

            case 7:
                sistema.ConfigurarAumento();
                
                break;

            case 8: 
                cout << "Digite o número (de 1 a 12) equivalente ao mês pra calcular a folha salarial: " << endl;
                cin >> mes;

                try{
                    sistema.CalcularFolhaSalarial(mes);

                }catch(int erro){
                    
                    if(erro == 2){
                        cout << "ERRO 2: MÊS INVÁLIDO" << endl << endl;
                        cout << "Retornando ao menu..." << endl;
                    }
                }
                sleep(3);
                break;

            case 9: 
                try{
                    sistema.ImprimirFolhaSalarial();

                }catch(int erro){

                    if(erro == 1){
                        cout << "ERRO 1: FUNCIONÁRIO NÃO EXISTENTE " << endl << endl;
                        cout << "Retornando ao menu..." << endl;
                    }
                }
                sleep(3);
                break;

            case 10: 
                try{
                    sistema.ImprimirFolhaSalarialEmpresa();

                }catch(int erro){

                    if(erro == 2){
                        cout << "ERRO 2: MÊS INVÁLIDO" << endl << endl;
                        cout << "Retornando ao menu..." << endl;
                    }
                }
                sleep(3);
                break;

            default:
                system("clear");
                cout << endl << "--------------A opção digitada é inexistente--------------" << endl; 
                sleep(2);
                break;
        }

    }

    cout << "\n";
    cout << "Programa encerrado. Até mais! " << endl << endl;
}