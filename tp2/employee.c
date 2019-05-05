#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "olivieri.h"
#include "validacion.h"
#include "employee.h"

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
        system("pause");
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


/*int emp_modificarEmployee (char* msg, char* msgError, sEmployee* employees, int tamEmp, sSector sectores, int tamSec)
{
    int retorno = FALSE;
    if (msg != NULL && msgError != NULL && employees != NULL && sectores != NULL && tamEmp > 0 && tamSec > 0)
    {
        int indice;
        if (getEmployee(employees, tamEmp, sectores, tamSec, &indice, msg, msgError))
        {
            printf("Que quiere cambiar del empleado:\n");
            printf("1. nombre\n");
            printf("2. apellido\n");
            printf("Su opcion: ");
        }
    }
    return retorno;
}*/


int isValidID (char* buffer, sEmployee* employees, int tamEmp)
{
    int retorno = FALSE;
    if (buffer != NULL && employees != NULL && tamEmp > 0)
    {
        int contadorEmpleados = 0;
        for (int i = 0; i < tamEmp; i++)
        {
            if (employees[i].isEmpty == 0)
            {
                contadorEmpleados++;
            }
        }
        if (isValidInt(buffer, 0, contadorEmpleados))
        {
            retorno = TRUE;
        }
    }
    return retorno;
}
