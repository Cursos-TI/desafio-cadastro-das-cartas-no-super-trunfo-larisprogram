#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.
//Teste larissa

int main() {
     // Definindo as cartas
    Carta carta1 = {"SP", "São Paulo", 12300000, 1521.11, 699.90, 0, 0};
    Carta carta2 = {"RJ", "Rio de Janeiro", 6000000, 1200.27, 412.35, 0, 0};

    // Calculando atributos derivados
    carta1.densidadePopulacional = carta1.populacao / carta1.area;
    carta1.pibPerCapita = carta1.pib / carta1.populacao;

    carta2.densidadePopulacional = carta2.populacao / carta2.area;
    carta2.pibPerCapita = carta2.pib / carta2.populacao;

    // Exibindo os atributos das cartas
    printf("Carta 1: %s (%s)\n", carta1.nome, carta1.estado);
    printf("População: %d\nÁrea: %.2f km²\nPIB: %.2f bilhões\n", carta1.populacao, carta1.area, carta1.pib);
    printf("Densidade Populacional: %.2f hab/km²\nPIB per capita: %.2f\n\n", carta1.densidadePopulacional, carta1.pibPerCapita);

    printf("Carta 2: %s (%s)\n", carta2.nome, carta2.estado);
    printf("População: %d\nÁrea: %.2f km²\nPIB: %.2f bilhões\n", carta2.populacao, carta2.area, carta2.pib);
    printf("Densidade Populacional: %.2f hab/km²\nPIB per capita: %.2f\n\n", carta2.densidadePopulacional, carta2.pibPerCapita);

    // Comparando por População
    printf("Comparando cartas pelo atributo: População\n");
    if (carta1.populacao > carta2.populacao) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome);
    } else if (carta1.populacao < carta2.populacao) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome);
    } else {
        printf("Resultado: Empate!\n");
    }

    // Comparando por Densidade Populacional
    printf("\nComparando cartas pelo atributo: Densidade Populacional\n");
    if (carta1.densidadePopulacional < carta2.densidadePopulacional) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome);
    } else if (carta1.densidadePopulacional > carta2.densidadePopulacional) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}
