#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#define TAM 100

typedef struct
{
    int dia;
    int mes;
    int anio;

} eFecha;

typedef struct
{
    int codigoEquipos;
    char nombreEquipos[50];
    char localidadEquipos[50];
    int ocupado;
} eEquipos;

typedef struct
{
    int codigoJugadores;
    char nombreJugadores[50];
    char apellidoJugadores[50];
    eEquipos codigoEquipoJugadores;
    char sexoJugadores;
    eFecha fechaNacimientoJugadores;
    int ocupado;
} eJugadores;

typedef struct
{
    int codigoReferi;
    char nombreReferi[50];
    char apellidoReferi[50];
    char sexoReferi;
    char emailReferi[50];
    eFecha fechaNacimientoReferi;
    int cantidadPartidosDirigidos;
    int ocupado;
} eReferi;

typedef struct
{
    int codigoPartido;
    eEquipos codigoEquipoVisitante;
    eEquipos codigoEquipoLocal;
    eReferi structReferi;
    eFecha fechaPartido;
    int ocupado;

} ePartido;

void inicializarVectorEquipos(eEquipos vectorEquipos[],int tam);
void inicializarVectorJugadores(eEquipos vectorJugadores[],int tam);
void inicializarVectorReferis(eEquipos vectorReferis[],int tam);
void inicializarVectorPartidos(eEquipos vectorPartidos[],int tam);
int buscarIndiceLibreEquipos(eEquipos vectorEquipos[],int tam);
int buscarIndiceLibreJugadores(eEquipos vectorJugadores[],int tam);
int buscarIndiceLibreReferis(eEquipos vectorReferis[],int tam);
int buscarIndiceLibrePartidos(eEquipos vectorPartidos[],int tam);
int buscarEquipoPorCodigo(eEquipos vectorEquipo[],int tam,int codigoABuscar);


int altaEquipo(eEquipos vectorEquipo[],int tam);
int bajaEquipo(eEquipos vectorEquipo[],int tam);
void mostrarEquipos(eEquipos vectorEquipos[],int tam);
void ordenarEquipos(eEquipos vectorEquipos[],int tam);
int verificarSiExisteEquipo(eEquipos vectorEquipo[], int tam, int equipoABuscar);
void modificarEquipos(eEquipos vectorEquipos[],int tam);
void mostrarEquipoConNombreMasLargo(eEquipos vectorEquipo[],int tam);


int altaJugadores(eJugadores vectorJugadores[],eEquipos vectorEquipo[],int tam);
void bajaJugador(eJugadores vectorJugador[],int tam,eEquipos vectorEquipo[]);
void mostrarJugadores(eJugadores vectorJugadores[],int tam,eEquipos vectorEquipo[]);
void ordenarJugadoresPorNombre(eJugadores vectorJugadores[],int tam);
void ordenarJugadoresPorEquipo(eJugadores vectorJugadores[],int tam);
void mostrarMismosNombresYQueEquipoJuega(eJugadores vectorJugadores[],int tam,eEquipos vectorEquipos[]);

int altaReferi(eReferi vectorReferi[], int tam);
void mostrarReferis(eReferi vectorReferi[], int tam);
void obtenerNombreReferi(eReferi vectorReferi[], int tam, int idReferi);
int verificarSiExisteReferi(eReferi vectorReferi[],int tam, int referiABuscar);
void agregarPartidoDirigidoAReferi(eReferi vectorReferi[],int tam,int codigoReferi);
void cantidadPartidosMasDirigidosPorReferi(eReferi vectorReferi[], int tam);

int altaPartido(ePartido vectorPartido[],eEquipos vectorEquipo[],eReferi vectorReferi[],int tam);
void mostrarPartidos(ePartido vectorPartidos[],eEquipos vectorEquipo[], int tam);
void ordenamientoPartidos(ePartido vectorPartidos[],int tam);
void ordenarPartidosPorFecha(ePartido vectorPartidos[],int tam);
void mostrarLocalVisitanteYReferi(eEquipos vectorEquipo[],eReferi vectorReferi[],int tam,int codLocal,int codVisitante,int codReferi);
void ingresarFechaYMostrarEquipoYReferi(ePartido vectorPartido[],eReferi vectorReferi[],eEquipos vectorEquipo[],int tam);

