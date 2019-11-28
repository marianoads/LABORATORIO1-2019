#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Vuelo.h"
#include "LinkedList.h"
#include "Controller.h"


Vuelo* vuelo_newParametros(char* idVueloStr,char* idAvionStr,char* idPilotoStr, char* fechaStr,char* destinoStr, char* cantPasajerosStr, char* horaDespegueStr, char* horaLlegadaStr)
{

    Vuelo* this;

    if (idVueloStr != NULL && idAvionStr != NULL && idPilotoStr != NULL && fechaStr != NULL && destinoStr != NULL && cantPasajerosStr != NULL && horaDespegueStr != NULL && horaLlegadaStr != NULL)
    {
        this  = vuelo_new();

        if( this != NULL)
        {

            if(  !vuelo_setIdAvion(this,atoi(idAvionStr)) ||
                    !vuelo_setIdPiloto(this,atoi(idPilotoStr)) ||
                    !vuelo_setIdVuelo(this,atoi(idVueloStr))   ||
                    !vuelo_setFecha(this,fechaStr)             ||
                    !vuelo_setDestino(this,destinoStr)         ||
                    !vuelo_setCantPasajeros(this,atoi(cantPasajerosStr)) ||
                    !vuelo_setHoraDespegue(this, atoi(horaDespegueStr))  ||
                    !vuelo_setHoraLlegada(this,atoi(horaLlegadaStr))


              )
            {

                free(this);
                this = NULL;
            }
        }
    }

    return this;
}

Vuelo* vuelo_new()
{

    Vuelo* this = (Vuelo*) malloc(sizeof(Vuelo));

    if( this != NULL)
    {
        this->idVuelo = 0;
        this->idAvion = 0;
        this->idPiloto = 0;
        strcpy(this->fecha,"");
        strcpy(this->destino,"");
        this->cantPasajeros = 0;
        this->horaDespegue = 0;
        this->horaLlegada = 0;

    }

    return this;
}

int vuelo_setIdVuelo(Vuelo* this,int idVuelo)
{

    int todoOk = 0;

    if( this != NULL )
    {

        this->idVuelo = idVuelo;
        todoOk = 1;
    }

    return todoOk;
}

int vuelo_getIdVuelo(Vuelo* this,int* idVuelo)
{

    int todoOk = 0;

    if( this != NULL)
    {

        *idVuelo = this->idVuelo;
        todoOk = 1;
    }
    return todoOk;
}

int vuelo_setIdAvion(Vuelo* this,int idAvion)
{

    int todoOk = 0;

    if( this != NULL )
    {

        this->idAvion = idAvion;
        todoOk = 1;
    }

    return todoOk;
}

int vuelo_getIdAvion(Vuelo* this,int* idAvion)
{

    int todoOk = 0;

    if( this != NULL)
    {

        *idAvion = this->idAvion;
        todoOk = 1;
    }
    return todoOk;
}

int vuelo_setIdPiloto(Vuelo* this,int idPiloto)
{

    int todoOk = 0;

    if( this != NULL )
    {

        this->idPiloto = idPiloto;
        todoOk = 1;
    }

    return todoOk;
}

int vuelo_getIdPiloto(Vuelo* this,int* idPiloto)
{

    int todoOk = 0;

    if( this != NULL)
    {

        *idPiloto = this->idPiloto;
        todoOk = 1;
    }
    return todoOk;
}

int vuelo_setFecha(Vuelo* this,char* fecha)
{

    int todoOk = 0;

    if( this != NULL)
    {

        strcpy(this->fecha, fecha);
        todoOk = 1;
    }

    return todoOk;

}

int vuelo_getFecha(Vuelo* this,char* fecha)
{

    int todoOk = 0;

    if( this != NULL)
    {

        strcpy(fecha, this->fecha);
        todoOk = 1;
    }

    return todoOk;

}

int vuelo_setDestino(Vuelo* this,char* destino)
{

    int todoOk = 0;

    if( this != NULL)
    {

        strcpy(this->destino, destino);
        todoOk = 1;
    }

    return todoOk;

}

int vuelo_getDestino(Vuelo* this,char* destino)
{

    int todoOk = 0;

    if( this != NULL)
    {

        strcpy(destino, this->destino);
        todoOk = 1;
    }

    return todoOk;

}

int vuelo_setCantPasajeros(Vuelo* this,int cantPasajeros)
{

    int todoOk = 0;

    if( this != NULL )
    {

        this->cantPasajeros = cantPasajeros;
        todoOk = 1;
    }

    return todoOk;
}

int vuelo_getCantPasajeros(Vuelo* this,int* cantPasajeros)
{

    int todoOk = 0;

    if( this != NULL)
    {

        *cantPasajeros = this->cantPasajeros;
        todoOk = 1;
    }
    return todoOk;
}

