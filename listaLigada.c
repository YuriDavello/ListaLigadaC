#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaLigada.h"

struct elemento
{
    FUNCIONARIO dados;
    struct elemento *prox;
};

typedef struct elemento ELEM;

Lista *criaLista() {
    Lista *li;
    li = (Lista*) malloc(sizeof(Lista));
    if (li != NULL)
    {
        *li = NULL;
    }
    return li;   
}


int tamLista(Lista *li) {
    if (li == NULL) {
        return 0;
    }
    int acum = 0;
    ELEM *no = *li;
    while (no != NULL)
    {
        acum++;
        no = no->prox;
    }
    return acum; 
}

int listaVazia(Lista *li) {
    if (li == NULL) {
        return 1;
    }
    if (*li == NULL) {
        return 1;
    }
        return 0;
}

int inseri_lista_ordenada(Lista *li, FUNCIONARIO fun) {
    if (li == NULL)
    {
        return 0;
    }
    ELEM *no = (ELEM*) malloc(sizeof(ELEM));
    if (no == NULL)
    {
        return 0;
    }
    no->dados = fun;
    if (listaVazia(li))
    {
        no->prox = (*li);
        *li = no;
        return 1;
    } else
    {
        ELEM *ant, *atual = *li;
        while (atual != NULL && atual->dados.id < fun.id)
        {
            ant = atual;
            atual = atual->prox;
        }
        if (atual == *li)
        {
            no->prox = (*li);
            *li = no;
        } else {
            no->prox = ant->prox;
            ant->prox = no;
        }
        return 1;
    }
}

FUNCIONARIO coletaDados() { 
    FUNCIONARIO fun;
    printf("Qual e o ID: ");
    scanf("%d",  &fun.id);
    printf("Qual e o nome do funcionario: ");
    getchar();
    fgets(fun.nome, 29, stdin);
    fun.nome[strlen(fun.nome)-1] = '\0';
    printf("Qual e o endereco do funcionario: ");
    fgets(fun.endereco, 99, stdin);
    fun.endereco[strlen(fun.endereco)-1] = '\0';
    printf("Qual e a idade: ");
    scanf("%d", &fun.idade);
    printf("Qual e o salario: ");
    scanf("%f", &fun.salario);
    printf("Qual e o cargo: ");
    getchar();
    fgets(fun.cargo, 29, stdin);
    fun.cargo[strlen(fun.cargo)-1] = '\0';
    return fun;
}

int imprimiDados(FUNCIONARIO fun) { 
    printf("\nID : %d", fun.id);
    printf("\nNome : %s", fun.nome);
    printf("\nEndereco : %s", fun.endereco);
    printf("\nIdade : %d", fun.idade);
    printf("\nSalario : %.2f", fun.salario);
    printf("\nCargo : %s \n", fun.cargo);
    return 0;
}

int remove_lista(Lista *li, int id) {
    if (li == NULL)
    {
        return 0;
    }
    ELEM *ant, *no = *li;
    while (no != NULL && no->dados.id != id)
    {
        ant = no;
        no = no->prox;
    }
    if (no == NULL)
    {
        return 0;
    }
    if (no == *li)
    {
        *li = no->prox;
    } else
    {
        ant->prox = no->prox;
    }
    free(no);
    return 1;   
}

int consulta_lista_id(Lista *li, int id, FUNCIONARIO *fun) {
    if (li == NULL)
    {
        return 0;
    }
    ELEM *no = *li;
    while (no != NULL && no->dados.id != id)
    {
        no = no->prox;
    }
    if (no == NULL)
    {
        return 0; 
    } else {
        *fun = no->dados;
        return 1;
    }
}


void apagaLista(Lista *li) {
    if (li != NULL) {
        ELEM *no;
        while ((*li) != NULL)
        {
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
    
}