int main()
{
    int opcion;
    char seguir = 's';


    eEquipos equipos[TAM];
    eJugadores jugadores[TAM];
    eReferi referis[TAM];
    ePartido partidos[TAM];

    eEquipos harcodeoEquipos[TAM] = {{1,"River","Nuniez",1},{2,"Boca","La boca",1},{3,"Racing","Avellaneda",1},{4,"Independiente","Avellaneda",1},{5,"San lorenzo","Boedo",1}};
    eJugadores harcodeoJugadores[TAM] = {{1,"Lucas","Pratto",{1},'m',{15,05,1999},1},{2,"Lucas","Borre",{1},'m',{12,10,1999},1},{3,"Carlos","Tevez",{2},'m',{30,10,1929},1},{4,"Nicolas","Blandi",{5},'m',{21,05,1999},1},{5,"Lisandro","Lopez",{3},'m',{21,03,1985},1},{6,"Ramon","Avila",{2},'m',{30,11,1999},1},{7,"Angel","Romero",{5},'m',{30,05,1999},1},{8,"Matias","Zaracho",{3},'m',{11,9,1995},1}};
    eReferi harcodeoReferis[TAM] = {{1,"Horacio","Elizondo",'m',"horacioelizondo@hotmail.com",{29,04,1980},4,1},{2,"Nestor","Pitana",'m',"nestorpitana@hotmail.com",{30,01,1979},2,1},{3,"Javier","Castrilli",'m',"javiercastri@gmail.com",{19,01,1974},3,1},{4,"Diego","Abal",'m',"abaldiego@yahoo.com",{11,02,1988},3,1},{5,"Pablo","Lunati",'m',"lupatip@hotmail.com",{31,04,1970},4,1}};
    ePartido harcodeoPartidos[TAM] = {{1,{1},{2},{3},{01,12,2015},1},{2,{3},{4},{3},{20,12,2015},1},{3,{5},{2},{4},{12,12,2015},1},{4,{5},{2},{1},{12,12,2019},1},{5,{1},{5},{4},{12,11,2018},1}};

    inicializarVectorEquipos(equipos,TAM);
    inicializarVectorJugadores(jugadores,TAM);
    inicializarVectorReferis(referis,TAM);
    inicializarVectorPartidos(partidos,TAM);

    while(seguir == 's')
    {
        printf("*****ABM JUGADOR*****\n\n1-Equipos\n2-Jugadores\n3-Referi\n4-Partidos\n5-Informar y listar\n6-Salir\n\nElija opcion (1-6): ");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            system("cls");
            printf("***Menu Equipos***\n\n1-Alta\n2-Listar\n3-Modificar\n4-Baja\n5-Salir\n\nElija opcion: ");
            scanf("%d",&opcion);
            switch(opcion)
            {
            case 1:
                altaEquipo(equipos,TAM);
                break;
            case 2:
                ordenarEquipos(harcodeoEquipos,TAM);
                mostrarEquipos(harcodeoEquipos,TAM);
                system("pause");
                break;
            case 3:
                modificarEquipos(harcodeoEquipos,TAM);
                break;
            case 4:
                bajaEquipo(harcodeoEquipos,TAM);
                break;
            case 5:

                break;
            default:
                printf("Ingrese opcion correcta (1-5)!!");
                system("pause");

            }
            break;
        case 2:
            system("cls");
            printf("***Menu Jugadores***\n\n1-Alta\n2-Listar\n3-Baja\n4-Salir\n\n Elija opcion: ");
            scanf("%d",&opcion);
            switch(opcion)
            {
            case 1:
                altaJugadores(jugadores,harcodeoEquipos,TAM);
                break;
            case 2:
                ordenarJugadoresPorNombre(harcodeoJugadores,TAM);
                mostrarJugadores(harcodeoJugadores,TAM,harcodeoEquipos);
                system("pause");
                break;
            case 3:
                bajaJugador(harcodeoJugadores,TAM,harcodeoEquipos);
                break;
            case 4:

                break;
            default:
                printf("Ingrese opcion correcta (1-4)!!\n");
                system("pause");
                break;
            }

            break;
        case 3:
            altaReferi(referis,TAM);

            system("pause");
            break;
        case 4:
            system("cls");
            printf("***Menu Partidos***\n\n1-Alta\n2-Listar\n3-Salir\n\nElija opcion :");
            scanf("%d",&opcion);
            switch(opcion)
            {
            case 1:
                altaPartido(partidos,harcodeoEquipos,harcodeoReferis,TAM);
                break;
            case 2:
                ordenarPartidosPorFecha(harcodeoPartidos,TAM);
                mostrarPartidos(harcodeoPartidos,harcodeoEquipos,TAM);
                system("pause");
                break;
            case 3:
                break;
            default:
                printf("\nIngrese una opcion correcta (1-3)!!!");
                system("pause");
                break;
            }

            break;
        case 5:
            system("cls");
            printf("*** MENU INFORMES ***\n\n");
            printf("1-Listar Jugadores por equipo\n2-Informar el referi que mas partidos dirigio\n3-Ingresar un nombre y listar todos los jugadores con ese nombre y en que equipo juega\n4-Listar el o los equipos con nombre mas largo\n5-Ingresar una fecha y listar los equipos y referi de los partidos de esa fecha\n6-Listar los equipo mas jovenes(promedio de edad)\n7-Salir\n\n Ingrese opcion : ");
            scanf("%d",&opcion);
            switch(opcion)
            {
            case 1:
                ordenarJugadoresPorEquipo(harcodeoJugadores,TAM);
                mostrarJugadores(harcodeoJugadores,TAM,harcodeoEquipos);
                system("pause");
                break;
            case 2:
                system("cls");
                cantidadPartidosMasDirigidosPorReferi(harcodeoReferis,TAM);
                mostrarReferis(harcodeoReferis,TAM);
                system("pause");
                break;
            case 3:
                mostrarMismosNombresYQueEquipoJuega(harcodeoJugadores,TAM,harcodeoEquipos);
                system("pause");

                break;
            case 4:
                system("cls");
                mostrarEquipos(harcodeoEquipos,TAM);
                mostrarEquipoConNombreMasLargo(harcodeoEquipos,TAM);
                system("pause");
                break;
            case 5:
                system("cls");
                mostrarPartidos(harcodeoPartidos,harcodeoEquipos,TAM);
                ingresarFechaYMostrarEquipoYReferi(harcodeoPartidos,harcodeoReferis,harcodeoEquipos,TAM);
                system("pause");
                break;
            case 6:
                mostrarElEquipoMasJoven(harcodeoJugadores,harcodeoEquipos,TAM);
                //equipoPromedioMasJoven(harcodeoJugadores,harcodeoEquipos,TAM);
                system("pause");
                break;
            case 7:
                break;
            default:
                printf("\n\nIngrese una opcion correcta (1-7)!!!!!\n");
                system("pause");
                break;


            }
            break;
        case 6:
            seguir='n';
            break;
        default:
            printf("\nIngrese una opcion correcta!! (1-6)\n");
            system("pause");
            break;
        }
        system("cls");
    };

    return 0;
}

