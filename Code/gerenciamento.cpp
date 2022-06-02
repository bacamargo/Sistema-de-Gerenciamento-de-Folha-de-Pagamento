#include <iostream>
#include <cstdlib>
#include "gerenciamento.hpp"

using namespace std;

#define HORAS_TRABALHO 8

Gerenciamento::Gerenciamento(){

}

void Gerenciamento::InserirFuncionario(Funcionario *newFunc){

    listaFunc.push_back(newFunc);
}

void Gerenciamento::EditarFuncionario(int change, string code){
    
    int indice;
    string novo;
    double novoSal;
    
    for(int i= 0; i < listaFunc.size(); i++){
        
        if(listaFunc[i]->getCodigo() == code){
            indice= i;
            break;
        }
    }

    switch(change){
        case 1:                        //alterar codigo 
            cin >> novo;
            listaFunc[indice]->setCodigo(novo);
            break;

        case 2:                       //alterar dataIngresso
            cin >> novo;
            listaFunc[indice]->setIngresso(novo);
            break;

        case 3:                         //alterar nome
            getline(cin, novo);
            listaFunc[indice]->setNome(novo);
            break;
        
        case 4:                         //alterar endereco
            getline(cin, novo);
            listaFunc[indice]->setEndereco(novo);
            break;

        case 5:                         //alterar telefone
            getline(cin, novo);
            listaFunc[indice]->setTelefone(novo);
            break;

        case 6:                         //alterar designacao
            getline(cin, novo);
            listaFunc[indice]->setDesignacao(novo);
            break;

        case 7:                         //alterar  salario
            cin >> novoSal;
            listaFunc[indice]->setSalario(novoSal);
            break;
    }
}

