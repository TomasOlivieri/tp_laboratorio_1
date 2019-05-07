typedef struct
{
    int id_employee;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}sEmployee;


typedef struct
{
    int id_sector;
    char sector[16];
}sSector;


int sec_init(sSector* sector, int tam);
int emp_init (sEmployee* employee, int tam);
int emp_buscarLibre (sEmployee* employee, int tam);
int emp_buscarIguales (sEmployee* employee, int tam, int id);
void emp_hardcode (sEmployee* employee, int tam);
int emp_alta (sEmployee* employees, int tamEmp, sSector* sectores, int tamSec);
void emp_showEmployee (sEmployee employee, sSector* sectores, int tamSec);
void emp_showEmployees (sEmployee* employees, sSector* sectores, int tamSec, int tamEmp);
void emp_obtenerStringSector (int enteroSector, sSector* sectores, int tamSector, int tamBuffer, char* charSector);
void sec_showSectores (sSector* sectores, int tamSec);
void sec_showSector (sSector sector);
int emp_getSector (char* msg, char* msgError,sSector* sectores, int tamSec, int reintentos, int* sectorEmpleado);
int isValidID (char* buffer, sEmployee* employees, int tamEmp);
int emp_modificarEmployee (char* primeraOpcion, char* segundaOpcion ,char* pedidoEmpleado ,char* msg, char* msgError, sEmployee* employees, int tamEmp, sSector* sectores, int tamSec, int reiteracion
                           , char* msgNombre, char* msgNombreError, char* msgApellido, char* msgApellidoError);
int getEmployee(sEmployee* employees, int tamEmp, sSector* sectores, int tamSec, int* indice, char* msg, char* msgError);
int menu_modificacion (char* primeraOpcion, char* segundaOpcion ,char* msgError, char* pedido ,sEmployee* employees, int tamEmp, sSector* sectores, int tamSec, int* opcion);
int emp_bajaEmpleado (char* msg, char* msgError, sEmployee* employees, int tamEmp, sSector* sectores, int tamSec);
void emp_burbujeoNombre (sEmployee* employee, int tamEmp);
void emp_swap (sEmployee* pa, sEmployee* pb);
void emp_burbujeoPromedio (sEmployee* employee, int tamEmp, sSector* sectores, int tamSec);
int emp_listado (char* primeraOpcion, char* segundaOpcion, char* msg, char* msgError, sEmployee* employees, int tamEmp, sSector* sectores, int tamSec);