void inicializarVectorEquipos(eEquipos vectorEquipos[],int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        vectorEquipos[i].ocupado=0;
    }
};

void inicializarVectorJugadores(eEquipos vectorJugadores[],int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        vectorJugadores[i].ocupado=0;
    }
};

void inicializarVectorReferis(eEquipos vectorReferis[],int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        vectorReferis[i].ocupado=0;
    }
};

void inicializarVectorPartidos(eEquipos vectorPartidos[],int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        vectorPartidos[i].ocupado=0;
    }
};

int buscarIndiceLibreEquipos(eEquipos vectorEquipos[],int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(vectorEquipos[i].ocupado == 0)
        {
            return i;
        }
    }
    return -1;
};

int buscarIndiceLibreJugadores(eEquipos vectorJugadores[],int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(vectorJugadores[i].ocupado == 0)
        {
            return i;
        }
    }
    return -1;
};

int buscarIndiceLibreReferis(eEquipos vectorReferis[],int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(vectorReferis[i].ocupado == 0)
        {
            return i;
        }
    }
    return -1;
};

int buscarIndiceLibrePartidos(eEquipos vectorPartidos[],int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(vectorPartidos[i].ocupado == 0)
        {
            return i;
        }
    }
    return -1;
};

int altaEquipo(eEquipos vectorEquipo[],int tam)
{
    int static idEquipo=1;
    int indiceLibre;
    char auxNombreEquipo[50];
    char auxLocalidadEquipo[50];

    indiceLibre=buscarIndiceLibreEquipos(vectorEquipo,tam);

    if(indiceLibre==-1)
    {
        printf("\n--NO HAY MAS LUGAR EN EL SISTEMA--\n");
    }
    else
    {
        vectorEquipo[indiceLibre].codigoEquipos= idEquipo;

        if(!getStringLetras("Ingrese nombre del equipo:", auxNombreEquipo))
        {
            printf("\nIngrese solo letras!!\n\n");
            system("pause");
            return 0;
        }
        if(!getStringLetras("Ingrese localidad :", auxLocalidadEquipo))
        {
            printf("\nIngrese solo letras!!\n\n");
            system("pause");
            return 0;
        }
        strcpy(vectorEquipo[indiceLibre].nombreEquipos,auxNombreEquipo);
        strcpy(vectorEquipo[indiceLibre].localidadEquipos,auxLocalidadEquipo);
        idEquipo++;
        vectorEquipo[indiceLibre].ocupado=1;

    }
    return 1;
};

void mostrarEquipos(eEquipos vectorEquipos[],int tam)
{
    int i;
    printf("\nidEquipo     Nombre       Localidad\n");
    for(i=0; i<tam; i++)
    {
        if(vectorEquipos[i].ocupado==1)
        {
            printf("\n%d   %15s %15s\n",vectorEquipos[i].codigoEquipos,vectorEquipos[i].nombreEquipos,vectorEquipos[i].localidadEquipos);
            //debo ordenar alfabeticamente los equipos
        }
    }

}

void ordenarEquipos(eEquipos vectorEquipos[],int tam)
{
    int i,j;
    eEquipos auxStruct;

    for(i=0; i<tam-1; i++)
    {
        if(vectorEquipos[i].ocupado==1)
        {
            for(j=i+1; j<tam; j++)
            {
                if(vectorEquipos[j].ocupado==1)
                {
                    if(strcmp(vectorEquipos[i].nombreEquipos,vectorEquipos[j].nombreEquipos)>0)
                    {
                        auxStruct=vectorEquipos[i];
                        vectorEquipos[i]=vectorEquipos[j];
                        vectorEquipos[j]=auxStruct;
                    }

                }
            }

        }
    }

}

