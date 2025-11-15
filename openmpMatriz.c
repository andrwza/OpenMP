#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#define N 4 // tamanho da matriz (N x N)
// Função para imprimir matriz
void printMatrix(int M[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%4d ", M[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int A[N][N], B[N][N], C[N][N];

    // Inicializa as matrizes
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = i + j;
            B[i][j] = i * j;
        }
    }

    printf("Matriz A:\n");
    printMatrix(A);
    printf("\nMatriz B:\n");
    printMatrix(B);

    // Detecta número de processadores (núcleos lógicos)
    int num_cores = omp_get_num_procs();
    printf("\nNumero de nucleos detectados: %d\n", num_cores);

    // Define o número de threads igual ao número de núcleos
    omp_set_num_threads(num_cores);

    // Soma paralela das matrizes
    #pragma omp parallel for collapse(2) shared(A,B,C)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = A[i][j] + B[i][j];
            printf("Thread %d calculou C[%d][%d]\n", omp_get_thread_num(), i, j);
        }
    }

    printf("\nMatriz Resultado (C = A + B):\n");
    printMatrix(C);

    return 0;
}
