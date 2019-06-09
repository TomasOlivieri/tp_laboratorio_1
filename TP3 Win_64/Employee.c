#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "validaciones.h"

#define TRUE 1
#define FALSE 0
#define TAM_BUFFER 300

/** \brief
 * \return Employee* UN NUEVO EMPLEADO
 */
Employee* employee_new()
{
    return (Employee*) malloc(sizeof(Employee));
}



/** \brief CREA UN NUEVO EMPLEADO YA CON PARAMETROS CARGADOS
 * \param char* idStr EL ID
 * \param char* nombreStr EL NOMBRE
 * \param char* horasTrabajadasStr LAS HORAS TRABAJADAS
 * \param char* sueldoStr EL SUELDO
 * \return 0 SI ALGO SALIO MAL, 11 SI ESTA TODO BIEN
 */
Employee* employee_newParametrosStr(char* idStr,char* nombreStr,
                                 char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* emp = NULL;
    Employee* retorno = NULL;
    if (idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
    {
        emp = employee_new();
        if (employee_setIdStr(emp, idStr) && employee_setNombre(emp, nombreStr) &&
            employee_setHorasTrabajadasStr(emp, horasTrabajadasStr) &&
            employee_setSueldoStr(emp, sueldoStr))
        {
            retorno = emp;
        } else
        {
            employee_delete(emp);
        }
    }
    return retorno;
}

Employee* employee_newParametros(int id,char* nombre,
                                 int horasTrabajadas, int sueldo)
{
    Employee* retorno = NULL;
    Employee* emp = NULL;
    if (id > 0 && nombre != NULL && horasTrabajadas > 0 && sueldo)
    {
        emp = employee_new();
        if (employee_setId(emp, id) && employee_setNombre(emp, nombre) &&
            employee_setHorasTrabajadas(emp, horasTrabajadas) && employee_setSueldo(emp, sueldo))
        {
            retorno = emp;
        } else
        {
            employee_delete(emp);
        }
    }
    return retorno;
}


/** \brief ELIMINA UN EMPLEADO
 * \param this Employee* EL EMPLEADO A ELIMINAR
 * \return int 1 SI SALIO BIEN, 0 SI ALGO SALIO MAL
 */
int employee_delete(Employee* this)
{
    int retorno = FALSE;
    if(this != NULL)
    {
        free((void*)this);
        retorno = TRUE;
    }
    return retorno;
}



/** \brief GUARDA EL ID EN UN PUNTERO A EMPLEADO
 * \param this Employee* EL PUNTERO DEL EMPLEADO
 * \param id int EL ID A SETEAR
 * \return int 0 SI ALGO SALIO MAL, 1 SI ESTA TODO BIEN
 */
int employee_setId(Employee* this, int id)
{
    int retorno = FALSE;
    if (this != NULL && id > 0)
    {
        this->id = id;
        retorno = TRUE;
    }
    return retorno;
}

/** \brief GUARDA EL ID EN FORMATO STRING
 * \param this Employee* EL EMPLEADO AL QUE LE VAMOS A GUARDAR EL ID
 * \param id char* EL ID A GUARDAR
 * \return int 1 SI ESTA TODO BIEN, 0 SI ALGO SALIO MAL
 */
int employee_setIdStr(Employee* this, char* id)
{
    int retorno = FALSE;
    if (this != NULL && id != NULL)
    {
        if (isValidId(id))
        {
            if (employee_setId(this, atoi(id)))
            {
                retorno = TRUE;
            }
        }
    }
    return retorno;
}
/** \brief OBTIENE EL ID DE UN PUNTERO A EMPLEADO
 * \param this Employee* EL PUNTERO DEL EMPLEADO
 * \param id int LA DIRECCION DONDE VAMOS A GUARDA EL ID OBTENIDO
 * \return int 0 SI ALGO SALIO MAL, 1 SI ESTA TODO BIEN
 */
int employee_getId(Employee* this, int* id)
{
    int retorno = FALSE;
    if (this != NULL && id != NULL)
    {
        *id = this->id;
        retorno = TRUE;
    }
    return retorno;
}




/** \brief GUARDA EL NOMBRE DE UN EMPLEADO
 * \param this Employee* EL EMPLEADO AL QUE LE VAMOS A GUARDAR EL NOMBRE
 * \param nombre char* EL NOMBRE
 * \return int 1 SI ESTA BIEN, 0 SI ALGO SALIO MAL
 */
int employee_setNombre(Employee* this,char* nombre)
{
    int retorno = FALSE;
    if (this != NULL && nombre != NULL)
    {
        if (isValidName(nombre))
        {
            strncpy(this->nombre, nombre, sizeof(this->nombre));
            retorno = TRUE;
        }
    }
    return retorno;
}
/** \brief OBTENER EL NOMBRE DE UN EMPLEADO
 * \param this Employee* EL EMPLEADO AL QUE LE VAMOS A OBTENER EL NOMBRE
 * \param nombre char* EL ARRAY DONDE VAMOS AL GUARDAR EL NOMBRE OBTENIDO
 * \return int
 */
int employee_getNombre(Employee* this,char* nombre)
{
    int retorno = FALSE;
    if (this != NULL && nombre != NULL)
    {
        strncpy(nombre, this->nombre, sizeof(this->nombre));
        retorno = TRUE;
    }
    return retorno;
}



/** \brief GUARDA LAS HORAS TRABAJADAS DE UN EMPLEADO
 * \param this Employee* EL EMPLEADO AL QUE LE VAMOS A GUARDAR LAS HORAS
 * \param horasTrabajadas int LAS HORAS TRABAJADAS
 * \return int 0 SI ALGO SALIO MAL, 1 SI SALI BIEN
 */
int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
    int retorno = FALSE;

    if (this != NULL && horasTrabajadas > 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        retorno = TRUE;
    }
    return retorno;
}
/** \brief GUARDA LAS HORAS TRABAJADAS EN FORMATO STRING
 * \param this Employee* EL EMPLEADO AL QUE LE VAMOS A GUARDAR LAS HORAS
 * \param horasTrabajadas char* LAS HORAS TRABAJADAS EN STRING
 * \return int 1 SI SALIO BIEN, 0 SI ALGO SALIO MAL
 */