int altaJugadores(eJugadores vectorJugadores[],eEquipos vectorEquipo[],int tam)
{
    int static idAuntoincremental=1;
    int indiceLibre;
    char auxNombreJugador[50];
    char auxApellidoJugador[50];




    indiceLibre=buscarIndiceLibreJugadores(vectorJugadores,tam);

    if(indiceLibre==-1)
    {
        printf("\n--NO HAY MAS LUGAR EN EL SISTEMA--\n");
    }
    else
    {
        vectorJugadores[indiceLibre].codigoJugadores=idAuntoincremental;

        if(!getStringLetras("Ingrese nombre del jugador:", auxNombreJugador))
        {
            printf("\nIngrese solo letras!!\n\n");
            system("pause");
            return 0;
        }
        if(!getStringLetras("Ingrese apellido del jugador:", auxApellidoJugador))
        {
            printf("\nIngrese solo letras!!\n\n");
            system("pause");
            return 0;
        }
        mostrarEquipos(vectorEquipo,tam);
        getInt(&vectorJugadores[indiceLibre].codigoEquipoJugadores.codigoEquipos,"\nElija codigo del equipo que desea registrarse :","Error, ingrese solo numeros",1,100);

        getChar(&vectorJugadores[indiceLibre].sexoJugadores,"Ingrese sexo (f/m): ","Error ingrese solo un caracter",'a','z');

        getInt(&vectorJugadores[indiceLibre].fechaNacimientoJugadores.dia,"Ingrese dia de nacimiento (1-31):","Error, ingrese solo numeros del (1-31)",1,31);
        getInt(&vectorJugadores[indiceLibre].fechaNacimientoJugadores.mes,"Ingrese mes de nacimiento (1-12):","Error, ingrese solo numeros del (1-12)",1,12);
        getInt(&vectorJugadores[indiceLibre].fechaNacimientoJugadores.anio,"Ingrese anio de nacimiento (1920-2015):","Error, ingrese solo numeros (1920-15)",1920,2015);

    }
    strcpy(vectorJugadores[indiceLibre].nombreJugadores,auxNombreJugador);
    strcpy(vectorJugadores[indiceLibre].apellidoJugadores,auxApellidoJugador);
    idAuntoincremental++;
    vectorJugadores[indiceLibre].ocupado=1;

    return 1;
}

void mostrarJugadores(eJugadores vectorJugadores[],int tam,eEquipos vectorEquipo[])
{
    int i,j;
    printf("\nIdJug idEquipo   Club     Nombre   Apellido   Sexo   Dia   Mes   Anio\n");
    for(i=0; i<tam; i++)
    {
        if(vectorJugadores[i].ocupado==1)
        {
            for(j=0; j<tam; j++)
            {
                if(vectorEquipo[j].codigoEquipos==vectorJugadores[i].codigoEquipoJugadores.codigoEquipos)
                {
                    printf("\n%2d      %2d %10s %10s %10s %4c  %6d%6d %6d\n",vectorJugadores[i].codigoJugadores,vectorJugadores[i].codigoEquipoJugadores.codigoEquipos,vectorEquipo[j].nombreEquipos,vectorJugadores[i].nombreJugadores,vectorJugadores[i].apellidoJugadores,vectorJugadores[i].sexoJugadores,vectorJugadores[i].fechaNacimientoJugadores.dia,vectorJugadores[i].fechaNacimientoJugadores.mes,vectorJugadores[i].fechaNacimientoJugadores.anio);

                }
            }
        }
    }
}

void ordenarJugadoresPorNombre(eJugadores vectorJugadores[],int tam)
{
    int i,j;
    eJugadores auxStruct;
    for(i=0; i<tam-1; i++)
    {
        if(vectorJugadores[i].ocupado==1)
        {
            for(j=i+1; j<tam; j++)
            {
                if(vectorJugadores[j].ocupado==1)
                {
                    if(strcmp(vectorJugadores[i].nombreJugadores,vectorJugadores[j].nombreJugadores)>0)
                    {
                        auxStruct=vectorJugadores[i];
                        vectorJugadores[i]=vectorJugadores[j];
                        vectorJugadores[j]=auxStruct;
                    }

                }
            }
        }
    }
}

