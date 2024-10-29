#include <iostream>
#include <cstring>
#include <limits>
#include <cstdio>
#include <string>
using namespace std;

    struct livros{
        int codigo,paginas;
        char area[30],titulo[255], autores[255],editora[50];
        struct emprestimos emp;
};
    struct emprestimos {
        char usuario[255],dt_emp[10],dt_devolucao[10];
};
int opc_princ, opc , cod, pos;
struct livros livro;

        int main(){
    do {
        cout << "###### MENU DE BIBLIOTECA ######" << endl;
        cout << "1 - Cadastro" << endl;
        cout << "2 - Alteracao" << endl;
        cout << "3 - Exclusao" << endl;
        cout << "4 - Emprestimo" << endl;
        cout << "5 - Devolucao" << endl;
        cout << "6 - Consulta de livro" << endl;
        cout << "7 - Livros disponiveis" << endl;
        cout << "8 - Listagem geral de livros" << endl;
        cout << "9 - Sair" << endl << endl;
        cout << "Digite a opcao desejada: ";
        cin >> opc_princ;

           switch (opc_princ){
            case 1:



                break;
            case 2:



                break;
            case 3:



                break;
            case 4:



                break;
            case 5:



                break;
            case 6:



                break;
            case 7:



                break;
            case 8:



                break;
            case 9:
                cout << "Ecerrado o programa! " << endl;


                break;
            default:
                cout << " Informe uma opcao valida! ";
                break;



        }
    }while (opc_princ != 9);
        }
