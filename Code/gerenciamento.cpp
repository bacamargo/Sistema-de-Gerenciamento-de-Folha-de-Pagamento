#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime> 
#include <unistd.h>
#include "gerenciamento.h"

using namespace std;

#define HORAS_TRABALHO 8

Gerenciamento::Gerenciamento(){

}

void Gerenciamento::InserirFuncionario(){

    system("clear");

    Funcionario *func;
    string codigo, dataIngresso, nome, endereco, telefone, designacao, areaSupervisao, areaFormacao, formAcademicaMax;
    int dia, mes, ano;
    double salario;


    cout << "Cadastro do novo funcionário: " << endl << endl;

    cout << "Digite o código do funcionário: ";    //pegando o codigo do funcionario
    getline(cin, codigo);

    cout << "Digite o nome do funcionário: ";   //pegando o nome do funcionario
    getline(cin, nome);

    cout << "Digite o ano de ingresso do funcionário: ";  //pegando o ano de ingresso do funcionario
    cin >> ano; 
    ValidaAno(ano);           //funcao que valida ano

    cout << "Digite o mês de ingresso do funcionário (de 1 a 12): ";    //pegando o mes de ingresso do funcionario
    cin >> mes; 
    ValidaMes(mes);        //funcao que valida mes 

    cout << "Digite o dia do mês de ingresso do funcionário (de 1 a 31): ";   //pegando o dia do funcionario
    cin >> dia;   
    ValidaDia(dia, mes);       //funcao que valida dia
      
    cin.ignore();

    dataIngresso= FormataData(dia, mes, ano);    //funcao pra validar a data


    cout << "Digite o endereço do funcionário: ";
    getline(cin, endereco);

    cout << "Digite o telefone: " ;
    getline(cin, telefone);

    cout << "Digite a designação do funcionário ('operador', 'gerente', 'presidente' ou 'diretor'): ";

    while(1){     //tratamento de erro para caso o usuario digite outro cargo nao esoecificado
        getline(cin, designacao);

        if(designacao != "operador" && designacao != "gerente" && designacao != "presidente" && designacao != "diretor" ){

            cout << "Digite novamente um cargo válido e como especificado ('operador', 'gerente', 'presidente' ou 'diretor'): ";

        }else{
            break;
        }
    }

    cout << "Digite o salário inicial do funcionário: ";
    cin >> salario;
    cin.ignore();


    //criando o objeto funcionário

    if(designacao == "operador"){
        func= new Operador(codigo, nome, endereco, telefone, dataIngresso, salario);          //cria um novo funcionario operador

    }else if(designacao == "gerente"){


        cout << "Digite a área de área de supervisão do Gerente: ";
        getline(cin, areaSupervisao);

        func= new Gerente(codigo, nome, endereco, telefone, dataIngresso, salario, areaSupervisao);    //cria um novo funcionario gerente

        // func->setAreaSupervisao(areaSupervisao);

    }else if(designacao == "diretor"){


        cout << "Digite a área de área de supervisão do Diretor: ";
        getline(cin, areaSupervisao);

        cout << "Digite a área de área de formação do Diretor: ";
        getline(cin, areaFormacao);     

        func= new Diretor(codigo, nome, endereco, telefone, dataIngresso, salario, areaSupervisao, areaFormacao);

    }else{

        cout << "Digite a área de área de formação do Presidente: ";
        getline(cin, areaFormacao);

        cout << "Digite a formação acadêmica máxima do Presidente: ";
        getline(cin, formAcademicaMax);

         func= new Presidente(codigo, nome, endereco, telefone, dataIngresso, salario, areaFormacao, formAcademicaMax); //cria um novo funcionario presidente

    }

    listaFunc.push_back(func);

    cout << endl << "---------------- Cadastro feito com sucesso! ----------------" << endl;

    sleep(2);
}