int altaReferi(eReferi vectorReferi[], int tam)
{
    int indiceLibre;
    int static idAutoincremental=1;
    char auxNombreReferi[50];
    char auxApellidoReferi[50];
    char auxEmail[50];

    indiceLibre=buscarIndiceLibreReferis(vectorReferi,tam);

    if(indiceLibre==-1)
    {
        printf("\n--NO HAY MAS LUGAR EN EL SISTEMA--\n");
    }
    else
    {
        vectorReferi[indiceLibre].codigoReferi=idAutoincremental;

        if(!getStringLetras("Ingrese nombre del referi: ", auxNombreReferi))
        {
            printf("\nIngrese solo letras!!\n\n");
            system("pause");
            return 0;
        }
        if(!getStringLetras("Ingrese apellido del referi: ", auxApellidoReferi))
        {
            printf("\nIngrese solo letras!!\n\n");
            system("pause");
            return 0;
        }

        getChar(&vectorReferi[indiceLibre].sexoReferi,"Ingrese sexo (f/m):","Error ingrese solo un caracter",'a','z');

        if(!getMail("Ingrese mail: ", auxEmail))
        {
            printf("\nIngrese un mail con caracteres validos !!\n\n");
            system("pause");
            return 0;
        }

        getInt(&vectorReferi[indiceLibre].fechaNacimientoReferi.dia,"Ingrese dia de nacimiento (1-31):","Error, ingrese solo numeros del (1-31)",1,31);
        getInt(&vectorReferi[indiceLibre].fechaNacimientoReferi.mes,"Ingrese mes de nacimiento (1-12):","Error, ingrese solo numeros del (1-12)",1,12);
        getInt(&vectorReferi[indiceLibre].fechaNacimientoReferi.anio,"Ingrese anio de nacimiento (1920-2015):","Error, ingrese solo numeros del (1920-2015)",1920,2015);

    }
    strcpy(vectorReferi[indiceLibre].nombreReferi,auxNombreReferi);
    strcpy(vectorReferi[indiceLibre].apellidoReferi,auxApellidoReferi);
    strcpy(vectorReferi[indiceLibre].emailReferi,auxEmail);
    idAutoincremental++;
    vectorReferi[indiceLibre].ocupado=1;
    return 1;
};

void mostrarReferis(eReferi vectorReferi[], int tam)
{
    int i;
    printf("\ncodReferi    Nombre        Apellido    CantidadPartidosDirigidos\n");
    for(i=0; i<tam; i++)
    {
        if(vectorReferi[i].ocupado==1)
        {
            printf("\n%4d %15s %15s            %d\n", vectorReferi[i].codigoReferi,vectorReferi[i].nombreReferi,vectorReferi[i].apellidoReferi,vectorReferi[i].cantidadPartidosDirigidos);
        }
    }
};

int altaPartido(ePartido vectorPartido[],eEquipos vectorEquipo[],eReferi vectorReferi[],int tam)
{
    int static idAutoincremental=1;
    int auxCodigoEquipoLocal;
    int auxCodigoEquipoVisitante;
    int auxCodigoReferi;
    int indiceLibre;

    indiceLibre=buscarIndiceLibrePartidos(vectorPartido,tam);

    if(indiceLibre==-1)
    {
        printf("\n--NO HAY MAS LUGAR EN EL SISTEMA--\n");
    }
    else
    {
        vectorPartido[indiceLibre].codigoPartido=idAutoincremental;

        mostrarEquipos(vectorEquipo,tam);

        getInt(&auxCodigoEquipoLocal,"\nIngrese codigo del equipo local: ","Error, ingrese solo numeros",1,100);

        if(!verificarSiExisteEquipo(vectorEquipo, tam, auxCodigoEquipoLocal))
        {
            printf("El equipo ingresado no se encuentra registrado!!\n");
            system("pause");
            return 0;
        }

        getInt(&auxCodigoEquipoVisitante,"\nIngrese codigo del equipo visitante: ","Error, ingrese solo numeros",1,100);

        if(!verificarSiExisteEquipo(vectorEquipo, tam, auxCodigoEquipoVisitante))
        {
            printf("El equipo ingresado no se encuentra registrado!!\n");
            system("pause");
            return 0;
        }

        system("cls");
        mostrarReferis(vectorReferi,tam);
        getInt(&auxCodigoReferi,"\nIngrese codigo del referi: ","Error, ingrese solo numeros",1,100);

        if(!verificarSiExisteReferi(vectorReferi, tam, auxCodigoReferi))
        {
            printf("El referi ingresado no se encuentra registrado!!\n");
            system("pause");
            return 0;
        }

        getInt(&vectorPartido[indiceLibre].fechaPartido.dia,"Ingrese dia del partido (1-31):","Error, ingrese solo dias del (1-31)",1,31);
        getInt(&vectorPartido[indiceLibre].fechaPartido.mes,"Ingrese mes del partido (1-12):","Error, ingrese solo meses del (1-12)",1,12);
        getInt(&vectorPartido[indiceLibre].fechaPartido.anio,"Ingrese anio del partido (2000-2019):","Error, ingrese solo anios del (2010-2019)",2000,2019);


    }


    vectorPartido[indiceLibre].codigoEquipoLocal.codigoEquipos=auxCodigoEquipoLocal;
    vectorPartido[indiceLibre].codigoEquipoVisitante.codigoEquipos=auxCodigoEquipoVisitante;
    vectorPartido[indiceLibre].structReferi.codigoReferi=auxCodigoReferi;
    agregarPartidoDirigidoAReferi(vectorReferi,tam,auxCodigoReferi);

    idAutoincremental++;
    vectorPartido[indiceLibre].ocupado=1;

    return 1;

}

