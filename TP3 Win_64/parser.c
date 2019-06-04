#include <stdio.h>
#include <stdlib.h>
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
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    char bufferId[TAM_BUFFER];
    char bufferNombre[TAM_BUFFER];
    char bufferHorasTrabajadas[TAM_BUFFER];
    char bufferSueldo[TAM_BUFFER];
    int retorno = FALSE;
    int flagInit = TRUE;
    Employee* pEmpleado;
    if(pFile != NULL)
    {
        while(!feof(pFile))
        {
            if(flagInit)
            {
                flagInit = FALSE;
                fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",
                                                        bufferId,
                                                        bufferNombre,
                                                        bufferHorasTrabajadas,
                                                        bufferSueldo);
            }
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

    return 1;
}
