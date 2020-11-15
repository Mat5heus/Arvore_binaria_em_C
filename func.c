#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

// Gera as constantes true e false
#define true 1
#define false 0

void mensagens(int cod, int valor) {
    printf("\nERRO %d: ", cod);
    switch (cod) {
    case 1:
        printf("O valor %d ja foi adicionado\n", valor);
        break;
    default:
        printf("Mensagem nao encontrada!");
        break;
    }
}

void iniciarArvore(Arvore **tree) { // Inicializa a arvore com valor "vazio"
    *tree = NULL;
}

//Não esta preenchendo a arvore corretamente
void inserirNo(Arvore **tree, int valor) {
    Arvore *aux = *tree;

    if(valor == NULL) return;

    if(estaVazia(*tree)) {
        Arvore *novo;

        novo = (Arvore*) malloc(sizeof(Arvore));
        
        novo->pai = NULL;
        novo->dir = NULL;
        novo->esq = NULL;
        novo->dado = valor;

        *tree = novo;
    } else {
        if(aux->dado == valor)
            mensagens(1, valor);
        else if(aux->dado > valor)
            inserirNo(&aux->esq, valor);
        else
            inserirNo(&aux->dir, valor);
    }
}

void lerArquivo(Arvore **tree) {}

int estaVazia(Arvore *tree) {
    if(tree == NULL)
        return true;
    else
        return false;
}

Arvore* buscar(Arvore *tree,int valor) {}

int printarNoRaiz(Arvore *tree) {
    Arvore *aux = tree;
    return aux->dado;
}

void printarNosFolha(Arvore *tree) {}

void printarNosRamo(Arvore *tree) {}

int alturaDaArvore(Arvore *tree) {} // Leo
    if (r == NULL) 
      return -1; // altura da árvore vazia
   else {
      int ae = altura (r->esq);
      int ad = altura (r->dir);
      if (ae < ad) return ad + 1;
      else return ae + 1;
   }

int profundidadeDaArvore(Arvore *tree) {}

int grauDoNo(Arvore *tree) {}

int alturaDoNo(Arvore *tree) {}

int profundidoDoNo(Arvore *tree) {}

void printarDescendentes(Arvore *tree) {}

void printarAncestrais(Arvore *tree) {}

void preOrdem(Arvore *tree) {} //Gui

void posOrdem(Arvore *tree) {} //Gui

void emOrdem(Arvore *tree) {
    if (!estaVazia(tree)) {
        emOrdem(tree->esq);
        printf("%d ", tree->dado);
        emOrdem(tree->dir);
    }
} 
