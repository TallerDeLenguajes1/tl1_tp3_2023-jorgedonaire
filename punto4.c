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
}typedef Producto;


struct Cliente
{
    int clienteID;
    char *nombreCliente;
    int cantidadProductosAPedir;
    Producto *Productos;
}typedef Cliente;



void cargarClientes(int cant, Cliente *nuevoCliente);
void mostrarPedidosClientes(int cant, Cliente *nuevoCliente);
float costoTotalProductos(int cantidad, int precio);

int main(){
    int cantidadClientes;
    srand(time(NULL));
    

    printf("Ingrese la cantidad de clientes: ");
    scanf("%d", &cantidadClientes);

    Cliente *listadoClientes;
    listadoClientes = (Cliente*) malloc(sizeof(Cliente)*cantidadClientes);

    cargarClientes(cantidadClientes, listadoClientes);
    mostrarPedidosClientes(cantidadClientes, listadoClientes);


    free(listadoClientes);
    return 0;
}

void cargarClientes(int cant, Cliente *nuevoCliente){   //consultar porque debo pasar *nuevoCliente y no nuevoCliente
    for (int i = 0; i < cant; i++)
    {
        nuevoCliente->clienteID = i+1;   //Asigna ID al cliente
        nuevoCliente->nombreCliente = (char *) malloc(sizeof(char)*50);

        printf("Ingrese el nombre del cliente %d: ",nuevoCliente->clienteID);
        scanf("%s",nuevoCliente->nombreCliente);

        nuevoCliente->cantidadProductosAPedir=1+rand()%6;    //Asigna cantidad aleatoria de productos a pedir
        nuevoCliente->Productos=(Producto *) malloc(sizeof(Producto)*nuevoCliente->cantidadProductosAPedir); //reservo memoria para la cantidad de productos asignados


        for (int j = 0; j < nuevoCliente->cantidadProductosAPedir; j++)  //Carga informacion de los productos
        {
            nuevoCliente->Productos[j].productoID=j+1; //Asigna el ID del producto
            nuevoCliente->Productos[j].cantidad=rand()%11+1;   //Asigna cantidad aleatoria de productos
            nuevoCliente->Productos[j].tipoProducto=tiposProductos[rand()%5]; //Asigna algun valor del arreglo TiposProductos
            nuevoCliente->Productos[j].precioUnitario=10+rand()%101;   //Asigna precio
            
        }
        nuevoCliente++;
    }
 
}

float costoTotalProductos(int cantidad, int precio){
    return cantidad*precio;
}

void mostrarPedidosClientes(int cant, Cliente *nuevoCliente){
    int costoTotalPorCliente=0;
    for (int i = 0; i < cant; i++)
    {
        printf("///////// CLIENTE %d - %s///////////////\n", nuevoCliente->clienteID, nuevoCliente->nombreCliente);
        printf("Cantidad de productos pedidos: %d\n", nuevoCliente->cantidadProductosAPedir);
        printf("\n");
        for (int j = 0; j < nuevoCliente->cantidadProductosAPedir; j++)
        {
            printf("Producto ID: %d\n",nuevoCliente->Productos[j].productoID);
            printf("Tipo de Producto: %s\n",nuevoCliente->Productos[j].tipoProducto);         
            printf("Cantidad: %d\n",nuevoCliente->Productos[j].cantidad);
            printf("Precio Unitario: %f\n",nuevoCliente->Productos[j].precioUnitario);
            costoTotalPorCliente+=costoTotalProductos(nuevoCliente->Productos[j].cantidad,nuevoCliente->Productos[j].precioUnitario);
            printf("Costo total por estos productos es: %f\n", costoTotalProductos(nuevoCliente->Productos[j].cantidad,nuevoCliente->Productos[j].precioUnitario));
            puts("-----------------");
        }
    printf("Total a pagar por el cliente %d: %d ", nuevoCliente->clienteID, costoTotalPorCliente);
    nuevoCliente++;
    }
}
// void liberarMemoria(int cant, Cliente *nuevoCliente){

//     free(nuevoCliente->nombreCliente);
//     free(nuevoCliente->Productos);

// }