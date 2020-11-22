#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

// Gera as constantes true e false
#define true 1
#define false 0

void mensagensAviso(int cod, int valor) {
    printf("\nAVISO #%d: ", cod); // Exibe aviso, cod e depois a mensagem
    switch (cod) {
    case 1:
        printf("O valor %d ja foi adicionado!", valor);
        break;
    case 2:
        printf("O No %d nao foi localizado!", valor);
        break;
    case 3:
        printf("O No %d nao possui descendentes! (folha)", valor);
        break;
    case 4:
        printf("O No %d nao possui ancestrais! (raiz)", valor);
        break;
    default:
        printf("Mensagem nao encontrada!");
        break;
    }

    printf("\n");
}
void mensagensErro(int cod, char *nome) {
    printf("\nERRO #%d: ", cod); // Exibe o erro e o cod e depois a mensagem 
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

        novo = (Arvore*) malloc(sizeof(Arvore)); // Aloca um espaco na memoria para o novo No
        
        novo->pai = NULL;
        novo->dir = NULL;
        novo->esq = NULL;
        novo->dado = valor;

        *tree = novo;
    } else { 
        // Garante que nao haveram valores repetidos
        // E que uma ordenacao de menor pra o  maior
        if(aux->dado == valor) {
            mensagensAviso(1, valor);
            return;
        } else if(aux->dado > valor)
            inserirNo(&aux->esq, valor);
        else
            inserirNo(&aux->dir,valor);
        
        // Adiciona um pai aos Nos
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
    char *nome = "dados.txt"; // Salva o nome do arquivo
    FILE *arq;

    arq = fopen(nome, "r"); // Abre o arquivo para leitura

    if(arq == NULL) {
        mensagensErro(1, nome); // Printa mensagem de erro 
        exit(1);
    }

    for(ctd = 0; !feof(arq); ctd++) { // Le todo o arquivo
        fscanf(arq, "%d", &valor); // Le valor por valor
        inserirNo(tree, valor); // Insere no No
    }

    fclose(arq); // Encerra a leitura e fecha o arquivo
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

int alturaEProfundidade(Arvore *tree) {
    int esq, dir;
    if (estaVazia(tree))
        return -1; // Garante que o primeiro No valido será zero

    esq = alturaEProfundidade(tree->esq); // Conta a profundidade a esquerda
    dir = alturaEProfundidade(tree->dir); // Conta a profundidade a direita

    if (esq > dir) // Retorna so a maior profundidade encontrada
        return esq+1;
    else
        return dir+1;
}

int grauDoNo(Arvore *tree) {
    int filhos = 0;
    if (tree->dir != NULL) // Se houver filho a direita soma +1
        filhos++;
    if(tree->esq != NULL) // Se houver filho a esquerda soma +1
        filhos++;
    
    return filhos; // Retorna o grau do No
}

int profundidadeDoNo(Arvore *tree) {
    int profundidade = 0;
    while(!ehNoRaiz(tree)) { // Para ao encontrar a raiz
        tree = tree->pai; // Sobe ate o no raiz
        profundidade++; // Conta os pulos
    }
    return profundidade;
}

void printarDescendentes(Arvore *tree, int valor) {
    emOrdem(tree->esq); // Exibe primeiro os Nos de menor valor
    emOrdem(tree->dir); // Depois os de maior
}

void printarAncestrais(Arvore *tree, int valor) {
    while(!ehNoRaiz(tree)) { // Para ao encontrar a raiz
        tree = tree->pai; // Sobe ate o no raiz
        printf("%d ", tree->dado); // Exibe todos os nos encontrados
    }
}

void preOrdem(Arvore *tree) { //Gui
    if(tree != NULL){
        printf("%d ", tree->dado); // Processa e pula
        preOrdem(tree->esq);
        preOrdem(tree->dir);
    }
} 

void posOrdem(Arvore *tree) { //Gui
	if(tree != NULL){
        posOrdem(tree->esq);
        posOrdem(tree->dir);
        printf("%d ", tree->dado); // Pula e processa
    }
} 

void emOrdem(Arvore *tree) {
    if (!estaVazia(tree)) {
        emOrdem(tree->esq);
        printf("%d ", tree->dado); // Pula, processa e continua
        emOrdem(tree->dir);
    }
} 