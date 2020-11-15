#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

// Gera as constantes true e false
#define true 1
#define false 0

void mensagens(int cod, int valor) {
    printf("\nAVISO #%d: ", cod);
    switch (cod) {
    case 1:
        printf("O valor %d ja foi adicionado!", valor);
        break;
    default:
        printf("Mensagem nao encontrada!");
        break;
    }

    printf("\n");
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
            inserirNo(&aux->dir,valor);
    }

     if(aux != NULL) {
        if (aux->esq != NULL)
            if(aux->esq->pai == NULL)
                aux->esq->pai = aux;
        if (aux->dir != NULL)
            if(aux->dir->pai == NULL)
                aux->dir->pai = aux;
    }
      
}

void lerArquivo(Arvore **tree) {}

//verifica se o no esta vazio
int estaVazia(Arvore *tree) {
    if(tree == NULL)
        return true;
    else
        return false;
}

// Verifica se o no tem filhos
int ehNoFolha(Arvore *tree) {
    if(tree->dir == NULL && tree->esq == NULL)
        return true;
    else
        return false;
}

// Verifica se o no é raiz
int ehNoRaiz(Arvore *tree) {
    if(tree->pai == NULL)
        return true;
    else
        return false;
}

// Busca um no na arvore e o retorna
Arvore* buscar(Arvore *tree,int valor, int *ctd) {
    *ctd = 0;
    while(tree != NULL) {
        if (tree->dado == valor)
            return tree;
        else if (tree->dado > valor)
            tree = tree->esq;
        else
            tree = tree->dir;
        (*ctd)++;
    }
    return tree;
}

// Printa somente os nos folha
void printarNosFolha(Arvore *tree) {
    if (!estaVazia(tree)) {
        if (ehNoFolha(tree)) // Printa so o que for folha
            printf("%d ", tree->dado);
        printarNosFolha(tree->esq);
        printarNosFolha(tree->dir);
    } 
}

void printarNosRamo(Arvore *tree) {
    if (!estaVazia(tree)) {
        // Printa tudo que nao for no folha ou raiz
        if (!ehNoFolha(tree) && !ehNoRaiz(tree))
            printf("%d ", tree->dado);
        printarNosRamo(tree->esq);
        printarNosRamo(tree->dir);
    } 
}

int alturaDaArvore(Arvore *tree) {}

int profundidadeDaArvore(Arvore *tree) {}

int grauDoNo(Arvore *tree) {}

int alturaDoNo(Arvore *tree) {}

int profundidoDoNo(Arvore *tree) {}

void printarDescendentes(Arvore *tree) {}

void printarAncestrais(Arvore *tree) {}

void preOrdem(Arvore *tree) { //Gui
    if(tree != NULL){
        printf("%d ", tree->dado);
        preOrdem(tree->esq);
        preOrdem(tree->dir);
    }
} 

void posOrdem(Arvore *tree) { //Gui
	if(tree != NULL){
        posOrdem(tree->esq);
        posOrdem(tree->dir);
        printf("%d ", tree->dado);
    }
} 

void emOrdem(Arvore *tree) {
    if (!estaVazia(tree)) {
        emOrdem(tree->esq);
        printf("%d ", tree->dado);
        emOrdem(tree->dir);
    }
} 