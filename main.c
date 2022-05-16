#include <stdio.h>
#include <stdlib.h>
#define MAX 15

void instruccions()
{
    printf("Hola! Benvingut al joc del Picross, es tracta d'un joc de puzzle on veuras\n");
    printf("una cuadricula amb numeros a la part superior i al lateral esquerre, aquests\n");
    printf("numeros tindicaran les caselles a emplenar. L'objectiu es emplenar els cuadres\n");
    printf("correctes per trobar la imatge oculta, tenint en compte els numeros abans esmenats.")
}
void abrir_archivo();
void generar_tabla();
void generar_filas(int filas);
void generar_columnas(int columnas);
void imprime_tablero_solucion();
void demana_coordenades();
bool columna_incorrecta();
bool fila_incorrecta();
void mostrar_intents(errors)
{
    printf("Et queden %d errors", errors);
}
bool guanyador (int contador, int cont)
{
    if (contador == cont) //si el numero de casillas correctas coincide con las casillas correctas del jugador
    {
        guanyador=true; //este gana
    }
}

bool comprueba (int tauler, int filas_usuari, int cols_usuari)
{
    if (tauler[filas_usuari][cols_usuari]==1) //si todo esta bien y coincide
    {
        comprueba = true;
        cont++;
    }
    else
    {
        comprueba = false;
    }
    return comprueba;
}

void devuelve (int intentos)
{
    if (comprueba==true)
    {
        imprime_tablero_solución;
    }
    else
    {
        imprime_tablero_solución;
        errores++;
        intentos--;
    }
}
int contador()
{
    for(tauler[i][j]=0; i<MAX; i++)
    {
        for(tauler[i][j]=0; j<MAX; j++)
        {
            if(tauler[i][j]==1)
            {
                contador++;
            }
        }
    }
}

void felicitacion ()
{
    printf("¡Felicidades amigo! ¡Ganaste la partida! Y te quedaron %d intentos", intentos);
}

void mostrar_intents()
{
    printf("Te quedan %d intentos", intentos);
}

void despedir()
{
    printf("¡Que mal! ¡¡¡Te quedaste sin intentos!!! ¡Adios!");
}



int main()
{
    //Definimos las variables
    int filas, columnas;
    int intentos = 3;
    //Comenzamos la ejecución del programa
    instruccions();
    abrir_archivo;
    while (intentos>0 && !guanyador)
    {
        if (guanyador == true)
        {
        felicitacion();
        }
        else
        {

        }
    }
    if (intentos == 0)
    {
        despedir();
    }

    return 0;
}

