#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

#define BIENVENIDA "Bienvenido al sistema de empleados\n"


#define OPCION_1 "1. Cargar los datos desde el archivo data.csv (modo texto)"
#define OPCION_2 "2. Cargar los datos desde el archivo data.csv (modo binario)"
#define OPCION_3 "3. Alta de empleado"
#define OPCION_4 "4. Modificar datos de empleado"
#define OPCION_5 "5. Baja de empleado"
#define OPCION_6 "6. Listar empleados"
#define OPCION_7 "7. Ordenar empleados"
#define OPCION_8 "8. Guardar los datos en el archivo data.csv (modo texto)."
#define OPCION_9 "9. Guardar los datos en el archivo data.csv (modo binario)."
#define OPCION_10 "10. Salir"
#define OPCION_MENSAJE "Su opcion: "
#define OPCION_ERROR "Opcion invalida"


#define ALTA_EXITOSA "Alta exitosa\n\n"
#define ALTA_NO_EXITOSA "Usted no pudo realizar el alta\n\n"
#define BAJA_EXITOSA "Baja exitosa\n\n"
#define BAJA_NO_EXITOSA "Usted no pudo realizar la baja\n\n"
#define LISTAR_NO_EXITOSA "Algo sucedio y no se pudo hacer el listado\n\n"
#define MODIFICACION_EXITOSA "Modificacion exitosa\n\n"
#define MODIFICACION_NO_EXITOSA "Usted no pudo realizar la modificacion\n\n"


#define ERROR_CARGA_DOBLE "Usted ya cargo el archivo\n\n"
#define ERROR_GUARDADO_MODO_BINARIO "Usted cargo el archivo en modo texto\nNo lo puede guardar en modo binario!\n\n"
#define ERROR_GUARDADO_MODO_TEXTO "Usted cargo el archivo en modo binario\nNo lo puede guardar en modo texto!\n\n"
#define ERROR_ALTA_NO_CARGA "Antes de realizar una alta, primero haga una carga del archivo\n\n"
#define ERROR_BAJA_NO_CARGA "Antes de realizar una baja, primero haga una carga del archivo\n\n"
#define ERROR_LISTADO_NO_CARGA "Antes de listar a los empleados, haga una carga del archivo\n\n"
#define ERROR_MODIFICACION_NO_CARGA "Antes de realizar una edicion, primero haga una carga\n\n"

#define FINAL_PROGRAMA "Programa cerrado correctamente\n\n"


#define FALSE 0
#define TRUE 1

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 0;
    int proxId = 0;

    int flagCargar = TRUE;
    int flagBinario = FALSE;
    int flagTexto = FALSE;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do
    {
        menu(OPCION_MENSAJE, BIENVENIDA, OPCION_1, OPCION_2, OPCION_3, OPCION_4,
             OPCION_5, OPCION_6, OPCION_7, OPCION_8, OPCION_9, OPCION_10, &option);
        switch(option)
        {
        case 1:
            if (flagCargar)
            {
                controller_loadFromText("data.csv", listaEmpleados, &proxId);
                proxId++;
                flagCargar = FALSE;
                flagTexto = TRUE;
            } else
            {
                printf("%s", ERROR_CARGA_DOBLE);
            }
            break;
        case 2:
            if (flagCargar)
            {
                controller_loadFromBinary("data.bin", listaEmpleados, &proxId);
                proxId++;
                flagCargar = FALSE;
                flagBinario = TRUE;
            } else
            {
                printf("%s", ERROR_CARGA_DOBLE);
            }
            break;
        case 3:
            if (!flagCargar)
            {
                if (controller_addEmployee(listaEmpleados, &proxId))
                {
                    printf("%s", ALTA_EXITOSA);
                } else
                {
                    printf("%s", ALTA_NO_EXITOSA);
                }
            } else
            {
                printf("%s", ERROR_ALTA_NO_CARGA);
            }
            break;
        case 4:
            if (!flagCargar)
            {
                if (controller_editEmployee(listaEmpleados))
                {
                    printf("%s", MODIFICACION_EXITOSA);
                } else
                {
                    printf("%s", MODIFICACION_NO_EXITOSA);
                }
            } else
            {
                printf("%s", ERROR_MODIFICACION_NO_CARGA);
            }
            break;
        case 5:
            if (!flagCargar)
            {
                if (controller_removeEmployee(listaEmpleados))
                {
                    printf("%s", BAJA_EXITOSA);
                } else
                {
                    printf("%s", BAJA_NO_EXITOSA);
                }
            } else
            {
                printf("%s", ERROR_BAJA_NO_CARGA);
            }
            break;
        case 6:
            if (!flagCargar)
            {
                if(!controller_ListEmployee(listaEmpleados))
                {
                    printf("%s", LISTAR_NO_EXITOSA);
                }
            } else
            {
                printf("%s", ERROR_LISTADO_NO_CARGA);
            }
            break;
        case 7:
            if (!flagCargar)
            {
                controller_sortEmployee(listaEmpleados);
                printf("Ordenamiento realizado");
            } else
            {
                printf("%s", ERROR_LISTADO_NO_CARGA);
            }
            break;
        case 8:
            if (flagTexto)
            {
                controller_saveAsText("data.csv", listaEmpleados);
            } else
            {
                printf("%s", ERROR_GUARDADO_MODO_TEXTO);
            }
            break;
        case 9:
            if (flagBinario)
            {
                controller_saveAsBinary("data.bin", listaEmpleados);
            } else
            {
                printf("%s", ERROR_GUARDADO_MODO_BINARIO);
            }
            break;
        case 10:
            printf("%s", FINAL_PROGRAMA);
            break;
        default:
            printf("%s\n", OPCION_ERROR);
        }
        system("pause");
    }
    while(option != 10);
    return 0;
}
