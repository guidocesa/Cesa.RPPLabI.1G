#include "operador.h"

void obtenerNombreOperador(char* nombreOperador,eOperador operadores[],int largoOperadores, int idOperador)
{
    int encontrado = 0;
    int i =0;
    while(!operadores[i].estaVacio && !encontrado && i < largoOperadores)
    {
        if(operadores[i].id == idOperador)
        {
            strcpy(nombreOperador, operadores[i].nombre);
            encontrado = 1;
        }
        i++;
    }
}
