#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "olivieri.h"
#include "validacion.h"
#include "employee.h"

#define MENSAJE_BIENVENIDA "*****BIENVENIDO AL SISTEMA DE EMPLEADOS*****"
#define OPCION1 "1. Dar de alta un empleado"
#define OPCION2 "2. Modificar empleado"
#define OPCION3 "3. Dar de baja un empleado"
#define OPCION4 "4. Listar empleados"
#define OPCION5 "5. Salir"
#define ERROR_OPCION "Su opcion ha sido invalida"
#define FALSE 0
#define TRUE 1



void burbujeoInt(int* aInt, int tam)
{
    int flag;
    do
    {
        flag = TRUE;
        for (int i = 0; i < tam - 1; i++)
        {
            if(aInt[i] > aInt[i + 1])
            {
                swapInt(&aInt[i], &aInt[i + 1]);
                flag = FALSE;
            }
        }
    }while (flag);
}

void swapChar(char* pa, char* pb)
{
    char buffer[51];
    strcpy(buffer, pa);
    strcpy(pa, pb);
    strcpy(pb, buffer);
}



void swapInt(int* pa, int* pb)
{
    int aux;
    aux = *pa;
    *pa = *pb;
    *pb = aux;
}


int getString(char* msg, char* cadena, int tam)
{
    int retorno = FALSE;
    if(msg != NULL && cadena != NULL && tam > 0)
    {
        int largo;
        char buffer[tam*3];
        printf(msg);
        fgets(buffer, sizeof(buffer), stdin);
        largo = strlen(buffer);
        if (largo != 1)
        {
            buffer[largo-1] = '\0';
            fflush(stdin);
            if (largo-1 <= tam)
            {
                strncpy(cadena, buffer, tam);
                retorno = TRUE;
            }
        }
    }
    return retorno;
}


int getInt (char* msg, char* msgError, int minimo, int maximo, int tamDigitos, int reintentos, int* resultado)
{
    int retorno = FALSE;

    if (msg != NULL && msgError != NULL && maximo > minimo && tamDigitos > 0 && reintentos > 0 && resultado != NULL)
    {
        char buffer[tamDigitos*3];
        do
        {
            if (getString(msg, buffer, tamDigitos) == TRUE && isValidInt(buffer, minimo, maximo) == TRUE)
            {
                *resultado = atoi(buffer);
                retorno = TRUE;
                break;
            }
            printf(msgError);
        }while (reintentos--);
    }
    return retorno;
}


int getFloat (char* msg, char* msgError, int tamDigitos, int reintentos, float* resultado)
{
    int retorno = FALSE;

    if (msg != NULL && msgError != NULL && tamDigitos > 0 && reintentos > 0 && resultado != NULL)
    {
        char buffer[tamDigitos*3];
        do
        {
            if (getString(msg, buffer, tamDigitos) == TRUE && isValidFloat(buffer) == TRUE )
            {
                *resultado = atof(buffer);
                retorno = TRUE;
                break;
            }
            printf(msgError);
        }while (reintentos--);
    }
    return retorno;
}



int getName (char* msg, char* msgError, int caracteres, int reintentos, char* nombre)
{
    int retorno = FALSE;
    if (msg != NULL && msgError != NULL && caracteres > 0 && reintentos > 0 && nombre != 0)
    {
        char buffer[caracteres*3];
        do
        {
            if (getString(msg, buffer, caracteres) == TRUE && isValidName(buffer) == TRUE)
            {
                strncpy(nombre, buffer, caracteres);
                retorno = TRUE;
                break;
            }
            printf(msgError);
        } while (reintentos--);
    }
    return retorno;
}


int getOpcion (char* msg, int* opcion)
{
    int retorno = FALSE;
    if (msg != NULL)
    {
        char buffer[1];
        if (getString(msg, buffer, 1) && isValidOpcion(buffer))
        {
            *opcion = atoi(buffer);
            retorno = TRUE;
        }
    }
    return retorno;
}


void menu(char* msg, int* opcion)
{
    system("cls");
    printf("%s", MENSAJE_BIENVENIDA);
    printf("\n\t%s", OPCION1);
    printf("\n\t%s", OPCION2);
    printf("\n\t%s", OPCION3);
    printf("\n\t%s", OPCION4);
    printf("\n\t%s", OPCION5);
    if (!getOpcion(msg, opcion))
    {
        *opcion = FALSE;
    }
}


int  getConfirmacion(char* msg, char* msgError)
{
    int retorno = FALSE;
    if (msg != NULL && msgError != NULL)
    {
        char buffer[2];
        if (getString(msg, buffer, 2) && isValidOpcion(buffer))
        {
            if (atoi(buffer) == 1)
            {
                retorno = TRUE;
            } else
            {
                printf(msgError);
            }
        }
    }
    return retorno;
}





