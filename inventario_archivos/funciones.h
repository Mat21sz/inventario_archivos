#define MAX_PRODUCTOS 100
#define MAX_NOMBRE 50

void ingresarProducto(char nombres[][MAX_NOMBRE], int cantidades[], float precios[], int *numProductos);
void editarProducto(char nombres[][MAX_NOMBRE], int cantidades[], float precios[], int numProductos);
void eliminarProducto(char nombres[][MAX_NOMBRE], int cantidades[], float precios[], int *numProductos);
void listarProductos(char nombres[][MAX_NOMBRE], int cantidades[], float precios[], int numProductos);
int compararCadenas(char *cadena1, char *cadena2);
void copiarCadena(char *destino, char *origen);
void guardarInventario(char nombres[][MAX_NOMBRE], int cantidades[], float precios[], int numProductos, char* nombreArchivo);
void cargarInventario(char nombres[][MAX_NOMBRE], int cantidades[], float precios[], int *numProductos, char* nombreArchivo);