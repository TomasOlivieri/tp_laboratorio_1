#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "olivieri.h"
#include "validacion.h"
#include "employee.h"


#define BAJA_PEDIR "Ingrese el id del empleado que quiera dar de baja: "
#define BAJA_ERROR "ID invalido o no encontrado\n"
#define MODIFICACION_PRIMERO "1. Modificar el nombre\n"
#define MODIFICACION_SEGUNDO "2. Modificar el apellido\n"
#define MODIFICACION_INGRESE_EMPLEADO "Ingrese el empleado que quiera modificar: "
#define MODIFICACION_ERROR_LEGAJO "Legajo invalido\n"
#define MODIFICACION_ELEGIR_EMPLEADO "Elija un empleado para modificar: "
#define MODIFICACION_PEDIR_NOMBRE "Ingrese el nuevo nombre: "
#define MODIFICACION_PEDIR_APELLIDO "Ingrese el nuevo apellido: "
#define ALTA_EXITOSA "\n\nCarga de empleado exitosa\n\n"
#define ALTA_NO_EXITOSA "\n\nUsted no ha podido ingresar un nuevo empleado\n\n"
#define MODIFICACION_EXITOSA "Usted modifico un empleado con exito\n"
#define MODIFICACION_NO_EXITOSA "Usted no ha podido modificar a un empleado\n"
#define BAJA_EXITOSA "Usted dio de baja a un empleado con exito\n"
#define BAJA_NO_EXITOSA "Usted no ha podido dar de baja a un empleado\n"
#define ALTA_PEDIR_NOMBRE "Ingrese un nombre: "
#define ALTA_PEDIR_APELLIDO "Ingrese un apellido: "
#define ALTA_PEDIR_SUELDO "Ingrese el sueldo del empleado: "
#define ALTA_PEDIR_SECTOR "Ingrese el sector del empleado: "
#define ALTA_ERROR_NOMBRE "\nNombre invalido, no puede contener caracteres especiales ni numeros\n"
#define ALTA_ERROR_APELLIDO "\nApellido invalido, no puede contener caracteres especiales ni numeros\n"
#define ALTA_ERROR_SUELDO "\nSueldo invalido, el mismo solo puede contener numeros\n"
#define ALTA_ERROR_SECTOR "\nSector ingresado es invalido\n"

#define PEDIR_CONFIRMACION "\nEsta seguro que quiere dar de alta a este empleado: (1 para confirmar) "
#define CONFIRMACION_DENEGADA "Operacion denegada\n\n"
#define REINTENTOS 2
#define TRUE 1
#define FALSE 0
#define LLENO -1




int sec_init(sSector* sector, int tam)
{
    int retorno = FALSE;

    if (sector != NULL && tam > 0)
    {
        sSector bufferSector[5] =
        {
            {1, "Juridico"},
            {2, "Contable"},
            {3, "Facturacion"},
            {4, "RRHH"},
            {5, "Sistemas"},
        };

        for (int i = 0; i <=5 ; i++)
        {
            sector[i] = bufferSector[i];
        }
        retorno = TRUE;
    }
    return retorno;
}



int emp_init (sEmployee* employee, int tam)
{
    int retorno = FALSE;
    if (employee != NULL && tam > 0)
    {
        for (int i = 0; i < tam; i++)
        {
            employee[i].isEmpty = TRUE;
        }
        retorno = TRUE;
    }
    return retorno;
}

