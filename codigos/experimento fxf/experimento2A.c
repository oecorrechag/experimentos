#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>


int main(int argc, char *argv[]){
    size_t **matrix; 
    size_t **matrizT; 
    size_t **resultado; 
    size_t N = 500;
    clock_t inicio, fin;
    double tiempo_transcurrido;
    srand(time(NULL));

    // Memoria dinamica
    matrix = (size_t **)calloc(N, sizeof(size_t *)); 
    for(size_t i = 0; i < N; ++i) 
        matrix[i] = (size_t *)malloc(N * sizeof(size_t)); 


    // Inicializa una matriz y la llena
    for(size_t i = 0; i < N; ++i){ 
        for(size_t j = 0; j < N; ++j){
            matrix[i][j] = (size_t) rand()%100 + 1;
        }   
    }
    

    // // imprime la matriz generada
    // for(size_t i = 0; i < N; ++i){ 
    //     for(size_t j = 0; j < N; ++j) { 
    //         printf("%zu", matrix[i][j]); 
    //     }
    //     printf("\n");
    // }


    // Memoria dinamica para matriz transpuesta
    matrizT = (size_t **)calloc(N, sizeof(size_t *)); 
    for(size_t i = 0; i < N; ++i) 
        matrizT[i] = (size_t *)malloc(N * sizeof(size_t)); 


    // Memoria dinamica -> salida resultado
    resultado = (size_t **)calloc(N, sizeof(size_t *)); 
    for(size_t i = 0; i < N; ++i) 
        resultado[i] = (size_t *)malloc(N * sizeof(size_t)); 


    // Registra el tiempo de inicio
    inicio = clock();


    // Transponer la matriz intercambiando filas y columnas
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			matrizT[j][i] = matrix[i][j];
		}
	}

    // // imprime la matriz generada
    // for(size_t i = 0; i < N; ++i){ 
    //     for(size_t j = 0; j < N; ++j) { 
    //         printf("%zu", matrizT[i][j]); 
    //     }
    //     printf("\n");
    // }


    // // Multiplicación de la matriz por sí misma
    // for (size_t i = 0; i < N; i++) {
    //     for (size_t j = 0; j < N; j++) {
    //         for (size_t k = 0; k < N; k++) {
    //             resultado[i][j] += matrix[i][k] * matrix[k][j];
    //         }
    //     }
    // }

    // Multiplicación de la matriz por sí misma
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            for (size_t k = 0; k < N; k++) {
                resultado[i][j] += matrix[i][k] * matrix[j][k];
            }
        }
    }



    // #pragma omp parallel
    // {
    //     // Multiplicación de la matriz por sí misma
    //     for (size_t i = 0; i < N; i++) {
    //         for (size_t j = 0; j < N; j++) {
    //             for (size_t k = 0; k < N; k++) {
    //                 resultado[i][j] += matrix[i][k] * matrix[k][j];
    //             }
    //         }
    //     }
    // }
    // return 0;




    // Registra el tiempo de finalización
    fin = clock();

    // Calcula el tiempo transcurrido en segundos
    tiempo_transcurrido = (double)(fin - inicio) / CLOCKS_PER_SEC;
    // printf("Tiempo de ejecución: %f segundos\n", tiempo_transcurrido);
    printf("%f\n", tiempo_transcurrido);

    // // imprime la matriz generada
    // for(size_t i = 0; i < N; ++i){ 
    //     for(size_t j = 0; j < N; ++j) { 
    //         printf("%zu", resultado[i][j]);
    //     }
    //     printf("\n");
    // }


    // evitar fuga de memoria
    for(size_t i = 0; i < N; ++i) {
        free(matrix[i]); 
        free(resultado[i]);
        free(matrizT[i]);
    }
    free(matrix);
    free(resultado);
    free(matrizT);

}
