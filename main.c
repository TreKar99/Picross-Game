#include <stdio.h>
#include <stdlib.h>
#include "funcions.h"
#define MAX 100
#define ROJO_F     "\x1b[41m"




int main()
{
    game_t picross;
    dibuja_picross();

    if(obrir_dades(&picross))
    {
        do
        {
            cifrar_tabla(&picross);
            pedir_entrada(&picross);
        } while(picross.error_play<picross.errores);
        //numeros_tablas(&picross);
    }


    return 0;
}
