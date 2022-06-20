#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime> 
#include <unistd.h>
#include "gerenciamento.h"
#include <fstream>
#include "gerente.h"
#include "operador.h"
#include "diretor.h"
#include "funcionario.h"
#include "nlohmann/json.hpp"

using namespace std;

#define HORAS_TRABALHO 8

Gerenciamento::Gerenciamento(){

}


Gerenciamento::~Gerenciamento(){

    for(int i= 0; i < listaFunc.size(); i++){

        delete listaFunc[i];
    }
}

void Gerenciamento::InserirFuncionario(){

    system("clear");

    Funcionario *func;
    string codigo, dataIngresso, nome, endereco, telefone, designacao, areaSupervisao, areaFormacao, formAcademicaMax;
    int dia, mes, ano;
    double salario;
    string cep;


    cout << "Cadastro do novo funcionário: " << endl << endl;

    cout << "Digite o código do funcionário: ";   
    getline(cin, codigo);
    ConfereCodigo(codigo);  //confere se o codigo já existe, se existir dá erro
    
    cout << "Digite o nome do funcionário: ";  
    getline(cin, nome);

    cout << "Digite o ano de ingresso do funcionário: "; 
    cin >> ano; 
    ValidaAno(ano);           //funcao que valida ano

    cout << "Digite o mês de ingresso do funcionário (de 1 a 12): ";   
    cin >> mes; 
    ValidaMes(mes);        //funcao que valida mes 

    cout << "Digite o dia de ingresso do funcionário (de 1 a 31): ";   
    cin >> dia;   
    ValidaDia(dia, mes);       //funcao que valida dia
      
    cin.ignore();

    dataIngresso= FormataData(dia, mes, ano);    //funcao pra validar a data


    cout << "Digite o endereço do funcionário: ";
    getline(cin, cep);
    endereco = EnderecoCEP(cep);

    cout << "Digite o telefone: " ;
    getline(cin, telefone);

    cout << "Digite a designação do funcionário com todas letras minúsculas ('operador', 'gerente', 'presidente' ou 'diretor'): ";
    getline(cin, designacao);    

    if(designacao != "operador" && designacao != "gerente" && designacao != "presidente" && designacao != "diretor" ){  //verificando existencia da designacao

        throw 8;       //erro 8: DESIGNACAO NAO EXISTENTE   
    }

    if(designacao == "presidente"){
        ExistePresid();     //valida se existe presidente
    }
    
    cout << "Digite o salário inicial do funcionário (utilize ponto ao invés de vírgula caso necessário): ";
    cin >> salario;
    cin.ignore();


    //criando o objeto funcionário

    if(designacao == "operador"){
        func= new Operador(codigo, nome, endereco, telefone, dataIngresso, salario);          //cria um novo funcionario operador

    }else if(designacao == "gerente"){


        cout << "Digite a área de supervisão do Gerente: ";
        getline(cin, areaSupervisao);

        func= new Gerente(codigo, nome, endereco, telefone, dataIngresso, salario, areaSupervisao);    //cria um novo funcionario gerente

        // func->setAreaSupervisao(areaSupervisao);

    }else if(designacao == "diretor"){


        cout << "Digite a área de supervisão do Diretor: ";
        getline(cin, areaSupervisao);

        cout << "Digite a área de formação do Diretor: ";
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
    EnderecoCEP(endereco);
    EscreverArquivoFuncionario(listaFunc);
    cout << endl << "---------------- Cadastro feito com sucesso! ----------------" << endl;

}

void Gerenciamento::EditarFuncionario(){
    
    Funcionario *func;
    int indice;
    int change;
    string novo;
    double novoSal;
    string code;    //codigo pra pesquisar o novo funcionario
    int dia, mes, ano;
    string areaFormacao, formAcademicaMax, areaSupervisao;

    system("clear");

    cout << "Digite o código do funcionário que irá ser editado: ";
    getline(cin, code);

    indice= -1;                   
    for(int i= 0; i < listaFunc.size(); i++){        //verificando se o codigo existe
        
        if(listaFunc[i]->getCodigo() == code){
            indice= i;
            break;
        }
    }

    if(indice == -1){     //significa que funcionario nao existe
        
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
            ConfereCodigo(novo);      //confere se já existe o codigo (e nao poderá ser usado)

            listaFunc[indice]->setCodigo(novo);

            cout << endl << "Atributo alterado com sucesso!------------------- ";
            break;

        case 2:         //alterar dataIngresso
            cout << endl << "Digite o novo ano de ingresso do funcionário: ";
            cin >> ano;      
            ValidaAno(ano);     //valida ano

            cout << "Digite o novo mês de ingresso do funcionário: ";
            cin >> mes;  
            ValidaMes(mes);    //valida mes 

            cout << "Digite a nova dia de ingresso do funcionário: ";
            cin >> dia;
            ValidaDia(dia, mes);   //valida dia

            novo= FormataData(dia, mes, ano);

            listaFunc[indice]->setIngresso(novo);

            cout << endl << "Atributo alterado com sucesso!------------------- ";
            break;

        case 3:                         //alterar nome
            cout << endl << "Digite o novo nome do funcionário: ";
            getline(cin, novo);
            listaFunc[indice]->setNome(novo);

            cout << endl << "Atributo alterado com sucesso!------------------- ";
            break;
        
        case 4:                         //alterar endereco
            cout << endl << "Digite o novo endereço do funcionário: ";
            getline(cin, novo);
            listaFunc[indice]->setEndereco(novo);

            cout << endl << "Atributo alterado com sucesso!------------------- ";
            break;

        case 5:                         //alterar telefone
            cout << endl << "Digite o novo telefone do funcionário: ";
            getline(cin, novo);
            listaFunc[indice]->setTelefone(novo);

            cout << endl << "Atributo alterado com sucesso!------------------- ";
            break;

        case 6:                         //alterar designacao
            cout << endl << "Digite a nova designação do funcionário: ";
            getline(cin, novo);


            if(novo != "operador" && novo != "gerente" && novo != "presidente" && novo != "diretor" ){  

                throw 8;       //erro 8: DESIGNACAO NAO EXISTENTE   
            }

            if(novo == "presidente"){

                ExistePresid();

                cout << "Digite a área de área de formação do novo Presidente: ";
                getline(cin, areaFormacao);

                cout << "Digite a formação acadêmica máxima do novo Presidente: ";
                getline(cin, formAcademicaMax);

                func= new Presidente(listaFunc[indice]->getCodigo(), listaFunc[indice]->getNome(), listaFunc[indice]->getEndereco(), 
                                    listaFunc[indice]->getTelefone(), listaFunc[indice]->getIngresso(), listaFunc[indice]->getSalario(),
                                     areaFormacao, formAcademicaMax);


            }else if(novo == "diretor"){

                cout << "Digite a área de supervisão do novo Diretor: ";
                getline(cin, areaSupervisao);

                cout << "Digite a área de formação do novo Diretor: ";
                getline(cin, areaFormacao);     

                func= new Diretor(listaFunc[indice]->getCodigo(), listaFunc[indice]->getNome(), listaFunc[indice]->getEndereco(), 
                                    listaFunc[indice]->getTelefone(), listaFunc[indice]->getIngresso(), listaFunc[indice]->getSalario(),
                                    areaSupervisao, areaFormacao);



            }else if(novo == "gerente"){

                cout << "Digite a área de supervisão do novo Gerente: ";
                getline(cin, areaSupervisao);

                func= new Gerente(listaFunc[indice]->getCodigo(), listaFunc[indice]->getNome(), listaFunc[indice]->getEndereco(), 
                                    listaFunc[indice]->getTelefone(), listaFunc[indice]->getIngresso(), listaFunc[indice]->getSalario(), 
                                    areaSupervisao);   

            }else{

                func= new Operador(listaFunc[indice]->getCodigo(), listaFunc[indice]->getNome(), listaFunc[indice]->getEndereco(), 
                                    listaFunc[indice]->getTelefone(), listaFunc[indice]->getIngresso(), listaFunc[indice]->getSalario()); 
            }

            listaFunc.push_back(func);
            listaFunc.erase(listaFunc.begin()+ indice);  //apaga a designacao antiga do funcionario
        
            cout << endl << "Atributo alterado com sucesso!------------------- ";
            break;

        case 7:                         //alterar  salario
            cout << endl << "Digite o novo salário do funcionário (utilize ponto ao invés de vírgula caso necessário): " << endl;
            cin >> novoSal;
            cin.ignore();
            listaFunc[indice]->setSalario(novoSal);

            cout << endl << "Atributo alterado com sucesso!------------------- ";
            break;

        default: 
            cout << endl << "--------------A opção digitada é inexistente--------------" << endl; 
            break;
    }

    cout << " (Aperte uma tecla para continuar....) " << endl;
    getchar();       
}

void Gerenciamento::ExcluirFuncionario(){

    system("clear");

    string desigRemovida;
    int indRemovido;
    bool existeCod= false;
    char confirmacao;
    string code;

    cout << "Digite o código do funcionário que vocẽ quer excluir: ";
    getline(cin, code);


    for(int i= 0; i < listaFunc.size(); i++){

        if(listaFunc[i]->getCodigo() == code){

            existeCod= true;
            desigRemovida= listaFunc[i]->getDesignacao();

            if(desigRemovida == "diretor" || desigRemovida == "presidente"){

                throw 7;     //diretor ou gerente nao podem ser apagados

            }else{
                indRemovido= i;
                break;
            }
        }
    }

    if(existeCod == 1){

        cout << endl<< "Você tem certeza que quer apagar o funcionário " << listaFunc[indRemovido]->getNome() << "?   (Digite 's' para SIM e 'n' para NÃO)" << endl;
        
        while(1){
            cin >> confirmacao;
            cin.ignore();

            if(confirmacao != 's' && confirmacao != 'n'){
                
                cout << "Digite o caractere certo: ";

            }else{

                if(confirmacao == 's'){
                    listaFunc.erase(listaFunc.begin()+ indRemovido);  //apaga o funcioanario
                    EscreverArquivoFuncionario(listaFunc);                
                    cout << endl << "----------Funcionário removido com sucesso!----------" << endl; 

                }else{

                    cout << endl << "------------Funcionário não removido------------" << endl; 
                }
                
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


        if(listaFunc[indImprimir]->getDesignacao() == "gerente"){

            cout << "Área de Supervisão: " << ((Gerente*)listaFunc[indImprimir])->getAreaSupervisao() << endl; 

        } else if(listaFunc[indImprimir]->getDesignacao()  == "diretor"){

            cout << "Área de Supervisão: " << ((Diretor*)listaFunc[indImprimir])->getAreaSupervisao() << endl;
            cout << "Área de Formação: " << ((Diretor*)listaFunc[indImprimir])->getAreaFormacao() << endl;

        } else if(listaFunc[indImprimir]->getDesignacao() == "presidente"){
            
            cout << "Área de Formação: " << ((Presidente*)listaFunc[indImprimir])->getAreaFormacao() << endl;
            cout << "Formação Máxima: " << ((Presidente*)listaFunc[indImprimir])->getFormacaoMax() << endl;
        }

    }else{
        throw 1;
    }
    
}

void Gerenciamento::ExibirListaFuncionario(){

    system("clear");

    if(listaFunc.empty() == true){

        cout << endl << "-------------------Não há nenhum funcionário cadastrado-------------------";
        return;
    }

    for(int i= 0; i < listaFunc.size(); i++){

        ExibirFuncionario(listaFunc[i]->getCodigo());

    }
     cout << "-----" << "\n";
    
    // LerArquivoFuncionario();
    // Ver onde que essa função vai ser chamada. Porque os professores querem que os dados sejam gravados e lidos num arquivo. Deixa num vector ou lê os arquivo? Ambos funcionam tho

}

void Gerenciamento::ExibirTipoFuncionario(){

    system("clear");

    string designation;

    cout << "Digite o tipo do funcionário que vocẽ quer exibir  (digite 'operador', 'gerente', 'diretor' ou 'presidente'): " ;
    getline(cin, designation);

    if(designation != "operador" && designation != "gerente" && designation != "presidente" && designation != "diretor" ){  //verificando existencia da designacao

        throw 8;       //erro 8: DESIGNACAO NAO EXISTENTE   
    }

    if(listaFunc.empty() == true){

        cout << endl << "-------------------Não há nenhum funcionário cadastrado-------------------" ;
        return;
    }

    if(designation == "operador" || designation == "diretor"){

        cout << endl << endl << "Lista de " << designation << "(es): " << endl;
    }else{

        cout << endl << endl << "Lista de " << designation << "(s): " << endl;
    }
    

    for(int i= 0; i < listaFunc.size(); i++){

        if(listaFunc[i]->getDesignacao() == designation){
            
            ExibirFuncionario(listaFunc[i]->getCodigo());
        }
    }

}

void Gerenciamento::BuscarFuncionario(string search){

    vector<int> indBuscado;


    for(int i= 0; i < listaFunc.size(); i++){

        if( (listaFunc[i]->getNome().find(search) != string::npos) || (listaFunc[i]->getIngresso().find(search) != string::npos) || 
            (listaFunc[i]->getEndereco().find(search) != string::npos) ){

            indBuscado.push_back(i);
        }
    }

    if(indBuscado.empty() == false){

        cout << endl << "O(s) funcionário(s) existe(m). Suas informações são: " << endl << endl;

        for(int i= 0; i < indBuscado.size(); i++){

            ExibirFuncionario(listaFunc[indBuscado[i]]->getCodigo());
        }

    }else{

        throw 1;   //erro 1: FUNCIONARIO NAO EXISTENTE;
    }

}


//funcoes folha salarial
double Gerenciamento::CalcularFolhaSalarial(int mes){     //revisar esse metodo

    static int aleatorio= 7;

    int diasMax;
    int diasTrabalhados, horasExtras;
    double salarioTotal= 0;
    double salarioFunc, valorHoraExtra;
    double valor;

    if(listaFunc.empty() == true){

        throw 10; 
    }

    if(mes <= 0 || mes > 12){

        throw 2;        //erro 2: ERRO MES INVALIDO

    }else if(mes == 2){

        diasMax= 20;

    }else{
        diasMax= 22;
    }

    srand(time(NULL)+aleatorio);

    for(int i= 0; i < listaFunc.size(); i++){

        while(1){                                  //gerando os dias trabalhados aleatoriamente
            diasTrabalhados= rand() % diasMax + 1; 

            if(diasTrabalhados >= 15){
                break;
            }
        }

        horasExtras= rand() % 3 + 1;  //so pode no maximo4 horas diarias 

        salarioFunc= (listaFunc[i]->getSalario() / diasMax) * diasTrabalhados;
        
        //calculando o salario de cada funcionario e o total

        valorHoraExtra= listaFunc[i]->getSalario() / (diasMax * 8.0);
        valorHoraExtra= valorHoraExtra * 2.0 * horasExtras;

        salarioFunc += valorHoraExtra;

        listaFunc[i]->setDescontoINSS(0); 

        if(salarioFunc <= 1100){
            
            valor= salarioFunc * 7.5/100;
            listaFunc[i]->setDescontoINSS(valor); 

        }else if(salarioFunc <= 2203.48){

            valor= salarioFunc * 9.0/100;
            listaFunc[i]->setDescontoINSS(valor); 

        }else if(salarioFunc <= 3305.22){
            
            valor= salarioFunc * 12.0/100;
            listaFunc[i]->setDescontoINSS(valor); 

        }else{
            valor= salarioFunc * 14.0/100;
            listaFunc[i]->setDescontoINSS(valor); 
        }


        if(salarioFunc <= 1903.98){
            
            listaFunc[i]->setDescontoImposto(0); 

        }else if(salarioFunc <= 2826.65){

            valor= salarioFunc * 7.5/100;
            listaFunc[i]->setDescontoImposto(valor); 

        }else if(salarioFunc <= 3751.05){

            valor= salarioFunc * 15.0/100;
            listaFunc[i]->setDescontoImposto(valor); 

        }else if(salarioFunc <= 4664.68){

            valor= salarioFunc * 22.5/100;
            listaFunc[i]->setDescontoImposto(valor);

        }else{
            valor= salarioFunc * 27.5/100;
            listaFunc[i]->setDescontoImposto(valor);
        }

        salarioFunc -= (listaFunc[i]->getDescontoImposto() + listaFunc[i]->getDescontoINSS());

        listaFunc[i]->setSalarioLiquido(salarioFunc);

        salarioTotal += salarioFunc;
    }

    aleatorio++;        //incrementar o numero aleatorio 

    return salarioTotal;
}

void Gerenciamento::ImprimirFolhaSalarial(){     //revisar esse metodo

    bool existeFunc= false;
    int indice;
    string searched;

    system("clear");

    cout << "Digite o nome do código ou nome completo cadastrado do funcionário: " << endl;
    getline(cin, searched);

    for(int i= 0; i < listaFunc.size(); i++){

        if(listaFunc[i]->getCodigo() == searched || listaFunc[i]->getNome() == searched){

            existeFunc= true;
            indice= i;
            break;
        }
    }

    if(existeFunc){
        EscreverArquivoFolhaSalarialFuncionario(indice);
        // cout << "--------------------------------Funcionário--------------------------------" << endl;
        // cout << "Código: " << listaFunc[indice]->getCodigo() << endl;
        // cout << "Nome: " << listaFunc[indice]->getNome() << endl;
        // cout << "Salário bruto: R$ " <<  listaFunc[indice]->getSalario() << endl;
        // cout << "Desconto Previdência Social (INSS): R$ " <<  listaFunc[indice]->getDescontoINSS() << endl;
        // cout << "Desconto Imposto de Renda: R$ " <<  listaFunc[indice]->getDescontoImposto() << endl;
        // cout << "Total de descontos: R$ " <<  listaFunc[indice]->getDescontoImposto() << endl;
        // cout << "Salário líquido: R$ " <<  listaFunc[indice]->getSalarioLiquido() << endl;
        // cout << "----------------------------------------------------------------------------" << endl << endl;
        LerArquivoFolhaSalarialFuncionario();
    }else{
    
        throw 1;       //erro 1: funcionario nao existe
    }

}

void Gerenciamento::ImprimirFolhaSalarialEmpresa(){   //revisar esse metodo

    system("clear");

    int escolha;
    double salario= 0;
    vector<string> meses= {"janeiro", "fevereiro", "março", "abril", "junho", "julho", "agosto", "setembro", "outubro", "novembro", "dezembro"};

    cout << "Você deseja imprimir a folha salarial anual ou de um mês específico? " << endl << endl;

    cout << "Digite (0)- folha anual" << endl;
    cout << "Digite o número equivalente ao mês (de 1 a 12)- folha mensal do mês" << endl;

    cin >> escolha;
    cin.ignore();

    if(escolha < 0 || escolha > 12){

        throw 2;      //erro 2: MES INVALIDO    

    }else if(escolha == 0){

        for(int i= 1; i <= 12; i++){

            salario += CalcularFolhaSalarial(i);      //pegar do arquivo 
        }

        cout << "Folha Salarial Anual: R$" << salario << endl; 
        sleep(5);

    }else{

        salario = CalcularFolhaSalarial(escolha);      //calculando a folha salarial mensal

        cout << "Folha do Mês de " << meses[escolha-1] << ":   R$" << salario << endl;
        sleep(5);

    }

}

void Gerenciamento::ConfigurarAumento(){

    int i;

    system("clear");

    if(listaFunc.empty() == true){

        cout << endl << "-------------------Não há nenhum funcionário cadastrado-------------------";
        return;
    }

    for(i= 0; i < listaFunc.size(); i++){

        listaFunc[i]->Aumento(listaFunc[i]);
    }

    cout << endl << "-------------O aumento foi configurado a todos os funcionários-------------" << endl;

    EscreverArquivoFuncionario(listaFunc);
}

//funcoes extra
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
    string zero= "0";

    if(day >= 1 && day < 10){

        dataFormatada= zero + to_string(day)+ barra;

    }else{

        dataFormatada= to_string(day)+ barra;
    }

    if(month >= 1 && month < 10){

        dataFormatada +=  zero + to_string(month)+ barra;
    
    }else{

        dataFormatada += to_string(month)+ barra;
    }

    dataFormatada += to_string(year);

    return dataFormatada;
}

void Gerenciamento::ConfereCodigo(string code){

    int indImprimir= -1;
    for(int i= 0; i < listaFunc.size(); i++){               //conferir se o codigo do funcionario ja existe

        if(listaFunc[i]->getCodigo() == code){

            indImprimir= i;
            break;
        }
    }

    if(indImprimir != -1){

        throw 6;       //erro 6: FUNCIONARIO JA EXISTENTE
    }
}

void Gerenciamento::ExistePresid(){

    bool existePresid= false;
    for(int i= 0; i < listaFunc.size(); i++){                 // verificar se existe presidente na empresa

        if(listaFunc[i]->getDesignacao() == "presidente"){

            existePresid= true;
            break;
        }
    }
    
    if(existePresid == true){

        throw 9;        //erro 9: UM PRESIDENTE JA EXISTE
    }
}


//funcoes arquivo
void Gerenciamento::EscreverArquivoFuncionario(vector<Funcionario*> Func){ // Lê um vetor atualizado. Pra atualizar essa lista, só chamar essa função de novo.
    ofstream write;
    write.open("ListaFuncionarios.txt", ofstream::trunc);

    if(!write.is_open()){
        cout << "Falha na criação/abertura do arquivo Cadastro de Funcionários" << endl;
        return;
    }
    if(write.is_open()){
        for(int i = 0; i < Func.size(); i++){
            write << "Funcionário " << i + 1 << "\n";
            write << "\n";
            write << "Código: " << Func[i]->getCodigo() << "\n";
            write << "Nome: " << Func[i]->getNome() << "\n";
            write << "Endereço: " << Func[i]->getEndereco() << "\n";
            write << "Telefone: " << Func[i]->getTelefone() << "\n";
            write << "Ingresso: " << Func[i]->getIngresso() << "\n";
            write << "Designação: " << Func[i]->getDesignacao() << "\n";
            write << "Salário: " << Func[i]->getSalario() << "\n";
            
            if(Func[i]->getDesignacao() == "gerente"){
                write << "Área de Supervisão: " << ((Gerente*)Func[i])->getAreaSupervisao() << "\n"; 
            } else if(Func[i]->getDesignacao() == "diretor"){
                write << "Área de Supervisão: " << ((Diretor*)Func[i])->getAreaSupervisao() << "\n";
                write << "Área de Formaçao: " << ((Diretor*)Func[i])->getAreaFormacao() << "\n";
            } else if(Func[i]->getDesignacao() == "presidente"){
                write << "Área de Formação: " << ((Presidente*)Func[i])->getAreaFormacao() << "\n";
                write << "Formação Máxima: " << ((Presidente*)Func[i])->getFormacaoMax() << "\n";
            }
            write << "\n";
        }
    }
    write.close();
}

void Gerenciamento::LerArquivoFuncionario(){
    ifstream read;
    vector <string> Cadastro;
    string line;
    read.open("ListaFuncionarios.txt");
    if(!read.is_open()){
        cout << "Falha na abertura do arquivo Cadastro de Funcionários" << "\n";
    }

    if(read.is_open()){
        if(!read.eof()){
            while(getline(read, line)){
                Cadastro.push_back(line);
            }
        }
    }

    for(string linha : Cadastro){
        cout << linha << "\n";
    }
}

void Gerenciamento::EscreverArquivoFolhaSalarialFuncionario(int indice){  // chamar dentro da função de ImprimirFolhaSalarial. Usar o i da função. 
    ofstream write_folha_funcionario;

    write_folha_funcionario.open("FolhaSalarialFuncionario.txt", ofstream::trunc);
    if(indice != -1){
        if (!write_folha_funcionario.is_open()){
            cout << "RaisedExceptionFalhaNaCriação de arquivo" << "\n";
        }

        if (write_folha_funcionario.is_open()){
            write_folha_funcionario << "------------- Folha Salarial: " << listaFunc[indice]->getNome() << "-------------" << "\n";
            write_folha_funcionario << "\n";
            write_folha_funcionario << "Nome: " << listaFunc[indice]->getNome() << "\n";
            write_folha_funcionario << "Código: " << listaFunc[indice]->getCodigo() << "\n";
            write_folha_funcionario << "Salário bruto: R$ " <<  listaFunc[indice]->getSalario() << "\n";
            write_folha_funcionario << "Desconto Previdência Social (INSS): R$ " <<  listaFunc[indice]->getDescontoINSS() << "\n";
            write_folha_funcionario << "Desconto Imposto de Renda: R$ " <<  listaFunc[indice]->getDescontoImposto() << "\n";
            write_folha_funcionario << "Salário líquido: R$ " <<  listaFunc[indice]->getSalarioLiquido() << endl << "\n";
            write_folha_funcionario << "-------------------------------------------------------------------" << "\n";

        }
    } else{
        cout << "RaisedException - Funcionario Não Existe" << "\n";
    }

    write_folha_funcionario.close();

}

void Gerenciamento::LerArquivoFolhaSalarialFuncionario(){
    ifstream readFolhaFuncionario;
    vector <string> vectorReadFolhaFuncionario;
    string line;

    readFolhaFuncionario.open("FolhaSalarialFuncionario.txt");

    if(!readFolhaFuncionario.is_open()){
        cout << "RaisedException - Falha na criação do arquivo" << "\n";        
    }
    if(readFolhaFuncionario.is_open()){
        while(!readFolhaFuncionario.eof()){
            getline(readFolhaFuncionario, line);
            vectorReadFolhaFuncionario.push_back(line);
        }
    }

    for(string linha : vectorReadFolhaFuncionario){
        cout << linha << "\n";
    }
}

// Função CEP
string Gerenciamento::EnderecoCEP(string CEP){ // esperando apenas um funcionário tava dando problema com a instanciação desse funcionário. (testar e colocar uma condicional para caso a opção tenha sido por endereco)
// Colocar um tratamento pra caso não retorne nada.
    string cep;
    ifstream read;
    nlohmann::json jfile;
    string address;
    cep = CEP;

    system(("wget viacep.com.br/ws/" + cep + "/json/ -q -O " + cep + ".json").c_str());
    string read_file = cep + ".json";

    read.open(read_file);

    if(read.is_open()){
        jfile = nlohmann::json::parse(read);

        string rua = jfile["logradouro"];
        string bairro = jfile["bairro"];
        string cidade = jfile["localidade"];
        string uf = jfile["uf"];
        string cep = jfile["cep"];
        address = string("Rua: ") + rua + (" / Bairro: ") + bairro + " / Cidade: " + cidade + " / UF: " + uf + " / CEP: " + cep;

        // for(int i = 0; i < Lista.size(); i++){
        //     Lista[i]->setEndereco(address);
        // }
    } else{
        // cout << "RaiseException Endereço inválido" << "\n";
        address = "Não encontrado";
    }
    
    return address;
}

