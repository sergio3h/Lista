#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

typedef struct {
  int valor;
  struct no *proximo;
};

typedef struct {
  No *inicio;
  int tam;
};

void criar_lista(Lista *lista){
  lista->inicio = NULL;
  lista->tam = 0;
}

void inserir_no_inicio(Lista *lista, int num){
  No *novo = malloc(sizeof(No));
  if(novo){
    novo->valor = num;
    novo->proximo = lista->inicio;
    lista->inicio = novo;
    lista->tam++;
  }
  else{
    printf("Erro ao alocar memoria");
  }
}

void inserir_no_fim(Lista *lista, int num){
  No *aux, *novo = malloc(sizeof(No));

  if(novo){
    novo->valor = num;
    novo->proximo = NULL;

    //Sera o primeiro?
    if(lista->inicio == NULL){
      lista->inicio = novo;
    }
    else{
      aux = lista->inicio;
      while(aux->proximo){
        aux = aux->proximo;
      }
      aux->proximo = novo;
    }
    lista->tam++;
  }
  else{
    printf("Erro ao alocar memoria");  
  }
}

void inserir_no_meio(Lista *lista, int num, int ant){
  No *aux, *novo = malloc(sizeof(No));

  if(novo){
    novo->valor = num;
    //Sera o primeiro?
    if(lista->inicio == NULL){
      novo->proximo = NULL;
      lista->inicio = novo;
    }
    else{
      aux = lista->inicio;
      while(aux->valor !=ant && aux -> proximo){
        aux = aux -> proximo;
      }
      novo -> proximo = aux -> proximo;
      aux -> proximo = novo;
    }
    lista ->tam++;
  }
  else{
    printf("Erro ao alocar memoria");
  }
}

void inserir_ordenado(Lista *lista, int num){
  No *aux,*novo = malloc(sizeof(No));

  if(novo){
    novo->valor = num;
    //A lista esta vazia?
    if(lista->inicio == NULL){
      novo -> proximo = NULL;
      lista->inicio = novo;
    }//E o menor?
    else if(novo -> valor < lista->inicio -> valor){
      novo -> proximo = lista->inicio;
      lista->inicio = novo;
    }
    else{
      aux = lista->inicio;
      while(aux -> proximo && novo -> valor > aux -> proximo -> valor){
        aux = aux ->proximo;
      }
      novo ->proximo = aux->proximo;
      aux ->proximo =novo;
    }
    lista ->tam++;
  }
  else{
    printf("Erro ao alocar memoria\n");
  }
}

No* remover(Lista *lista, int num){
  No *aux,*remover = NULL;
  
  if(lista ->inicio){
    if(lista ->inicio ->valor == num){
      remover = lista ->inicio;
      lista->inicio = remover ->proximo;
      lista -> tam--;
    }
    else{
      aux = lista ->inicio;
      while(aux ->proximo && aux ->proximo->valor != num){
        aux = aux ->proximo;
      }
      if(aux->proximo){
        remover = aux -> proximo;
        aux -> proximo = remover -> proximo;
        lista -> tam--;
      }
    }
  }
  return remover;
}

No *buscar(Lista *lista, int num){
  No *aux, *no = NULL;
  aux = lista -> inicio;

  while(aux && aux -> valor != num){
    aux = aux -> proximo;
  if(aux){
    no = aux;
  }
  }
  return no;
}

void imprimir(Lista lista){
  No *no = lista.inicio;
  printf("\n\tLista: ");
  while(no){
    printf("%d ", no ->valor);
    no = no -> proximo;
  }
  printf("\n\n");
}

int main(void) {
  int opcao,valor,anterior;
  Lista lista;
  criar_lista(&lista);
  No *removido = NULL;
  do{
    printf("\n \t0-Sair\n\t1-Inserir no inicio\n\t2-Inserir no fim\n\t3-Inserir no meio\n\t4-Inserir Ordenado\n\t5-Remover\n\t6-Imprimir\n\t7-Buscar\n");
    scanf("%d", &opcao);

    switch(opcao){
      case 1:
        printf("Digite um valor: ");
        scanf("%d", &valor);
        inserir_no_inicio(&lista, valor);
        break;
      case 2:
        printf("Digite um valor: ");
        scanf("%d", &valor);
        inserir_no_fim(&lista, valor);
        break;
      case 3:
        printf("Digite um valor e o valor de referencia: ");
        scanf("%d%d", &valor, &anterior);
        inserir_no_meio(&lista, valor, anterior);
        break;
      case 4:
        printf("Digite um valor: ");
        scanf("%d", &valor);
        inserir_ordenado(&lista, valor);
        break;
      case 5:
        printf("Digite um valor a ser removido: ");
        scanf("%d", &valor);
        removido = remover(&lista, valor);
          if(removido){
            printf("Elemtento removido: %d\n", removido->valor);
            free(removido);
          }
          else{
            printf("Elemento inexistente\n");
          }
        break;
      case 6:
        imprimir(lista);
        break;
      case 7:
        printf("Digite um valor a ser buscado: ");
        scanf("%d", &valor);
        removido = buscar(&lista, valor);
        if(removido){
          printf("Elemento encontrado: %d\n", removido->valor);
        }
        else{
          
        }
        break;
      default:
        if(opcao != 0){
          printf("Opcao invalida");
        }
    }
  }while(opcao);
  return 0;
}