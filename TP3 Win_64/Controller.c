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



#define BAJA_PEDIDO "Ingrese el ID del empleado: "
#define BAJA_PEDIDO_ERROR "El ID solo puede contener numeros\n"
#define BAJA_NO_ENCONRADO "El ID de empleado no fue encontrado\n"
#define BAJA_CONFIRMACION "Esta seguro que quiere dar de baja este emplado: (Confirmacion 's')"



#define MODIFICACION_PEDIDO "Ingrese el ID del empleado que quiere modificar: "
#define MODIFICACION_PEDIDO_ERROR "El ID solo puede contener numeros\n"
#define MODIFICACION_PEDIDO_NO_ENCONTRADO "El ID ingresado no fue encontrado\n"

#define MODIFICACION_CONFIRMARCION_EMPLEADO "Esta seguro que quiere modificar este empleado? (confirmacion = 's')"

#define MODIFICACION_NOMBRE "1. Modificar el nombre"
#define MODIFICACION_SUELDO "2. Modificar el sueldo"
#define MODIFICACION_HORAS "3. Modificar las horas trabajadas"
#define MODIFICACION_PEDIDO_OPCION "Ingrese el campo que quiere modificar: "
#define MODIFICACION_PEDIDO_OPCION_ERROR "La opcion ingresada es invalida\n\n"


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
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int idModificacion;
    int opcion;
    int indexModificacion;
    int retorno = FALSE;
    char confirmacion;
    Employee* pEmployeeMod = NULL;
    if (pArrayListEmployee != NULL)
    {
        if(getNumero(MODIFICACION_PEDIDO, MODIFICACION_PEDIDO_ERROR, 9, REINTENTOS, &idModificacion))
        {
            indexModificacion = employee_getIndexById(pArrayListEmployee, idModificacion);
            if (indexModificacion != -1)
            {
                pEmployeeMod = ll_get(pArrayListEmployee, indexModificacion);
                employee_showPunteroEmployee(pEmployeeMod);
                if (getString(MODIFICACION_CONFIRMARCION_EMPLEADO, &confirmacion, sizeof(confirmacion)) &&
                    (confirmacion == 's' || confirmacion == 'S'))
                {
                    printf("%s\n", MODIFICACION_NOMBRE);
                    printf("%s\n", MODIFICACION_SUELDO);
                    printf("%s\n", MODIFICACION_HORAS);
                    if (getOpcion(MODIFICACION_PEDIDO_OPCION, &opcion))
                    {
                        switch (opcion)
                        {
                            case 1:
                                if (employee_editName(pEmployeeMod))
                                {
                                    retorno = TRUE;
                                }
                                break;
                            case 2:
                                if (employee_editSueldo(pEmployeeMod))
                                {
                                    retorno = TRUE;
                                }
                                break;
                            case 3:
                                if (employee_editHorasTrabajadas(pEmployeeMod))
                                {
                                    retorno = TRUE;
                                }
                                break;
                            default:
                                printf("%s", MODIFICACION_PEDIDO_OPCION_ERROR);
                        }
                    }
                }
            } else
            {
                printf("%s", MODIFICACION_PEDIDO_NO_ENCONTRADO);
            }

        }
    }
    return retorno;
}

/** \brief Baja de empleado
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int idBaja;
    int indexBaja;
    int retorno = FALSE;
    char confirmacion;
    Employee* pEmpleadoBaja = NULL;

    if (pArrayListEmployee != NULL)
    {
        if (getNumero(BAJA_PEDIDO, BAJA_PEDIDO_ERROR, 9, REINTENTOS, &idBaja))
        {
            indexBaja = employee_getIndexById(pArrayListEmployee, idBaja);
            if (indexBaja != -1)
            {
                pEmpleadoBaja = ll_get(pArrayListEmployee, indexBaja);
                employee_showPunteroEmployee(pEmpleadoBaja);
                if(getString(BAJA_CONFIRMACION, &confirmacion, sizeof(confirmacion)) &&
                            (confirmacion == 's' || confirmacion == 'S'))
                {
                    employee_delete(ll_pop(pArrayListEmployee, indexBaja));
                    retorno = TRUE;
                }
            } else
            {
                printf("%s", BAJA_NO_ENCONRADO);
            }
        }
    }
    return retorno;
}

/** \brief Listar empleados
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = FALSE;
    if (pArrayListEmployee != NULL)
    {
        if (employee_showListEmployee(pArrayListEmployee))
        {
            retorno = TRUE;
        }
    }
    return retorno;
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
    int retorno = FALSE;
    if (pArrayListEmployee != NULL)
    {
       int opcion;
       printf("Ingrese el orden por el que quiere ser ordenado el array\n");
       printf("1. Por ID de menor a mayor\n");
       printf("2. Por ID de mayor a menor\n");
       printf("3. Por nombre de la A a la Z\n");
       printf("4. Por nombre de la Z a la A\n");
       printf("5. Por sueldo de menor a mayor\n");
       printf("6. Por sueldo de mayor a menor\n");
       printf("7. Por horas trabajadas de menor a mayor\n");
       printf("8. Por horas trabajadas de mayor a menor\n");
       if (getOpcion("Su opcion: ", &opcion))
       {
           switch (opcion)
           {
                case 1:
                    ll_sort(pArrayListEmployee, employee_criterioById, 1);
                    retorno = TRUE;
                    break;
                case 2:
                    ll_sort(pArrayListEmployee, employee_criterioById, 0);
                    retorno = TRUE;
                    break;
                case 3:
                    ll_sort(pArrayListEmployee, employee_criterioByNombre, 1);
                    retorno = TRUE;
                    break;
                case 4:
                    ll_sort(pArrayListEmployee, employee_criterioByNombre, 0);
                    retorno = TRUE;
                    break;
                case 5:
                    ll_sort(pArrayListEmployee, employee_criterioBySueldo, 1);
                    retorno = TRUE;
                    break;
                case 6:
                    ll_sort(pArrayListEmployee, employee_criterioBySueldo, 0);
                    retorno = TRUE;
                    break;
                case 7:
                    ll_sort(pArrayListEmployee, employee_criterioByHorasTrabajadas, 1);
                    retorno = TRUE;
                    break;
                case 8:
                    ll_sort(pArrayListEmployee, employee_criterioByHorasTrabajadas, 0);
                    retorno = TRUE;
                    break;
                default:
                    printf("Opcion ingreada es invalida\n\n");
           }
       }
    }
    return retorno;
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

