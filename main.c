/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#define MAX 100
int main()
{
    int filas = 0, columnas = 0, errores = 0;
    int i = 0, j = 0;
    int tabla[MAX][MAX];
    FILE* fichero;
    fichero = fopen("ejemplo numeros.txt", "r");
    
    if(fichero == NULL)
    {
        printf("Error\n");
    }
    
    
    fscanf(fichero, "%d %d %d", &filas, &columnas, &errores);
    printf("Filas: %d\t Columnas: %d\t Errores: %d\t\n", filas, columnas, errores);
    
    for(i = 0; i < filas; i++)
    {
        for(j = 0; j < columnas; j++)
        {
        fscanf(fichero, "%d", &tabla[i][j]);
        printf("%d\t", tabla[i][j]);
        }
        printf("\n");
    }
    
    
    fclose(fichero);
    
    ////////////
    /*int numeros_maximos = 0, contador = 0;
    int indice = 0;
    
    numeros_maximos = (filas/2) + 1;
    printf("%d\n", numeros_maximos);
    
    int tabla_columnas[filas][numeros_maximos-1]; //Definimos tabla que dice cuantos numeros poner;

    for(i = 0; i < filas; i++)
    {
        contador = 0;
        for(j = 0; j < columnas; j++)
        {
            /*contador = 0;
            while(tabla[i][j] == 1)
            {
                contador++;
                j++;
            }
            tabla_numeros_maximos1[indice1][indice2] = contador;
            indice2++;*/
            /*if(tabla[i][j] == 1)
            {
                contador++;
            }
            else if (contador > 0)
            {
                tabla_columnas[filas][indice] = contador;
                contador = 0;
                indice++;

            }
        }
        if(contador >0)
        {
        tabla_columnas[i][indice] = contador;
        contador = 0;
        indice = 0;
        }
    }
    
    for(i = 0; i < filas; i++)
    {
        for(j = 0; j < numeros_maximos; j++)
        {
        printf("%d\t", tabla_columnas[i][j]);
        }
        printf("\n");
    }*/
    

}
