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
    int proxId;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do
    {
        menu(OPCION_MENSAJE, BIENVENIDA, OPCION_1, OPCION_2, OPCION_3, OPCION_4,
             OPCION_5, OPCION_6, OPCION_7, OPCION_8, OPCION_9, OPCION_10, &option);
        switch(option)
        {
        case 1:
            controller_loadFromText("data.csv", listaEmpleados, &proxId);
            printf("%d\n\n", proxId);
            break;
        case 2:
            controller_loadFromBinary("data.bin", listaEmpleados, &proxId);
            printf("%d\n\n", proxId);
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            controller_saveAsText("data.csv", listaEmpleados);
            break;
        case 9:
            controller_saveAsBinary("data.bin", listaEmpleados);
            break;
        case 10:
            break;
        default:
            printf("%s\n", OPCION_ERROR);
        }
        system("pause");
    }
    while(option != 10);
    return 0;
}
