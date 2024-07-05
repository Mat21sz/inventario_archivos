#include <stdio.h>
#include "funciones.h"
#include "lecturas.h"
#include "productos.h"

int compararCadenas(char *cadena1, char *cadena2) {
    int i = 0;
    while (cadena1[i] != '\0' && cadena2[i] != '\0') {
        if (cadena1[i] != cadena2[i]) {
            return 0;
        }
        i++;
    }
    return cadena1[i] == '\0' && cadena2[i] == '\0';
}

void copiarCadena(char *destino, char *origen) {
    int i = 0;
    while (origen[i] != '\0') {
        destino[i] = origen[i];
        i++;
    }
    destino[i] = '\0';
}

void ingresarProducto(char nombres[][MAX_NOMBRE], int cantidades[], float precios[], int *numProductos) {
    printf("Ingrese el nombre del producto: ");
    scanf("%s", nombres[*numProductos]);
    cantidades[*numProductos] = leerEnteroPositivo("Ingrese la cantidad: ");
    precios[*numProductos] = leerFlotantePositivo("Ingrese el precio: ");
    (*numProductos)++;
}

void editarProducto(char nombres[][MAX_NOMBRE], int cantidades[], float precios[], int numProductos) {
    char nombre[MAX_NOMBRE];
    int i;
    int encontrado = 0;

    printf("Ingrese el nombre del producto a editar: ");
    scanf("%s", nombre);

    for (i = 0; i < numProductos; i++) {
        if (compararCadenas(nombres[i], nombre)) {
            encontrado = 1;
            break;
        }
    }

    if (encontrado) {
        cantidades[i] = leerEnteroPositivo("Ingrese la nueva cantidad: ");
        precios[i] = leerFlotantePositivo("Ingrese el nuevo precio: ");
        printf("Producto actualizado.\n");
    } else {
        printf("Producto no encontrado.\n");
    }
}

void eliminarProducto(char nombres[][MAX_NOMBRE], int cantidades[], float precios[], int *numProductos) {
    char nombre[MAX_NOMBRE];
    int i, j;
    int encontrado = 0;

    printf("Ingrese el nombre del producto a eliminar: ");
    scanf("%s", nombre);

    for (i = 0; i < *numProductos; i++) {
        if (compararCadenas(nombres[i], nombre)) {
            encontrado = 1;
            break;
        }
    }

    if (encontrado) {
        for (j = i; j < *numProductos - 1; j++) {
            copiarCadena(nombres[j], nombres[j + 1]);
            cantidades[j] = cantidades[j + 1];
            precios[j] = precios[j + 1];
        }
        (*numProductos)--;
        printf("Producto eliminado.\n");
    } else {
        printf("Producto no encontrado.\n");
    }
}

void listarProductos(char nombres[][MAX_NOMBRE], int cantidades[], float precios[], int numProductos) {
    int i;
    printf("Lista de productos:\n");
    for (i = 0; i < numProductos; i++) {
        printf("Nombre: %s, Cantidad: %d, Precio: %.2f\n", nombres[i], cantidades[i], precios[i]);
    }
}