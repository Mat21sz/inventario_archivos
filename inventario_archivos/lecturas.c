#include <stdio.h>
#include "lecturas.h"
#include "productos.h"

int leerEnteroPositivo(char* mensaje) {
    int valor;
    do {
        printf("%s", mensaje);
        scanf("%d", &valor);
    } while (valor <= 0);
    return valor;
}

float leerFlotantePositivo(char* mensaje) {
    float valor;
    do {
        printf("%s", mensaje);
        scanf("%f", &valor);
    } while (valor <= 0);
    return valor;
}

int leerEnteroEntre(char* mensaje, int lmenor, int lmayor) {
    int numero;
    do {
        printf("%s", mensaje);
        scanf("%d", &numero);
    } while (numero < lmenor || numero > lmayor);
    return numero;
}

int leerEntero(char* mensaje) {
    int numero;
    printf("%s", mensaje);
    scanf("%d", &numero);
    return numero;
}

float leerFlotante(char* mensaje) {
    float numero;
    printf("%s", mensaje);
    scanf("%f", &numero);
    return numero;
}

float leerFlotanteEntre(char* mensaje, float lmenor, float lmayor) {
    float numero;
    do {
        printf("%s", mensaje);
        scanf("%f", &numero);
    } while (numero < lmenor || numero > lmayor);
    return numero;
}

char leerCaracter(char* mensaje) {
    char caracter;
    printf("%s", mensaje);
    scanf(" %c", &caracter);
    return caracter;
}

float leerFlotanteMayorIgual(char* mensaje, float menor) {
    float valor;
    do {
        printf("%s", mensaje);
        scanf("%f", &valor); 
    } while (valor < menor);
    return valor;
}

void guardarInventario(char nombres[][MAX_NOMBRE], int cantidades[], float precios[], int numProductos, char* nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "w");
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return;
    }

    for (int i = 0; i < numProductos; i++) {
        fprintf(archivo, "%s %d %.2f\n", nombres[i], cantidades[i], precios[i]);
    }

    fclose(archivo);
}

void cargarInventario(char nombres[][MAX_NOMBRE], int cantidades[], float precios[], int *numProductos, char* nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return;
    }

    *numProductos = 0;
    while (fscanf(archivo, "%s %d %f", nombres[*numProductos], &cantidades[*numProductos], &precios[*numProductos]) != EOF) {
        (*numProductos)++;
    }

    fclose(archivo);
}