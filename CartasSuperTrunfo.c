#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.
//Teste larissa
#include <stdio.h>

typedef struct {
    char estado[30];
    char nome[30];
    int populacao;
    float area;
    float pib;
    float densidadePopulacional;
    float pibPerCapita;
} Carta;

// Calcula os atributos derivados de uma carta
void calcularAtributos(Carta *carta) {
    carta->densidadePopulacional = carta->populacao / carta->area;
    carta->pibPerCapita = carta->pib / carta->populacao;
}

// Compara múltiplos atributos e retorna o vencedor com base na soma dos valores
void compararMultiplo(Carta c1, Carta c2) {
    float somaCarta1 = c1.populacao + c1.densidadePopulacional + c1.pibPerCapita;
    float somaCarta2 = c2.populacao + c2.densidadePopulacional + c2.pibPerCapita;

    printf("\n>>> Comparando múltiplos atributos...\n");
    printf("Pontuação total de %s: %.2f\n", c1.nome, somaCarta1);
    printf("Pontuação total de %s: %.2f\n", c2.nome, somaCarta2);

    if (somaCarta1 > somaCarta2) {
        printf("Resultado: Carta 1 (%s) venceu!\n", c1.nome);
    } else if (somaCarta1 < somaCarta2) {
        printf("Resultado: Carta 2 (%s) venceu!\n", c2.nome);
    } else {
        printf("Empate! Ambas as cartas possuem a mesma pontuação total.\n");
    }
}

// Lida com empates utilizando um critério secundário
void tratarEmpate(Carta c1, Carta c2) {
    printf("\n>>> Resolvendo o empate com critério de menor densidade populacional...\n");
    if (c1.densidadePopulacional < c2.densidadePopulacional) {
        printf("Desempate: Carta 1 (%s) venceu com densidade %.2f hab/km²!\n", c1.nome, c1.densidadePopulacional);
    } else if (c1.densidadePopulacional > c2.densidadePopulacional) {
        printf("Desempate: Carta 2 (%s) venceu com densidade %.2f hab/km²!\n", c2.nome, c2.densidadePopulacional);
    } else {
        printf("Ainda houve empate! Ambas as cartas são realmente equivalentes.\n");
    }
}

int main() {
    Carta carta1 = {"SP", "São Paulo", 12300000, 1521.11, 699.90, 0, 0};
    Carta carta2 = {"RJ", "Rio de Janeiro", 6000000, 1200.27, 412.35, 0, 0};

    // Calcula os atributos derivados das cartas
    calcularAtributos(&carta1);
    calcularAtributos(&carta2);

    int opcao;

    do {
        printf("\n==== MENU SUPER TRUNFO ====\n");
        printf("1. Comparar por População\n");
        printf("2. Comparar por Densidade Populacional\n");
        printf("3. Comparar por Múltiplos Atributos\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf(">>> Comparando População...\n");
                if (carta1.populacao == carta2.populacao) {
                    tratarEmpate(carta1, carta2);
                } else {
                    printf("Resultado: Carta com maior população venceu\n");
                }
                break;
            case 2:
                printf(">>> Comparando Densidade Populacional...\n");
                if (carta1.densidadePopulacional == carta2.densidadePopulacional) {
                    tratarEmpate(carta1, carta2);
                } else {
                    printf("Resultado baseado...\n");
                }
                break;
            case 3:
                compararMultiplo(carta1, carta2);
                break;
            case 4:
                printf("Saindo do programa. Até logo!\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}
