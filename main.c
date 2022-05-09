#include <stdio.h>
#include <stdlib.h>

bool comprueba (int tauler, int filas_usuari, int cols_usuari)
{
    if (tauler[filas_usuari][cols_usuari]==1)//todo esta bien y coincide
    {
        comprueba = true;
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
        intentos++;
    }

}

int main()
{
    int errores = 3;
    int intentos = 0;
    int cols, filas, cols_usuario, filas_usuario;
    comprueba();
    devuelve(intentos);
    return 0;
}
