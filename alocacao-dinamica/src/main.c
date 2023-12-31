// Igor Max de Lima Nunes - 2311249 - Eng. Software
// Brenno de Aguiar Pinheiro Lopes - 2311260 - Eng. Software
// Pedro Henrique Cabral Jersey - 2311220 - Eng. Software

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OFFSET 10

typedef unsigned int uint;

typedef struct
{
  int id;
  char nome[100];
  int idade;
  char genero;
} Pessoa;

typedef struct
{
  uint size;
  uint limite;
  Pessoa *pessoas;
} Vetor;

void zerar(Vetor *vetor);
void inicializar(Vetor *vetor, int limite);
void inserirFim(Vetor *vetor, Pessoa p);
void listar(Vetor *vetor);
void liberarMemoria(Vetor *vetor);

// Implemente as seguintes funções
void inserirInicio(Vetor *vetor, Pessoa p);
void inserirIndice(Vetor *vetor, int indice, Pessoa p);
void inserirOrdenadoPorIdade(Vetor *vetor, Pessoa p, int idade);
void inserirOrdenadoPorNome(Vetor *vetor, Pessoa p, char *nome);
void deletarInicio(Vetor *vetor);
void deletarFim(Vetor *vetor);
void deletarIndice(Vetor *vetor, int indice);
void deletarPorNome(Vetor *vetor, char *nome);
void atualizarIndice(Vetor *vetor, int indice, Pessoa p);
void atualizarPorNome(Vetor *vetor, Pessoa p, char *nome);

int main(void)
{
  Vetor vetor;
  inicializar(&vetor, 11);
  inserirFim(&vetor, (Pessoa){.id = 1, .nome = "Ana", .idade = 17, .genero = 'F'});
  inserirFim(&vetor, (Pessoa){2, "Beto", 19, 'M'});
  inserirFim(&vetor, (Pessoa){3, "Caio", 21, 'M'});
  inserirFim(&vetor, (Pessoa){4, "Dani", 21, 'F'});
  // inserirInicio(&vetor, (Pessoa){5, "Joao", 19, 'M'});
  // inserirIndice(&vetor, 4, (Pessoa){6, "Messi", 36, 'M'});
  // inserirOrdenadoPorIdade(&vetor, (Pessoa){7, "Cr7", 38, 'M'}, 38);
  // inserirOrdenadoPorNome(&vetor, (Pessoa){8, "Neymar", 32, 'M'}, "Neymar");
  // deletarInicio(&vetor);
  // deletarFim(&vetor);
  // deletarIndice(&vetor, 5);
  // deletarPorNome(&vetor, "Beto");
  // atualizarIndice(&vetor, 3, (Pessoa){4, "Dani", 25, 'F'});
  // atualizarPorNome(&vetor, (Pessoa){3, "Caio", 25, 'M'}, "Caio");

  listar(&vetor);
  liberarMemoria(&vetor);
  return 0;
}

void inicializar(Vetor *vetor, int limite)
{
  vetor->size = 0; // (*vetor).size = 0;
  vetor->limite = limite;
  vetor->pessoas = malloc(sizeof(Pessoa) * limite);
}

void inserirFim(Vetor *vetor, Pessoa p)
{
  // restrição da função
  if (vetor->size >= vetor->limite)
  {
    vetor->pessoas = realloc(vetor->pessoas, OFFSET);
  }
  vetor->pessoas[vetor->size] = p;
  vetor->size++;
}

void listar(Vetor *vetor)
{
  for (int i = 0; i < vetor->size; i++)
  {
    printf("Pessoa %d: (id: %d, nome: %s, idade: %d, genero: %c)\n", i, vetor->pessoas[i].id, vetor->pessoas[i].nome, vetor->pessoas[i].idade, vetor->pessoas[i].genero);
  }
}

void zerar(Vetor *vetor)
{
  vetor->size = 0;
}

void inserirInicio(Vetor *vetor, Pessoa p)
{
  // restricao da funcao
  if (vetor->size >= vetor->limite)
  {
    printf("Lista cheia!\n");
    return;
  }
  int i;
  for (i = vetor->size; i > 0; i--)
  {
    vetor->pessoas[i] = vetor->pessoas[i - 1];
  }
  vetor->pessoas[0] = p;
  vetor->size++;
}

void inserirIndice(Vetor *vetor, int indice, Pessoa p)
{
  // restricao da funcao
  if (indice < 0 || indice > vetor->limite)
  {
    printf("Índice Inválido!\n");
    return;
  }

  int i;
  for (i = vetor->size; i > indice; i--)
  {
    vetor->pessoas[i] = vetor->pessoas[i - 1];
  }
  vetor->pessoas[indice] = p;
  vetor->size++;
}

void inserirOrdenadoPorIdade(Vetor *vetor, Pessoa p, int idade)
{
  int indiceAoSerInserido = vetor->size;
  int i;
  for (i = 0; i < vetor->size; i++)
  {
    if (idade < vetor->pessoas[i].idade)
    {
      indiceAoSerInserido = i;
      break;
    }
  }
  inserirIndice(vetor, indiceAoSerInserido, p);
}

void inserirOrdenadoPorNome(Vetor *vetor, Pessoa p, char *nome)
{
  int indiceAoSerInserido = vetor->size;
  int i;
  for (i = 0; i < vetor->size; i++)
  {
    if (strncmp(nome, vetor->pessoas[i].nome, 1) < 0)
    {
      indiceAoSerInserido = i;
      break;
    }
  }
  inserirIndice(vetor, indiceAoSerInserido, p);
}

void deletarInicio(Vetor *vetor)
{
  int i;
  for (i = 0; i < vetor->size; i++)
  {
    vetor->pessoas[i] = vetor->pessoas[i + 1];
  }
  vetor->size--;
}

void deletarFim(Vetor *vetor)
{
  vetor->size--;
}

void deletarIndice(Vetor *vetor, int indice)
{
  // restricao da funcao
  if (indice < 0 || indice >= vetor->limite || indice >= vetor->size)
  {
    printf("Índice Inválido!\n");
    return;
  }

  int i;
  for (i = indice; i < vetor->size; i++)
  {
    vetor->pessoas[i] = vetor->pessoas[i + 1];
  }
  vetor->size--;
}

void deletarPorNome(Vetor *vetor, char *nome)
{
  int indiceAoSerDeletado = -1;
  int i;
  for (i = 0; i < vetor->size; i++)
  {
    if (strcmp(nome, vetor->pessoas[i].nome) == 0)
    {
      indiceAoSerDeletado = i;
      deletarIndice(vetor, indiceAoSerDeletado);
      break;
    }
  }

  if (indiceAoSerDeletado == -1)
  {
    printf("Nome não Encontrado!\n");
  }
}

void atualizarIndice(Vetor *vetor, int indice, Pessoa p)
{
  // restricao da funcao
  if (indice < 0 || indice >= vetor->limite)
  {
    printf("Índice Inválido!\n");
    return;
  }

  vetor->pessoas[indice] = p;
}

void atualizarPorNome(Vetor *vetor, Pessoa p, char *nome)
{
  int indiceAoSerAlterado = -1;
  int i;
  for (i = 0; i < vetor->size; i++)
  {
    if (strcmp(nome, vetor->pessoas[i].nome) == 0)
    {
      indiceAoSerAlterado = i;
      vetor->pessoas[indiceAoSerAlterado] = p;
      break;
    }
  }

  if (indiceAoSerAlterado == -1)
  {
    printf("Nome não Encontrado!\n");
  }
}

void liberarMemoria(Vetor *vetor)
{
  free(vetor->pessoas);
}