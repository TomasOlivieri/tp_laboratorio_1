#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"


#define ALTA_NOMBRE "Ingrese el nombre del empleado: "
#define ALTA_HORAS "Ingrese las horas trabajadas por el empleado: "
#define ALTA_SUELDO "Ingrese el sueldo del empleado: "

#define ALTA_NOMBRE_ERROR "El nombre no puede contener numeros, espacios ni caracteres especiales\n\n"
#define ALTA_HORAS_ERROR "La cantidad de horas solo puede contener numero\n\n"
#define ALTA_SUELDO_ERROR "El sueldo solo puede contener numero\n\n"

#define ALTA_CONFIRMACION "Esta seguro que quiere hacer la alta de este empleado: (Confirmar= 's')"

#define FALSE 0
#define TRUE 1
#define REINTENTOS 2
#define TAM_BUFFER 300


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto)
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_loadFromText(char* path ,LinkedList* pArrayListEmployee, int* proxId)
{
    int retorno = FALSE;
    FILE* pFile = NULL;
    pFile = fopen(path,"r");
    if(parser_EmployeeFromText(pFile, pArrayListEmployee, proxId))
    {
        printf("\nArchivo cargado\n");
        retorno = TRUE;
    }
    fclose(pFile);
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee, int* proxId)
{
    int retorno = FALSE;
    FILE* pFile;
    pFile = fopen(path,"rb");
    if(parser_EmployeeFromBinary(pFile, pArrayListEmployee, proxId))
    {
        printf("\nArchivo cargado\n");
        retorno = TRUE;
    }
    fclose(pFile);
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int* proxId)
{
    int retorno = FALSE;
    char confirmacion;
    Employee bufferEmployee;
    Employee* newEmpleado = NULL;
    if (getName(ALTA_NOMBRE, ALTA_NOMBRE_ERROR, sizeof(bufferEmployee.nombre),
                REINTENTOS, bufferEmployee.nombre))
    {
        if (getNumero(ALTA_HORAS, ALTA_HORAS_ERROR, 4, REINTENTOS,
                      &bufferEmployee.horasTrabajadas))
        {
            if (getNumero(ALTA_SUELDO, ALTA_SUELDO_ERROR, 6, REINTENTOS,
                          &bufferEmployee.sueldo))
            {
                bufferEmployee.id = *proxId;
                employee_showEmployee(bufferEmployee);
                if (getString(ALTA_CONFIRMACION, &confirmacion, sizeof(confirmacion)) &&
                             (confirmacion == 's' || confirmacion == 'S'))
                {
                    newEmpleado = employee_newParametros(bufferEmployee.id, bufferEmployee.nombre,
                                                         bufferEmployee.horasTrabajadas, bufferEmployee.sueldo);

                    ll_add(pArrayListEmployee, newEmpleado);
                    autoincremental(proxId);
                    retorno = TRUE;
                }
            }
        }
    }
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = FALSE;
    FILE* pFile;
    pFile = fopen(path,"w");
    if(parser_saveAsText(pFile,pArrayListEmployee))
    {
        printf("\nArchivo guardado");
        retorno = TRUE;
    }
    fclose(pFile);
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = FALSE;
    FILE* pFile;
    pFile = fopen(path,"wb");
    if(parser_saveAsBinary(pFile,pArrayListEmployee))
    {
        printf("\nArchivo guardado");
        retorno = TRUE;
    }
    fclose(pFile);
    return retorno;
}

