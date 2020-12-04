#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "operador.h"
#include "alquiler.h"
#define AMOLADORA 1
#define MEZCLADORA 2
#define TALADRO 3

int solicitarDatosYAgregarCliente(eCliente clientes[], int largoClientes, int idAcumulativo)
{
    char nombre[31];
    char apellido[31];
    int dni;
    int clienteAgregado=0;

    system("cls");
    printf("Por favor ingrese el Nombre del cliente nuevo y luego la tecla enter. \n\n");
    fflush(stdin);
    gets(nombre);

    system("cls");
    printf("Por favor ingrese el Apellido del cliente nuevo y luego la tecla enter. \n\n");
    fflush(stdin);
    gets(apellido);

    do
    {
        system("cls");
        printf("Por favor ingrese el dni del cliente nuevo seguido de la tecla enter. \n\n");
        scanf("%d" , &dni);
    }while(dni < 1000000 || dni > 100000000);

    int i = 0;
    while(!clientes[i].estaVacio && i<largoClientes)
    {
        i++;

    }
    if(clientes[i].estaVacio)
    {
        clientes[i].dni = dni;
        clientes[i].id = idAcumulativo;
        clientes[i].estaVacio = 0;
        clientes[i].habilitado = 1;
        strcpy(clientes[i].nombre, nombre);
        strcpy(clientes[i].apellido, apellido);
        clienteAgregado = 1;
    }

    return clienteAgregado;
}


int mostrarOpcionesYObtenerSeleccion()
{
    int seleccion;
    int seleccionEsCorrecta = 0;

    while(!seleccionEsCorrecta)
    {

        system("cls");
        printf("Por favor seleccione una opcion y presione la tecla enter: \n\n");
        printf("1 - Dar de ALTA un Cliente.\n");
        printf("2 - Modificar datos de un cliente. \n");
        printf("3 - Dar de BAJA un cliente. \n");
        printf("4 - Dar de ALTA un nuevo alquiler.\n");
        printf("5 - Finalizar un alquiler. \n");
        printf("6 - Mostrar menu de informes. \n");
        printf("0 - Salir de la base de datos. \n");

        fflush(stdin);

        scanf("%i" , &seleccion );

        if(seleccion < 7 && seleccion > -1)
        {
            seleccionEsCorrecta = 1;
        }
    }

    return seleccion;
}

int mostrarMenuModificacion()
{
    int seleccion;
    do
    {
        system("cls");
        printf("Seleccione que desea modificar:\n\n1. Nombre\n2. Apellido\n3. DNI\n");
        fflush(stdin);
        scanf("%i", &seleccion);
    }while(seleccion < 1 || seleccion > 3);

    return seleccion;
}

void imprimirCliente(eCliente cliente)
{
    printf("%i\t%s\t\t%s\t\t%i\t", cliente.id, cliente.nombre, cliente.apellido, cliente.dni);
    if(cliente.habilitado)
    {
        printf("SI\n");
    }
    else
    {
        printf("NO\n");
    }
}

void listarClientes(eCliente clientes[], int largoClientes)
{
    int i = 0;
    printf("ID\tNOMBRE\t\tAPELLIDO\t\tDNI\t\tHABILITADO\n");
    printf("----------------------------------------------------------------\n");
    while(!clientes[i].estaVacio && i < largoClientes)
    {
        imprimirCliente(clientes[i]);
        i++;
    }
}

int darDeBajaCliente(eCliente clientes[], int largoClientes)
{
    system("cls");
    int idAModificar;
    int idEncontrado = 0;
    int i = 0;
    printf("Por favor ingrese el numero de ID del cliente a modificar seguido de la tecla enter.\n");
    listarClientes(clientes, largoClientes);
    printf("\n\n");
    fflush(stdin);
    scanf("%i", &idAModificar);

    while(!idEncontrado && !clientes[i].estaVacio && i < largoClientes)
    {
        if(clientes[i].id == idAModificar)
        {
            idEncontrado = 1;
        }
        i++;
    }
    i--;

    if(idEncontrado)
    {
        clientes[i].habilitado = 0;
    }
    else
    {
        printf("No se encontro un cliente con ese ID, por favor checkee el listado.\n\n");
    }

    return idEncontrado;
}

