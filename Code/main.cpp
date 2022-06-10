#include <iostream>
#include "gerenciamento.hpp"
#include "funcionario.hpp"
#include "diretor.hpp"
#include "gerente.hpp"
#include "operador.hpp"
#include "presidente.hpp"

using namespace std;
 

int main(){
    string Empresa;
    int opcao_menu_principal, opcao_menu_secundario;
    cout << "\n";
    cout << "Sistema de Gerenciamento de Folha de Pagamento" << endl;
    cout << "\n";
    cout << "/---------------------------------------------/" << endl;
    cout << "\n";
    cout << "Antes de começarmos, precisamos saber o nome da sua empresa." << endl;
    cout << "\n";

    getline(cin >> ws, Empresa);
    cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << endl;
    cout << "\n";
    cout << "\n";
    cout << "Bem-vindo ao Sistema de Gerenciamento de Folha de Pagamento da " << Empresa << endl;
    cout << "\n";
    cout << "\n";
    cout << "No menu de opções abaixo, selecione a tarefa a ser realizada."; 
    cout << "\n";

    
    cout << "1 - Funcionário" << endl;
    cout << "2 - Folha de Pagamento" << endl;
    cout << "0 - Encerrar Programa" << endl;
    cout << "Opção: "; 
    cin >> opcao_menu_principal;
    cout << " " << endl;

    while(opcao_menu_principal != 0){
        switch(opcao_menu_principal){
            case 1:
            {
                cout << "\n";
                cout << "Funcionários:" << endl;
                cout << "\n";
                cout << "1 - Cadastrar Funcionário" << endl; // InserirFuncionario
                cout << "2 - Editar Funcionário" << endl; // EditarFuncionario
                cout << "3 - Exibir Funcionário por código" << endl; // ExibirFuncionario
                cout << "4 - Exibir Tipo do Funcionário" << endl; // ExibirTipoFuncionario
                cout << "5 - Exibir Código do Funcionário" << endl; // ExibirFuncionario
                cout << "6 - Listar Funcionários Existentes" << endl; // ExibirListaFuncionario
                cout << "7 - Buscar Funcionário (Nome/Ingresso/Endereço)" << endl; // BuscarFuncionario
                cout << "8 - Excluir Funcionário" << endl;
                cout << "0 - Voltar ao Menu Principal" << endl;
                break;
            }
            case 2:
            {
                cout << "\n";
                cout << "Folha de Pagamento" << endl;
                cout << "\n";
                cout << "1 - Calcular Folha Salarial" << endl;
                cout << "2 - Imprimir Folha Salarial Funcionário" << endl;
                cout << "3 - Imprimir Folha Salarial Empresa " << endl;
                cout << "0 - Voltar ao Menu Principal" << endl;
                break;
            }
        }
        cin >> opcao_menu_principal;
    }

    cout << "\n";
    cout << "Até mais" << endl;
}