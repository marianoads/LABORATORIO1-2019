#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int valor;
    int returnScanf;
    int error = -1;

    printf("%s ", message);
    returnScanf = scanf("%d", &valor);

    while(returnScanf == 0  || valor < lowLimit || valor > hiLimit)
    {

        printf("\n%s\n", eMessage);
        printf("\n%s ", message);
        fflush(stdin);
        returnScanf = scanf("%d", &valor);
    }

    *input = valor;
    error = 0;

    return error;
}

/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getFloat(float* input,char message[],char eMessage[], float lowLimit, float hiLimit)
{
    float valor;
    float returnScanf;
    int error = -1;

    printf("%s ", message);
    returnScanf = scanf("%f", &valor);

    while(returnScanf == 0  || valor < lowLimit || valor > hiLimit)
    {

        printf("\n%s\n", eMessage);
        printf("\n%s ", message);
        fflush(stdin);
        returnScanf = scanf("%f", &valor);
    }

    *input = valor;
    error = 0;

    return error;
}


/**
* \brief Solicita un caracter al usuario y lo valida
* \param input Se carga el caracter ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el caracter [0] si no [-1]
*
*/
int getChar(char* input,char message[],char eMessage[], char lowLimit, char hiLimit)
{
    char valor;
    int error = -1;

    printf("\n%s", message);
    fflush(stdin);
    scanf("%c", &valor);

    while(valor < lowLimit || valor > hiLimit)
    {
        printf("%s\n",eMessage);
        printf("%s\n",message);
        fflush(stdin);
        scanf("%c", &valor);

    }


    *input = valor;
    error=0;

    return error;
}


/**
* \brief Solicita una cadena de caracteres al usuario y la valida
* \param input Se carga el string ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Longitud mínima de la cadena
* \param hiLimit Longitud máxima de la cadena
* \return Si obtuvo la cadena [0] si no [-1]
*
*/
int getString(char* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    char valor[100];
    int error = -1;

    printf("\n%s", message);
    fflush(stdin);
    gets(valor);

    while(strlen(valor) < lowLimit || strlen(valor) > hiLimit)
    {
        printf("%s\n",eMessage);
        printf("%s\n",message);
        fflush(stdin);
        gets(valor);

    }


    strcpy(input,valor);
    error=0;

    return error;

}

/** \brief Solicita un texto al usuario y lo devuelve
 *
 * \param mensaje: Es el mensaje a ser mostrado
 * \param  input: Array donde se cargara el texto ingresado
 * \return  1 si el texto contiene solo letras
 *
 */

int getStringLetras(char mensaje[], char input[])
{
    char aux[250];
    getString(aux,mensaje,"Error",0,250);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

/** \brief Solicita un numero al usuario y lo devuelve
 *
 * \param mensaje: Es el mensaje a mostrar
 * \param input: Array donde se guarda el dato
 * \return 1 si lo ingresado contiene solo numeros
 *
 */

int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    getString(aux,mensaje,"Error",0,5000);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

/** \brief  Verifica si el valor recibido es numerico
 *
 * \param  str Array con la cadena a ser analizaada
 * \param
 * \return  1 si es numerico, y si no lo es
 *
 */

int esNumerico(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
        {
            return 0;
        }
        i++;
    }
    return 1;
}

/** \brief  Verifica si el valor recibido contiene solo letras
 *
 * \param  str Array con la cadena a ser analizada
 * \param  1 si contiene solo ' ' y letras. y 0 si no lo es
 * \return
 *
 */

int esSoloLetras(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] != ' '))
        {
            return 0;
        }
        i++;
    }
    return 1;

}


/** \brief Verifica si el valor recibido contiene solo numeros, + y -
 *
 * \param  str Array con la cadena a ser realizada
 * \param
 * \return  1 si contiene solo numeros, espacios y un guion.
 *
 */

int esTelefono(char str[])
{
    int i=0;
    int contadorGuiones=0;
    while(str[i] != '\0')
    {
        if((str[i] < '0' || str[i] > '9') && (str[i] != ' ') && (str[i] != '-'))
        {
            return 0;
        }
        if(str[i] == '-')
        {
            contadorGuiones++;

        }
        i++;
    }
    if(contadorGuiones==1)
    {
        return 1;
    }
    return 0;
}



/** \brief Verifica si el valor recibido solo contiene letras y numeros
 *
 * \param  str Array con la cadena a ser analizaada
 * \param
 * \return  1 si contiene solo espacio o letras y numero, 0 y si no lo es
 *
 */

int esAlfaNumerico(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] != ' ') && (str[i] < '0' || str[i] > '9'))
        {
            return 0;
        }
        i++;
    }
    return 1;

}
/** \brief Solicita un texto numero al usuario y lo devuelve
 *
 * \param mensaje: es el mensaje a ser mostrado
 * \param input: array donde se cargara el texto ingresado
 * \return 1 si el texto contiene solo float
 *
 */

int getStringFloat(char mensaje[], char input[])
{
    char aux[256];
    printf("%s", mensaje);
    gets(aux);
    if(esFloat(aux))
    {
        strcpy(input, aux);
        return 1;
    }
    return 0;
}
/** \brief Verifica si el valor recibido es float
 *
 * \param str: Array con la cadena a ser analizada
 * \param
 * \return 1 si es float y 0 si no lo es
 *
 */

int esFloat(char str[])
{
   int i = 0;
   while(str[i] != '\0')
   {
       if((str[i] < '0' || str[i] > '9') && str[i] != '.')
           return 0;
       i++;
   }
   return 1;
}

int esMailValido(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i]<'-' && str[i]!='+') || (str[i]>'9' && str[i]<'@') ||
           (str[i]>'Z' && str[i]!='_' && str[i]<'a')|| str[i]>'z')
        {
            return 0;
        }
        i++;
    }
    return 1;

}

int getMail(char mensaje[], char input[])
{
    char aux[250];
    getString(aux,mensaje,"Error",0,250);
    if(esMailValido(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
