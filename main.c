#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/**
* @brief Accio que demana pel teclat les coordenades a emplenar de la taula
* @param errores (E) El máximo de errores permitido
* @param filas (E) El número de filas de la tabla
* @param cols (E) El número de columnas de la tabla
* @param filas_usuari (E) El número de filas de la tabla
* @param cols_usuari (E) El número de columnas de la tabla
*/
void demana_coordenades (int intents, int cols, int filas, int filas_usuari, int cols_usuari, int errores) //struct por referencia
{
    errores=3;
    intents=4;
    cols, filas=5;
    if(intents>errores)
    {
        do
        {
            printf("Quina fila vols emplenar?");
            scanf("%d", &filas_usuari);
            printf("Quina columna vols emplenar?");
            scanf("%d", &cols_usuari);
            if (filas_usuari>filas)
            {
                printf("Tria un altre fila");
            }
            if(cols_usuari>cols)
            {
                printf("Tria un altre columna");
            }
        }while((filas_usuari>filas)&&(cols_usuari>cols));
    }
    else
    {
        printf("Intents esgotats");
    }
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
    int errores,  cols,  filas,  filas_usuari, cols_usuari,indice;
    demana_coordenades(errores, cols, filas, filas_usuari, cols_usuari, indice);
}
