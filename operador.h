#ifndef OPERADOR_H_INCLUDED
#define OPERADOR_H_INCLUDED

typedef struct
{
    int id;
    char nombre[31];
    int estaVacio;
}eOperador;

void obtenerNombreOperador(char* nombreOperador,eOperador operadores[],int largoOperadores, int idOperador);

#endif // OPERADOR_H_INCLUDED
