#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int filas = 5;
const int columnas = 12;

void promedioGanancias(int *pMatriz);
void maximo(int *pMatriz);
void minimo(int *pMatriz);

int main(){
    srand(time(NULL));
    int *pMatriz = (int *) malloc(sizeof(int*)*filas*columnas);

    printf("La matriz es: \n");
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            *(pMatriz + (i * columnas + j))=rand() %50001 + 10000;
            printf("%d ", *(pMatriz + (i * columnas + j)));
        }
        printf("\n");
    }
    
    printf("Los promedio de las gananacias por anio son: \n");
    promedioGanancias(pMatriz);

    maximo(pMatriz);
    minimo(pMatriz);
    return 0;
}

void promedioGanancias(int *pMatriz){
    
    for (int i = 0; i < filas; i++)
    {
        int resultado=0,acumulado=0;

        for (int j = 0; j < columnas; j++)
        {
            acumulado+=*(pMatriz + (i * columnas + j));
            resultado=acumulado/12;
        }
        printf("%d", resultado);
        printf("\n");
    }

}

void maximo(int *pMatriz){

int anio, mes, maximo =0;

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            if (*(pMatriz + (i * columnas + j)) > maximo)
            {
                maximo = *(pMatriz + (i * columnas + j));
                anio=i;
                mes=j;
            }
        }
    }
        printf("El valor maximo es: %d, y ocurrio en el anio %d y el mes %d", maximo, anio+1, mes+1);
        printf("\n");

}

void minimo(int *pMatriz){
    int anio,mes,minimo=50000;

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            if (*(pMatriz + (i * columnas + j)) < minimo)
            {
                minimo = *(pMatriz + (i * columnas + j));
                anio=i;
                mes=j;
            }
        }
    }
        printf("El valor minimo es: %d, y ocurrio en el anio %d y el mes %d", minimo, anio+1, mes+1);
        printf("\n");
}