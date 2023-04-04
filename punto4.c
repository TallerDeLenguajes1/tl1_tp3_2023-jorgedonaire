#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *tiposProductos[]={"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};

struct Producto
{
    int productoID;
    int cantidad;
    char *tipoProducto;
    float precioUnitario;
};
typedef struct Producto Producto;

struct cliente
{
    int clienteID;
    char *nombreCliente;
    int cantidadProductosAPedir;
    Producto *Productos;
};
typedef struct cliente cliente;

int main(){
    int cantidadClientes;
    srand(time(NULL));
    printf("Ingrese la cantidad de clientes: ");
    scanf("%d", &cantidadClientes);

    cliente *pClientes;
    pClientes = (cliente*) malloc(sizeof(cliente)*cantidadClientes);

    for (int i = 0; i < cantidadClientes; i++)
    {
        cliente pClientes;
        pClientes.clienteID=i;

        printf("Ingrese el nombre del cliente %d: ", i);
        scanf("%s", *pClientes.nombreCliente);

        printf("Ingrese la cantidad de productos a pedir: ");
        scanf("%d", pClientes.cantidadProductosAPedir);

        for (int j = 0; j < pClientes.cantidadProductosAPedir; j++)
        {
            pClientes.Productos->productoID=j;
            printf("Ingrese la cantidad: ");
            scanf("%d", pClientes.Productos->cantidad);

            pClientes.Productos->tipoProducto = tiposProductos[rand()%6+1];

            printf("Ingrese el precio del producto: ");
            scanf("%d", pClientes.Productos->precioUnitario);
        }

    }
    
    free(pClientes);
    return 0;
}