int modificarDatosDelCliente(eCliente clientes[], int largoClientes)
{
    system("cls");
    int idAModificar;
    int idEncontrado = 0;
    int i = 0;
    int clienteModificado = 0;

    printf("Por favor ingrese el numero de ID del cliente a modificar seguido de la tecla enter.\n");
    listarClientes(clientes, largoClientes);
    printf("\n\n");
    fflush(stdin);
    scanf("%i", &idAModificar);

    while(!idEncontrado && !clientes[i].estaVacio && i < largoClientes)
    {
        if(clientes[i].id == idAModificar)
        {
            idEncontrado = 1;
        }
        i++;
    }
    i--;

    if(idEncontrado)
    {
        int dniNuevo;
        char nombreNuevo[31];
        char apellidoNuevo[31];

        int seleccion = mostrarMenuModificacion();
        eCliente aux = clientes[i];
        switch(seleccion)
        {
            case 1:

                system("cls");
                printf("Por favor ingrese el nuevo Nombre del cliente y luego la tecla enter. \n\n");
                fflush(stdin);
                gets(nombreNuevo);
                strcpy(aux.nombre, nombreNuevo);
                break;

            case 2:

                system("cls");
                printf("Por favor ingrese el nuevo Apellido del cliente y luego la tecla enter. \n\n");
                fflush(stdin);
                gets(apellidoNuevo);
                strcpy(aux.apellido, apellidoNuevo);
                break;

            case 3:

                do
                {
                    system("cls");
                    printf("Por favor ingrese el nuevo DNI del cliente seguido de la tecla enter. \n\n");
                    fflush(stdin);
                    scanf("%i" , &dniNuevo);
                }while(dniNuevo < 1000000 || dniNuevo > 100000000);
                aux.dni = dniNuevo;
                break;
        }
        clientes[i] = aux;
        clienteModificado = 1;

    }
    else
    {
        printf("No se pudo encontrar un cliente con ese Id, por favor confirme que sea el correcto.");
        system("pause");
    }

    return clienteModificado;
}

void listarOperadores(eOperador operadores[], int largo)
{
    int i =0;
    printf("\nID\tNOMBRE\n\n");

    while(!operadores[i].estaVacio)
    {
        printf("%i\t%s\n", operadores[i].id, operadores[i].nombre);
        i++;
    }
}

void imprimirAlquiler(eAlquiler alquiler,  eCliente clientes[], int largoClientes, eOperador operadores[], int largoOperadores)
{
    char nombreCliente[31];
    char nombreOperador[31];

    obtenerNombreCliente(nombreCliente, clientes, largoClientes,  alquiler.idCliente);
    obtenerNombreOperador(nombreOperador, operadores, largoOperadores, alquiler.idOperador);

    printf("%i\t%s\t\t", alquiler.id, nombreCliente);
    switch(alquiler.equipo)
    {
    case AMOLADORA:
        printf("Amoladora\t");
        break;
    case MEZCLADORA:
        printf("Mezcladora\t");
        break;
    case TALADRO:
        printf("Taladro\t");
        break;
    }
    printf("%i\t\t%s\t", alquiler.tiempoAlquilerEstimado, nombreOperador);
    if(alquiler.estaAlquilado)
    {
        printf("ALQUILADO\n");
    }
    else
    {
        printf("FINALIZADO\n");
    }
}

void listarAlquileres(eAlquiler alquileres[], int largoAlquileres, eCliente clientes[], int largoClientes, eOperador operadores[], int largoOperadores)
{
    printf("ID\tCLIENTE\t\tEQUIPO\t\tTIEMPO EST.\t\tOPERADOR\tESTADO\n");
    printf("----------------------------------------------------------------");
    int i =0;
    while(!alquileres[i].estaVacio)
    {
        imprimirAlquiler(alquileres[i], clientes, largoClientes, operadores, largoOperadores);
        i++;
    }
}

int finalizarAlquiler(eCliente clientes[], int largoClientes, eAlquiler alquileres[], int largoAlquileres, int idAlquileres, eOperador operadores[], int largoOperadores)
{
    int idAlquilerSeleccionado, diasDeAlquiler, cargaExitosa = 0;
    do
    {
        system("cls");
        listarAlquileres(alquileres, largoAlquileres, clientes, largoClientes, operadores, largoOperadores);
        printf("\nPor favor ingrese un ID de un alquiler de la lista\n");
        scanf("%i", &idAlquilerSeleccionado);
    }while(idAlquilerSeleccionado < 0 || idAlquilerSeleccionado > idAlquileres);

    if(alquileres[idAlquilerSeleccionado].estaAlquilado)
    {
        do
        {
            system("cls");
            printf("Por favor ingrese los dias reales de alquiler.\n");
            fflush(stdin);
            scanf("%i", &diasDeAlquiler );
        }while(diasDeAlquiler < 1 || diasDeAlquiler > 365);

        alquileres[idAlquilerSeleccionado].tiempoRealAlquiler = diasDeAlquiler;
        alquileres[idAlquilerSeleccionado].estaAlquilado = 0;
        printf("Carga exitosa.");
        cargaExitosa = 1;

    }
    else
    {
        printf("Ese alquiler ya ha finalizado.");
    }
    system("pause");
    return cargaExitosa;
}

