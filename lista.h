#ifndef LISTA_H
#define LISTA_H

#endif

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct no{
  int valor;
  struct no *proximo;
}No;

typedef struct lista{
  No *inicio;
  int tam;
}Lista;

void criar_lista(Lista *lista);

void inserir_no_inicio(Lista *lista, int num);

void inserir_no_fim(Lista *lista, int num);

void inserir_no_meio(Lista *lista, int num, int ant);

void inserir_ordenado(Lista *lista, int num);

No* remover(Lista *lista, int num);
No *buscar(Lista *lista, int num);
void imprimir(Lista lista);

