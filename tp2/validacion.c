#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "olivieri.h"
#include "validacion.h"
#include "employee.h"
#define FALSE 0
#define TRUE 1



int isValidInt(char* buffer, int min, int max)
{
    int retorno = FALSE;
    if(buffer != NULL && max > min)
    {
        int valid = TRUE;
        for (int i = 0; buffer[i] != '\0'; i++)
        {
            if (!(buffer[i] >= '0' && buffer[i] <= '9'))
            {
                valid = FALSE;
                break;
            }
        }

        if (valid == TRUE)
        {
            valid = atoi(buffer);
            if (valid > min && valid <= max)
            {
                retorno = TRUE;
            }
        }
    }
    return retorno;
}


int isValidFloat(char* buffer)
{
    int retorno = FALSE;
    if(buffer != NULL)
    {
        retorno = TRUE;
        for (int i = 0;buffer[i] == '\0'; i++)
        {
            if (!(buffer[i] >= '0' && buffer[i] <= '9'))
            {
                retorno = FALSE;
                break;
            }
        }
    }
    return retorno;
}


int isValidName (char* buffer)
{
    int retorno = FALSE;
    if (buffer != NULL)
    {
        retorno = TRUE;
        for (int i = 0; buffer[i] != '\0'; i++)
        {
            if(!(tolower(buffer[i]) >= 'a' && tolower(buffer[i]) <= 'z'))
            {
                retorno = FALSE;
                break;
            }
        }
    }
    return retorno;
}



int isValidOpcion (char* buffer)
{
    int retorno = FALSE;
    if (buffer != NULL)
    {
        if (*buffer > '0' && *buffer < '9')
        {
            retorno = TRUE;
        }
    }
    return retorno;
}


int isValidSector (char* buffer, int max, int min)
{
    int retorno = FALSE;
    if (buffer != NULL)
    {
        if (*buffer > '0' && *buffer < '9')
        {
            if (atoi(buffer) <= max && atoi(buffer) >= min)
            {

                retorno = TRUE;
            }
        }
    }
    return retorno;
}



