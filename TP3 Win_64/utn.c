#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validaciones.h"

#define FALSE 0
#define TRUE 1


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
        char buffer[3];
        if (getString(msg, buffer, 3) && isValidOpcion(buffer))
        {
            *opcion = atoi(buffer);
            retorno = TRUE;
        }
    }
    return retorno;
}


void autoincremental (int* contador)
{
    *contador = *contador + 1;
}



int getTelefono (char* msg, char* msgError, int caracteres, int reintentos, char* telefono)
{
    int retorno = FALSE;
    if (msg != NULL && msgError != NULL && caracteres > 0 && reintentos > 0 && telefono != 0)
    {
        char buffer[caracteres*3];
        do
        {
            if (getString(msg, buffer, caracteres) == TRUE && isValidPhone(buffer, caracteres) == TRUE)
            {
                strncpy(telefono, buffer, caracteres);
                retorno = TRUE;
                break;
            }
            printf(msgError);
        } while (reintentos--);
    }
    return retorno;
}


int getSexo (char* msg, char* msgError, int caracteres, int reintentos, char* sexo)
{
    int retorno = FALSE;
    if (msg != NULL && msgError != NULL && caracteres > 0 && reintentos > 0 && sexo != 0)
    {
        char buffer[caracteres*3];
        do
        {
            if (getString(msg, buffer, caracteres) == TRUE && isValidSexo(buffer) == TRUE)
            {
                strncpy(sexo, buffer, caracteres);
                retorno = TRUE;
                break;
            }
            printf(msgError);
        } while (reintentos--);
    }
    return retorno;
}


int getTitulo (char* msg, char* msgError, int caracteres, int reintentos, char* texto)
{
    int retorno = FALSE;
    if (msg != NULL && msgError != NULL && caracteres > 0 && reintentos > 0 && texto != 0)
    {
        char buffer[caracteres*3];
        do
        {
            if (getString(msg, buffer, caracteres) == TRUE && isValidTitulo(buffer) == TRUE)
            {
                strncpy(texto, buffer, caracteres);
                retorno = TRUE;
                break;
            }
            printf(msgError);
        } while (reintentos--);
    }
    return retorno;
}


int getMail (char* msg, char* msgError, int caracteres, int reintentos, char* mail)
{
    int retorno = FALSE;
    if (msg != NULL && msgError != NULL && caracteres > 0 && reintentos > 0 && mail != NULL)
    {
        char buffer[caracteres*3];
        do
        {
            if (getString(msg, buffer, caracteres) == TRUE && isValidMail(buffer, caracteres) == TRUE)
            {
                strncpy(mail, buffer, caracteres);
                retorno = TRUE;
                break;
            }
            printf(msgError);
        } while (reintentos--);
    }
    return retorno;
}

int getNumero (char* msg, char* msgError, int caracteres, int reintentos, int* numero)
{
    int retorno = FALSE;
    if (msg != NULL && msgError != NULL && caracteres > 0 && reintentos > 0 && numero != NULL)
    {
        char buffer[caracteres*3];
        do
        {
            if (getString(msg, buffer, caracteres) == TRUE && isValidId(buffer) == TRUE)
            {
                *numero = atoi(buffer);
                retorno = TRUE;
                break;
            }
            printf(msgError);
        } while (reintentos--);
    }
    return retorno;
}

int getFecha (char* msgDia, char* msgMes, char* msgAnio, char* msgError, int reintentos, int* dia, int* mes, int* anio)
{
    int retorno = FALSE;
    if (msgDia != NULL && msgMes != NULL && msgAnio != NULL && msgError != NULL && reintentos > 0 && dia != NULL &&
        mes != NULL && anio != NULL)
    {
        char bufferDia[3];
        char bufferMes[3];
        char bufferAnio[5];
        do
        {
            if (getString(msgDia, bufferDia, sizeof(bufferDia)) == TRUE &&
                getString(msgMes, bufferMes, sizeof(bufferMes)) == TRUE &&
                getString(msgAnio, bufferAnio, sizeof(bufferAnio)) == TRUE &&
                isValidFecha(bufferDia, bufferMes, bufferAnio) == TRUE)
            {
                *dia = atoi(bufferDia);
                *mes = atoi(bufferMes);
                *anio = atoi(bufferAnio);
                retorno = TRUE;
                break;
            }
            printf(msgError);
        } while (reintentos--);
    }
    return retorno;
}

void menu(char* msg, char* msgBienvenida, char* opcion1, char* opcion2, char* opcion3, char* opcion4,
          char* opcion5, char* opcion6, char* opcion7, char* opcion8, char* opcion9,
          char* opcion10, int* opcion)
{
    if (msg != NULL && opcion1 != NULL && opcion2 != NULL && opcion3 != NULL &&
        opcion4 != NULL && opcion5 != NULL && opcion6 != NULL && opcion7 != NULL &&
        opcion8 != NULL && opcion9 != NULL && opcion10 != NULL && opcion != NULL)
    {
        system("cls");
        printf("%s", msgBienvenida);
        printf("\t%s\n", opcion1);
        printf("\t%s\n", opcion2);
        printf("\t%s\n", opcion3);
        printf("\t%s\n", opcion4);
        printf("\t%s\n", opcion5);
        printf("\t%s\n", opcion6);
        printf("\t%s\n", opcion7);
        printf("\t%s\n", opcion8);
        printf("\t%s\n", opcion9);
        printf("\t%s\n", opcion10);
        if (!getOpcion(msg, opcion))
        {
            *opcion = FALSE;
        }
    }
}

void subMenu(char* msg ,char* opcion1, char* opcion2, int* opcion)
{
    printf("%s\n", opcion1);
    printf("%s\n", opcion2);
    if (!getOpcion(msg, opcion))
    {
        *opcion = FALSE;
    }
}
