typedef struct funcionario
{
    int id;
    char nome[30];
    char endereco[100];
    int idade;
    float salario;
    char cargo[30];
} FUNCIONARIO;

typedef struct elemento* Lista;

Lista *criaLista();

int tamLista(Lista *li);

int listaVazia(Lista *li);

int inseri_lista_ordenada(Lista *li, FUNCIONARIO fun);

FUNCIONARIO coletaDados();

int imprimiDados(FUNCIONARIO fun);

int remove_lista(Lista *li, int id);

int consulta_lista_id(Lista *li, int id, FUNCIONARIO *fun);

void apagaLista(Lista *li);