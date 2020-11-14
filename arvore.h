#ifndef ARVORE_H
#define ARVORE_H


typedef struct _arvore {
    struct _arvore *pai;
    struct _arvore *esq;
    struct _arvore *dir;
    int dado;
} Arvore;

void iniciarArvore(Arvore **);
void inserirNo(Arvore **, int);
void lerArquivo(Arvore **);
void printarNosFolha(Arvore *);
void printarNosRamo(Arvore *);
int alturaDaArvore(Arvore *);
int profundidadeDaArvore(Arvore *);
int grauDoNo(Arvore *);
int alturaDoNo(Arvore *);
int profundidoDoNo(Arvore *);
void printarDescendentes(Arvore *);
void printarAncestrais(Arvore *);
void preOrdem(Arvore *);
void posOrdem(Arvore *);
void emOrdem(Arvore *);
Arvore* buscar(Arvore *, int);

#endif