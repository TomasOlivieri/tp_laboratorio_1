#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "olivieri.h"

int menu()
{
    char opcion[5];
    int opcionValida;



    printf("1. Ingresar 1er operando\n");
    printf("2. Ingresar 2do operando\n");
    printf("3. Calcular todas las operaciones\n");
    printf("4. Informar resultados\n");
    printf("5. salir\n");
    printf("\t Su opcion: ");
    gets(opcion);
    opcionValida = validarNumero(opcion);
    return opcionValida;
}

int ingresarNumero()
{
    char numero[5];
    int numeroValido;
    int i = 0;

    system("cls");
    printf("Ingrese un numero: ");
    gets(numero);
    numeroValido = validarNumero(numero);

    while (numeroValido == -1)
    {
        i++;
        if (i == 3)
        {
            system("cls");
            printf("Usted no ha podido ingresar un numero correcto\n");
            system("pause");
            break;
        }
        printf("Usted no puede ingresar letras\n");
        printf("Ingrese un numero: ");
        gets(numero);
        numeroValido = validarNumero(numero);
    }
    return numeroValido;
}

int validarNumero(char numero[])
{
    int cantidad;
    int valido = 1;

    cantidad = strlen(numero);
    for (int i = 0; i < cantidad; i++)
    {
        if (!(numero[i] >= 48 && numero[i] <= 57))
        {
            valido = -1;
            if (i == 0 && numero[i] == 45)
            {
                valido = 1;
            }
        }
    }
    if (valido == 1)
    {
        valido = atoi(numero);
    }
    return valido;
}


void mostrarNumeros(int flag1, int flag2, int primerNumero, int segundoNumero)
{
    if (flag1 == 1)
    {
        printf("Primer numero: %d\n", primerNumero);
    } else
    {
        printf("Falta ingresar el primer numero\n");
    }
    if (flag2 == 1)
    {
        printf("Segundo numero: %d\n\n", segundoNumero);
    } else
    {
        printf("Falta ingresar el segundo numero\n\n");
    }
}

int sumar(int primerNumero, int segundoNumero)
{
    return primerNumero + segundoNumero;
}


int restar(int primerNumero, int segundoNumero)
{
    return primerNumero - segundoNumero;
}


int multiplicar(int primerNumero, int segundoNumero)
{
    return primerNumero * segundoNumero;
}


float dividir(int primerNumero, int segundoNumero)
{
    float resultado = 0;
    if (segundoNumero != 0)
    {
        resultado = primerNumero / (float)segundoNumero;
    }
    return resultado;
}

int ffactorial(int primerNumero)
{
    if (primerNumero == 0)
    {
        return 1;
    }else if (primerNumero > 0)
    {
        return (primerNumero * ffactorial(primerNumero - 1));
    } else
    {
        return 0;
    }
}

void mostrarResultados (int flagCalculo, int suma, int resta, int multiplicacion, float division, long long int factorial, int primerNumero, int segundoNumero)
{
    system("cls");
    if (flagCalculo == 1)
    {
        printf("El resultado de la suma: %d\n", suma);
        printf("El resultado de la resta: %d\n", resta);
        printf("El resultado de la multiplicacion: %d\n", multiplicacion);
        if (segundoNumero == 0)
        {
            printf("No se puede dividir por 0\n");
        } else
        {
            printf("El resultado de la division: %f\n", division);
        }
        if (primerNumero > 0)
        {
            printf("El resultado del factorial del primer numero %lld", factorial);
        } else
        {
            printf("No se puede hacer factorial de numeros negativos\n");
        }
    } else
    {
        printf("Primero calcule los resultados\n");
    }

    system("pause");
}


int cambiarBandera(int numero)
{
    int bandera = 0;
    if (numero != -1)
    {
        bandera = 1;
    }
    return bandera;
}
