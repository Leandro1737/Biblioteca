#include <iostream>
#include <cstring>
#include <limits>
#include <cstdio>
using namespace std;

    struct emprestimos {
        char usuario[255],dt_emp[10],dt_devolucao[10];
};

    struct livros{
        int codigo,paginas;
        char area[30],titulo[255], autores[255],editora[50];
        struct emprestimos emp;
};

int opc_princ, cod, pos;
char opc ;

FILE *arquivo, *arqreserva;

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
                cout << " Deseja cadastrar um livro (S ou N)";
                cin >> opc;
                while (opc == 'S' || opc == 's'){
                    cout << "Digite o codigo do livro: ";
                    cin >> livro.codigo;
                    cout << "Digite a area do livro: ";
                    cin.get(livro.area, 30);
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    cout << "Digite o titulo do livro: ";
                    cin.get(livro.titulo, 255);
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    cout << "Digite o nome dos Autores: ";
                    cin.get(livro.autores, 255);
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    cout << "Digite o nome da Editora: ";
                    cin.get(livro.editora, 50);
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    cout << "N paginas: ";
                    cin >> livro.paginas;

                    arquivo = fopen("dados.dat", "ab");
                    if (arquivo == NULL){
                        arquivo = fopen("dados.dat", "wb");
                    }

                   if(fwrite(&livro,sizeof(struct livros),1,arquivo) ==1){
                    cout << "Livro cadastrado com sucesso! ";
                   }else{
                    cout << "Erro ao cadastrar o livro! ";
                   }
                   fclose (arquivo);

                   cin.ignore();
                   cin.get();


                    cout << " Deseja cadastrar um livro (S ou N)";
                    cin >> opc;
                }

                break;
            case 2:
                arquivo = fopen("dados.dat","rb+");
                if(arquivo != NULL){
                  cout << "Digite o codigo do livro que deseja alterar: ";
                  cin >> cod;
                  cin.ignore(numeric_limits<streamsize>::max(),'\n');

                  pos = -1;
                  while(!feof(arquivo)){

                    fread(&livro,sizeof(struct livros),1,arquivo);
                    pos++;
                    if(cod == livro.codigo ){
                        cout << "Digite onde voce quer alterar"<< endl << endl;
                        cout << "opção 1 - Titulo" << endl;
                        cout << "opção 2 - Area" << endl;
                        cout << "opção 3 - Autore" << endl;
                        cout << "opção 4 - Editora" << endl;
                        cout << "opção 5 - Numero de Paginas" << endl;


                        fwrite(&livro,sizeof(struct livros)*pos,arquivo) // define onde ira ser alterado


                    }

                  }


                }



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
