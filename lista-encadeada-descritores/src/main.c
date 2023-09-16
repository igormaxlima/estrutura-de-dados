#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
  int valor;
  struct No *prox;
} t_no;

typedef struct
{
  t_no *primeiro;
  t_no *ultimo;
  int size;
} t_lista;

t_lista inicializarLista();
t_no *criarNo(int valor);
void listar(t_lista *lista);
void inserirInicio(t_lista *lista, int valor);
void inserirFim(t_lista *lista, int valor);
void inserirOrdenado(t_lista *lista, int valor);
void deletarInicio(t_lista *lista);
void deletarFim(t_lista *lista);

int main()
{
  t_lista lista = inicializarLista();
  inserirFim(&lista, 5);
  inserirFim(&lista, 10);
  inserirInicio(&lista, 10);
  inserirInicio(&lista, 2);

  listar(&lista);

  return 0;
}

t_lista inicializarLista()
{
  t_lista lista = {.primeiro = NULL, .ultimo = NULL, .size = 0};
  return lista;
}

t_no *criarNo(int valor)
{
  t_no *novo_no = malloc(sizeof(t_no));
  if (novo_no)
  {
    novo_no->valor = valor;
    novo_no->prox = NULL;
  }
  return novo_no;
}

void listar(t_lista *lista)
{
  t_no *aux = lista->primeiro;
  while (aux)
  {
    printf("(%d)->", aux->valor);
    aux = aux->prox;
  }
  printf("\nSize: %d\n", lista->size);
}

void inserirFim(t_lista *lista, int valor)
{
  t_no *novo_no = criarNo(valor);
  if (!lista->primeiro)
  {
    lista->primeiro = novo_no;
    lista->ultimo = novo_no;
    lista->size++;
  }
  else
  {
    lista->ultimo->prox = novo_no;
    lista->ultimo = novo_no;
    lista->size++;
  }
}

void inserirInicio(t_lista *lista, int valor)
{
  t_no *novo_no = criarNo(valor);
  if (!lista->primeiro)
  {
    lista->primeiro = novo_no;
    lista->ultimo = novo_no;
    lista->size++;
  }
  else
  {
    novo_no->prox = lista->primeiro;
    lista->primeiro = novo_no;
    lista->size++;
  }
}