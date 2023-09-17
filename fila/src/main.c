#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
  int valor;
  struct No *prox;
} t_no;

typedef struct
{
  t_no *primeiro
} t_fila;

t_fila inicializarFila();
t_no *criarNo(int valor);
void listar(t_fila *fila);
void liberarMemoria(t_fila *fila);
void enfileira(t_fila *fila, int valor);
int desenfileira(t_fila *fila);

int main()
{

  t_fila fila = inicializarFila();
  enfileira(&fila, 5);
  enfileira(&fila, 2);
  enfileira(&fila, 3);
  listar(&fila);

  enfileira(&fila, 8);
  enfileira(&fila, 10);
  enfileira(&fila, 2);
  desenfileira(&fila);
  listar(&fila);
  return 0;
}

t_fila inicializarFila()
{
  t_fila fila = {.primeiro = NULL};
  return fila;
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

void listar(t_fila *fila)
{
  if (!fila)
  {
    fprintf(stderr, "Fila Inválida!\n");
    return;
  }

  if (!fila->primeiro)
  {
    printf("Fila Vazia!\n");
    return;
  }
  t_no *aux = fila->primeiro;
  while (aux)
  {
    printf("(%d)->", aux->valor);
    aux = aux->prox;
  }
  printf("NULL\n");
}

void liberarMemoria(t_fila *fila)
{
  if (!fila)
  {
    fprintf(stderr, "Fila Inválida!\n");
    return;
  }

  if (!fila->primeiro)
  {
    printf("Fila Vazia!\n");
    return;
  }

  t_no *aux = fila->primeiro;
  while (aux)
  {
    t_no *prox = aux->prox;
    free(aux);
    aux = prox;
  }
}

void enfileira(t_fila *fila, int valor)
{
  if (!fila)
  {
    fprintf(stderr, "Fila Inválida!\n");
    return;
  }

  t_no *novo_no = criarNo(valor);
  if (!novo_no)
  {
    fprintf(stderr, "Erro ao criar nó.\n");
    return;
  }

  if (!fila->primeiro)
  {
    fila->primeiro = novo_no;
  }
  else
  {
    t_no *aux = fila->primeiro;
    while (aux->prox)
    {
      aux = aux->prox;
    }
    aux->prox = novo_no;
  }
}

int desenfileira(t_fila *fila)
{
  if (!fila)
  {
    fprintf(stderr, "Fila Inválida!\n");
    return NULL;
  }

  if (!fila->primeiro)
  {
    printf("Fila Vazia!\n");
    return -1;
  }

  t_no *aux = fila->primeiro->prox;
  int valor = fila->primeiro->valor;
  free(fila->primeiro);
  fila->primeiro = aux;
  return valor;
}