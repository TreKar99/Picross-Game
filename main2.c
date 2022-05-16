#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_F 100
#define MAX_C 100
/**
 * @brief Retorna una boolea si l'usuari ha guanyat el joc
* @param contador (E) Quantitat de caselles que son correctes
* @param contador (E) Quantitat de caselles correcets del jugador
*/
 bool guanyador(int contador, int cont)
 {
     bool ganador=false;
     if(cont==contador)
     {
         ganador=true;
     }
     return(ganador);
 }
/**
 * @brief Comprova el resultats
* @param tauler (E) Tauler donat per a comprovar els resultats
* @param filas_usuari (E) El número de filas de la tabla
* @param cols_usuari (E) El número de columnas de la tabla
 * @param comprueba (E/S) booleà que retorna cert si coincideix i fals altrament.
 */
 bool comprueba (int tauler[MAX_F][MAX_C], int filas_usuari, int cols_usuari, int cont, int errores, int intents)
{
    bool comprueba=false;
    if (tauler[filas_usuari][cols_usuari]==1)//todo esta bien y coincide
    {
        comprueba = true;
        cont++;
    }
    else
    {
        comprueba = false;
        errores++;
        intents--;
    }
    return comprueba;
}
/**
* @brief Accio que demana pel teclat les files del usuari a emplenar de la taula
* @param errores (E) El máximo de errores permitido
* @param intents (E) El máximo de intentos permitido
* @param filas (S) El número de filas de la tabla
* @param filas_usuari (S) El número de la fila de l'usuario de la tabla
*/
void demana_filas(int intents, int filas, int filas_usuari, int errores) //struct por referencia
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
* @brief Accio que demana pel teclat les columnes del usuari a emplenar de la taula
* @param errores (E) El máximo de errores permitido
* @param intents (E) El máximo de intentos permitido
* @param cols (S) El número de columnas de la tabla
* @param cols_usuari (S) El número de la columna de l'usuario de la tabla
*/
void demana_columna (int intents, int cols, int cols_usuari, int errores) //struct por referencia
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
int main()
{
    printf("___  _ ____ ____  ____ ____ ____");
    printf("\n");
    printf("|__] | |    |__/  |  | [__  [__");
    printf("\n");
    printf("|    | |___ |  \\  |__| ___] ___]");
    printf("\n");
    printf("\n");

    int errores, cols, filas, filas_usuari, cols_usuari, intents, cont, contador, tauler[MAX_F][MAX_C];
    cols=5;
    filas=5;
    errores=3;
    intents=4;
    bool ganador=false;
    while((intents>0)&&(!ganador))
    {
        demana_filas(errores, filas, filas_usuari, intents);
        demana_columna(errores, cols, cols_usuari, intents);
        comprueba (tauler,filas_usuari, cols_usuari, cont, errores, intents);
        ganador=guanyador(cont, contador);
        if(intents>1 && !ganador)
        {
            printf("Et queden %d intents",intents);
        }
        else if(intents==1 && !ganador)
        {
            printf("Et queda %d intent",intents);
        }
    }
    printf("Intents esgotats");
}



