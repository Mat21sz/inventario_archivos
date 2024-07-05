#include <stdio.h>
#include "funciones.h"
#include "lecturas.h"
#include "productos.h"

int main() {
    char nombres[MAX_PRODUCTOS][MAX_NOMBRE];
    int cantidades[MAX_PRODUCTOS];
    float precios[MAX_PRODUCTOS];
    int numProductos = 0;
    int opcion;
    char nombreArchivo[] = "inventario.txt";

 
    cargarInventario(nombres, cantidades, precios, &numProductos, nombreArchivo);

    do {
        printf("Sistema de Inventarios\n");
        printf("1. Ingresar producto\n");
        printf("2. Editar producto\n");
        printf("3. Eliminar producto\n");
        printf("4. Listar productos\n");
        printf("5. Guardar y salir\n");
        opcion = leerEntero("Ingrese una opción: ");

        switch (opcion) {
            case 1:
                ingresarProducto(nombres, cantidades, precios, &numProductos);
                break;
            case 2:
                editarProducto(nombres, cantidades, precios, numProductos);
                break;
            case 3:
                eliminarProducto(nombres, cantidades, precios, &numProductos);
                break;
            case 4:
                listarProductos(nombres, cantidades, precios, numProductos);
                break;
            case 5:
                
                guardarInventario(nombres, cantidades, precios, numProductos, nombreArchivo);
                printf("Inventario guardado. Saliendo del sistema...\n");
                break;
            default:
                printf("Opción inválida. Intente nuevamente.\n");
        }
    } while (opcion != 5);

    return 0;
}