int emp_buscarLibre (sEmployee* employee, int tam)
{
    int retorno = LLENO;
    if (employee != NULL && tam > 0)
    {
        for (int i = 0; i < tam; i++)
        {
            if (employee[i].isEmpty == TRUE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


int emp_buscarIguales (sEmployee* employee, int tam, int id)
{
    int retorno = FALSE;
    if (employee != NULL && tam > 0 && id > 0)
    {
        for (int i = 0; i < tam; i++)
        {
            if (employee[i].id_employee == id)
            {
                retorno = TRUE;
                break;
            }
        }
    }
    return retorno;
}


void emp_hardcode (sEmployee* employee, int tam)
{
    sEmployee bufferEmployee[5] =
    {
        {1, "Tomas", "Olivieri", 15000.00, 1, 0},
        {2, "Seba", "Olivieri", 20000.00, 1, 0},
        {3, "Lucas", "Olivieri", 15000.00, 1, 0},
        {4, "Gustavo", "Olivieri", 15000.00, 1, 0},
        {5, "Pablo", "Olivieri", 15000.00, 1, 0},
    };

    for (int i = 0; i <=5 ; i++)
    {
        employee[i] = bufferEmployee[i];
    }
}


int emp_alta (sEmployee* employees, int tamEmp, sSector* sectores, int tamSec)
{
    system("cls");
    int retorno = FALSE;
    if (employees != NULL && tamEmp > 0 && sectores != NULL && tamSec > 0)
    {
        sEmployee bufferEmployee;
        int indice = emp_buscarLibre(employees, tamEmp);
        if (indice != LLENO)
        {
            if (getName(ALTA_PEDIR_NOMBRE, ALTA_ERROR_NOMBRE, sizeof(bufferEmployee.name), REINTENTOS, bufferEmployee.name))
            {
                if (getName(ALTA_PEDIR_APELLIDO, ALTA_ERROR_APELLIDO, sizeof(bufferEmployee.lastName), REINTENTOS, bufferEmployee.lastName))
                {
                    if (getFloat(ALTA_PEDIR_SUELDO, ALTA_ERROR_SUELDO, 9, REINTENTOS, &bufferEmployee.salary))
                    {
                        if (emp_getSector(ALTA_PEDIR_SECTOR, ALTA_ERROR_SECTOR, sectores, tamSec, REINTENTOS, &bufferEmployee.sector))
                        {
                            system("cls");
                            bufferEmployee.id_employee = indice + 1;
                            emp_showEmployee(bufferEmployee, sectores, tamSec);
                            if (getConfirmacion(PEDIR_CONFIRMACION, CONFIRMACION_DENEGADA))
                            {
                                employees[indice] = bufferEmployee;
                                retorno = TRUE;
                            }
                        }
                    }
                }
            }
        } else
        {
            printf("\nNO HAY MAS LUGAR\n");
        }
    }
    return retorno;
}


void emp_showEmployee (sEmployee employee, sSector* sectores, int tamSec)
{
    if (sectores != NULL && tamSec > 0)
    {
        char bufferSector[16];
        emp_obtenerStringSector(employee.sector, sectores, tamSec, sizeof(bufferSector), bufferSector);
        printf("Id: %d\nNombre: %s\nApellido: %s\nSueldo: %.2f\nSector: %s", employee.id_employee, employee.name, employee.lastName, employee.salary, bufferSector);
    }
}


void emp_showEmployees (sEmployee* employees, sSector* sectores, int tamSec, int tamEmp)
{
    if (employees != NULL && sectores != NULL && tamSec > 0 && tamEmp > 0)
    {
        system("cls");
        for (int i = 0; i < tamEmp; i++)
        {
            if (employees[i].isEmpty == 0)
            {
                emp_showEmployee(employees[i], sectores, tamSec);
                printf("\n\n");
            }
        }
    }
}


void emp_obtenerStringSector (int enteroSector, sSector* sectores, int tamSector, int tamBuffer, char* charSector)
{
    if (enteroSector > 0 && sectores != NULL && tamSector > 0 && tamBuffer > 0 && charSector != NULL)
    {
        for (int i = 0; i < tamSector; i++)
        {
            if (enteroSector == sectores[i].id_sector)
            {
                strncpy(charSector, sectores[i].sector, tamBuffer);
                break;
            }
        }
    }
}


void sec_showSectores (sSector* sectores, int tamSec)
{
    printf("\n");
    for (int i = 0; i < tamSec; i++)
    {
        sec_showSector(sectores[i]);
    }
}


void sec_showSector (sSector sector)
{
    printf("Id: %d\nSector: %s\n", sector.id_sector, sector.sector);
}


int emp_getSector (char* msg, char* msgError,sSector* sectores, int tamSec, int reintentos, int* sectorEmpleado)
{
    char bufferSector[1];
    int retorno = FALSE;
    if (msg != NULL && msgError != NULL && sectores != NULL && tamSec > 0 && sectorEmpleado != NULL)
    {
        sec_showSectores(sectores, tamSec);
        do
        {
            if (getString(msg, bufferSector, sizeof(bufferSector)) && isValidSector(bufferSector, 5, 1))
            {
                *sectorEmpleado = atoi(bufferSector);
                retorno = TRUE;
                break;
            } printf(msgError);
        }while (reintentos--);
    }
    return retorno;
}


int emp_modificarEmployee (char* primeraOpcion, char* segundaOpcion ,char* pedidoEmpleado ,char* msg, char* msgError, sEmployee* employees, int tamEmp, sSector* sectores, int tamSec, int reiteracion)
{
    int retorno = FALSE;
    if (primeraOpcion != NULL && segundaOpcion != NULL && pedidoEmpleado != NULL && msg != NULL && msgError != NULL && employees != NULL && sectores != NULL && tamEmp > 0 && tamSec > 0)
    {
        sEmployee bufferEmployee;
        int opcion;
        int indice;
        if (getEmployee(employees, tamEmp, sectores, tamSec, &indice, msg, msgError))
        {
            if (menu_modificacion(primeraOpcion, segundaOpcion, msgError, pedidoEmpleado, employees, tamEmp, sectores, tamSec, &opcion))
            {
                switch (opcion)
                {
                    case 1:
                        if (getName(MODIFICACION_PEDIR_NOMBRE, "\nNOMBRE INVALIDO\n", sizeof(bufferEmployee.name), 2, bufferEmployee.name))
                        {
                            strncpy(employees[indice+1].name, bufferEmployee.name, sizeof(bufferEmployee.name));
                            retorno = TRUE;
                        }
                        break;
                    case 2:
                        if (getName(MODIFICACION_PEDIR_APELLIDO, "\nAPELLIDO INVALIDO\n", sizeof(bufferEmployee.lastName), 2, bufferEmployee.lastName))
                        {
                            strncpy(employees[indice+1].lastName, bufferEmployee.lastName, sizeof(bufferEmployee.lastName));
                            retorno = TRUE;
                        }
                        break;
                    default:
                        printf("%s" ,msgError);
                }
            }
        }
    }
    return retorno;
}


int isValidID (char* buffer, sEmployee* employees, int tamEmp)
{
    int retorno = FALSE;
    if (buffer != NULL && employees != NULL && tamEmp > 0)
    {
        int flag = FALSE;
        int max;
        for (int i = 0; i < tamEmp; i++)
        {
            if (employees[i].isEmpty == 0)
            {
                if (flag == FALSE)
                {
                    max = employees[i].id_employee;
                    flag = TRUE;
                }
                if (max < employees[i].id_employee)
                {
                    max = employees[i].id_employee;
                }
            }
        }
        if (isValidInt(buffer, 0, max))
        {
            retorno = TRUE;
        }
    }
    return retorno;
}


int getEmployee(sEmployee* employees, int tamEmp, sSector* sectores, int tamSec, int* indice, char* msg, char* msgError)
{
    int retorno = FALSE;
    if (employees != NULL && tamEmp > 0 && sectores != NULL && tamSec > 0 && indice != NULL && msg != NULL && msgError != NULL)
    {
        char buffer[5];
        emp_showEmployees(employees, sectores, tamSec, tamEmp);
        if (getString(msg, buffer, sizeof(buffer)) && isValidID(buffer, employees, tamEmp))
        {
            *indice = atoi(buffer);
            retorno = TRUE;
        } else
        {
            printf(msgError);
        }
    }
    return retorno;
}


int menu_modificacion (char* primeraOpcion, char* segundaOpcion , char* msgError,char* pedido ,sEmployee* employees, int tamEmp, sSector* sectores, int tamSec, int* opcion)
{
    int retorno = TRUE;
    if (primeraOpcion != NULL && segundaOpcion != NULL && pedido != NULL && employees != NULL && tamEmp > 0 && sectores != NULL && tamSec > 0 && opcion != NULL)
    {
        char buffer[3];
        printf("%s", primeraOpcion);
        printf("%s", segundaOpcion);
        if (getString(pedido, buffer, sizeof(buffer)))
        {
            printf("%s", buffer);
            *opcion = atoi(buffer);
            retorno = TRUE;
        }
    }
    return retorno;
}


int emp_bajaEmpleado (char* msg, char* msgError, sEmployee* employees, int tamEmp, sSector* sectores, int tamSec)
{
    int retorno = FALSE;
    if (msg != NULL && msgError != NULL && employees != NULL && tamEmp > 0 && sectores != NULL && tamSec > 0)
    {
        char buffer[2];
        emp_showEmployees(employees, sectores, tamSec, tamEmp);
        if (getString(msg, buffer, sizeof(buffer)) && isValidID(buffer, employees, tamEmp))
        {
            if (employees[atoi(buffer)+1].isEmpty == FALSE)
            {
                employees[atoi(buffer)+1].isEmpty = TRUE;
                retorno = TRUE;
            } else
            {
                printf("%s",msgError);
            }
        } else
        {
            printf("%s",msgError);
        }
    }
    return retorno;
}
