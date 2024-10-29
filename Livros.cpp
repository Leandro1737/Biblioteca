#include <iostream>
#include <string>
using namespace std;

    struct livros{
        int codigo;
        string titulo, autor;
};
    struct emprestimo {
        int codigoLivro;
        string usuario,dataEmprestimo,dataDevolucao;
};

void exibirMenu() {
    cout << "\n--- Menu de Livros ---" << endl;
    cout << "1 – Cadastro" << endl;
    cout << "2 – Alteracao" << endl;
    cout << "3 – Exclusao" << endl;
    cout << "4 – Emprestimo" << endl;
    cout << "5 – Devolucao" << endl;
    cout << "6 – Consulta de livro" << endl;
    cout << "7 – Livros disponiveis" << endl;
    cout << "8 – Listagem geral de livros" << endl;
    cout << "9 – Sair" << endl;
    cout << "Escolha uma opcao: ";
};
int main(){

}
