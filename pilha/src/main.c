#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
  int valor;
  struct No *prox;
} t_no;

typedef struct
{
  t_no *topo;
} t_pilha;

t_pilha inicializarPilha();
t_no *criarNo(int valor);
void listar(t_pilha *pilha);
int top(t_pilha *pilha);
void push(t_pilha *pilha, int valor);
int pop(t_pilha *pilha);
void liberarMemoria(t_pilha *pilha);

int main()
{
  t_pilha pilha = inicializarPilha();
  push(&pilha, 10);
  push(&pilha, 3);
  push(&pilha, 6);
  push(&pilha, 8);
  listar(&pilha);

  pop(&pilha);
  listar(&pilha);

  pop(&pilha);
  printf("%d", top(&pilha));

  listar(&pilha);

  liberarMemoria(&pilha);
  return 0;
}

t_pilha inicializarPilha()
{
  t_pilha pilha = {.topo = NULL};
  return pilha;
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

void listar(t_pilha *pilha)
{
  if (!pilha)
  {
    fprintf(stderr, "Pilha Inválida!\n");
    return;
  }

  t_no *aux = pilha->topo;
  while (aux)
  {
    printf("(%d)\n", aux->valor);
    aux = aux->prox;
  }
  printf("NULL\n");
  printf("\n");
}

int top(t_pilha *pilha)
{
  if (!pilha)
  {
    fprintf(stderr, "Pilha Inválida!\n");
    return NULL;
  }

  if (!pilha->topo)
  {
    printf("Pilha Vazia!\n");
    return NULL;
  }
  return pilha->topo->valor;
}

void push(t_pilha *pilha, int valor)
{
  if (!pilha)
  {
    fprintf(stderr, "Pilha Inválida!\n");
    return;
  }

  t_no *novo_no = criarNo(valor);
  if (!novo_no)
  {
    fprintf(stderr, "Erro ao criar nó.\n");
    return;
  }

  if (!pilha->topo)
  {
    pilha->topo = novo_no;
  }
  else
  {
    novo_no->prox = pilha->topo;
    pilha->topo = novo_no;
  }
}

int pop(t_pilha *pilha)
{
  if (!pilha)
  {
    fprintf(stderr, "Pilha Inválida!\n");
    return NULL;
  }

  if (!pilha->topo)
  {
    printf("Pilha Vazia!\n");
    return NULL;
  }
  int topo = pilha->topo->valor;
  t_no *aux = pilha->topo->prox;
  free(pilha->topo);
  pilha->topo = aux;

  return topo;
}

void liberarMemoria(t_pilha *pilha)
{
  if (!pilha)
  {
    fprintf(stderr, "Pilha Inválida!\n");
    return;
  }

  if (!pilha->topo)
  {
    printf("Pilha Vazia!\n");
    return;
  }

  t_no *aux = pilha->topo;
  while (aux)
  {
    t_no *prox = aux->prox;
    free(aux);
    aux = prox;
  }
  pilha->topo = NULL;
}