void Gerenciamento::EditarFuncionario(){
    
    int indice;
    int change;
    string novo;
    double novoSal;
    string code;    //codigo pra pesquisar o novo funcionario
    int dia, mes, ano;

    system("clear");

    cout << "Digite o código do funcionário que irá ser editado: " << endl;
    getline(cin, code);

    indice= -1;                        //o indice é iniciado com -1 pois se o codigo nao existir, o indice permanecerá -1 
    for(int i= 0; i < listaFunc.size(); i++){
        
        if(listaFunc[i]->getCodigo() == code){
            indice= i;
            break;
        }
    }

    if(indice == -1){     //adicionar excecao de codigo inexistente
        
        throw 1;    //codigo erro 1: FUNCIONARIO NAO EXISTENTE
    }

    cout << endl << "Qual atributo do funcionário você deseja alterar? " << endl;
    cout << "(1) alterar código " << endl;
    cout << "(2) alterar data de ingresso " << endl;
    cout << "(3) alterar nome " << endl;
    cout << "(4) alterar endereço " << endl;
    cout << "(5) alterar telefone " << endl;
    cout << "(6) alterar designação " << endl;
    cout << "(7) alterar salário " << endl;
    
    cout << "Opção: ";
    cin >> change;
    cin.ignore();


    switch(change){
        case 1:                        //alterar codigo 
            cout << endl << "Digite o novo código do funcionário: ";
            getline(cin, novo);
            listaFunc[indice]->setCodigo(novo);
            break;

        case 2:         //alterar dataIngresso
            cout << "Digite o novo ano de ingresso do funcionário: ";
            cin >> ano;      
            cout << "Digite o novo mês de ingresso do funcionário: ";
            cin >> mes;        
            cout << "Digite a nova dia de ingresso do funcionário: ";
            cin >> dia;
            

            novo= FormataData(dia, mes, ano);

            listaFunc[indice]->setIngresso(novo);
            break;

        case 3:                         //alterar nome
            cout << endl << "Digite o novo nome do funcionário: ";
            getline(cin, novo);
            listaFunc[indice]->setNome(novo);
    
            break;
        
        case 4:                         //alterar endereco
            cout << endl << "Digite o novo endereço do funcionário: ";
            getline(cin, novo);
            listaFunc[indice]->setEndereco(novo);
    
            break;

        case 5:                         //alterar telefone
            cout << endl << "Digite o novo telefone do funcionário: ";
            getline(cin, novo);
            listaFunc[indice]->setTelefone(novo);
    
            break;

        case 6:                         //alterar designacao
            cout << endl << "Digite a nova designação do funcionário: ";
            getline(cin, novo);
            listaFunc[indice]->setDesignacao(novo);
        
            break;

        case 7:                         //alterar  salario
            cout << endl << "Digite o novo salário do funcionário: " << endl;
            cin >> novoSal;
            listaFunc[indice]->setSalario(novoSal);
            
            break;
    }

    cout << endl << "Atributo alterado com sucesso!------------------- (Aperte uma tecla para continuar....) " << endl;
    getchar();       
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

            if(desigRemovida == "diretor" || desigRemovida == "gerente"){

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

        throw 1;          //erro 1: FUNCIONARIO NAO EXISTENTE
    }

}

void Gerenciamento::ExibirFuncionario(string code){

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
    
        cout << "-----------------Funcionário " << indImprimir+1 << " -----------------" << endl;

        cout << "Código: " << listaFunc[indImprimir]->getCodigo() << endl;
        cout << "Nome: " << listaFunc[indImprimir]->getNome() << endl;
        cout << "Endereço: " << listaFunc[indImprimir]->getEndereco() << endl;
        cout << "Telefone: " << listaFunc[indImprimir]->getTelefone() << endl; 
        cout << "Data de Ingresso: " << listaFunc[indImprimir]->getIngresso() << endl;
        cout << "Designação: " << listaFunc[indImprimir]->getDesignacao() << endl;  
        cout << "Salário: " << listaFunc[indImprimir]->getSalario() << endl; 

    }else{
        throw 1;
    }

}

void Gerenciamento::ExibirListaFuncionario(){

    system("clear");

    for(int i= 0; i < listaFunc.size(); i++){

        ExibirFuncionario(listaFunc[i]->getCodigo());
    }

    
    sleep(5);
}

void Gerenciamento::ExibirTipoFuncionario(){

    string designation;

    cout << "Digite o tipo do funcionário que vocẽ quer exibir  (digite 'operador', 'gerente', 'diretor' ou 'presidente'): " << endl;
    cout << designation;

    if(designation == "operador"){

        cout << "Lista de " << designation << "(es): ";
    }else{

        cout << "Lista de " << designation << "(s): ";
    }
    

    for(int i= 0; i < listaFunc.size(); i++){

        if(listaFunc[i]->getDesignacao() == designation){
            
            ExibirFuncionario(listaFunc[i]->getCodigo());
        }
    }
}