int altaAlquiler(eCliente clientes[], int largoClientes, eAlquiler alquileres[], int largoAlquileres, int idAlquileres, eOperador operadores[], int largoOperadores)
{
    system("cls");
    int idcliente, equipoSeleccionado, diasDeAlquiler, idOperador;
    int idEncontrado = 0;
    int i = 0;

    printf("Por favor ingrese el numero de ID del cliente que realizara el alquiler seguido de la tecla enter.\n");
    listarClientes(clientes, largoClientes);
    printf("\n\n");
    fflush(stdin);
    scanf("%i", &idcliente);

    while(!idEncontrado && !clientes[i].estaVacio && i < largoClientes)
    {
        if(clientes[i].id == idcliente)
        {
            idEncontrado = 1;
        }
        i++;
    }
    i--;

    if(idEncontrado && clientes[i].habilitado && idAlquileres < largoAlquileres)
    {
        do
        {
            system("cls");
            printf("Seleccione que equipo va a alquilar:\n\n1. Amoladora\n2. Mezcladora\n3. Taladro");
            fflush(stdin);
            scanf("%i", &equipoSeleccionado );
        }while(equipoSeleccionado < 1 || equipoSeleccionado > 3);

        do
        {
            system("cls");
            printf("Ingrese el periodo estimado en dias del alquiler. (Maximo 365 dias)\n");
            fflush(stdin);
            scanf("%i", &diasDeAlquiler );
        }while(diasDeAlquiler < 1 || diasDeAlquiler > 365);

        do
        {
            system("cls");
            printf("Ingrese su ID de operador.\n");
            listarOperadores(operadores, largoOperadores);
            fflush(stdin);
            scanf("%i", &idOperador );
        }while(idOperador < 101 || idOperador > 103); //Esto esta "mal hecho" ya que no contempra agregar operadores

        alquileres[idAlquileres].equipo = equipoSeleccionado;
        alquileres[idAlquileres].idOperador = idOperador;
        alquileres[idAlquileres].estaAlquilado = 1;
        alquileres[idAlquileres].tiempoAlquilerEstimado = diasDeAlquiler;
        alquileres[idAlquileres].idCliente = idcliente;
        alquileres[idAlquileres].id = idAlquileres;
        alquileres[idAlquileres].estaVacio = 0;

    }
    else
    {
        printf("Ese ID no se encuentra en el listado o no esta habilitado, por favor checkee.\n\n");
        system("pause");
    }

    return idEncontrado;
}

void mostrarClienteConMasAlquileres(eCliente clientes[], int largoClientes, eAlquiler alquileres[], int largoAlquileres,int idAcumulativoAlquileres, eOperador operadores[], int largoOperadores)
{
    int i = 0;
    int contadorAlquileres[largoClientes];

    int x = 0;

    while( i < largoClientes)
    {
        contadorAlquileres[i] = 0;
        i++;
    }


    while(!alquileres[x].estaVacio && x < largoAlquileres)
    {
        contadorAlquileres[alquileres[x].idCliente] = ( contadorAlquileres[alquileres[x].idCliente] + 1) ;
        x++;
    }

    int mayorCantidad;
    int primeraPasada = 1;

    for(int u = 0; u < largoClientes ; u++)
    {
        if(primeraPasada || mayorCantidad < contadorAlquileres[u])
        {
            mayorCantidad = contadorAlquileres[u];
            primeraPasada = 0;
        }
    }
    system("cls");
    printf("El/Los clientes con mayor cantidad de alquileres son: \n\n");

    for(int j = 0; j < i ; j++)
    {
        if(mayorCantidad == contadorAlquileres[j])
        {
            printf("%s %s : %i\n", clientes[j].nombre, clientes[j].apellido, mayorCantidad);
        }
    }

    system("pause");
}

