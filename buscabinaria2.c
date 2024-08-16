#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_NOMES 1000
#define TAM_NOME 100


void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}


int buscaBinaria(char nomes[][TAM_NOME], int n, char *prefixo) {
    int s = 0, e = n - 1;
    int resultado = -1;

    while (s <= e) {
        int m = (s + e) / 2;


        if (strncmp(nomes[m], prefixo, strlen(prefixo)) == 0) {
            resultado = m;
            e = m - 1;
        } else if (strcmp(nomes[m], prefixo) < 0) {
            s = m + 1;
        } else {
            e = m - 1;
        }
    }

    return resultado;
}

int main() {
    char nomes[MAX_NOMES][TAM_NOME];
    int n = 0;
    char prefixo[TAM_NOME];
    FILE *arquivo = fopen("nomes.txt", "r");



    while (fgets(nomes[n], TAM_NOME, arquivo)) {
        nomes[n][strcspn(nomes[n], "\n")] = 0;
        toLowerCase(nomes[n]);
        n++;
    }
    fclose(arquivo);


    qsort(nomes, n, sizeof(nomes[0]), (int (*)(const void *, const void *)) strcmp);


    printf("Digite o prefixo que deseja buscar: ");

    fgets(prefixo, TAM_NOME, stdin);
    prefixo[strcspn(prefixo, "\n")] = 0;
    toLowerCase(prefixo);


    int indice = buscaBinaria(nomes, n, prefixo);


    if (indice != -1) {
        printf("Nomes encontrados:\n");
        for (int i = indice; i < n && strncmp(nomes[i], prefixo, strlen(prefixo)) == 0; i++) {
            printf("%s\n", nomes[i]);
        }
    } else {
        printf("Nenhum nome encontrado com o prefixo \"%s\".\n", prefixo);
    }

    return 0;
}


