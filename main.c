#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaLigada.h"

int main() {
    // ponteiro para ponteiro que está no arquivo .h
    Lista *li;
    int menu = 10, x, opcao, id, i;
    float min, max;
    struct funcionario fun;

    li = criaLista();

    while (menu != 0) {        
        system("clear || cls");
        printf("======MENU======\n");
        printf("Escolha uma opcao: \n");
        printf("0 - Sair do programa\n");
        printf("1 - Adicionar funcionario\n");
        printf("2 - Excluir funcionario\n");
        printf("3 - Editar funcionario, inclusive com opcao especifica para aumento de salarios por percentual de aumento\n");
        printf("4 - Buscar funcionario\n");
        printf("5 - Exibir funcionario ordenados por ID, com todos os seus dados \n");
        printf("6 - Exibir uma lista de funcionarios por faixa salarial\n");

        scanf("%d", &menu);

        if (menu == 1) {
            x = inseri_lista_ordenada(li, coletaDados());
            if (x) {
                printf("\nInserido no ordenadamente com sucesso!\n");
            } else {
                printf("\nInserido no ordenadamente sem sucesso!\n");
            }
            system("PAUSE");
        } else if (menu == 2) {
            printf("Qual ID voce quer excluir:");
            scanf("%d", &id);
            x = consulta_lista_id(li, id, &fun);
            if (x)
            {
                imprimiDados(fun);
                printf("\nVoce tem certeza que deseja excluir");
                printf("\n[1] Para sim");
                printf("\n[2] Para nao \n");
                printf("\n[Qualquer numero] Para sair \n");
                scanf("%d", &opcao);
                if (opcao == 1) {
                    x = remove_lista(li, id);
                    if (x)
                    {
                        printf("\nRemovido ordenadamente com sucesso!\n");
                    } else {
                        printf("\nRemovido ordenadamente sem sucesso!\n");
                    }
                }    
            } else {
                printf("\nDados nao encontrados!\n");
            }
            system("PAUSE");
        } else if (menu == 3) {
            printf("Qual ID voce quer editar funcionario,:");
            scanf("%d", &id);
            x = consulta_lista_id(li, id, &fun);
            if (x) {
                imprimiDados(fun);
                printf("\nVoce quer: ");
                printf("\n[1]  Editar de informacoes");
                printf("\n[2] Reajustar salarial; \n");
                printf("\n[Qualquer numero] Para sair \n");
                scanf("%d", &opcao);
                if (opcao == 1 || opcao == 2) {
                    x = remove_lista(li, id);
                    fun = coletaDados();
                    x = inseri_lista_ordenada(li, fun);
                    if (x) {
                        printf("\nInserido no ordenadamente com sucesso!\n");
                    } else {
                        printf("\nInserido no ordenadamente sem sucesso!\n");
                    }
                }
            } else {
                printf("\nDados nao encontrados!\n");
            }
            system("PAUSE");
        } else if (menu == 4) {
            printf("Qual ID voce quer buscar:");
            scanf("%d", &id);
            x = consulta_lista_id(li, id, &fun);
            if (x) {
                imprimiDados(fun);
            } else {
                printf("\nDados nao encontrados!\n");
            }
            system("PAUSE");
        } else if (menu == 5) {
            for (i = 1; i <= tamLista(li); i++) {
                x = consulta_lista_id(li, i, &fun);
                if (x) {
                    imprimiDados(fun);
                } else {
                    printf("\nDados nao encontrados!\n");
                }
            }
            system("PAUSE");
        } else if (menu == 6) {
            printf("Qual o menor salario que voce quer ver:");
            scanf("%f", &min);
            printf("Qual o maior salario que voce quer ver:");
            scanf("%f", &max);
            for (i = 1; i <= tamLista(li); i++) {
                x = consulta_lista_id(li, i, &fun);
                if (x) {
                    if (min <= fun.salario && fun.salario <= max) {
                        printf("\nID : %d", fun.id);
                        printf("\nNome : %s", fun.nome);
                        printf("\nSalario R$ %.2f", fun.salario);
                        printf("\nCargo : %s \n", fun.cargo);
                    }
                } else {
                printf("\nDados nao encontrados!\n");
                }
            }
            system("PAUSE");
        }
    }
    

    apagaLista(li);
    printf("\n\n\n");
    system("PAUSE");

    return 0;
}