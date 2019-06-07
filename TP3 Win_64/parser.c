#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"




#define TRUE 1
#define FALSE 0
#define TAM_BUFFER 1024

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo texto).
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee, int* proxId)
{
    Employee* pEmpleado;
    Employee* buscarMaximo = NULL;
    char bufferId[TAM_BUFFER];
    char bufferNombre[TAM_BUFFER];
    char bufferHorasTrabajadas[TAM_BUFFER];
    char bufferSueldo[TAM_BUFFER];
    int bufferMax;
    int flagPrimero = TRUE;
    int flagMax = TRUE;
    int retorno = FALSE;
    if(pFile != NULL)
    {
        while(!feof(pFile))
        {
            if (flagPrimero)
            {
                fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",
                                                    bufferId,
                                                    bufferNombre,
                                                    bufferHorasTrabajadas,
                                                    bufferSueldo);
                flagPrimero = FALSE;
            }

            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",
                                                bufferId,
                                                bufferNombre,
                                                bufferHorasTrabajadas,
                                                bufferSueldo);

            pEmpleado = employee_newParametros(bufferId,
                                               bufferNombre,
                                               bufferHorasTrabajadas,
                                               bufferSueldo);

            if(pEmpleado != NULL)
            {
                ll_add(pArrayListEmployee, pEmpleado);
                retorno = TRUE;
            }
        }
        for (int i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            buscarMaximo = ll_get(pArrayListEmployee, i);
            employee_getId(buscarMaximo, &bufferMax);
            if (flagMax)
            {
                employee_getId(buscarMaximo, proxId);
                flagMax = FALSE;
            }
            if (*proxId < bufferMax)
            {
                employee_getId(buscarMaximo, proxId);
            }
        }
    }
    return retorno;
}

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo binario).
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee, int* proxId)
{
    Employee* pEmpleado;
    Employee* buscarMax = NULL;
    int retorno = FALSE;
    int flagMax = TRUE;
    int bufferMax;
    int bufferId;
    int bufferHorasTrabajadas;
    int bufferSueldo;
    char bufferNombre[TAM_BUFFER];
    if(pFile!=NULL)
    {
        while(!feof(pFile))
        {
            pEmpleado = employee_new();
            fread(pEmpleado,sizeof(Employee),1,pFile);
            employee_getId(pEmpleado,&bufferId);
            employee_getNombre(pEmpleado,bufferNombre);
            employee_getHorasTrabajadas(pEmpleado,&bufferHorasTrabajadas);
            employee_getSueldo(pEmpleado,&bufferSueldo);
            if( bufferId >= 0 && strlen(bufferNombre) > 0 &&
                bufferHorasTrabajadas > 0 && bufferSueldo > 0)
            {
                ll_add(pArrayListEmployee, pEmpleado);
                retorno = TRUE;
            }
        }
        for (int i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            buscarMax = ll_get(pArrayListEmployee, i);
            employee_getId(buscarMax, &bufferMax);
            if (flagMax)
            {
                employee_getId(buscarMax, proxId);
                flagMax = FALSE;
            }
            if (*proxId < bufferMax)
            {
                employee_getId(buscarMax, proxId);
            }
        }
    }
    return retorno;
}


/** \brief
 * \param pFile FILE*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int parser_saveAsText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno = FALSE;
    Employee* pEmpleado;
    int bufferId;
    char bufferNombre[TAM_BUFFER];
    int bufferHorasTrabajadas;
    int bufferSueldo;
    if(pFile != NULL)
    {
        fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");
        for(int i = 0; i<ll_len(pArrayListEmployee); i++)
        {
            pEmpleado = ll_get(pArrayListEmployee,i);
            employee_getId(pEmpleado,&bufferId);
            employee_getNombre(pEmpleado,bufferNombre);
            employee_getHorasTrabajadas(pEmpleado,&bufferHorasTrabajadas);
            employee_getSueldo(pEmpleado,&bufferSueldo);
            if( bufferId >= 0 && strlen(bufferNombre) > 0 &&
                bufferHorasTrabajadas > 0 && bufferSueldo > 0)
            {
                fprintf(pFile,"%d,%s,%d,%d\n",  bufferId,bufferNombre,
                                                bufferHorasTrabajadas,
                                                bufferSueldo);
                retorno = FALSE;
            }
        }
    }
    return retorno;
}


/** \brief
 * \param pFile FILE*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int parser_saveAsBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno = FALSE;
    Employee* pEmpleado;
    int bufferId;
    char bufferNombre[TAM_BUFFER];
    int bufferHorasTrabajadas;
    int bufferSueldo;
    if(pFile != NULL)
    {
        for(int i=0; i<ll_len(pArrayListEmployee); i++)
        {
            pEmpleado = ll_get(pArrayListEmployee,i);
            employee_getId(pEmpleado,&bufferId);
            employee_getNombre(pEmpleado,bufferNombre);
            employee_getHorasTrabajadas(pEmpleado,&bufferHorasTrabajadas);
            employee_getSueldo(pEmpleado,&bufferSueldo);
            if( bufferId >= 0 && strlen(bufferNombre) > 0 &&
                bufferHorasTrabajadas > 0 && bufferSueldo > 0)
            {
                fwrite(pEmpleado,sizeof(Employee),1,pFile);
                retorno = TRUE;
            }
        }
    }
    return retorno;
}
