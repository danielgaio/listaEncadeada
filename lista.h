struct aluno{
  int matricula;
  char nome[30];
  float n1, n2, n3;
};
typedef struct elemento *Lista;

Lista *criaLista();
void liberaLista(Lista *li);

int tamanhoLista(Lista *li);

int listaVazia(Lista *li);

int insereListaInicio(Lista *li, struct aluno al);

int insereListaFinal(Lista *li, struct aluno al);

int insereListaOrdenada(Lista *li, struct aluno al);

int removeListaInicio(Lista *li);

int removeListaFinal(Lista *li);

int removeListaMeio(Lista *li, int mat);

int consultaListaPos(Lista *li, int pos, struct aluno *al);

int consultaListaMat(Lista *li, int mat, struct aluno *al);