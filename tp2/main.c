#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "olivieri.h"
#include "validacion.h"
#include "employee.h"

#define ALTA_EXITOSA "\n\nCarga de empleado exitosa\n\n"
#define ALTA_NO_EXITOSA "\n\nUsted no ha podido ingresar un nuevo empleado\n\n"
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
                    printf("opcion2\n");
                    system("pause");
                    break;
                case 3:
                    printf("opcion3\n");
                    system("pause");
                    break;
                case 4:
                    printf("opcion4\n");
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


