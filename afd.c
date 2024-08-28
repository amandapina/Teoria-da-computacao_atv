#include <stdio.h>
#include <string.h>

// Função para obter o próximo estado com base no estado atual e no caractere lido
int transicao(int estado_atual, char caractere) {
    switch (estado_atual) {
        case 0: // q00 que será R
            return (caractere == '0') ? 2 : 1; // 0 -> q10, 1 -> q01
        case 1: // q01 que será S
            return (caractere == '0') ? 3 : 0; // 0 -> q11, 1 -> q00
        case 2: // q10 que será T
            return (caractere == '0') ? 0 : 3; // 0 -> q00, 1 -> q11
        case 3: // q11 que será U
            return (caractere == '0') ? 1 : 2; // 0 -> q01, 1 -> q10
        default:
            return -1;
    }
}


int main() {
    char cadeia[100];
    int estado_atual = 0; // Estado inicial q00 = R

    printf("considere a seguinte linguagem: L = {w|w tem um número par tanto de 0's e 1's}\n");
    printf("Digite a cadeia binária: ");
    scanf("%s", cadeia);

    printf("Sequência de estados: {");

    //estado inicial
    printf("R"); //q00

    // Processando a cadeia 
    for (int i = 0; i < strlen(cadeia); i++) {
        estado_atual = transicao(estado_atual, cadeia[i]);
  
        switch (estado_atual) {
            case 0: printf(", R"); break; //q00
            case 1: printf(", S"); break; //q01
            case 2: printf(", T"); break; //q10
            case 3: printf(", U"); break; //q11
            default: printf(", estado inválido"); break;
        }
    }

    printf("}\n");

    if (estado_atual == 0) {
        printf("A cadeia \"%s\" está correta.\n", cadeia);
    } else {
        printf("A cadeia \"%s\" não está correta.\n", cadeia);
    }

    return 0;
}
