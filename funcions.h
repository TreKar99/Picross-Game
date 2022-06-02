#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct{
    int dades[MAX][MAX]; //Datos del juego
    int filas, columnas, errores;
    int fila_play, colum_play, error_play; //Lo que introduce el jugador
    int nums_files[MAX][MAX], nums_columns[MAX][MAX]; //Tablas de numeros a introducir
    int num_files, num_columns; //Auxiliar para hacer bien las tablas de numeros a introducir
    int aciertos, num_victoria; //Nums 1 acertados y unos para ganar
    char joc[MAX][MAX];

} game_t;

/** \brief Dibuja ascii art de la palabra Picross
 *
 */
void dibuja_picross();

/** \brief Pone los datos en un fichero e inicializa la tabla
 *
 * \param p El conjunt a posar dades
 * \return true Se abrio bien el archivo
 * \return false Se abrio mal
 */
bool obrir_dades(game_t *p);

/** \brief Comprobar que aciertas una posición
 *
 * \param p El conjunto a comprobar el numero correcto
 * \return false Si el numero es incorrecto
 * \return true Si el numero es correcto
 */
bool comprovar_num(game_t *p);

/** \brief Poner el numero incorrecto a X
 *
 * \param p Conjunto a comprobar numero incorrecto
 * \return false Num no incorrecto
 * \return true Num correcto
 */
bool comprovar_num_incorrecte(game_t *p);

/** \brief Comprueba si la casilla acertada se repite con la entrada
 *
 * \param p Conjunto a comprobar
 * \return false numero no repetido
 * \return true numero repetido
 */
bool num_repetit(game_t *p);

/** \brief Comprueba si la casilla erronea se repite con la entrada
 *
 * \param p Conjunto a analizar
 * \return false numero no repetido
 * \return true numero repetido
 */
bool num_equivocat_repetit(game_t *p);

/** \brief Pide la entrada de la fila y columna para la casilla del jugador
 *
 * \param p conjunto donde volcamos los datos
 *
 */
void pedir_entrada(game_t *p);

/** \brief Genera las tablas que indican las casillas que hay que acertar
 *
 * \param p Conjunto donde se vuelcan los datos
 *
 */
void numeros_tablas(game_t *p);

/** \brief Comprueba si has ganado
 *
 * \param p Conjunto miramos si el numero de aciertos es el maximo
 * \return false no has ganado
 * \return true has ganado
 */
bool victoria(game_t p);

/** \brief Imprime la situacion del juego
 *
 * \param p Conjunto donde esta la tabla del juego
 *
 */
void imprimir_tabla(game_t p);


