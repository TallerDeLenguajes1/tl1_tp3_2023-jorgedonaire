#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char *V[5];
    char *nombre;

    for (int i = 0; i < 5; i++)
    {
        nombre = (char *) malloc(sizeof(char) * 20);
        printf("Ingrese el nombre: ");
        scanf("%s", nombre);
        V[i]=nombre;
    }
    printf("Los nombres ingresados son: \n");
    
    for (int j = 0; j < 5; j++)
    {
        printf("%s\n", V[j]);
    }
    
    free(nombre);
    return 0;
}