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
#define ELEGIR_OPCION "\nSu opcion: "
#define TAM_EMPLOYEE 1000
#define TAM_SECTOR 5
#define FALSE 0
#define TRUE 1




int main()
{
    sEmployee employee[TAM_EMPLOYEE];
    sSector sector[TAM_SECTOR];
    if (emp_init(employee, TAM_EMPLOYEE) && sec_init(sector, TAM_SECTOR))
    {
        emp_hardcode(employee, TAM_EMPLOYEE);
        int opcion;
        do
        {
            menu(ELEGIR_OPCION, &opcion);
            switch (opcion)
            {
                case 1:
                    if (emp_alta(employee, TAM_EMPLOYEE, sector, TAM_SECTOR))
                    {
                        printf("%s", ALTA_EXITOSA);
                    } else
                    {
                        printf("%s", ALTA_NO_EXITOSA);
                    }
                    system("pause");
                    break;
                case 2:
                    if (emp_modificarEmployee(MODIFICACION_PRIMERO, MODIFICACION_SEGUNDO, MODIFICACION_INGRESE_EMPLEADO
                                              ,MODIFICACION_ELEGIR_EMPLEADO, MODIFICACION_ERROR_LEGAJO, employee,
                                                TAM_EMPLOYEE, sector,TAM_SECTOR, 2))
                    {
                        printf("%s", MODIFICACION_EXITOSA);
                    } else
                    {
                        printf("%s", MODIFICACION_NO_EXITOSA);
                    }
                    system("pause");
                    break;
                case 3:
                    if (emp_bajaEmpleado(BAJA_PEDIR, BAJA_ERROR, employee, TAM_EMPLOYEE, sector, TAM_SECTOR))
                    {
                        printf("%s", BAJA_EXITOSA);
                    } else
                    {
                        printf("%s", BAJA_NO_EXITOSA);
                    }
                    system("pause");
                    break;
                case 4:
                    emp_showEmployees(employee, sector, TAM_SECTOR, TAM_EMPLOYEE);
                    system("pause");
                    break;
                case 5:
                    printf("salir\n");
                    break;
                default:
                    printf("Usted ingreso una opcion erronea\n");
                    system("pause");
            }
        } while (opcion != 5);
    }
    return 0;
}


