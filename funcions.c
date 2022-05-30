#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "funcions.h"
#define MAX 100




void dibuja_picross()
{
    printf("___  _ ____ ____  ____ ____ ____");
    printf("\n");
    printf("|__] | |    |__/  |  | [__  [__");
    printf("\n");
    printf("|    | |___ |  \\  |__| ___] ___]");
    printf("\n");
    printf("\n");
}

bool obrir_dades(game_t *p)
{
    FILE* fichero;
    bool abrir = false; //Controlador de si abre bien
    char nom_fitxer[MAX];

    p->filas = 0; //Inicializamos variables
    p->columnas = 0;
    p->errores = 0;
    p->error_play = 0;

    printf("Introdueix el nom del fitxer: ");
    scanf("%s", nom_fitxer);
    fichero = fopen(nom_fitxer, "r");

    if(fichero == NULL)
    {
        printf("\n\tERROR AL OBRIR FITXER\n");
    }

    else
    {
        abrir = true;
        fscanf(fichero, "%d %d %d", &p->filas, &p->columnas, &p->errores);
        printf("Filas: %d Columnas: %d Errores: %d\n", p->filas, p->columnas, p->errores); //Leemos las instrucciones (primera fila archivo)

        /*while (fgets(p->dades[i], 100, fichero) != NULL)
            {
                printf("%s\t", p->dades[i]);
                i++;
            }*/

        for(int i = 0; i < p->filas; i++)
        {
            for(int j = 0; j < p->columnas; j++)
            {
                fscanf(fichero, "%d", &p->dades[i][j]); //Leemos el fichero y lo ponemos en la tabla dades.
            }
        }

    }


    fclose(fichero);

    //Inicializamos tabla cifrada
    for(int i = 0; i < p->filas; i++)
    {
        for(int j = 0; j < p->columnas; j++)
        {
            //system("COLOR 4B");
            p->joc[i][j] = '*';
        }
    }

    return abrir;
}

bool comprovar_num(game_t *p)
{
    bool trobat = false;

    if(p->dades[p->fila_play][p->colum_play] == 1)
    {
        p->joc[p->fila_play][p->colum_play] = p->dades[p->fila_play][p->colum_play];
        trobat = true;
    }

    return trobat;
}

void pedir_entrada(game_t *p)
{
    do
    {
        printf("Quina fila vols emplenar?\n");
        scanf("%d", &p->fila_play);
        if ((p->fila_play>p->filas) || (p->fila_play<1))
            printf("Numero de fila incorrecta\n");
    }while ((p->fila_play>p->filas) || (p->fila_play<1));

    p->fila_play--;

    do
    {
        printf("Quina columna vols emplenar?\n");
        scanf("%d", &p->colum_play);
        if ((p->colum_play>p->columnas) || (p->colum_play<1))
            printf("Numero de columna incorrecta");
    }while ((p->colum_play>p->columnas) || (p->colum_play<1));

    p->colum_play--;

    if(comprovar_num(p))
    {
        printf("Correcte!\n");
        printf("Errors: %d\n", p->error_play);
    }
    else
    {
        printf("Maricon!\n");
        p->error_play++;
        printf("Errors: %d\n", p->error_play);
    }
}

void numeros_tablas(game_t *p)
{
    int ind = p->columnas--;
    bool cond_fila = false; //Booleano para ayudar a contar las casillas a rellenar

    for(int i=0; i<p->filas; i++)
    {
        for(int j=0; j<p->columnas; j++)
        {
            if(p->dades[i][j] == 1)
            {
                p->nums_files[i][ind]++;
                cond_fila = true;
            }
            else if((p->dades[i][j] == 0) && cond_fila)
            {
                ind--;
                cond_fila = false;
            }

        }
        ind = p->columnas--;
    }

    /*for(int i = 0; i < p->filas; i++)
    {
        for(int j = 0; j < p->columnas; j++)
        {
            if(p->nums_files[i][j] != 0)
            {
            printf("%d", p->nums_files[i][j]);
            printf("%c", 179);
            }



        }
        printf("\n");

    }
    printf("\n");*/

    /*for(int i=0; i<p->columnas; i++)
    {
        for(int j=0; j<p->filas; j++)
        {
            if(p->dades[j][i] == 1)
            {
                p->nums_colums[ind][i]++;
                cond_fila = true;
            }
            else if((p->dades[j][i] == 0) && cond_fila)
            {
                ind++;
                cond_fila = false;
            }

        }
        ind = 0;
    }*/
    /*for(int i = 0; i < picross.filas; i++)
    {
        for(int j = 0; j < picross.columnas; j++)
        {
            if(picross.nums_colums[i][j] != 0)
            printf("%d\t", picross.nums_colums[i][j]);

        }
        printf("\n");

    }*/
}

void cifrar_tabla(game_t *p)
{
    /*for(int i = 0; i < p->filas; i++)
    {
        printf("%c", 179);
        for(int j = 0; j < p->columnas; j++)
        {
            //system("COLOR 4B");
            printf(" %d ", p->dades[i][j]);
            printf("%c", 179);

        }

        //printf("%c", 179);
        printf("\n");

    }
    printf("\n");*/

    for(int i = 0; i < p->filas; i++)
    {
        printf("%c", 179);
        for(int j = 0; j < p->columnas; j++)
        {
            printf("%c", p->joc[i][j]);
            printf("%c", 179);

        }

        printf("\n");

    }
    printf("\n");

}
