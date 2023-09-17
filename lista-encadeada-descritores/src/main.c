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
  inserirFim(&lista, 2);
  inserirFim(&lista, 4);
  inserirFim(&lista, 6);
  inserirOrdenado(&lista, 10);
  deletarFim(&lista);
  deletarFim(&lista);
  deletarFim(&lista);

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
  printf("NULL\n");
  printf("Size: %d\n", lista->size);
}

void inserirEmListaVazia(t_lista *lista, t_no *novo_no)
{
  lista->primeiro = novo_no;
  lista->ultimo = novo_no;
  lista->size++;
}

void inserirFim(t_lista *lista, int valor)
{
  if (!lista)
  {
    fprintf(stderr, "Lista inválida!\n");
    return;
  }

  t_no *novo_no = criarNo(valor);
  if (!novo_no)
  {
    fprintf(stderr, "Novo Nó nao criado com sucesso!\n");
    return;
  }

  if (!lista->primeiro)
  {
    inserirEmListaVazia(lista, novo_no);
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
  if (!lista)
  {
    fprintf(stderr, "Lista inválida!\n");
    return;
  }

  t_no *novo_no = criarNo(valor);
  if (!novo_no)
  {
    fprintf(stderr, "Novo Nó nao criado com sucesso!\n");
    return;
  }

  if (!lista->primeiro)
  {
    inserirEmListaVazia(lista, novo_no);
  }
  else
  {
    novo_no->prox = lista->primeiro;
    lista->primeiro = novo_no;
    lista->size++;
  }
}

void inserirOrdenado(t_lista *lista, int valor)
{
  if (!lista)
  {
    fprintf(stderr, "Lista inválida!\n");
    return;
  }

  t_no *novo_no = criarNo(valor);
  if (!novo_no)
  {
    fprintf(stderr, "Novo Nó nao criado com sucesso!\n");
    return;
  }

  if (!lista->primeiro)
  {
    inserirEmListaVazia(lista, novo_no);
  }
  else if (novo_no->valor < lista->primeiro->valor)
  {
    inserirInicio(lista, valor);
  }
  else if (novo_no->valor > lista->ultimo->valor)
  {
    inserirFim(lista, valor);
  }
  else
  {
    t_no *atual = lista->primeiro;
    while (atual->prox)
    {
      if (novo_no->valor < atual->prox->valor)
        break;
      atual = atual->prox;
    }
    novo_no->prox = atual->prox;
    atual->prox = novo_no;
    lista->size++;
  }
}

void deletarInicio(t_lista *lista)
{
  if (!lista)
  {
    fprintf(stderr, "Lista inválida!\n");
    return;
  }

  if (!lista->primeiro)
  {
    printf("Lista vazia!\n");
    return;
  }

  t_no *aux = lista->primeiro->prox;
  free(lista->primeiro);
  lista->primeiro = aux;
  lista->size--;
}

void deletarFim(t_lista *lista)
{
  if (!lista)
  {
    fprintf(stderr, "Lista inválida!\n");
    return;
  }

  if (!lista->primeiro)
  {
    printf("Lista vazia!\n");
    return;
  }

  if (!lista->primeiro->prox)
  {
    free(lista->primeiro);
    lista->primeiro = NULL;
    lista->size--;
  }
  else
  {
    t_no *aux = lista->primeiro;
    while (aux->prox != lista->ultimo)
    {
      aux = aux->prox;
    }
    free(lista->ultimo);
    aux->prox = NULL;
    lista->ultimo = aux;
    lista->size--;
  }
}