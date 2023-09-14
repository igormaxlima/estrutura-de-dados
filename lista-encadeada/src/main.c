#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
  int info; // elemento da lista
  struct no *prox;
} t_no;

typedef struct lista
{
  t_no *primeiro;
} t_lista;

void inicializarListaV1(t_lista *lista)
{
  lista->primeiro = NULL;
}
t_lista inicializarListaV2()
{
  t_lista lista = {.primeiro = NULL};
  return lista;
}

void liberarMemoria(t_lista *lista)
{
  if (!lista)
  {
    fprintf(stderr, "Lista inválida.\n");
    return;
  }

  t_no *atual = lista->primeiro;
  while (atual != NULL)
  {
    t_no *prox = atual->prox;
    free(atual);
    atual = prox;
  }

  lista->primeiro = NULL;
}

t_no *criar_no(int info)
{
  t_no *novo_no = malloc(sizeof(t_no));
  if (novo_no)
  {
    novo_no->info = info;
    novo_no->prox = NULL;
  }
  return novo_no;
}

void inserirFim(t_lista *lista, int info)
{
  if (lista == NULL)
  {
    fprintf(stderr, "Lista inválida.\n");
    return;
  }

  t_no *novo_no = criar_no(info);
  if (!novo_no)
  {
    fprintf(stderr, "Erro ao criar nó.\n");
    return;
  }

  if (!lista->primeiro)
  {
    lista->primeiro = novo_no;
  }
  else
  {
    t_no *aux = lista->primeiro;
    while (aux->prox != NULL)
    {
      aux = aux->prox;
    }
    aux->prox = novo_no;
  }
}

void inserirInicio(t_lista *lista, int info)
{
  if (lista == NULL)
  {
    fprintf(stderr, "Lista inválida.\n");
    return;
  }

  t_no *novo_no = criar_no(info);
  if (!novo_no)
  {
    fprintf(stderr, "Erro ao criar nó.\n");
    return;
  }
  novo_no->prox = lista->primeiro;
  lista->primeiro = novo_no;
}

void listar(t_lista *lista)
{
  t_no *aux = lista->primeiro;
  while (aux != NULL)
  {
    printf("(%d)->", aux->info);
    aux = aux->prox;
  }
}

void deletarInicio(t_lista *lista)
{
  if (lista == NULL)
  {
    fprintf(stderr, "Lista inválida.\n");
    return;
  }

  if (!lista->primeiro)
  {
    printf("Lista vazia.\n");
    return;
  }

  t_no *aux = lista->primeiro->prox;
  free(lista->primeiro);
  lista->primeiro = aux;
}

void deletarFim(t_lista *lista)
{
  if (lista == NULL)
  {
    fprintf(stderr, "Lista inválida.\n");
    return;
  }

  if (!lista->primeiro)
  {
    printf("Lista vazia.\n");
    return;
  }

  t_no *aux = lista->primeiro;
  while (aux->prox->prox != NULL)
  {
    aux = aux->prox;
  }
  free(aux->prox);
  aux->prox = NULL;
}

int main(void)
{
  t_lista lista = inicializarListaV2();
  inserirFim(&lista, 5);
  inserirFim(&lista, 4);
  inserirFim(&lista, 3);
  inserirFim(&lista, 2);
  inserirFim(&lista, 1);
  inserirInicio(&lista, 7);
  deletarFim(&lista);

  listar(&lista);
  printf("NULL\n");

  liberarMemoria(&lista);
  return 0;
}