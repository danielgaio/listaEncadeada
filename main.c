#include <stdio.h>
#include "lista.h"
#include <stdlib.h>
#include <string.h>

int main(void) {
  Lista *li; // ponteiro para ponteiro
  li = criaLista(); // recebe ponteiro para o primeiro elemento
  printf("Lista criada!\n");
  //liberaLista(li);
  //printf("Lista liberada!\n");
  printf("Tamanho da lista %i\n", tamanhoLista(li));
  printf("Lista eh vazia: %i\n", listaVazia(li));
  //------
  struct aluno dadosAluno1;
  dadosAluno1.matricula = 1;
  dadosAluno1.n1 = 7;
  dadosAluno1.n2 = 8;
  dadosAluno1.n3 = 10;
  strcpy(dadosAluno1.nome, "Daniel Gaio");
  //------
  struct aluno dadosAluno2;
  dadosAluno2.matricula = 3;
  dadosAluno2.n1 = 3;
  dadosAluno2.n2 = 2;
  dadosAluno2.n3 = 7;
  strcpy(dadosAluno2.nome, "Joaozinho");
  //-----
  struct aluno dadosAluno3;
  dadosAluno3.matricula = 2;
  dadosAluno3.n1 = 7;
  dadosAluno3.n2 = 7;
  dadosAluno3.n3 = 7;
  strcpy(dadosAluno3.nome, "Joaninha");
  //-----
  struct aluno dadosAluno4;
  dadosAluno4.matricula = 4;
  dadosAluno4.n1 = 0;
  dadosAluno4.n2 = 0;
  dadosAluno4.n3 = 0;
  strcpy(dadosAluno4.nome, "Zero Esquerda");
  //------
  int x = insereListaInicio(li, dadosAluno1);
  printf("Inseriu 1? %i\n", x);
  int y = insereListaFinal(li, dadosAluno2);
  printf("Inseriu 2? %i\n", y);
  int z = insereListaOrdenada(li, dadosAluno3);
  printf("Inseriu 3? %i\n", z);
  int w = insereListaOrdenada(li, dadosAluno4);
  printf("Inseriu 4? %i\n", w);
  //-----
  int a = removeListaInicio(li);
  printf("Removeu inicio? %i\n", a);
  int b = removeListaFinal(li);
  printf("Removeu final? %i\n", b);
  int c = removeListaMeio(li, dadosAluno2.matricula);
  printf("Removeu meio? %i\n", c);
  //------ consulta por posição
  int posicao = 1;
  struct aluno dadosAluno;
  int d = consultaListaPos(li, posicao, &dadosAluno);
  printf("Consulta posicao 1: %i\n", d);
  printf("Matricula: %i\nNome: %s\n", dadosAluno.matricula, dadosAluno.nome);
  //----- consulta por matricula
  int matricula = 2;
  struct aluno dadosAlunoMat;
  int e = consultaListaMat(li, matricula, &dadosAlunoMat);
  printf("Consulta matricula 2: %i\n", e);
  printf("Matricula: %i\nNome: %s\n", dadosAlunoMat.matricula, dadosAlunoMat.nome);
  system("pause");
  return 0;
}