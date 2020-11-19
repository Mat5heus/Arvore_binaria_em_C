/*
 * Nome do programa : Arvore
 * 
 * Desenvolvedores
 * Nome: Matheus do carmo Santos RA: 106020 
 * Nome: Matheus Galvani de Camargo RA: 107285
 * Nome: RA: Leonardo Garcia RA: 106939
 * Nome: RA: 
 * Nome: RA:
 * 
 */

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
        "3) Encerrar\n"
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
            printf("\nAbrindo arquivo...\n"); // Se usuario escolheu ler do arquivo
            break;
        case 3:
            printf("\nEncerrando...\n"); // Se usuario escolheu encerrar
            exit(0); // Finaliza a execucao do programa e retorna 0
            break;
        default:
            printf("\nOpcao nao identificada!\n"); // Se usuario digitou uma opcao invalida
            break;
        }

    } while(resp != 2 && resp != 1); // Finaliza a exibicao do menu caso usuario responda <valor>

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
        "7) Grau do no\n"
        "8) Descendentes do no\n"
        "9) Ancestrais do no\n"
        "10) Pre-ordem\n"
        "11) Pos-ordem\n"
        "12) Em-Ordem\n"
        "13) Encerrar\n"
        "\n"
        "Digite a opcao desejada: "
        );

        // Pega a resposta do usuario
        scanf("%d", &resp); 

        // Usa a resposta do usuario para iniciar uma acao
        switch (resp) {
        case 1:
            printf("\nDigite um valor para busca: "); // Se usuario escolheu digitar os dados
            scanf("%d", &valor);
            if ((aux = buscar(tree, valor, &ctd)) != NULL)
                printf("O valor %d foi encontrado com %d pulos!", aux->dado, ctd);
            else
                printf("O valor %d nao foi localizado!", valor);
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
            printf("\nFuncao ainda nao definida!"); // Por favor, comentar funcao
            break;
        case 6:
            printf("\nFuncao ainda nao definida!"); // Por favor, comentar funcao
            break;
        case 7:
            printf("\nFuncao ainda nao definida!"); // Por favor, comentar funcao
            break;
        case 8:
            printf("\nFuncao ainda nao definida!"); // Por favor, comentar funcao
            break;
        case 9:
            printf("\nFuncao ainda nao definida!"); // Por favor, comentar funcao
            break;
       case 10:
        	printf("\nPre-ordem: "); // Poe os dados ordem de processamento
            preOrdem(tree);
            break;
        case 11:
        	printf("\nPos-ordem: "); // Poe os dados em ordem decresente
            posOrdem(tree);
            break;
        case 12:
            printf("\nEm ordem: "); // Pega os dados em ordem crescente
            emOrdem(tree);
            break;
        case 13:
            printf("\nEncerrando..."); // Se usuario escolheu encerrar
            break;
        default:
            printf("\nOpcao nao identificada!"); // Se usuario digitou uma opcao invalida
            break;
        }
        printf("\n"); //Pula uma linha apos exibir opcao acionada
    } while(resp != 13); // Finaliza a exibicao do menu caso usuario responda <valor>

    return 0;
    
} /*----- Fim do Codigo -----*/
