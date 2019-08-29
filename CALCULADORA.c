#include <stdio.h>
#include <stdlib.h>

float sumar (int num1, int num2);
float restar (int num1, int num2);
float dividir (int num1, int num2);
float multiplicar (int num1, int num2);
float factorial (int num1);
void mostrar (float resultado);

int main()
{
    int num1;
    int num2;
    int opcion;
    char seguir = 's';

    while(seguir == 's')
    {
        printf("1-Ingrese primer operando :\n2-Ingrese segundo operando :\n3-Calcular todas las operaciones\n4-Informar resultados\n5-Salir\n\nIngresar opcion :");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            printf("Ingresar primer operando :");
            scanf("%d", &num1);
            break;
        case 2:
            printf("Ingresar segundo operando :");
            scanf("%d", &num2);
            break;
        case 3:
            calculadora(num1,num2,opcion);
            break;
        case 4:

            break;


        }

    }


    return 0;
}

void calculadora(int num1,int num2,int opcion)
{
    float resultado;
    char seguir = 's';


    switch(opcion)
    {
    case 1:
        resultado = sumar(num1,num2);
        break;
    case 2:
        resultado = restar(num1,num2);
        break;
    case 3:
        resultado = dividir(num1,num2);
        break;
    case 4:
        resultado = multiplicar(num1,num2);
        break;
    case 5:
        resultado= factorial(num1);

        break;
    case 6:
        seguir == 'n';
        break;

    }
    mostrar(resultado);
}

float sumar (int num1, int num2)
{
    return num1+num2;

}

float restar (int num1, int num2)
{
    return num1-num2;
}

float dividir (int num1, int num2)
{
    return num1/num2;
}

float multiplicar (int num1, int num2)
{

    return num1*num2;

}

float factorial (int num1)
{
    float resultado;
    float fact =1;
    for(int i=1; i<=num1; i++)
    {
        fact=fact*i;
    }
    resultado=fact;

    return resultado;
}

void mostrar (float resultado)
{
    printf("El resultado es :%.2f", resultado);
}
