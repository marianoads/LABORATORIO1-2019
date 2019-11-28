#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "LinkedList.h"
#include "Vuelo.h"
#include "Controller.h"
#include "input.h"
#include "parser.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListVuelo)
{

    FILE *data;
    int retorno= -1;
    data=fopen(path,"r");
    if(!parser_VueloFromText(data, pArrayListVuelo))
    {
        retorno = 0;
        printf("\n\n Archivo cargado correctamente \n\n");
    }

    fclose(data);

    return retorno;
}

int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE *pFile;
    pFile = fopen(path,"w");
    int cantidadLetras;
    int cantidadLista = ll_len(pArrayListEmployee);
    if(pFile == NULL)
    {
        printf("\nError al abrir el archivo");
        return 0;
    }
    int i = 0;

    while(i <= cantidadLista)
    {
        Vuelo *p = ll_get(pArrayListEmployee,i);
        if(p != NULL)
        {
            cantidadLetras=fprintf(pFile,"%d,%d,%d,%s,%s,%d,%d,%d\n",p->idVuelo,p->idAvion,p->idPiloto,p->fecha,p->destino,p->cantPasajeros,p->horaDespegue,p->horaLlegada);
        }
        if(cantidadLetras == 0)
        {
            break;
        }
        i++;

    }
    fclose(pFile);
    printf("\n\nLos datos se han filtrado y guardado en el archivo ''datosFiltrados.csv'' \n\n");
    system("pause");

    return 1;
}

int controller_showVuelos(LinkedList* pArrayListVuelo, int sizeList)
{
    Vuelo_showVuelos(pArrayListVuelo, sizeList);

    return 1;
}
