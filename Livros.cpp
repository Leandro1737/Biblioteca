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

int opc_princ, cod, pos,opc1;
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
        cin.ignore();

        switch (opc_princ){
            case 1:
                cout << " Deseja cadastrar um livro (S ou N)";
                cin >> opc;
                while (opc == 'S' || opc == 's'){
                    cout << "Digite o codigo do livro: ";
                    cin >> livro.codigo;
                    cin.ignore();

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
                    cin.ignore();

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

                    cout << " Deseja cadastrar outro livro (S ou N)";
                    cin >> opc;
                }

                break;
            case 2:
                 arquivo = fopen("dados.dat", "rb+"); // Abre o arquivo para leitura e escrita
                if (arquivo != NULL) {
                cout << "Digite o codigo do livro que deseja alterar: ";
                cin >> cod;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

          int pos =0;
        bool livro_encontrado = false;

        while (fread(&livro, sizeof(struct livros), 1, arquivo) == 1) {
            if (cod == livro.codigo) {
                livro_encontrado = true;
                cout << "Livro encontrado! Você pode alterar os seguintes campos:" << endl;
                cout << "1 - Titulo" << endl;
                cout << "2 - Area" << endl;
                cout << "3 - Autores" << endl;
                cout << "4 - Editora" << endl;
                cout << "5 - Numero de Paginas" << endl;
                cout << "6 - Sair" << endl;

                do {
                    cout << "Escolha a opção: ";
                    cin >> opc1;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    switch (opc1) {
                        case 1: {
                            char tit_novo[255];
                            cout << "Digite o novo titulo: ";
                            cin.get(tit_novo, 255);
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            strcpy(livro.titulo, tit_novo); // Atualiza o título
                            break;
                        }
                        case 2:
                            cout << "Digite a nova area: ";
                            cin.get(livro.area, 30);
                            break;

                        case 3:
                            cout << "Digite os novos autores: ";
                            cin.get(livro.autores, 255);
                            break;

                        case 4:
                            cout << "Digite a nova editora: ";
                            cin.get(livro.editora, 50);
                            break;

                        case 5:
                            cout << "Digite o novo numero de paginas: ";
                            cin >> livro.paginas;
                            cin.ignore();
                            break;

                        case 6:
                            cout << "Saindo da alteração." << endl;
                            break;

                        default:
                            cout << "Opcao invalida! Tente novamente." << endl;
                            break;
                    }

                    // Atualiza o livro no arquivo após cada alteração
                    fseek(arquivo, sizeof(struct livros) * pos, SEEK_SET);
                    fwrite(&livro, sizeof(struct livros), 1, arquivo);
                } while (opc1 != 6);
            }
            pos++;
        }
        if (!livro_encontrado) {
            cout << "Livro não encontrado!" << endl;
        }
        fclose(arquivo);
    } else {
        cout << "Erro ao abrir o arquivo!" << endl;
    }
    break;
            case 3:
 arquivo = fopen("dados.dat", "rb+");
                if (arquivo != NULL){
                    cout << "Digite o código do livro que deseja emprestar: ";
                    cin >> cod;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    pos = -1;
                    while(!feof(arquivo)){
                        fread(&livro, sizeof(struct livros), 1, arquivo);
                        pos++;
                        if (cod == livro.codigo){
                            fseek(arquivo, sizeof(struct livros) * pos, SEEK_SET);
                            cout << "Data de empréstimo: ";
                            cin.get(livro.emp.dt_emp, 10);
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "Data de devolução: ";
                            cin.get(livro.emp.dt_devolucao, 10);
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "Usuário: ";
                            cin.get(livro.emp.usuario, 255);
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            fwrite(&livro, sizeof(struct livros), 1, arquivo);
                            break;
                        }
                    }
                    fclose(arquivo);

                } else {
                    cout << "Erro ao abrir o banco de dados!";
                    cin.ignore();
                    cin.get();
                }
                break;
            case 5:
                  arquivo = fopen("dados.dat", "rb+");
                if (arquivo != NULL){
                    cout << "Digite o código do livro que deseja devolver: ";
                    cin >> cod;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    pos = -1;
                    while(!feof(arquivo)){
                        fread(&livro, sizeof(struct livros), 1, arquivo);
                        pos++;
                        if (cod == livro.codigo){
                            fseek(arquivo, sizeof(struct livros) * pos, SEEK_SET);
                            strcpy(livro.emp.dt_emp, "");
                            strcpy(livro.emp.dt_devolucao, "");
                            strcpy(livro.emp.usuario, "");
                            fwrite(&livro, sizeof(struct livros), 1, arquivo);
                            break;
                        }
                    }
                    fclose(arquivo);

                } else {
                    cout << "Erro ao abrir o banco de dados!";
                    cin.ignore();
                    cin.get();
                }
                break;
            case 6:
                arquivo = fopen("dados.dat", "rb");
                if (arquivo != NULL){
                    cout << "Digite o código do livro que deseja pesquisar: ";
                    cin >> cod;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    while(!feof(arquivo)){
                        fread(&livro, sizeof(struct livros), 1, arquivo);
                        if (cod == livro.codigo){
                            cout << "Código: " << livro.codigo << endl;
                            cout << "Área: " << livro.area << endl;
                            cout << "Título: " << livro.titulo << endl;
                            cout << "Autor(es): " << livro.autores << endl;
                            cout << "Editora: " << livro.editora << endl;
                            cout << "Nº páginas: " << livro.paginas << endl;
                            cin.get();
                            break;
                        }
                    }
                    fclose(arquivo);

                } else {
                    cout << "Erro ao abrir o banco de dados!";
                    cin.ignore();
                    cin.get();
                }
                break;



                break;
            case 7:
                arquivo = fopen("dados.dat", "rb");
                if (arquivo != NULL){
                    fread(&livro, sizeof(struct livros), 1, arquivo);
                    while(!feof(arquivo)){
                        if (strcmp(livro.emp.dt_emp, "") == 0){
                            cout << "Código: " << livro.codigo << endl;
                            cout << "Área: " << livro.area << endl;
                            cout << "Título: " << livro.titulo << endl;
                            cout << "Autor(es): " << livro.autores << endl;
                            cout << "Editora: " << livro.editora << endl;
                            cout << "Nº páginas: " << livro.paginas << endl;
                            cout << "---------------------------------------" << endl;
                        }
                        fread(&livro, sizeof(struct livros), 1, arquivo);
                    }
                    fclose(arquivo);
                    cin.ignore();
                    cin.get();
                } else {
                    cout << "Erro ao abrir o banco de dados!";
                    cin.ignore();
                    cin.get();
                }
                break;



                break;
            case 8:
                arquivo = fopen("dados.dat", "rb");
                if (arquivo != NULL) {
                    while (fread(&livro, sizeof(struct livros), 1, arquivo) == 1) {
                        cout << "Código: " << livro.codigo << endl;
                        cout << "Área: " << livro.area << endl;
                        cout << "Título: " << livro.titulo << endl;
                        cout << "Autor(es): " << livro.autores << endl;
                        cout << "Editora: " << livro.editora << endl;
                        cout << "Nº páginas: " << livro.paginas << endl;
                        cout << "---------------------------------------" << endl;
                    }
                    fclose(arquivo);
                    cin.ignore();
                    cin.get();
                } else {
                    cout << "Erro ao abrir o banco de dados!" << endl;
                }
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
