#include <stdio.h>
#include <stdlib.h>
#include "funcions.h"

int main()
{
    system("color A"); //Poner letras de color verde
    game_t picross;
    dibuja_picross();

    if(obrir_dades(&picross))
    {
        numeros_tablas(&picross); //Calcular los numeros de las tablas
        do
        {
            imprimir_tabla(picross);
            system("pause");
            system("cls"); //Limpiar pantalla
            pedir_entrada(&picross);

        } while((picross.error_play<picross.errores) && !victoria(picross));

        if(victoria(picross))
        {
            printf("GANADORRRRRRRR\n");
        }
        else
            printf("GAME OVER\n");
    }

    return 0;
}
