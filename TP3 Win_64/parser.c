#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"




#define TRUE 1
#define FALSE 0
#define TAM_BUFFER 1024

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile ,LinkedList* pArrayListEmployee)
{
    char bufferId[TAM_BUFFER];
    char bufferNombre[TAM_BUFFER];
    char bufferHorasTrabajadas[TAM_BUFFER];
    char bufferSueldo[TAM_BUFFER];
    int retorno = FALSE;
    Employee* pEmpleado;
    if(pFile != NULL)
    {
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",
                                                    bufferId,
                                                    bufferNombre,
                                                    bufferHorasTrabajadas,
                                                    bufferSueldo);

            pEmpleado = employee_newParametros( bufferId,
                                                bufferNombre,
                                                bufferHorasTrabajadas,
                                                bufferSueldo);
            if(pEmpleado != NULL)
            {
                ll_add(pArrayListEmployee, pEmpleado);
                retorno = TRUE;
            } else
            {
                printf("%s\n%s\n\n",bufferId, bufferNombre);
            }
        }
    }
    return retorno;
}

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno = FALSE;
    Employee* pEmpleado;
    int bufferId;
    char bufferNombre[128];
    int bufferHorasTrabajadas;
    int bufferSueldo;
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
    }
    return retorno;
}
