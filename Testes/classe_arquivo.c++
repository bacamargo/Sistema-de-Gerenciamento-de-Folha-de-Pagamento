/*

A ideia é copiar algumas funções ou pelo menos a ideia delas aqui e escrever num arquivo a fim de ver como os objetos e seus atributos se comportam no salvamento

*/

# include <iostream>
# include <vector>
# include <fstream>
# include <string>

using namespace std;

class Funcionario{
    public:
        string nome;
        string funcao;
        int idade;          ////

        void setNome(string Nome){
            nome = Nome;
        }
       
        void setFuncao(string Funcao){
            funcao = Funcao;
        }

        void setIdade(int Idade){
            idade = Idade;
        }
         

};

class Gerencimaneto{
    protected:
        vector <Funcionario> Lista;
        ofstream Write;
        ifstream Read;
        vector <string> Read_vec;
        string str;
        string line;
    public:
        void AdicionarFuncionario(Funcionario *Func){
            Lista.push_back(*Func);
            Write.open("Cadastro_Funcionarios.txt");
            if(Write.is_open()){
                Write << Func->nome;
                Write << "\n";
                Write << Func->funcao;
                Write << "\n";
                Write << to_string(Func->idade);
            } else{
                cout << "RaisedException: Falha na criação do arquivo 'Cadastro_Funcionario.txt'." << endl;
            }
            Write.close();
        }

        void ListarFuncionariosVetor(){
            for(int i = 0; i < Lista.size(); i++){
                cout << Lista[i].nome << endl;
                cout << Lista[i].funcao << endl;
                cout << Lista[i].idade << endl;

            }
        }

        void ListarFuncionariosArquivos(){
            Read.open("Cadastro_Funcionarios.txt");
            if(Read.is_open()){
                while(getline(Read, line)){
                    Read_vec.push_back(line);
                }
            }
            else{
                cout << "RaisedException: Falha na abertura do arquivo 'Cadastro_Funcionario.txt" << endl;
            }

            for(string item : Read_vec){
                cout << item << endl;
            }
        }

};

int main(){

    string nome, funcao;
    int idade;

    getline(cin >> ws, nome);
    getline(cin >> ws, funcao);
    cin >> idade;

    Funcionario *Func = new Funcionario(); 
    Func->setNome(nome);
    Func->setIdade(idade);
    Func->setFuncao(funcao);

    Gerencimaneto Folha;

    Folha.AdicionarFuncionario(Func);
    cout << "------------------------" << endl;
    Folha.ListarFuncionariosVetor();
    cout << "------------------------" << endl;
    Folha.ListarFuncionariosArquivos();


}
