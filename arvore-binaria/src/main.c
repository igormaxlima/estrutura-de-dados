#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
  struct No *esq;
  struct No *dir;
  char valor;
} t_no;

t_no *criarNo(char valor)
{
  t_no *no = malloc(sizeof(t_no));
  if (no)
  {
    no->esq = NULL;
    no->dir = NULL;
    no->valor = valor;
  }
  return no;
}

void exibir_pre_ordem(t_no *raiz)
{
  if (raiz)
  {
    printf("%c ", raiz->valor);
    exibir_pre_ordem(raiz->esq);
    exibir_pre_ordem(raiz->dir);
  }
}

void exibir_in_ordem(t_no *raiz)
{
  if (raiz)
  {
    exibir_in_ordem(raiz->esq);
    printf("%c ", raiz->valor);
    exibir_in_ordem(raiz->dir);
  }
}

void exibir_pos_ordem(t_no *raiz)
{
  if (raiz)
  {
    exibir_pos_ordem(raiz->esq);
    exibir_pos_ordem(raiz->dir);
    printf("%c ", raiz->valor);
  }
}

void eliminar_arvore(t_no *raiz)
{
  if (raiz)
  {
    eliminar_arvore(raiz->esq);
    eliminar_arvore(raiz->dir);
    free(raiz);
  }
}

int main(void)
{
  t_no *raiz = criarNo('A');
  if (!raiz)
    return -1;
  raiz->esq = criarNo('B');
  raiz->dir = criarNo('C');
  if (raiz->esq)
  {
    raiz->esq->esq = criarNo('D');
    raiz->esq->dir = criarNo('E');
  }
  if (raiz->dir)
  {
    raiz->dir->esq = criarNo('F');
    raiz->dir->dir = criarNo('G');
  }
  exibir_in_ordem(raiz);
  eliminar_arvore(raiz);
  return 0;
}
