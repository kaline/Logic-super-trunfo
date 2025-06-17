#include <stdio.h>
#include <string.h>

#define MAX_CARTAS 5

typedef struct {
    char nome[50];
    int forca;
    int inteligencia;
    int velocidade;
} Carta;

void cadastrarCarta(Carta cartas[], int *total) {
    if (*total >= MAX_CARTAS) {
        printf("Limite de cartas atingido!\n");
        return;
    }

    printf("\n-- Cadastro da Carta %d --\n", *total + 1);
    printf("Nome: ");
    scanf(" %[^\n]", cartas[*total].nome);
    printf("Força: ");
    scanf("%d", &cartas[*total].forca);
    printf("Inteligência: ");
    scanf("%d", &cartas[*total].inteligencia);
    printf("Velocidade: ");
    scanf("%d", &cartas[*total].velocidade);
    (*total)++;
}

void exibirCartas(Carta cartas[], int total) {
    if (total == 0) {
        printf("Nenhuma carta cadastrada.\n");
        return;
    }
    for (int i = 0; i < total; i++) {
        printf("\nCarta %d:\n", i + 1);
        printf("Nome: %s\n", cartas[i].nome);
        printf("Força: %d\n", cartas[i].forca);
        printf("Inteligência: %d\n", cartas[i].inteligencia);
        printf("Velocidade: %d\n", cartas[i].velocidade);
    }
}

// Desafio 1: Comparação com único atributo usando if/else
void compararUmAtributo(Carta c1, Carta c2) {
    int opcao;
    printf("\nEscolha o atributo para comparar:\n");
    printf("1 - Força\n2 - Inteligência\n3 - Velocidade\n> ");
    scanf("%d", &opcao);

    int valor1, valor2;

    if (opcao == 1) {
        valor1 = c1.forca;
        valor2 = c2.forca;
    } else if (opcao == 2) {
        valor1 = c1.inteligencia;
        valor2 = c2.inteligencia;
    } else {
        valor1 = c1.velocidade;
        valor2 = c2.velocidade;
    }

    printf("\n%s: %d | %s: %d\n", c1.nome, valor1, c2.nome, valor2);

    if (valor1 > valor2) {
        printf("Vencedor: %s\n", c1.nome);
    } else if (valor2 > valor1) {
        printf("Vencedor: %s\n", c2.nome);
    } else {
        printf("Empate!\n");
    }
}

// Desafio 2: Comparação com múltiplos atributos
void compararMultiplosAtributos(Carta c1, Carta c2) {
    int pontos1 = 0, pontos2 = 0;

    if (c1.forca > c2.forca) pontos1++;
    else if (c2.forca > c1.forca) pontos2++;

    if (c1.inteligencia > c2.inteligencia) pontos1++;
    else if (c2.inteligencia > c1.inteligencia) pontos2++;

    if (c1.velocidade > c2.velocidade) pontos1++;
    else if (c2.velocidade > c1.velocidade) pontos2++;

    printf("\n%s: %d pontos | %s: %d pontos\n", c1.nome, pontos1, c2.nome, pontos2);

    if (pontos1 > pontos2) {
        printf("Vencedor: %s\n", c1.nome);
    } else if (pontos2 > pontos1) {
        printf("Vencedor: %s\n", c2.nome);
    } else {
        printf("Empate!\n");
    }
}

// Desafio 3: Comparação com 2 atributos e operador ternário
void compararDoisAtributos(Carta c1, Carta c2) {
    int att1, att2;

    printf("\nAtributos disponíveis:\n1 - Força\n2 - Inteligência\n3 - Velocidade\n");
    printf("Escolha o primeiro atributo: ");
    scanf("%d", &att1);
    printf("Escolha o segundo atributo: ");
    scanf("%d", &att2);

    int soma1 = 0, soma2 = 0;

    soma1 += (att1 == 1) ? c1.forca : (att1 == 2) ? c1.inteligencia : c1.velocidade;
    soma2 += (att1 == 1) ? c2.forca : (att1 == 2) ? c2.inteligencia : c2.velocidade;

    soma1 += (att2 == 1) ? c1.forca : (att2 == 2) ? c1.inteligencia : c1.velocidade;
    soma2 += (att2 == 1) ? c2.forca : (att2 == 2) ? c2.inteligencia : c2.velocidade;

    printf("\nSoma de atributos: %s = %d | %s = %d\n", c1.nome, soma1, c2.nome, soma2);
    (soma1 > soma2) ? printf("Vencedor: %s\n", c1.nome) :
    (soma2 > soma1) ? printf("Vencedor: %s\n", c2.nome) :
                      printf("Empate!\n");
}

int main() {
    Carta cartas[MAX_CARTAS];
    int total = 0;
    int opcao;

    do {
        printf("\n===== MENU SUPER TRUNFO =====\n");
        printf("1 - Cadastrar carta\n");
        printf("2 - Exibir cartas\n");
        printf("3 - Comparar um único atributo (Desafio 1)\n");
        printf("4 - Comparar múltiplos atributos (Desafio 2)\n");
        printf("5 - Comparar dois atributos com ternário (Desafio 3)\n");
        printf("0 - Sair\n> ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarCarta(cartas, &total);
                break;
            case 2:
                exibirCartas(cartas, total);
                break;
            case 3:
            case 4:
            case 5:
                if (total < 2) {
                    printf("Cadastre ao menos duas cartas.\n");
                } else {
                    int i, j;
                    printf("Escolha duas cartas para comparar (1 a %d): ", total);
                    scanf("%d %d", &i, &j);
                    if (i <= 0 || j <= 0 || i > total || j > total || i == j) {
                        printf("Escolha inválida.\n");
                    } else if (opcao == 3) {
                        compararUmAtributo(cartas[i-1], cartas[j-1]);
                    } else if (opcao == 4) {
                        compararMultiplosAtributos(cartas[i-1], cartas[j-1]);
                    } else {
                        compararDoisAtributos(cartas[i-1], cartas[j-1]);
                    }
                }
                break;
            case 0:
                printf("Encerrando programa.\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 0);

    return 0;
}
