typedef struct
{
    int idVuelo;
    int idAvion;
    int idPiloto;
    char fecha[50];
    char destino[50];
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;
}Vuelo;

int vuelo_setIdVuelo(Vuelo* this,int idVuelo);
Vuelo* vuelo_new();
int funcionPilotoUno (void* element);
int funcionPilotoDos (void* element);
int funcionPilotoTres (void* element);
int funcionPilotoCuatro (void* element);
int funcionPilotoCinco (void* element);

int funcionContar(void*element);
int funcionContarIrlanda(void *element);
