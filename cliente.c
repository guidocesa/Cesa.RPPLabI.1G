#include "cliente.h"

void obtenerNombreCliente(char* nombreCliente,eCliente clientes[],int largoClientes, int idCliente)
{
    int encontrado = 0;
    int i =0;
    while(!clientes[i].estaVacio && !encontrado && i < largoClientes)
    {
        if(clientes[i].id == idCliente)
        {
            strcpy(nombreCliente, clientes[i].nombre);
            encontrado = 1;
        }
        i++;
    }
}
