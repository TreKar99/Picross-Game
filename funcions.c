#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "funcions.h"
#define MAX 100



void dibuja_picross()
{

    printf("\t8888888b.  d8b\n");
    printf("\t888   Y88b Y8P\n");
    printf("\t888    888         \n");
    printf("\t888   d88P 888  .d8888b 888d888  .d88b.  .d8888b  .d8888b  \n");
    printf("\t8888888Pb  888 d88Pb    888P    d88..88b 88K      88K      \n");
    printf("\t888        888 888      888     888  888 8Y8888b. bY8888b. \n");
    printf("\t888        888 Y88b.    888     Y88..88P      X88      X88 \n");
    printf("\t888        888  .Y8888P 888      8Y88P8   88888P'  88888P' \n");
    printf("\n\n\n");
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
    p->num_victoria = 0;
    p->aciertos = 0;

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
        fscanf(fichero, "%d%d%d", &p->filas, &p->columnas, &p->errores);
        printf("Filas: %d Columnas: %d Errores: %d\n\n", p->filas, p->columnas, p->errores); //Leemos las instrucciones (primera fila archivo)

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
            p->joc[i][j] = '*';
            if(p->dades[i][j] == 1)
            {
                p->num_victoria++;
            }
        }
    }

    //contamos los numeros

    return abrir;
}

bool comprovar_num_correcte(game_t *p)
{
    bool trobat = false;

    if(p->dades[p->fila_play][p->colum_play] == 1)
    {
        p->joc[p->fila_play][p->colum_play] = 'O';
        p->aciertos++;
        trobat = true;
    }

    return trobat;
}

bool comprovar_num_incorrecte(game_t *p)
{
    bool trobat = false;

    if(p->dades[p->fila_play][p->colum_play] == 0)
    {
        p->joc[p->fila_play][p->colum_play] = 'X';
        trobat = true;
    }

    return trobat;
}

bool num_repetit(game_t *p)
{
    bool repe = false;

    if(p->joc[p->fila_play][p->colum_play] == 'O')
    {
        repe = true;
    }

    return repe;
}

bool num_equivocat_repetit(game_t *p)
{
    bool repe = false;

    if(p->joc[p->fila_play][p->colum_play] == 'X')
    {
        repe = true;
    }

    return repe;
}

void pedir_entrada(game_t *p)
{
    do
    {
        printf("Quina fila vols emplenar?\n");
        scanf("%d", &p->fila_play);
        printf("\n");
        if ((p->fila_play>p->filas) || (p->fila_play<1))
            printf("Numero de fila incorrecta\n");
    }while ((p->fila_play>p->filas) || (p->fila_play<1));

    p->fila_play--;

    do
    {
        printf("Quina columna vols emplenar?\n");
        scanf("%d", &p->colum_play);
        printf("\n");
        if ((p->colum_play>p->columnas) || (p->colum_play<1))
            printf("Numero de columna incorrecta\n");
    }while ((p->colum_play>p->columnas) || (p->colum_play<1));

    p->colum_play--;


    if(num_repetit(p))
    {
        printf("Casilla repetida\n");
        printf("Selecciona otra\n\n");
    }
    else if(comprovar_num_correcte(p))
    {
        printf("Casilla CORRECTA!\n");
        printf("Errors: %d\n\n", p->error_play);
    }
    else if(num_equivocat_repetit(p))
    {
        printf("Casilla elegida repetida\n");
        printf("Selecciona otra\n\n");
    }
    else if(comprovar_num_incorrecte(p))
    {
        printf("Casilla INCORRECTA!\n");
        p->error_play++;
        printf("Errors: %d\n\n", p->error_play);
    }
}

void numeros_tablas(game_t *p)
{
    bool cond_fila = false; //Booleano para ayudar a contar las casillas a rellenar
    int ind = 0;

    //Bucle para sacar los numeros a poner de las filas
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
                ind++;
                cond_fila = false;
            }

        }
        ind = 0;
    }

    //Bucle para contar el numero de las columnas del numero de filas a poner
    ind = 0;
    p->num_columns = 0;
    for(int i = 0; i < p->filas; i++)
    {
        for(int j = 0; j < p->columnas; j++)
        {
            if(p->nums_files[i][j]!=0)
            {
                ind++;
            }
        }
        if(ind>p->num_columns)
        {
            p->num_columns = ind;
        }
        ind = 0;
    }




    //Bucle para sacar los numeros a poner de las columnas
    ind = 0;
    for(int i=0; i<p->columnas; i++)
    {
        for(int j=0; j<p->filas; j++)
        {
            if(p->dades[j][i] == 1)
            {
                p->nums_columns[ind][i]++;
                cond_fila = true;
            }
            else if((p->dades[j][i] == 0) && cond_fila)
            {
                ind++;
                cond_fila = false;
            }

        }
        ind = 0;
    }

    //Bucle para sacar los numeros de columnes de los numeros de las filas a poner
    ind = 0;
    p->num_files = 0;
    for(int i = 0; i < p->filas; i++)
    {
        for(int j = 0; j < p->columnas; j++)
        {
            if(p->nums_columns[j][i]!=0)
            {
                ind++;
            }
        }
        if(ind>p->num_files)
        {
            p->num_files = ind;
        }
        ind = 0;
    }



}

bool victoria(game_t p)
{
    bool win = false;

    if(p.aciertos == p.num_victoria)
        win = true;

    return win;
}

void imprimir_tabla(game_t p)
{


    printf("\n");
    //Imprimir num de 1 en columnas
    for(int i = 0; i < p.num_files; i++)
    {
        for(int j = 0; j < p.num_columns; j++)
        {
            printf("   ");
        }
        for(int j = 0; j < p.columnas; j++)
        {
            printf("\t %d", p.nums_columns[i][j]);

        }
        printf("\n");

    }

    printf("\n");
    for(int i = 0; i < p.filas; i++)
    {
        //Imprimir num de 1 en filas
        for(int j = 0; j < p.num_columns; j++)
        {
            printf(" %d ", p.nums_files[i][j]);
        }

        for(int j = 0; j < p.columnas; j++)
        {

            printf("\t%c%c%c", 179, p.joc[i][j], 179);
        }

        printf("\n\n");
    }
    printf("\n");

}
