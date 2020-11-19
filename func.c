#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

// Gera as constantes true e false
#define true 1
#define false 0

void mensagensAviso(int cod, int valor) {
    printf("\nAVISO #%d: ", cod);
    switch (cod) {
    case 1:
        printf("O valor %d ja foi adicionado!", valor);
        break;
     case 2:
        printf("O No %d nao foi localizado!", valor);
        break;
    default:
        printf("Mensagem nao encontrada!");
        break;
    }

    printf("\n");
}
void mensagensErro(int cod, char *nome) {
    printf("\nERRO #%d: ", cod);
    switch (cod) {
    case 1:
        printf("O arquivo \"%s\" nao foi aberto corretamente", nome);
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
        if(aux->dado == valor) {
            mensagensAviso(1, valor);
            return;
        } else if(aux->dado > valor)
            inserirNo(&aux->esq, valor);
        else
            inserirNo(&aux->dir,valor);
        
        if (aux->esq != NULL)
            if(aux->esq->pai == NULL)
                aux->esq->pai = aux;
        if (aux->dir != NULL)
            if(aux->dir->pai == NULL)
                aux->dir->pai = aux;
    }
      
}

void lerArquivo(Arvore **tree) {
    int valor, ctd;
    char *nome = "dados.txt";
    FILE *arq;

    arq = fopen(nome, "r");

    if(arq == NULL) {
        mensagensErro(1, nome);
        exit(1);
    }

    for(ctd = 0; !feof(arq); ctd++) {
        fscanf(arq, "%d", &valor);
        inserirNo(tree, valor);
    }

    fclose(arq);
}

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
Arvore* buscar(Arvore *tree,int valor) {
    while(tree != NULL) {
        if (tree->dado == valor)
            return tree; // Retorna o No caso ele seja encontrado
        else if (tree->dado > valor)
            tree = tree->esq;
        else
            tree = tree->dir;
    }
    return tree; // Retorna NULL caso o No nao exista
}

// Printa somente os nos folha
void printarNosFolha(Arvore *tree) {
    if (!estaVazia(tree)) {
        // Printa so o que for folha
        if (ehNoFolha(tree))
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

int alturaDaArvore(Arvore *tree) {
    int esq, dir;
    if (estaVazia(tree))
        return -1;

    esq = alturaDaArvore(tree->esq);
    dir = alturaDaArvore(tree->dir);

    if (esq > dir)
        return esq+1;
    else
        return dir+1;
}

int profundidadeDaArvore(Arvore *tree) {
    int esq, dir;
    if (estaVazia(tree))
        return -1;

    esq = profundidadeDaArvore(tree->esq);
    dir = profundidadeDaArvore(tree->dir);

    if (esq > dir)
        return esq+1;
    else
        return dir+1;

}

int grauDoNo(Arvore *tree) {
    int filhos = 0;
    if (tree->dir != NULL)
        filhos++;
    if(tree->esq != NULL)
        filhos++;
    
    return filhos;
}

int alturaDoNo(Arvore *tree) {
    int esq, dir;
    if (estaVazia(tree))
        return -1;

    esq = alturaDoNo(tree->esq);
    dir = alturaDoNo(tree->dir);

    if (esq > dir)
        return esq+1;
    else
        return dir+1;
}

int profundidadeDoNo(Arvore *tree) {
    int profundidade = 0;
    while(!ehNoRaiz(tree)) {
        tree = tree->pai;
        profundidade++;
    }
    return profundidade;
}

void printarDescendentes(Arvore *tree, int valor) {
    emOrdem(tree->esq);
    emOrdem(tree->dir);
}

void printarAncestrais(Arvore *tree, int valor) {
    while(!ehNoRaiz(tree)) {
        tree = tree->pai;
        printf("%d ", tree->dado);
    }
}

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