#include <iostream>
#include <cstdlib>
#include "gerenciamento.hpp"

using namespace std;

#define HORAS_TRABALHO 8

Gerenciamento::Gerenciamento(){

}

void Gerenciamento::InserirFuncionario(){

    Funcionario *func;
    string codigo, data, nome, endereco, telefone, designacao, areaSupervisao, formAcademica;
    double salario;


    cout << "Cadastro do novo funcionário: " << endl << endl;

    cout << "Digite o código: " << endl;
    getline(cin, codigo);

    cout << "Digite o nome: " << endl;
    getline(cin, nome);

    cout << "Digite o data de ingresso: " << endl;    //tem que ter tratamento pra data
    getline(cin, data);

    cout << "Digite o endereço: " << endl;
    getline(cin, endereco);

    cout << "Digite o telefone: " << endl;
    getline(cin, telefone);

    cout << "Digite a designação ('operador', 'gerente' ou 'presidente'): " << endl;
    getline(cin, designacao);

    cout << "Digite o salário inicial: " << endl;
    cin >> salario;


    if(designacao == "operador"){
        func= new Operador();          //cria um novo funcionario operador

    }else if(designacao == "gerente"){

        Gerente gerente;    //cria um novo funcionario gerente

        cin.ignore();

        cout << "Digite a área de área de supervisão do Gerente: " << endl;
        getline(cin, areaSupervisao);

        gerente.setAreaSupervisao(areaSupervisao);

    }else{

        Presidente presid; //cria um novo funcionario presidente

        cin.ignore();

        cout << "Digite a área de área de supervisão do Presidente: " << endl;
        getline(cin, areaSupervisao);

        cout << "Digite a área de formação acadêmica máximo do Presidente: " << endl;
        getline(cin, formAcademica);
    }

    listaFunc.push_back(func);
}

void Gerenciamento::EditarFuncionario(){
    
    int indice;
    int change;
    string novo;
    double novoSal;
    string code;    //codigo pra pesquisar o novo funcionario

    cout << "Digite o código do funcionário que irá ser editado: " << endl;
    cin >> code;

    for(int i= 0; i < listaFunc.size(); i++){
        
        if(listaFunc[i]->getCodigo() == code){
            indice= i;
            break;
        }
    }

    switch(change){
        case 1:                        //alterar codigo 
            cout << "Digite o novo código do funcionário: " << endl;
            cin >> novo;
            listaFunc[indice]->setCodigo(novo);
            break;

        case 2:                       //alterar dataIngresso
            cout << "Digite a nova data de ingresso do funcionário: " << endl;
            cin >> novo;
            listaFunc[indice]->setIngresso(novo);
            break;

        case 3:                         //alterar nome
            cout << "Digite o novo nome do funcionário: " << endl;
            getline(cin, novo);
            listaFunc[indice]->setNome(novo);
            break;
        
        case 4:                         //alterar endereco
            cout << "Digite o novo endereço do funcionário: " << endl;
            getline(cin, novo);
            listaFunc[indice]->setEndereco(novo);
            break;

        case 5:                         //alterar telefone
            cout << "Digite o novo telefone do funcionário: " << endl;
            getline(cin, novo);
            listaFunc[indice]->setTelefone(novo);
            break;

        case 6:                         //alterar designacao
            cout << "Digite a nova designação do funcionário: " << endl;
            getline(cin, novo);
            listaFunc[indice]->setDesignacao(novo);
            break;

        case 7:                         //alterar  salario
            cout << "Digite o novo salário do funcionário: " << endl;
            cin >> novoSal;
            listaFunc[indice]->setSalario(novoSal);
            break;
    }
}

void Gerenciamento::ExcluirFuncionario(){

    string desigRemovida;
    int indRemovido;
    bool existeCod= false;
    char confirmacao;
    string code;

    cout << "Digite o código do funcionário que vocẽ quer excluir: " << endl;
    getline(cin, code);

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

int Gerenciamento::ExibirFuncionario(){

    int indImprimir;
    bool existeFunc= false;
    string code;

    cout << "Digite o código de qual funcionário vocẽ quer excluir: " << endl;
    cin >> code;

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

        cout << "Código: " << listaFunc[i]->getCodigo() << endl;
        cout << "Nome: " << listaFunc[i]->getNome() << endl;
        cout << "Endereço: " << listaFunc[i]->getEndereco() << endl;
        cout << "Telefone: " << listaFunc[i]->getTelefone() << endl; 
        cout << "Data de Ingresso: " << listaFunc[i]->getIngresso() << endl;
        cout << "Designação: " << listaFunc[i]->getDesignacao() << endl;  
        cout << "Salário: " << listaFunc[i]->getSalario() << endl;  
    }

}

void Gerenciamento::ExibirTipoFuncionario(){

    string designation;

    cout << "Digite o tipo do funcionário que vocẽ quer exibir  (digite 'operador', 'gerente' ou 'presidente'): " << endl;
    cout << designation;

    if(designation == "operador"){

        cout << "Lista de " << designation << "(es): ";
    }else{

        cout << "Lista de " << designation << "(s): ";
    }
    

    for(int i= 0; i < listaFunc.size(); i++){

        if(listaFunc[i]->getDesignacao() == designation){
        
        cout << "-----------------Funcionário-----------------" << endl;
        cout << " Código: " << listaFunc[i]->getCodigo() << endl;
        cout << " Nome: " << listaFunc[i]->getNome() << endl;
        cout << " Endereço: " << listaFunc[i]->getEndereco() << endl; 
        cout << " Telefone: " << listaFunc[i]->getTelefone() << endl; 
        cout << " Data de Ingresso: " << listaFunc[i]->getIngresso() << endl; 
        cout << " Salário: " << listaFunc[i]->getSalario() << endl;  

        }
    }
}

void Gerenciamento::BuscarFuncionario(){

    int indBuscado;
    bool existeFunc= false;
    string search;

    cout << "Qual o código do funcionário que você quer excluir: " << endl;
    cin >> search;

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

    static int aleatorio= 56;

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

    aleatorio++;        //incrementar o numero aleatorio 

    return salarioTotal;
}

int Gerenciamento::ImprimirFolhaSalarial(){

    bool existeFunc= false;
    int indice;

    cout << "Digite o nome do código ou nome do funcionário: " << endl;
    cin >> searched;

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

