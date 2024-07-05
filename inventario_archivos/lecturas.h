#include "productos.h"

int leerEnteroPositivo(char*);
int leerEntero(char*);
int leerEnteroEntre(char*, int, int);

float leerFlotantePositivo(char*);
float leerFlotante(char*);
float leerFlontanteEntre(char*, float, float);
float leerFlotanteMayorIgual(char*, float);

char leerCaracter(char*);

void guardarInventario(char nombres[][MAX_NOMBRE], int cantidades[], float precios[], int numProductos, char* nombreArchivo);
void cargarInventario(char nombres[][MAX_NOMBRE], int cantidades[], float precios[], int *numProductos, char* nombreArchivo);

