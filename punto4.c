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

struct Cliente
{
    int clienteID;
    char *nombreCliente;
    int cantidadProductosAPedir;
    Producto *Productos;
};
typedef struct Cliente Cliente;


void cargarClientes(int cant, Cliente *nuevoCliente);

int main(){
    int cantidadClientes;
    srand(time(NULL));
    

    printf("Ingrese la cantidad de clientes: ");
    scanf("%d", &cantidadClientes);

    Cliente *listadoClientes;
    listadoClientes = (Cliente*) malloc(sizeof(Cliente)*cantidadClientes);

    cargarClientes(cantidadClientes, listadoClientes);

    free(listadoClientes);
    return 0;
}

void cargarClientes(int cant, Cliente *nuevoCliente){   //consultar porque debo pasar *nuevoCliente y no nuevoCliente
    for (int i = 0; i < cant; i++)
    {
        nuevoCliente->clienteID = i+1;   //Asigna ID al cliente
        nuevoCliente->nombreCliente = (char *) malloc(sizeof(char)*50);

        printf("Ingrese el nombre del cliente: ");
        scanf("%s",nuevoCliente->nombreCliente);

        nuevoCliente->cantidadProductosAPedir=rand()%6+1;    //Asigna cantidad aleatoria de productos a pedir
        nuevoCliente->Productos=(Producto *) malloc(sizeof(Producto)*nuevoCliente->cantidadProductosAPedir); //reservo memoria para la cantidad de productos asignados

        for (int j = 0; j < nuevoCliente->cantidadProductosAPedir; j++)  //Carga informacion de los productos
        {
            nuevoCliente->Productos->cantidad=rand()%11+1;   //Asigna cantidad aleatoria de productos
            nuevoCliente->Productos->productoID=15; //Asigna el ID del producto
            nuevoCliente->Productos->tipoProducto=tiposProductos[1]; //Asigna algun valor del arreglo TiposProductos
            nuevoCliente->Productos->precioUnitario=rand()%101+10;   //Asigna precio
        }
    }
}