void mostrarEquipoMasAlquilado(eAlquiler alquileres[], int largoAlquileres,int idAcumulativoAlquileres)
{
    int i =0;
    int contadorEquipos[3];

    contadorEquipos[0] = 0;
    contadorEquipos[1] = 0;
    contadorEquipos[2] = 0;

    while(!alquileres[i].estaVacio)
    {
        contadorEquipos[alquileres[i].equipo] = (contadorEquipos[alquileres[i].equipo] + 1);
        i++;
    }

    int mayorCantidad;
    int primeraPasada = 1;

    for(int u = 0; u < 3 ; u++)
    {
        if(primeraPasada || mayorCantidad < contadorEquipos[u])
        {
            mayorCantidad = contadorEquipos[u];
            primeraPasada = 0;
        }
    }

    system("cls");
    printf("El/Los equipo con mayor cantidad de alquileres son: \n\n");

    for(int j = 0; j < i ; j++)
    {
        if(mayorCantidad == contadorEquipos[j])
        {
            switch(j + 1)
            {
            case AMOLADORA:
                printf("Amoladora\t");
                break;
            case MEZCLADORA:
                printf("Mezcladora\t");
                break;
            case TALADRO:
                printf("Taladro\t");
                break;
            }
            printf(" : %i\n", mayorCantidad);
        }
    }
    system("pause");
}

int obtenerSeleccionInformes()
{
    int seleccion;
    do{
    printf("Por favor selecciones que informe desea ver:\n\n1. Cliente con mas alquileres\n2. Equipo mas alquilado\n3. Promedio del tiempo real de los quipos\n4. Todos los alquileres.\n\n");
    scanf("%i", &seleccion);
    }while(seleccion > 4 || seleccion < 1);

    return seleccion;

}

void mostrarPromedioAlquilerReal(eAlquiler alquileres[], int largoAlquileres)
{
    int contador = 0;
    int i =0;
    int total = 0;
    while(!alquileres[i].estaVacio)
    {
        if(!alquileres[i].estaAlquilado)
        {
            total = (total + alquileres[i].tiempoRealAlquiler);
            contador++;
        }
        i++;
    }

    printf("aca");
    system("pause");
    if(contador > 0)
    {
        float promedio = (float) (total / contador);
        system("cls");
        printf("El tiempo promedio de alquiler en dias es de: %f\n\n", promedio );
        system("pause");
    }
}

int menuInformes(eCliente clientes[], int largoClientes, eAlquiler alquileres[], int largoAlquileres,int idAcumulativoAlquileres, eOperador operadores[], int largoOperadores)
{
    int seleccion = obtenerSeleccionInformes();

    switch(seleccion)
    {
    case 1:
        mostrarClienteConMasAlquileres(clientes, largoClientes, alquileres, largoAlquileres, idAcumulativoAlquileres, operadores, largoOperadores);
        break;
    case 2:
        mostrarEquipoMasAlquilado(alquileres, largoAlquileres, idAcumulativoAlquileres);
        break;
    case 3:
        mostrarPromedioAlquilerReal(alquileres, largoAlquileres);
        break;
    case 4:
        listarAlquileres(alquileres, largoAlquileres, clientes, largoClientes, operadores, largoOperadores);
        break;
    }
    return 0;
}

int menuPrincipal(eCliente clientes[], int largoClientes, eAlquiler alquileres[], int largoAlquileres, eOperador operadores[], int largoOperadores)
{
    int opcionSeleccionada;
    int idAcumulativoClientes = 0;
    int idAcumulativoAlquileres = 0;

    do
    {
        opcionSeleccionada = mostrarOpcionesYObtenerSeleccion();
        switch(opcionSeleccionada)
        {
        case 1:
            if(solicitarDatosYAgregarCliente(clientes, largoClientes, idAcumulativoClientes))
            {
                idAcumulativoClientes++;
            }
            break;
        case 2:
            modificarDatosDelCliente(clientes, largoClientes);
            break;
        case 3:
            darDeBajaCliente(clientes, largoClientes);
            break;
        case 4:
            if(altaAlquiler(clientes, largoClientes, alquileres, largoAlquileres, idAcumulativoAlquileres, operadores, largoOperadores))
            {
                idAcumulativoAlquileres++;
            }
            break;
        case 5:
            finalizarAlquiler(clientes, largoClientes, alquileres, largoAlquileres, idAcumulativoAlquileres, operadores, largoOperadores);
            break;
        case 6:
            menuInformes(clientes, largoClientes, alquileres, largoAlquileres, idAcumulativoAlquileres, operadores, largoOperadores);
            break;
        case 0:
            break;
        }
    }while(opcionSeleccionada != 0);
}
