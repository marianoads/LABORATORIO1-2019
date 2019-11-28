#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Vuelo.h"


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_VueloFromText(FILE* pFile, LinkedList* pArrayListVuelo)
{

    //validaciones acá! o al contructor con parametros ya que deberia validar desde ahí!
    Vuelo* pVuelo;
    char bufferID_Vuelo[100];
    char bufferID_Avion[100];
    char bufferID_Piloto[100];
    char bufferFecha[100];
    char bufferDestino[100];
    char bufferCantPasajeros[100];
    char bufferHoraDespegue[100];
    char bufferHoraLlegada[100];


    int retorno = -1;

    if(pFile != NULL)
    {


        while(!feof(pFile))
        {


            fscanf(pFile, "%[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]\n", bufferID_Vuelo, bufferID_Avion, bufferID_Piloto,bufferFecha,bufferDestino , bufferCantPasajeros, bufferHoraDespegue, bufferHoraLlegada);


            pVuelo = vuelo_newParametros(bufferID_Vuelo, bufferID_Avion, bufferID_Piloto,bufferFecha,bufferDestino , bufferCantPasajeros, bufferHoraDespegue, bufferHoraLlegada);

            if(pVuelo != NULL)

            {
                ll_add(pArrayListVuelo, pVuelo);
                retorno = 0;
            }
        }
    }

    return retorno;

}
