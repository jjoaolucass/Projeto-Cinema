#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filme.h"
#include "cinema.h"

int main() {
    Filme* listaFilmes = NULL;
    Usuario* listaUsuario = NULL;
    const char *nomeArquivoFilmes = "filmes.txt";
    const char *nomeArquivoUsuarios = "usuarios.txt";
    int opcaoGeral, opcaoFilme, opcaoUsuario, id;

    carregarFilmesDoArquivo(&listaFilmes, nomeArquivoFilmes);
    carregarUsuariosDoArquivo(&listaUsuario, nomeArquivoUsuarios);

    do {
        printf("\n--- Sistema de Gerenciamento ---\n");
        printf("1. Gerenciar Filmes\n");
        printf("2. Gerenciar Usuários\n");
        printf("0. Sair\n");

        opcaoGeral = obterOpcaoMenu();

        switch (opcaoGeral) {
            case 1:
                do {
                    printf("\nGerenciamento de Filmes\n");
                    printf("1. Adicionar Filme\n");
                    printf("2. Exibir Filmes\n");
                    printf("3. Excluir Filme\n");
                    printf("4. Editar Filme\n");
                    printf("0. Voltar\n");

                    opcaoFilme = obterOpcaoMenu();

                    switch (opcaoFilme) {
                        case 1:
                            adicionarFilme(&listaFilmes);
                            salvarFilmesNoArquivo(listaFilmes, nomeArquivoFilmes);
                            break;
                        case 2:
                            exibirFilmes(listaFilmes);
                            break;
                        case 3:
                            printf("Digite o ID do filme que deseja excluir: ");
                            scanf("%d", &id);
                            getchar();
                            excluirFilme(&listaFilmes, id);
                            salvarFilmesNoArquivo(listaFilmes, nomeArquivoFilmes);
                            break;
                        case 4:
                            printf("Digite o ID do filme que deseja editar: ");
                            scanf("%d", &id);
                            getchar();
                            editarFilme(listaFilmes, id);
                            salvarFilmesNoArquivo(listaFilmes, nomeArquivoFilmes);
                            break;
                        case 0:
                            break;
                        default:
                            printf("Opção inválida!\n");
                    }
                } while (opcaoFilme != 0);
                break;

            case 2:
                do {
                    printf("\nCadastramento de Usuários\n");
                    printf("1. Cadastrar usuário\n");
                    printf("2. Listar usuários\n");
                    printf("0. Voltar\n");

                    opcaoUsuario = obterOpcaoMenu();

                    switch (opcaoUsuario) {
                        case 1:
                            cadastrarUsuario(&listaUsuario);
                            salvarUsuarioNoArquivo(listaUsuario, nomeArquivoUsuarios);
                            break;
                        case 2:
                            exibirUsuarios(listaUsuario);
                            break;
                        case 0:
                            break;
                        default:
                            printf("Opção inválida!\n");
                    }
                } while (opcaoUsuario != 0);
                break;

            case 0:
                printf("Saindo...\n");
                salvarFilmesNoArquivo(listaFilmes, nomeArquivoFilmes);
                salvarUsuarioNoArquivo(listaUsuario, nomeArquivoUsuarios);
                break;

            default:
                printf("Opção inválida!\n");
        }
    } while (opcaoGeral != 0);

    return 0;
}