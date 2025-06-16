#include <stdio.h>
#include <locale.h>
#include <string.h>

typedef struct {
    char nome[50];
    char estado[30];
    char codigo[30];
    int populacao, turismo;
    float pib, area;
} Carta;

void lerCarta(Carta *carta) {
    printf("Digite o nome do estado: ");
    fgets(carta->estado, sizeof(carta->estado), stdin);

    printf("Digite o nome da cidade: ");
    fgets(carta->nome, sizeof(carta->nome), stdin);

    printf("Digite o codigo da cidade: ");
    scanf("%s", carta->codigo);

    printf("Digite a populacao da cidade: ");
    scanf("%d", &carta->populacao);

    printf("Digite a quantidade de pontos turísticos da cidade: ");
    scanf("%d", &carta->turismo);

    printf("Digite o PIB da cidade: ");
    scanf("%f", &carta->pib);

    printf("Digite a área da cidade: ");
    scanf("%f", &carta->area);

}

void mostrarCarta(Carta *carta) {
    printf("\nEstado: %s", carta->estado);
    printf("Cidade: %s", carta->nome);
    printf("Código: %s\n", carta->codigo);
    printf("População: %d\n", carta->populacao);
    printf("Pontos turísticos: %d\n", carta->turismo);
    printf("PIB: %.2f\n", carta->pib);
    printf("Área: %.2f\n", carta->area);
}

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil.1252");

    Carta carta1, carta2;
    int opcao;

    printf("Cadastro da primeira carta:\n");
    lerCarta(&carta1);

    printf("\nCadastro da segunda carta:\n");
    lerCarta(&carta2);

    printf("\nEscolha o atributo para comparar:\n");
    printf("1 - População\n2 - Pontos turísticos\n3 - PIB\n4 - Área\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    printf("\nCarta 1:");
    mostrarCarta(&carta1);
    printf("\nCarta 2:");
    mostrarCarta(&carta2);

    printf("\nResultado da comparação: ");
    switch(opcao) {
        case 1:
            if (carta1.populacao > carta2.populacao)
                printf("Carta 1 vence (população maior).\n");
            else if (carta1.populacao < carta2.populacao)
                printf("Carta 2 vence (população maior).\n");
            else
                printf("Empate (população igual).\n");
            break;
        case 2:
            if (carta1.turismo > carta2.turismo)
                printf("Carta 1 vence (mais pontos turísticos).\n");
            else if (carta1.turismo < carta2.turismo)
                printf("Carta 2 vence (mais pontos turísticos).\n");
            else
                printf("Empate (mesma quantidade de pontos turísticos).\n");
            break;
        case 3:
            if (carta1.pib > carta2.pib)
                printf("Carta 1 vence (PIB maior).\n");
            else if (carta1.pib < carta2.pib)
                printf("Carta 2 vence (PIB maior).\n");
            else
                printf("Empate (PIB igual).\n");
            break;
        case 4:
            if (carta1.area > carta2.area)
                printf("Carta 1 vence (área maior).\n");
            else if (carta1.area < carta2.area)
                printf("Carta 2 vence (área maior).\n");
            else
                printf("Empate (área igual).\n");
            break;
        default:
            printf("Opção inválida.\n");
    }

    return 0;
}
