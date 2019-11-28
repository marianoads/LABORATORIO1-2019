#include <stdio.h>
#include <stdlib.h>
#include "Vuelo.h"
#include "Controller.h"
#include "LinkedList.h"



int main()
{
    LinkedList* pArrayListVuelo = ll_newLinkedList();
    LinkedList* nuevaLista = NULL;
    int cantTotalPasajeros;
    int cantTotalPasajerosIrlanda;
    int opcion;
    int opcion2;
    char seguir = 's';

    while(seguir=='s')
    {
        printf("** PARCIAL 2 ** \n\n1-Cargar archivo\n2-Imprimir vuelos\n3-Cantidad de pasajeros\n4-Cantidad pasajeros a irlanda\n\nElija opcion: ");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            controller_loadFromText("Vuelos.csv", pArrayListVuelo);
            break;

        case 2:
            controller_showVuelos(pArrayListVuelo,ll_len(pArrayListVuelo));

          /*  printf("Ingrese numero de piloto");
            fflush(stdin);
            scanf("%d",&opcion2);
            switch(opcion2){
        case 1:
            nuevaLista=ll_filter(pArrayListVuelo,funcionPilotoUno);
            controller_saveAsText("datosFiltrados.csv", nuevaLista);
            break;
        case 2:
            nuevaLista=ll_filter(pArrayListVuelo,funcionPilotoDos);
            controller_saveAsText("datosFiltrados.csv", nuevaLista);
            break;
        case 3:
            nuevaLista=ll_filter(pArrayListVuelo,funcionPilotoTres);
            controller_saveAsText("datosFiltrados.csv", nuevaLista);
            break;
        case 4:
            nuevaLista=ll_filter(pArrayListVuelo,funcionPilotoCuatro);
            controller_saveAsText("datosFiltrados.csv", nuevaLista);
            break;
            case 5:
            nuevaLista=ll_filter(pArrayListVuelo,funcionPilotoCinco);
            controller_saveAsText("datosFiltrados.csv", nuevaLista);
            break;

            }

*/


            break;
        case 3:
            cantTotalPasajeros=ll_count(pArrayListVuelo,funcionContar);
           printf("\nLa cantidad total de pasajeros es : %d", cantTotalPasajeros);

            break;
        case 4:
            cantTotalPasajerosIrlanda=ll_count(pArrayListVuelo,funcionContarIrlanda);
            printf("\nLa cantidad total de pasajeros es : %d", cantTotalPasajerosIrlanda);
            break;
        default:
            break;
        }
    }






    return 0;
}
