#include <stdio.h>
#include <stdlib.h>
#include "controller.h"
#include "cliente.h"
#include "operador.h"
#include "alquiler.h"
#define MAXIMOCLIENTES 50
#define MAXIMOALQUILERES 100
#define MAXIMOOPERADORES 10

void inicializarClientes(eCliente clientes[], int largo)
{
    for(int i = 0; i < largo; i++)
    {
        clientes[i].estaVacio = 1;
    }
}

void inicializarOperadores(eOperador operadores[], int largo)
{
    for(int i = 0; i < largo; i++)
    {
        operadores[i].estaVacio = 1;
    }
}
void inicializarAlquileres(eAlquiler alquileres[], int largo)
{
    for(int i = 0; i < largo; i++)
    {
        alquileres[i].estaVacio = 1;
    }
}

void harcodearDatos(eOperador operadores[])
{
    operadores[0].id = 101;
    strcpy(operadores[0].nombre, "Juan" );

    operadores[1].id = 102;
    strcpy(operadores[1].nombre, "Marcos" );

    operadores[2].id = 103;
    strcpy(operadores[2].nombre, "Veronica" );

    for(int i = 0 ; i < 3; i++)
    {
        operadores[i].estaVacio = 0;
    }
}

int main()
{
    eCliente clientes[MAXIMOCLIENTES];
    eAlquiler alquileres[MAXIMOALQUILERES];
    eOperador operadores[MAXIMOOPERADORES];
    inicializarClientes(clientes, MAXIMOCLIENTES);
    inicializarAlquileres(alquileres, MAXIMOALQUILERES);
    inicializarOperadores(operadores, MAXIMOOPERADORES);
    harcodearDatos(operadores);
    menuPrincipal(clientes, MAXIMOCLIENTES, alquileres, MAXIMOALQUILERES, operadores, MAXIMOOPERADORES);
    return 0;
}
