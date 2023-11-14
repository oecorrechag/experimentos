#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, suma;
    
    // Generar dos números aleatorios
    srand(time(NULL));
    num1 = rand() % 100;
    num2 = rand() % 100;
    
    // Calcular la suma
    suma = num1 + num2;
    
    // Imprimir los números y la suma
    printf("Número 1: %d\n", num1);
    printf("Número 2: %d\n", num2);
    printf("Suma: %d\n", suma);
    
    return 0;
}