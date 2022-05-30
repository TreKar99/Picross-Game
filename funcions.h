#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct{
    int dades[MAX][MAX]; //Datos del juego
    int filas, columnas, errores;
    int fila_play, colum_play, error_play; //Lo que introduce el jugador
    int nums_files[MAX][MAX], nums_colums[MAX][MAX];
    char joc[MAX][MAX];
} game_t;

void dibuja_picross();
bool obrir_dades(game_t *p);
bool comprovar_num(game_t *p);
void pedir_entrada(game_t *p);
void numeros_tablas(game_t *p);
void cifrar_tabla(game_t *p);