void mostrarPartidos(ePartido vectorPartidos[],eEquipos vectorEquipo[], int tam)
{
    int i,j,k;
    char equipoVisitante[50];
    char equipoLocal[50];

    printf("\nidPartido   - EquipoLocal      - EquipoVisitante -  idReferi   -   Fecha\n");
    for(i=0; i<tam; i++)
    {
        if(vectorPartidos[i].ocupado==1)
        {
            for(j=0; j<tam; j++)
            {
                if(vectorEquipo[j].codigoEquipos==vectorPartidos[i].codigoEquipoLocal.codigoEquipos)
                {
                    strcpy(equipoLocal,vectorEquipo[j].nombreEquipos);
                }
            }
            for(k=0; k<tam; k++)
            {
                if(vectorEquipo[k].codigoEquipos==vectorPartidos[i].codigoEquipoVisitante.codigoEquipos)
                {
                    strcpy(equipoVisitante,vectorEquipo[k].nombreEquipos);
                }
            }

            printf("\n%3d     %15s      %15s     %8d      %3d/%3d/%4d\n",vectorPartidos[i].codigoPartido,equipoLocal,equipoVisitante,vectorPartidos[i].structReferi.codigoReferi,vectorPartidos[i].fechaPartido.dia,vectorPartidos[i].fechaPartido.mes,vectorPartidos[i].fechaPartido.anio);

        }

    }
}

void ordenarPartidosPorFecha(ePartido vectorPartidos[],int tam)
{
    int i,j;
    ePartido auxPartido;
    for(i=0; i<tam-1; i++)
    {
        if(vectorPartidos[i].ocupado==1)
        {
            for(j=i+1; j<tam; j++)
            {
                if(vectorPartidos[j].ocupado==1)
                {
                    if(vectorPartidos[i].fechaPartido.anio>vectorPartidos[j].fechaPartido.anio)
                    {
                        auxPartido=vectorPartidos[i];
                        vectorPartidos[i]=vectorPartidos[j];
                        vectorPartidos[j]=auxPartido;
                    }
                    else if(vectorPartidos[i].fechaPartido.anio==vectorPartidos[j].fechaPartido.anio)
                    {
                        if(vectorPartidos[i].fechaPartido.mes>vectorPartidos[j].fechaPartido.mes)
                        {
                            auxPartido=vectorPartidos[i];
                            vectorPartidos[i]=vectorPartidos[j];
                            vectorPartidos[j]=auxPartido;
                        }
                        else if(vectorPartidos[i].fechaPartido.mes==vectorPartidos[j].fechaPartido.mes)
                        {
                            if(vectorPartidos[i].fechaPartido.dia>vectorPartidos[j].fechaPartido.dia)
                            {
                                auxPartido=vectorPartidos[i];
                                vectorPartidos[i]=vectorPartidos[j];
                                vectorPartidos[j]=auxPartido;
                            }
                        }
                    }
                }
            }
        }
    }
}


int verificarSiExisteEquipo(eEquipos vectorEquipo[], int tam, int equipoABuscar)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(equipoABuscar==vectorEquipo[i].codigoEquipos)
        {
            return 1;
        }
    }
    return 0;
}

int verificarSiExisteReferi(eReferi vectorReferi[],int tam, int referiABuscar)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(referiABuscar==vectorReferi[i].codigoReferi)
        {
            return 1;
        }
    }
    return 0;
}

void obtenerNombreReferi(eReferi vectorReferi[], int tam, int idReferi)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(idReferi==vectorReferi[i].codigoReferi)
        {
            printf("%15s %15s", vectorReferi[i].nombreReferi,vectorReferi[i].apellidoReferi);
        }
    }
}

void modificarEquipos(eEquipos vectorEquipos[],int tam)
{
    int codigoEquipo;
    int indiceEncontrado;
    int opcion;

    mostrarEquipos(vectorEquipos,tam);
    printf("\nIngrese codigo del equipo a modificar: ");
    scanf("%d", &codigoEquipo);
    indiceEncontrado=buscarEquipoPorCodigo(vectorEquipos,tam,codigoEquipo);
    if(indiceEncontrado==-1)
    {
        printf("\n\nii No se encontro el equipo ingresado !!\n");
        system("pause");
    }
    else
    {
        system("cls");
        printf("** Menu modificacion de equipo **\n\n");
        printf("1-Modificar nombre\n2-Modificar localidad\n3-Salir\n\nElija opcion: ");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            printf("Ingrese nuevo nombre: ");
            scanf("%s",vectorEquipos[indiceEncontrado].nombreEquipos);
            break;
        case 2:
            printf("Ingrese nueva localidad: ");
            scanf("%s",vectorEquipos[indiceEncontrado].localidadEquipos);
            break;
        case 3:
            break;
        default:
            printf("Ingrese una opcion correcta (1-3)");
            break;

        }

    }


}

int bajaEquipo(eEquipos vectorEquipo[],int tam)
{
    int codigoADarDeBaja;
    int indiceEncontrado;
    char confirma;
    mostrarEquipos(vectorEquipo,tam);
    printf("\n\nIngrese codigo del equipo a dar de baja: ");
    scanf("%d",&codigoADarDeBaja);
    indiceEncontrado=buscarEquipoPorCodigo(vectorEquipo,tam,codigoADarDeBaja);
    printf("\nUsted desea dar de baja el equipo %s ? (s/n):",vectorEquipo[indiceEncontrado].nombreEquipos);

    fflush(stdin);
    scanf("%c",&confirma);
    if(confirma=='s')
    {
        vectorEquipo[indiceEncontrado].ocupado=0;
        printf("\n BAJA EXITOSA!!!!");
        system("pause");
    }


    return 0;

}