int vuelo_setHoraDespegue(Vuelo* this,int horaDespegue)
{

    int todoOk = 0;

    if( this != NULL )
    {

        this->horaDespegue = horaDespegue;
        todoOk = 1;
    }

    return todoOk;
}

int vuelo_getHoraDespegue(Vuelo* this,int* horaDespegue)
{

    int todoOk = 0;

    if( this != NULL)
    {

        *horaDespegue = this->horaDespegue;
        todoOk = 1;
    }
    return todoOk;
}

int vuelo_setHoraLlegada(Vuelo* this,int horaLlegada)
{

    int todoOk = 0;

    if( this != NULL )
    {

        this->horaLlegada = horaLlegada;
        todoOk = 1;
    }

    return todoOk;
}

int vuelo_getHoraLlegada(Vuelo* this,int* horaLlegada)
{

    int todoOk = 0;

    if( this != NULL)
    {

        *horaLlegada = this->horaLlegada;
        todoOk = 1;
    }
    return todoOk;
}

int Vuelo_showVuelos(Vuelo* pArrayListVuelo, int sizeList)
{
    Vuelo* pVuelo;

    int i;
    int retorno = 0;
    int auxIdVuelo;
    int auxIdAvion;
    int auxIdPiloto;
    char auxFecha[50];
    char auxDestino[50];
    int auxCantPasajeros;
    int auxHoraDespegue;
    int auxHoraLlegada;



    for(i=0; i<sizeList; i++)
    {
        pVuelo = ll_get(pArrayListVuelo, i);
        vuelo_getIdVuelo(pVuelo,&auxIdVuelo);
        vuelo_getIdAvion(pVuelo,&auxIdAvion);
        vuelo_getIdPiloto(pVuelo,&auxIdPiloto);
        vuelo_getFecha(pVuelo,auxFecha);
        vuelo_getDestino(pVuelo,auxDestino);
        vuelo_getCantPasajeros(pVuelo,&auxCantPasajeros);
        vuelo_getHoraDespegue(pVuelo,&auxHoraDespegue);
        vuelo_getHoraLlegada(pVuelo,&auxHoraLlegada);

        //problemaEnFormatoTexto(auxIdProblema,problemaStr);
        //vueloEnFormatoTexto()

        printf("\n %d   %d   %d   %s    %s    %d    %d   %d", auxIdVuelo, auxIdAvion, auxIdPiloto, auxFecha, auxDestino,auxCantPasajeros,auxHoraDespegue,auxHoraLlegada);

    }
    printf("\n");
    system("pause");
    return retorno;
}

void vueloEnFormatoTexto(int idVuelo,char* vueloStr)
{
    if(idVuelo==1 && idVuelo != NULL )
    {
        strcpy(vueloStr,"Alex Lifeson");
    }
    else if(idVuelo == 2 && idVuelo != NULL)
    {
        strcpy(vueloStr,"Richard Bach");
    }
    else if(idVuelo == 3 && idVuelo != NULL)
    {
        strcpy(vueloStr,"John Kerry");
    }
    else if(idVuelo == 4 && idVuelo != NULL)
    {
        strcpy(vueloStr,"Erwin Rommel");
    }
    else if(idVuelo == 5 && idVuelo != NULL)
    {
        strcpy(vueloStr,"Stephen Coonts");
    }
    return vueloStr;


};

int funcionPilotoUno (void* element)
{
    int aux=0;
    if(  ((Vuelo*) element)->idPiloto == 1)
    {
        aux=1;
    }

    return aux;

}
int funcionPilotoDos (void* element)
{
    int aux=0;
    if(  ((Vuelo*) element)->idPiloto == 2)
    {
        aux=1;
    }

    return aux;

}

int funcionPilotoTres (void* element)
{
    int aux=0;
    if(  ((Vuelo*) element)->idPiloto == 3)
    {
        aux=1;
    }

    return aux;

}
int funcionPilotoCuatro (void* element)
{
    int aux=0;
    if(  ((Vuelo*) element)->idPiloto == 4)
    {
        aux=1;
    }

    return aux;

}

int funcionPilotoCinco (void* element)
{
    int aux=0;
    if(  ((Vuelo*) element)->idPiloto == 5)
    {
        aux=1;
    }

    return aux;

}

int funcionContar(void* element){


    int cantPasajeros=-1;
    if( element != NULL){
     cantPasajeros = ((Vuelo*)element)->cantPasajeros;

    }

    return cantPasajeros;
}

int funcionContarIrlanda(void* element){
    int cantPasajeros=0;

    if( strcmp( ((Vuelo*)element)->destino,"Irlanda" ) == 0 ){
        cantPasajeros=((Vuelo*)element)->cantPasajeros;
    }
    return cantPasajeros;


}
