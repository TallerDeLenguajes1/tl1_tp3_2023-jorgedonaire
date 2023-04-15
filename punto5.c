#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct nombre
{
    char *nombre;
}typedef nombre;

void cargarNombres(int cant, char * listadoNombres);
void mostrarNombres(int cant, char *listadoNombres);

int main(){
    int cantidadNombres=0;

    printf("Ingrese la cantidad de nombres: ");
    scanf("%d", &cantidadNombres);

    char *listadoNombres[];
    listadoNombres=(char *)malloc(sizeof(char)*cantidadNombres);

    cargarNombres(cantidadNombres,listadoNombres);
    mostrarNombres(cantidadNombres,listadoNombres);

    return 0;
}

void cargarNombres(int cant, char * listadoNombres){
   
    for (int i = 0; i < cant; i++)
    {
        nombre listadoNombres = (char *) malloc(sizeof(char) * 20);
        printf("Ingrese el nombre: ");
        scanf("%s", nombre);

        listadoNombres=nombre;
        listadoNombres++;
    }
    free(nombre);
}

void mostrarNombres(int cant, char *listadoNombres){
    printf("Los nombres ingresados son: \n");
    for (int j = 0; j < cant; j++)
    {
        printf("%s\n", listadoNombres[j]);
    }
    
}