int buscarEquipoPorCodigo(eEquipos vectorEquipo[],int tam,int codigoABuscar)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(vectorEquipo[i].codigoEquipos==codigoABuscar)
        {
            return i;
        }
    }
    return -1;
}

int buscarJugadorPorCodigo(eJugadores vectorJugador[],int tam, int codigoJugador)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(vectorJugador[i].codigoJugadores==codigoJugador)
        {
            return i;
        }
    }
    return -1;
}

void bajaJugador(eJugadores vectorJugador[],int tam,eEquipos vectorEquipo[])
{
    int codigoJugador;
    int indiceEncontrado;
    char confirma;

    mostrarJugadores(vectorJugador,tam,vectorEquipo);
    printf("\nIngrese codigo de jugador a dar de baja: ");
    scanf("%d", &codigoJugador);
    indiceEncontrado=buscarJugadorPorCodigo(vectorJugador,tam,codigoJugador);
    if(indiceEncontrado==-1)
    {
        printf("\n No se encontro a ningun jugador con el codigo ingresado!!!\n");
        system("pause");
    }
    else
    {
        printf("\nUsted desea dar de baja al jugador %s %s?(s/n): ",vectorJugador[indiceEncontrado].apellidoJugadores,vectorJugador[indiceEncontrado].nombreJugadores);
        fflush(stdin);
        scanf("%c",&confirma);
        if(confirma=='s')
        {
            vectorJugador[indiceEncontrado].ocupado=0;
            printf("\n BAJA EXITOSA!!!!\n");
            system("pause");
        }
    }
}

void ordenarJugadoresPorEquipo(eJugadores vectorJugadores[],int tam)
{
    int i,j;
    eJugadores auxStruct;
    for(i=0; i<tam-1; i++)
    {
        if(vectorJugadores[i].ocupado==1)
        {
            for(j=i+1; j<tam; j++)
            {
                if(vectorJugadores[j].ocupado==1)
                {
                    if(vectorJugadores[i].codigoEquipoJugadores.codigoEquipos>vectorJugadores[j].codigoEquipoJugadores.codigoEquipos)
                    {
                        auxStruct=vectorJugadores[i];
                        vectorJugadores[i]=vectorJugadores[j];
                        vectorJugadores[j]=auxStruct;
                    }
                }
            }
        }
    }
}

void cantidadPartidosMasDirigidosPorReferi(eReferi vectorReferi[], int tam)
{
    int i,j;
    eReferi auxStruct;
    int maximaCantidadPartidos;
    for(i=0; i<tam-1; i++)
    {
        if(vectorReferi[i].ocupado==1)
        {
            for(j=i+1; j<tam; j++)
            {
                if(vectorReferi[j].ocupado==1)
                {
                    if(vectorReferi[i].cantidadPartidosDirigidos<vectorReferi[j].cantidadPartidosDirigidos)
                    {
                        auxStruct=vectorReferi[i];
                        vectorReferi[i]=vectorReferi[j];
                        vectorReferi[j]=auxStruct;
                    }
                }
            }
        }
    }
    //El referi con partidos mas dirigidos estara primero
    maximaCantidadPartidos=vectorReferi[0].cantidadPartidosDirigidos;

    printf("El referi con mayor cantidad de partidos dirigidos  PartidosDirigidos");
    for(i=0; i<tam; i++)
    {
        if(vectorReferi[i].cantidadPartidosDirigidos==maximaCantidadPartidos)
        {
            printf("\n%15s %15s                             %d \n",vectorReferi[i].apellidoReferi,vectorReferi[i].nombreReferi,maximaCantidadPartidos);
        }
    }



}

void agregarPartidoDirigidoAReferi(eReferi vectorReferi[],int tam,int codigoReferi)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(vectorReferi[i].codigoReferi==codigoReferi)
        {
            vectorReferi[i].cantidadPartidosDirigidos++;
        }
    }
}

void mostrarMismosNombresYQueEquipoJuega(eJugadores vectorJugadores[],int tam,eEquipos vectorEquipos[])
{
    char nombreABuscar[50];
    int i;
    mostrarJugadores(vectorJugadores,tam,vectorEquipos);
    printf("\n\nIngrese un nombre: ");
    scanf("%s",nombreABuscar);

    for(i=0; i<tam; i++)
    {
        if(strcmp(vectorJugadores[i].nombreJugadores,nombreABuscar)==0)
        {
            for(int j=0; j<tam; j++)
            {
                if(vectorEquipos[j].codigoEquipos==vectorJugadores[i].codigoEquipoJugadores.codigoEquipos)
                {
                    printf("Apellido :%s Nombre :%s  Club: %s\n", vectorJugadores[i].apellidoJugadores,vectorJugadores[i].nombreJugadores,vectorEquipos[j].nombreEquipos);
                }
            }
        }

    }
}

