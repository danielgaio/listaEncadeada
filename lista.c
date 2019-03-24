#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

struct elemento{
  struct aluno dados;
  struct elemento *prox;
};

Lista *criaLista(){
  Lista *li = (Lista*) malloc(sizeof(Lista));
  if(li != NULL) *li = NULL;
  return li;
}

void liberaLista(Lista *li){
  if(li != NULL){
    struct elemento *no;
    while((*li) != NULL){
      no = *li;
      *li = (*li)->prox;
      free(no);
    }
    free(li);
  }
}

int tamanhoLista(Lista *li){
  if(li == NULL) return 0;
  int count = 0;
  struct elemento *no = *li;
  while(no != NULL){
    count++;
    no = no->prox;
  }
  return count;
}

int listaVazia(Lista *li){
  if(li == NULL) return 1;
  if(*li == NULL) return 1;
  return 0;
}

int insereListaInicio(Lista *li, struct aluno al){
    if(li == NULL) return 0;
    struct elemento *no = (struct elemento*) malloc(sizeof(struct elemento));
    if(no == NULL) return 0;
    no->dados = al;
    no->prox = (*li);
    *li = no;
    return 1;
}

int insereListaFinal(Lista *li, struct aluno al){
    if(li == NULL) return 0;
    struct elemento *no = (struct elemento*) malloc(sizeof(struct elemento));
    if(no == NULL) return 0;
    no->dados = al;
    no->prox = NULL;
    if((*li) == NULL){
        *li = no;
    }else{
        struct elemento *aux = *li;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
    }
    return 1;
}

int insereListaOrdenada(Lista *li, struct aluno al){
  if(li == NULL) return 0;
  struct elemento *no = (struct elemento*) malloc(sizeof(struct elemento));
  if(no == NULL) return 0;
  no->dados = al;
  if(listaVazia(li)){
    no->prox = (*li);
    *li = no;
    return 1;
  }else{
    struct elemento *ant, *atual = *li;
    while(atual != NULL && atual->dados.matricula < al.matricula){
      ant = atual;
      atual = atual->prox;
    }
    if(atual == *li){
      no->prox = (*li);
      *li = no;
    }else{
      no->prox = ant->prox;
      ant->prox = no;
    }
    return 1;
  }
}

int removeListaInicio(Lista *li){
  if (li == NULL) return 0;
  if((*li) == NULL) return 0;
  struct elemento *no = *li;
  *li = no->prox;
  free(no);
  return 1;
}

int removeListaFinal(Lista *li){
  if(li == NULL) return 0;
  if((*li) == NULL) return 0;
  struct elemento *ant, *no = *li;
  while(no->prox != NULL){
    ant = no;
    no = no->prox;
  }
  if(no == (*li)) *li = no->prox;
  else ant->prox = no->prox;
  free(no);
  return 1;
}

int removeListaMeio(Lista *li, int mat){
  if(li == NULL) return 0;
  struct elemento *ant, *no = *li;
  while(no != NULL && (no->dados.matricula) != mat){
    ant = no;
    no = no->prox;
  }
  if(no == NULL) return 0; // não foi encontrado
  if(no == *li) *li = no->prox;
  else ant->prox = no->prox;
  free(no);
  return 1;
}

int consultaListaPos(Lista *li, int pos, struct aluno *al){
  if(li == NULL || pos <= 0) return 0;
  struct elemento *no = *li;
  int i = 1;
  while(no != NULL && i < pos){
    no = no->prox;
    i++;
  }
  if(no == NULL) return 0;
  else{
    *al = no->dados;
    return 1;
  }
}

int consultaListaMat(Lista *li, int mat, struct aluno *al){
  if(li == NULL) return 0;
  struct elemento *no = *li;
  while(no != NULL && no->dados.matricula != mat) no = no->prox;
  if(no == NULL) return 0;
  else{
    *al = no->dados;
    return 1;
  }
}