void Gerenciamento::BuscarFuncionario(){

    int indBuscado;
    string search;

    indBuscado= -1; 
    for(int i= 0; i < listaFunc.size(); i++){

        if(listaFunc[i]->getNome() == search || listaFunc[i]->getIngresso() == search || listaFunc[i]->getEndereco()== search){

            indBuscado= i;
            break;
        }
    }

    if(indBuscado != -1){
        cout << "O funcionário existe. Seu código é " << listaFunc[indBuscado]->getCodigo() << "." << endl;  

    }else{

        throw 1;   //erro 1: FUNCIONARIO NAO EXISTENTE;
    }

}

double Gerenciamento::CalcularFolhaSalarial(int mes){

    static int aleatorio= 56;

    int diasMax;
    int diasTrabalhados, horasExtras;
    double salarioTotal= 0;
    double salarioFunc, valorHora;

    cin.ignore();

    if(mes <= 0 || mes > 12){

        throw 2;        //erro 2: ERRO INVALIDO

    }else if(mes == 2){

        diasMax= 20;

    }else{
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

void Gerenciamento::ImprimirFolhaSalarial(){

    bool existeFunc= false;
    int indice;
    string searched;

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

        cout << "Código do funcionário: " << listaFunc[indice]->getCodigo() << endl << endl;
        cout << "Salário bruto: R$ " <<  listaFunc[indice]->getSalario() << endl;
        cout << "Desconto Previdência Social (INSS): R$ " <<  listaFunc[indice]->getDescontoINSS() << endl;
        cout << "Desconto Imposto de Renda: R$ " <<  listaFunc[indice]->getDescontoImposto() << endl;
        cout << "Salário líquido: R$ " <<  listaFunc[indice]->getSalarioLiquido() << endl << endl;

    }else{
    
        throw 1;
    }

}

void Gerenciamento::ImprimirFolhaSalarialEmpresa(){

    int escolha;
    double salario= 0;
    vector<string> meses= {"janeiro", "fevereiro", "março", "abril", "junho", "julho", "agosto", "setembro", "outubro", "novembro", "dezembro"};

    cout << "Você deseja imprimir a folha salarial anual ou de um mês específico? " << endl;
    cout << "Digite (0)- folha anual" << endl;
    cout << "Digite (número equivalente ao mês)- folha mensal equivalente ao mês" << endl;

    cin >> escolha;

    if(escolha < 0 || escolha > 12){

        throw 2;      //erro 2: MES INVALIDO    

    }else if(escolha == 0){

        for(int i= 1; i <= 12; i++){

            salario += CalcularFolhaSalarial(i);      //calculando a folha salarial anual
        }

        cout << "Folha Salarial Anual: R$" << salario << endl;

    }else{

        salario = CalcularFolhaSalarial(escolha);      //calculando a folha salarial mensal

        cout << "Folha do Mês de " << meses[escolha-1] << ":   R$" << salario << endl;

    }

}


void Gerenciamento::ValidaAno(int year){

    time_t current_time;                           
	struct tm *time_info;
	char ano[5];

	current_time = time(NULL);
	time_info = localtime(&current_time);
	strftime(ano, 5, "%Y", time_info);              //codigo pra ver se pega o ano atual
    int anoAtual = atoi(ano);


    if (year < 1952 || year > anoAtual){     //a pessoa pode ter no maximo 70 anos na empresa

        throw 4;      //erro 4: ANO INVALIDO
    }

    //formatando a data: 
    
}

void Gerenciamento::ValidaMes(int month){

    if(month <= 0 || month > 12){

        throw 2;       //erro 2: MES INVALIDO
    }

}

void Gerenciamento::ValidaDia(int day, int month){

    if(month <= 0 || month > 12){

        throw 2;       //erro 2: MES INVALIDO

    }else if(day <= 0 || day > 31){

        throw 3;      //erro 3: DIA INVALIDO    

    }

    if(month == 2 && day > 28){            //se o ano for fevereiro e tiver dia maior que 28 (dia 29 de ano bissexto é desconsiderado), invalida! 

        throw 5;    //ERRO 5

    }else if ( (month == 4 || month == 6 || month == 9 || month == 11) && day > 30){   //se for um mes com apenas 30 dias e tiver mais q 30, invalida!

        throw 5;   //ERRO 5: DIA INVALDO PARA O MES
    }
}


string Gerenciamento::FormataData(int day, int month, int year){

    string dataFormatada;
    string barra= "/";

    dataFormatada= to_string(day) + barra + to_string(month) + barra + to_string(year);

    return dataFormatada;
}

void Gerenciamento::ConfigurarAumento(){

    int i;

    for(i= 0; i < listaFunc.size(); i++){

        listaFunc[i]->Aumento(listaFunc[i]);
    }

}