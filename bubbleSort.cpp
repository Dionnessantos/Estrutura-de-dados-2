#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimeVetor(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void troca(int v[], int a, int b) {
    int tmp = v[a];
    v[a] = v[b];
    v[b] = tmp;
}

void bubbleSort(int v[], int n) {
    int trocado;
    for (int i = 0; i < n - 1; i++) {
        trocado = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                troca(v, j, j + 1);
                trocado = 1;
            }
        }
        // Se não houve troca, o vetor já está ordenado
        if (!trocado) {
            break;
        }
    }
}

void geraVetor(int v[], int n) {
    for (int i = 0; i < n; i++) {
        v[i] = rand() % n;
    }
}

int main() {
    srand(time(NULL));
    int n = 5;
    int v[n];

    geraVetor(v, n);

    imprimeVetor(v, n);
    bubbleSort(v, n);
    imprimeVetor(v, n);

    return 0;
}
