#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para representar uma sala
typedef struct Sala {
    char nome[50];
    struct Sala *esquerda;
    struct Sala *direita;
} Sala;

// Função para criar uma nova sala
Sala* criarSala(char nome[]) {
    Sala *novaSala = (Sala*) malloc(sizeof(Sala));

    strcpy(novaSala->nome, nome);
    novaSala->esquerda = NULL;
    novaSala->direita = NULL;

    return novaSala;
}

// Função para conectar duas salas
void conectarSalas(Sala *sala, Sala *esquerda, Sala *direita) {
    sala->esquerda = esquerda;
    sala->direita = direita;
}

// Função para explorar a mansão
void explorarSalas(Sala *inicio) {

    Sala *atual = inicio;
    char escolha;

    while (atual != NULL) {

        printf("\n=================================\n");
        printf("Voce esta na sala: %s\n", atual->nome);
        printf("=================================\n");

        printf("\nEscolha uma opcao:\n");
        printf("E - Ir para a esquerda\n");
        printf("D - Ir para a direita\n");
        printf("S - Sair da exploracao\n");
        printf("Opcao: ");
        scanf(" %c", &escolha);

        if (escolha == 'e' || escolha == 'E') {

            if (atual->esquerda != NULL) {
                atual = atual->esquerda;
            } else {
                printf("\nNao existe uma sala para a esquerda.\n");
            }

        } else if (escolha == 'd' || escolha == 'D') {

            if (atual->direita != NULL) {
                atual = atual->direita;
            } else {
                printf("\nNao existe uma sala para a direita.\n");
            }

        } else if (escolha == 's' || escolha == 'S') {

            printf("\nExploracao encerrada!\n");
            break;

        } else {

            printf("\nOpcao invalida!\n");
        }
    }
}

int main() {

    // Criando as salas da mansao
    Sala *hall = criarSala("Hall de Entrada");
    Sala *biblioteca = criarSala("Biblioteca");
    Sala *cozinha = criarSala("Cozinha");
    Sala *sotao = criarSala("Sotao");
    Sala *quarto = criarSala("Quarto");

    // Conectando as salas
    conectarSalas(hall, biblioteca, cozinha);
    conectarSalas(biblioteca, sotao, quarto);

    // Inicio da exploracao
    printf("=================================\n");
    printf("     DETECTIVE QUEST\n");
    printf("     Nivel Novato\n");
    printf("=================================\n");

    explorarSalas(hall);

    // Liberando a memoria
    free(hall);
    free(biblioteca);
    free(cozinha);
    free(sotao);
    free(quarto);

    return 0;
}
