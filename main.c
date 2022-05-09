#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/**
* @brief Accio que demana pel teclat les columnes del usuari a emplenar de la taula
* @param errores (E) El máximo de errores permitido
* @param intents (E) El máximo de intentos permitido
* @param cols (S) El número de columnas de la tabla
* @param cols_usuari (S) El número de la columna de l'usuario de la tabla
*/
void demana_columna (int intents, int cols, int filas, int filas_usuari, int cols_usuari, int errores) //struct por referencia
{
    do
    {
        printf("Quina columna vols emplenar?");
        printf("\n");
        scanf("%d", &cols_usuari);
        if (cols_usuari>cols)
        {
            printf("Tria un altre columna");
            printf("\n");
        }
    }while(cols_usuari>cols);
}
/**
* @brief Accio que demana pel teclat les columnes del usuari a emplenar de la taula
* @param errores (E) El máximo de errores permitido
* @param intents (E) El máximo de intentos permitido
* @param filas (S) El número de filas de la tabla
* @param filas_usuari (S) El número de la fila de l'usuario de la tabla
*/
void demana_filas(int intents, int cols, int filas, int filas_usuari, int cols_usuari, int errores) //struct por referencia
{
    do
    {
        printf("Quina fila vols emplenar?");
        printf("\n");
        scanf("%d", &filas_usuari);
        if (filas_usuari>filas)
        {
            printf("Tria un altre fila");
            printf("\n");
        }
    }while(filas_usuari>filas);
}    
    
/**
 * @brief Accio a fer si el número es passa de columna
* @return bool que indica si la columna del usuario es igual al del tablero
 */
bool columna_incorrecta(n_columnes);

/**
 * @brief Accio a fer si el número es passa de fila
 * @return bool que indica si la fila del usuario es igual al del tablero
 */
bool fila_incorrecta(n_files);


int main()
{
    int errores, cols, filas, filas_usuari, cols_usuari, intents;
    cols=5;
    filas=5;
    errores=3;
    intents=4;
    if(intents>errores)
    {
        demana_columna(errores, cols, filas, filas_usuari, cols_usuari, intents);
        demana_filas(errores, cols, filas, filas_usuari, cols_usuari, intents);
    }
     else
    {
        printf("Intents esgotats");
    }
}
