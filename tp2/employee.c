#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "olivieri.h"
#include "validacion.h"
#include "employee.h"


#define ALTA_PEDIR_NOMBRE "Ingrese el nombre del empleado: "
#define ALTA_ERROR_NOMBRE "El nombre no puede contener caracteres especiales ni numeros\n"
#define ALTA_PEDIR_APELLIDO "Ingrese el apellido del empleado: "
#define ALTA_ERROR_APELLIDO "El apellido no puede contener caracteres especiales ni numeros\n"
#define ALTA_PEDIR_SUELDO "Ingrese el sueldo del empleado: "
#define ALTA_ERROR_SUELDO "El sueldo no puede contener letras ni caracteres especiales"
#define ALTA_PEDIR_SECTOR "Ingrese el sector del empleado: "
#define ALTA_ERROR_SECTOR "Sector invalido\n"





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
        {1, "Tomas", "Olivieri", 5000.00, 1, 0},
        {2, "Seba", "Olivieri", 20000.00, 1, 0},
        {3, "Lucas", "Olivieri", 25000.00, 1, 0},
        {4, "Gustavo", "Olivieri", 15000.00, 1, 0},
        {5, "Pablo", "Olivieri", 50000.00, 1, 0},
    };

    for (int i = 0; i < 5 ; i++)
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


int emp_modificarEmployee (char* primeraOpcion, char* segundaOpcion ,char* pedidoEmpleado ,char* msg, char* msgError, sEmployee* employees,
                           int tamEmp, sSector* sectores, int tamSec, int reiteracion, char* msgNombre, char* msgNombreError, char* msgApellido, char* msgApellidoError)
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
                        if (getName(msgNombre, msgError, sizeof(bufferEmployee.name), 2, bufferEmployee.name))
                        {
                            strncpy(employees[indice+1].name, bufferEmployee.name, sizeof(bufferEmployee.name));
                            retorno = TRUE;
                        }
                        break;
                    case 2:
                        if (getName(msgApellido, msgApellidoError, sizeof(bufferEmployee.lastName), 2, bufferEmployee.lastName))
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


void emp_burbujeoNombre (sEmployee* employee, int tamEmp)
{
    int flag;
    do
    {
        flag = TRUE;
        for (int i = 0; i < tamEmp - 1; i++)
        {
            if(strcmp(employee[i].name, employee[i+1].name))
            {
                emp_swap(&employee[i], &employee[i+1]);
                flag = FALSE;
            } else if (strcmp(employee[i].name, employee[i+1].name) == FALSE && employee[i].sector > employee[i+1].sector)
            {
                emp_swap(&employee[i], &employee[i+1]);
                flag = FALSE;
            }
        }
    }while (flag);
}


void emp_swap (sEmployee* pa, sEmployee* pb)
{
    sEmployee buffer;
    buffer = *pa;
    *pa = *pb;
    *pb = buffer;
}



void emp_burbujeoPromedio (sEmployee* employee, int tamEmp, sSector* sectores, int tamSec)
{
    int cont = 0;
    float acum = 0;
    float promedio = 0;
    for (int i = 0; i < tamEmp; i++)
    {
        if (employee[i].isEmpty == FALSE)
        {
            acum = acum + employee[i].salary;
            cont++;
        }
    }

    promedio = acum / cont;
    for (int i = 0; i < tamEmp; i++)
    {
        if (promedio < employee[i].salary && employee[i].isEmpty == FALSE)
        {
            emp_showEmployee(employee[i], sectores, tamSec);
            printf("\n\n");
        }
    }

}


int emp_listado (char* primeraOpcion, char* segundaOpcion, char* msg, char* msgError, sEmployee* employees, int tamEmp, sSector* sectores, int tamSec)
{
    int retorno = FALSE;
    if (primeraOpcion != NULL && segundaOpcion != NULL && msg != NULL && msgError != NULL && employees != NULL && tamEmp > 0 && sectores != NULL && tamSec > 0)
    {
        char buffer[2];
        printf("%s", primeraOpcion);
        printf("%s", segundaOpcion);
        if (getString(msg, buffer, sizeof(buffer)))
        {
            switch (atoi(buffer))
            {
                case 1:
                    emp_burbujeoNombre(employees, tamEmp);
                    emp_showEmployees(employees, sectores, tamEmp, tamSec);
                    retorno = TRUE;
                    break;
                case 2:
                    emp_burbujeoPromedio(employees, tamEmp, sectores, tamSec);
                    retorno = TRUE;
                    break;
                default:
                    printf("%s",msgError);
            }
        } else
        {
            printf("%s",msgError);
        }
    }
    return retorno;
}