void Gerenciamento::ExcluirFuncionario(string code){

    string desigRemovida;
    int indRemovido;
    bool existeCod= false;
    char confirmacao;


    for(int i= 0; i < listaFunc.size(); i++){

        if(listaFunc[i]->getCodigo() == code){

            existeCod= true;
            desigRemovida= listaFunc[i]->getDesignacao();

            if(desigRemovida == "diretor" || desigRemovida == "Diretor" || desigRemovida == "gerente" || desigRemovida == "Gerente"){

                throw "nao pode ser apagado"; 

            }else{
                indRemovido= i;
                break;
            }
        }
    }

    if(existeCod == 1){

        cout << "Você tem certeza que quer apagar o funcionário " << listaFunc[indRemovido]->getNome() << "?   (Digite 's' para SIM e 'n' para NÃO)" << endl;
        
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

        if(listaFunc[i]->getCodigo() == code){

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

        cout << "Código: " << listaFunc[i]->getCodigo() << "\pNome: " << listaFunc[i]->getNome() << endl;
        cout << "Endereço: " << listaFunc[i]->getEndereco() << "\pTelefone: " << listaFunc[i]->getTelefone() << endl; 
        cout << "Data de Ingresso: " << listaFunc[i]->getIngresso() << "\pDesignação: " << listaFunc[i]->getDesignacao() << endl;  
        cout << "Salário: " << listaFunc[i]->getSalario() << endl;  
    }

}

void Gerenciamento::ExibirTipoFuncionario(string designation){

    if(designation == "operador"){

        cout << "Lista de " << designation << "(es): ";
    }else{

        cout << "Lista de " << designation << "(s): ";
    }
    

    for(int i= 0; i < listaFunc.size(); i++){

        if(listaFunc[i]->getDesignacao() == designation){
        
        cout << "-----------------Funcionário-----------------" << endl;
        cout << "Código: " << listaFunc[i]->getCodigo() << "\pNome: " << listaFunc[i]->getNome() << endl;
        cout << "Endereço: " << listaFunc[i]->getEndereco() << "\pTelefone: " << listaFunc[i]->getTelefone() << endl; 
        cout << "Data de Ingresso: " << listaFunc[i]->getIngresso() << "\pSalário: " << listaFunc[i]->getSalario() << endl;  

        }
    }
}

void Gerenciamento::BuscarFuncionario(string search){

    int indBuscado;
    bool existeFunc= false;

    for(int i= 0; i < listaFunc.size(); i++){

        if(listaFunc[i]->getNome() == search || listaFunc[i]->getIngresso() == search || listaFunc[i]->getEndereco()== search){

            existeFunc= true;
            indBuscado= i;
            break;
        }
    }

    if(existeFunc){
        cout << "O funcionário existe. Seu código é " << listaFunc[indBuscado]->getCodigo() << "." << endl;  

    }else{

        cout << "Não existe nenhum funcionário com a informação \" "<< search << " \" fornecida." << endl;
    }

}

double Gerenciamento::CalcularFolhaSalarial(int mes){

    int diasMax;
    int diasTrabalhados, horasExtras;
    double salarioTotal= 0;
    double salarioFunc, valorHora;

    if(mes <= 0 || mes > 12){

        return -1;       //mes não válido

    }else if(mes == 2){

        diasMax= 20;

    }else {
        diasMax= 22;
    }

    srand(time(NULL));

    for(int i= 0; i < listaFunc.size(); i++){

        while(1){                                  //gerando os dias trabalhados aleatoriamente
            diasTrabalhados= rand() % diasMax + 1; 

            if(diasTrabalhados >= 15){
                break;
            }
        }

        horasExtras= rand() % (diasMax * 24 - diasTrabalhados* HORAS_TRABALHO) + 1;           //gerando as horas extras aleatoriamente

        
        //calculando o salario de cada funcionario e o total

        valorHora= ((double) listaFunc[i]->getSalario() / (HORAS_TRABALHO * diasMax) );

        salarioFunc= (valorHora *  diasTrabalhados) + (2.0 * valorHora * horasExtras);

        if(salarioFunc <= 1100){
            
            listaFunc[i]->setDescontoINSS(7.5/100); 

        }else if(salarioFunc <= 2203.48){

            listaFunc[i]->setDescontoINSS(9.0/100); 

        }else if(salarioFunc <= 3305.22){

            listaFunc[i]->setDescontoINSS(12.0/100);

        }else{

            listaFunc[i]->setDescontoINSS(14.0/100);
        }

        salarioFunc -= ((double)salarioFunc * listaFunc[i]->getDescontoINSS() );


         if(salarioFunc <= 1903.98){
            

        }else if(salarioFunc <= 2826.65){

            listaFunc[i]->setDescontoImposto(7.5/100); 

        }else if(salarioFunc <= 3751.05){

            listaFunc[i]->setDescontoImposto(15.0/100);

        }else if(salarioFunc <= 4664.68){

            listaFunc[i]->setDescontoImposto(22.5/100);

        }else{

             listaFunc[i]->setDescontoImposto(27.5/100);
        }

        salarioFunc -= ((double)salarioFunc * listaFunc[i]->getDescontoImposto() );

        listaFunc[i]->setSalarioLiquido(salarioFunc);

        salarioTotal += salarioFunc;
    }

    return salarioTotal;
}

int Gerenciamento::ImprimirFolhaSalarial(string searched){

    bool existeFunc= false;
    int indice;

    for(int i= 0; i < listaFunc.size(); i++){

        if(listaFunc[i]->getCodigo() == searched || listaFunc[i]->getNome() == searched){

            existeFunc= true;
            indice= i;
            break;
        }
    }

    if(existeFunc){

        return indice;
        // cout << "Funcionário código " << listaFunc[indice]->getCodigo() << endl << endl;
        // cout << "Salário bruto: R$ " <<  listaFunc[indice]->getSalario() << endl;
        // cout << "Desconto Previdência Social (INSS): R$ " <<  listaFunc[indice]->getDescontoINSS() << endl;
        // cout << "Desconto Imposto de Renda: R$ " <<  listaFunc[indice]->getDescontoImposto() << endl;
        // cout << "Salário líquido: R$ " <<  listaFunc[indice]->getSalarioLiquido() << endl << endl;

    }else{
    
        return -1;
        // cout << "Funcionario nao existe" << endl;
    }

}

void Gerenciamento::ImprimirFolhaSalarialEmpresa(){

    int escolha;
    double salario= 0;
    vector<string> meses= {"janeiro", "fevereiro", "março", "abril", "junho", "julho", "agosto", "setembro", "outubro", "novembro", "dezembro"};

    cout << "Você deseja imprimir a folha salarial anual ou de um mês específico? " << endl;
    cout << "Digite (0)- folha anual" << endl;
    cout << "Digite (número equivalente ao mês)- folha mensal" << endl;

    cin >> escolha;

    if(escolha <= 0 || escolha > 12){

        throw "exception";

    }else if(escolha == 0){

        for(int i= 1; i <= 12; i++){

            salario += CalcularFolhaSalarial(i);      //calculando a folha salarial anual
        }

        cout << "Folha Salarial Anual: RS" << salario << endl;

    }else{

        salario = CalcularFolhaSalarial(escolha);      //calculando a folha salarial mensal

        cout << "Folha do Mês de " << meses[escolha-1] << ":   RS" << salario << endl;

    }

    
}

