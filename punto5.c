#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(){
    char **V;
    char *nombre;
    int cantidad;

    printf("Ingrese la cantidad de nombres: ");
    scanf("%d", &cantidad);

    //reserva dinamica para el vector

    V = (char **) malloc(sizeof(char *)*cantidad);

    //carga de nombres

    for (int i = 0; i < cantidad; i++)
    {
        nombre = (char *) malloc(sizeof(char) * 20);
        printf("Ingrese el nombre: ");
        scanf("%s", nombre);
        V[i]=nombre;
    }

    printf("Los nombres ingresados son: \n");
    
    for (int j = 0; j < cantidad; j++)
    {
        printf("%s\n", V[j]);
    }
    
    //liberar memoria dinamica
    for (int i = 0; i < cantidad; i++)
    {
        free(nombre);
    }
    
    free(V);

    return 0;
}
