/*
 * Nome do programa : Arvore
 * 
 * Desenvolvedores
 * Nome: Matheus do carmo Santos RA: 106020 
 * Nome: Matheus Galvani de Camargo RA: 107285
 * Nome: Guilherme dos Santos Bueno Meyer RA: 107129
 * Nome: Tiago Moises Antonio RA: 89541
 * Nome: Leonardo Garcia RA: 106939
 * Nome: Marcelo Costa Correa RA: 104442
 * 
 */

#include <time.h>
#include "func.c"

int main() {

    Arvore *tree, *aux;
    int resp, valor, ctd;

    iniciarArvore(&tree); // Gera um nó vazio

    do { // Exibe o menu até que o usuario o encerre

        printf( // Printa o menu
        "\n============== Menu =================\n"
        "1) Digitar os dados\n"
        "2) Ler dados do arquivo\n"
        "3) Preencher automaticamente\n"
        "4) Encerrar\n"
        "\n"
        "Digite a opcao desejada: "
        );

        // Pega a resposta do usuario
        scanf("%d", &resp); 

        // Usa a resposta do usuario para iniciar uma acao
        switch (resp) { 
        case 1:
            valor = NULL;
            printf("\nLiberando entrada de dados...\n"); // Se usuario escolheu digitar os dados
            printf(
                "\nDigite -1 para finalizar a leitura...\n"
                "Digite o(s) valor(es) que deseja adicionar: "
            );
            do {
                inserirNo(&tree, valor);
                scanf("%d", &valor);
            } while(valor != -1);
            break;
        case 2:
            printf("\nAbrindo arquivo para leitura...\n"); // Se usuario escolheu ler do arquivo
            lerArquivo(&tree);
            break;
        case 3:
            printf("\nPreencher arvore com quantos valores aleatorios: ");
            scanf("%d", &valor);
            printf("\nPreenchendo com valores aleatorios de 0 a 100...\n"); // Se usuario escolheu ler do arquivo
            srand(time(NULL)); // Passa valores diferentes para evitar repeticoes no rand
            for(ctd = 0; ctd < valor; ctd++) // Insere a quantidade desejado pelo usuario
                inserirNo(&tree, rand() % 100); // (% 100) limita a faixa de de numeros entre 0 - 100
            break;
        case 4:
            printf("\nEncerrando...\n"); // Se usuario escolheu encerrar
            exit(0); // Finaliza a execucao do programa e retorna 0
            break;
        default:
            printf("\nOpcao nao identificada!\n"); // Se usuario digitou uma opcao invalida
            break;
        }

    } while(resp < 1 || resp > 4); // Finaliza a exibicao do menu caso usuario responda <valor>

    printf("\nDados armazenados com sucesso!!\n");

    do { // Exibe o menu até que o usuario o encerre

        printf( // Printa o segundo menu
        "\n============== Sub-Menu =================\n"
        "1) Buscar um valor\n"
        "2) Mostrar no raiz\n"
        "3) Mostrar nos folha\n"
        "4) Mostrar nos ramo\n"
        "5) Altura da arvore\n"
        "6) Profundidade da Arvore\n"
        "7) Grau do No\n"
        "8) Altura do No\n"
        "9) Profundidade do No\n"
        "10) Descendentes do No\n"
        "11) Ancestrais do No\n"
        "12) Pre-ordem\n"
        "13) Pos-ordem\n"
        "14) Em-Ordem\n"
        "15) Encerrar\n"
        "\n"
        "Digite a opcao desejada: "
        );

        // Pega a resposta do usuario
        scanf(" %d", &resp); 

        // Usa a resposta do usuario para iniciar uma acao
        switch (resp) {
        case 1:
            printf("\nDigite um valor para busca: "); // Se usuario escolheu digitar os dados
            scanf("%d", &valor);
            if ((aux = buscar(tree, valor)) != NULL)
                printf("\nO valor %d foi encontrado!", aux->dado, ctd);
            else
                mensagensAviso(2, valor);
            break;
        case 2:
            printf("\nNo raiz: %d", tree->dado); // Se usuario escolheu ver a raiz
            break;
        case 3:
            printf("\nNo(s) folha: "); // Exibe somente os nos folha
            printarNosFolha(tree);
            break;
        case 4:
            printf("\nNo(s) ramo: "); // Exibe somente os nos ramo
            printarNosRamo(tree);
            break;
        case 5:
            printf("\nAltura da arvore: %d", alturaEProfundidade(tree)); // Exibe a altura da arvore
            break;
        case 6:
            printf("\nProfundidade da arvore: %d", alturaEProfundidade(tree)); // Exibe a profundidade da arvore
            break;
        case 7:
            printf("\nDigite o No que deseja saber a grau: "); // Pergunta ao usuario que desejad
            scanf("%d", &valor);
            aux = buscar(tree, valor);
            if (estaVazia(aux))
                mensagensAviso(2, valor);
            else
                printf("\nGrau do No %d: %d", valor, grauDoNo(aux)); // Exibe valor do No e o grau dele
            break;
         case 8:
            printf("\nDigite o no que deseja saber a altura: "); // Pergunta qual No deseja saber a altura
            scanf("%d", &valor);
            aux = buscar(tree, valor); // Busca o No
            if (estaVazia(aux))
                mensagensAviso(2, valor); // Avisa caso ele nao exista
            else
                printf("\nAltura do No %d: %d", valor, alturaEProfundidade(aux)); // Exibe o valor e a altura do No
            break;
         case 9:
            printf("\nDigite o no que deseja saber a profundidade: "); /// Pergunta qual No deseja saber a profundidade
            scanf("%d", &valor);
            aux = buscar(tree, valor);
            if (estaVazia(aux))
                mensagensAviso(2, valor); // Avisa caso ele nao exista
            else
                printf("\nProfundidade do No %d: %d", valor, profundidadeDoNo(aux)); // Exibe o valor e a profundidade do No
            break;
        case 10:
            printf("\nDigite o No do qual deseja ver o descendentes: ");
            scanf("%d", &valor);
            aux = buscar(tree, valor);
            if (estaVazia(aux))
                mensagensAviso(2, valor); // Avisa caso ele nao exista
            else if(!grauDoNo(aux))
                mensagensAviso(3, valor); // Avisa caso o No nao tenha filhos
            else {
                printf("\nDescendentes de %d: ", valor);
                printarDescendentes(aux, valor);
            }
            break;
        case 11:
            printf("\nDigite o No do qual deseja ver o ancestrais: ");
            scanf("%d", &valor);
            aux = buscar(tree, valor); // Busca o No
            if (estaVazia(aux))
                mensagensAviso(2, valor);
            else if(ehNoRaiz(aux)) // verifica se o No é raiz
                mensagensAviso(4, valor); // Se for avisa 
            else {
                printf("\nAncestrais de %d: ", valor);
                printarAncestrais(aux, valor);
            }
            break;
       case 12:
        	printf("\nPre-ordem: "); // Poe os dados ordem de processamento
            preOrdem(tree);
            break;
        case 13:
        	printf("\nPos-ordem: "); // Poe os dados em ordem decresente
            posOrdem(tree);
            break;
        case 14:
            printf("\nEm ordem: "); // Pega os dados em ordem crescente
            emOrdem(tree);
            break;
        case 15:
            printf("\nEncerrando..."); // Se usuario escolheu encerrar
            break;
        default:
            printf("\nOpcao nao identificada!"); // Se usuario digitou uma opcao invalida
            break;
        }
        printf("\n"); //Pula uma linha apos exibir opcao acionada
    } while(resp != 15); // Finaliza a exibicao do menu caso usuario responda <valor>

    return 0;
    
} /*----- Fim do Codigo -----*/