int employee_setHorasTrabajadasStr(Employee* this, char* horasTrabajadas)
{
    int retorno = FALSE;
    if (this != NULL && horasTrabajadas != NULL)
    {
        if (isValidId(horasTrabajadas))
        {
            if (employee_setHorasTrabajadas(this, atoi(horasTrabajadas)))
            {
                retorno = TRUE;
            }

        }
    }
    return retorno;
}
/** \brief OBTIENE LAS HORAS DEL TRABAJADOR
 * \param this Employee* EL TRABAJADOR
 * \param horasTrabajadas int* EL PUNTERO DONDE VAMOS A GUARDAR LAS HORAS TRABAJADAS
 * \return int 1 SI ESTA BIEN, 0 SI ALGO SALIO MAL
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno = FALSE;
    if (this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno = TRUE;
    }
    return retorno;
}



/** \brief GUARDA EL SUELDO DE UN EMPLEADO
 * \param this Employee* EL EMPLEADO
 * \param sueldo int EL SUELDO A GUARDAR
 * \return int 0 SI ALGO SALIO MAL, 1 SI SALIO BIEN
 */
int employee_setSueldo(Employee* this, int sueldo)
{
    int retorno = FALSE;

    if (this != NULL && sueldo > 0)
    {
        this->sueldo = sueldo;
        retorno = TRUE;
    }
    return retorno;
}
/** \brief GUARDA EL SUELDO EN FORMATO STRING
 * \param this Employee* EL EMPLEADO
 * \param sueldo char* EL SUELDO
 * \return int 1 SI SALIO BIEN, 0 SI ALGO SALIO MAL
 */
int employee_setSueldoStr(Employee* this, char* sueldo)
{
    int retorno = FALSE;
    if (this != NULL && sueldo != NULL)
    {
        if (isValidId(sueldo))
        {
            if (employee_setSueldo(this, atoi(sueldo)))
            {
                retorno = TRUE;
            }

        }
    }
    return retorno;
}
/** \brief OBTIENE EL SUELDO DEL EMPLEADO
 * \param this Employee* EL EMPLEADO
 * \param sueldo int* EL ESPACIO EN MEMORIA DONDE VAMOS A GUARDAR EL SUELDO
 * \return int 1 SI SALIO BIEN, 0 SI ALGO SALIO MAL
 */
int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno = FALSE;
    if (this != NULL && sueldo != NULL)
    {
        *sueldo = this->id;
        retorno = TRUE;
    }
    return retorno;
}


/** \brief MUESTRA UN EMPLEADO
 * \param emp Employee EL EMPLEADO A MOSTRAR
 * \return void
 */
void employee_showEmployee(Employee emp)
{
    printf("ID: %d\nNombre: %s\nSueldo: %d\nHoras Trabajadas: %d\n\n",
           emp.id, emp.nombre, emp.sueldo, emp.horasTrabajadas);
}

/** \brief MUESTRA UN EMPLEADO A TRAVES DE SU PUNTERO
 * \param emp Employee* EL PUNTERO DEL EMPLEADO
 * \return void
 */
void employee_showPunteroEmployee(Employee* emp)
{
   int id;
   int sueldo;
   int horasTrabajadas;
   char nombre[TAM_BUFFER];

   if (employee_getHorasTrabajadas(emp, &horasTrabajadas) && employee_getId(emp, &id) &&
       employee_getSueldo(emp, &sueldo) && employee_getNombre(emp, nombre))
   {
       printf("ID: %d\nNombre: %s\nSueldo: %d\nHoras trabajadas: %d\n\n",
              id, nombre, sueldo, horasTrabajadas);
   }

}


/** \brief BUSCA EL INDICE DE UN EMPLEADO POR SU ID
 * \param listaEmpleados LinkedList* LA LISTA DE EMPLEADOS
 * \param id int EL ID QUE BUSCO
 * \return int EL INDICE DEL EMPLEADO SI LO ENCONTRO O -1 SI NO LO ENCONTRO
 *
 */
int employee_getIndexById(LinkedList* listaEmpleados, Employee* pEmpleadoBaja, int id)
{
    int retorno = -1;
    int idPempleado;
    Employee* pEmpleado = NULL;
    if (listaEmpleados != NULL && id > 0)
    {
        for (int i = 0; i < ll_len(listaEmpleados); i++)
        {
            pEmpleado = ll_get(listaEmpleados, i);
            employee_getId(pEmpleado, &idPempleado);
            if (id == idPempleado)
            {
                pEmpleadoBaja = pEmpleado;
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