void mostrarEquipoConNombreMasLargo(eEquipos vectorEquipo[],int tam)
{
    int i,j;
    eEquipos auxStruct;
    char nombreMasLargo[50];
    for(i=0; i<tam-1; i++)
    {
        if(vectorEquipo[i].ocupado==1)
        {
            for(j=i+1; j<tam; j++)
            {
                if(vectorEquipo[j].ocupado==1)
                {
                    if(strlen(vectorEquipo[i].nombreEquipos)<strlen(vectorEquipo[j].nombreEquipos))
                    {
                        auxStruct=vectorEquipo[i];
                        vectorEquipo[i]=vectorEquipo[j];
                        vectorEquipo[j]=auxStruct;
                    }
                }
            }
        }
    }
    strcpy(nombreMasLargo,vectorEquipo[0].nombreEquipos);

    for(i=0; i<tam; i++)
    {
        if(vectorEquipo[i].ocupado==1)
        {
            if(strlen(vectorEquipo[i].nombreEquipos)==strlen(nombreMasLargo))
            {
                printf("\nEl/Los equipos con nombres mas largos son: %s\n\n", vectorEquipo[i].nombreEquipos);
            }
        }
    }

}

void ingresarFechaYMostrarEquipoYReferi(ePartido vectorPartido[],eReferi vectorReferi[],eEquipos vectorEquipo[],int tam)
{
    int dia;
    int mes;
    int anio;
    int i;
    getInt(&dia,"Ingrese dia (0-31) : ","Error, ingrese un dia correcto (0-31)",0,31);
    getInt(&mes,"Ingrese mes (1-12) : ","Error,ingrese un dia correcto (0-12)",0,12);
    getInt(&anio,"Ingrese anio (2010-2019) : ","Error, ingrese un anio correcto (2010-2019)",2010,2019);


    for(i=0; i<tam; i++)
    {
        if(vectorPartido[i].ocupado==1)
        {
            if(vectorPartido[i].fechaPartido.anio==anio && vectorPartido[i].fechaPartido.mes==mes && vectorPartido[i].fechaPartido.dia==dia)
            {
                mostrarLocalVisitanteYReferi(vectorEquipo,vectorReferi,tam,vectorPartido[i].codigoEquipoLocal.codigoEquipos,vectorPartido[i].codigoEquipoVisitante.codigoEquipos,vectorPartido[i].structReferi.codigoReferi);
                break;
            }


        }

    }

}

void mostrarLocalVisitanteYReferi(eEquipos vectorEquipo[],eReferi vectorReferi[],int tam,int codLocal,int codVisitante,int codReferi)
{
    int i,j,k;
    printf("     -EquipoLocal-        -EquipoVisitante-       -Referi-\n\n");
    for(i=0; i<tam; i++)
    {
        if(vectorEquipo[i].codigoEquipos==codLocal)
        {
            printf("%15s    ", vectorEquipo[i].nombreEquipos);
        }
    }
    for(j=0; j<tam; j++)
    {
        if(vectorEquipo[j].codigoEquipos==codVisitante)
        {
            printf("%15s    ", vectorEquipo[j].nombreEquipos);
        }
    }
    for(k=0; k<tam; k++)
    {
        if(vectorReferi[k].codigoReferi==codReferi)
        {
            printf("%15s  %s\n",vectorReferi[k].apellidoReferi,vectorReferi[i].nombreReferi);
        }
    }

}

void mostrarElEquipoMasJoven(eJugadores vectorJugador[],eEquipos vectorEquipo[],int tam)
{
    int i,j;
    //int contadorJugadores=0;
    int edadJugador=0;
    int acumuladorEdad=0;
    float promedio=0;
    int codEquipo=1;
    char equipo[50];
    int contadorJugadores=0;

    for(i=0; i<tam; i++)
    {
        if(vectorEquipo[i].codigoEquipos==codEquipo && vectorEquipo[i].ocupado==1)
        {
            for(j=0; j<tam; j++) //Empiezo a recorrer el vector de los jugadores
            {

                if(vectorJugador[j].codigoEquipoJugadores.codigoEquipos==codEquipo && vectorJugador[j].ocupado==1) //Si el codigoEquipo del jugador coincide con el codEquipo guardo y acumulo edad
                {

                    contadorJugadores++;
                    acumuladorEdad=acumuladorEdad+(2019-vectorJugador[j].fechaNacimientoJugadores.anio);


                }

                strcpy(equipo,vectorEquipo[i].nombreEquipos);
                promedio=acumuladorEdad/contadorJugadores;

            }


            printf("Equipo:%s  PromedioEdad:%.2f\n",equipo,promedio);
            printf("Cantidad de personas :%d",contadorJugadores);





        }

        codEquipo++;
        promedio=0;
        contadorJugadores=0;//Problema con contadorjugadores
        acumuladorEdad=0;
    }


    // printf("Cantidad de jugadores: %d y promedio edad es %d\n",contadorJugadores,promedio);

}

int contador()
{
    int contador=0;





}

