typedef struct
{
    int id_employee;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}Employee;


typedef struct
{
    int id_sector;
    char sector[16];
}Sector;


int sec_init(Sector* sector, int tam);
int emp_init (Employee* employee, int tam);
int emp_buscarLibre (Employee* employee, int tam);
int emp_buscarIguales (Employee* employee, int tam, int id);
void emp_hardcode (Employee* employee, int tam);
int emp_alta (Employee* employees, int tamEmp, Sector* sectores, int tamSec);
void emp_showEmployee (Employee employee, Sector* sectores, int tamSec);
void emp_showEmployees (Employee* employees, Sector* sectores, int tamSec, int tamEmp);
void emp_obtenerStringSector (int enteroSector, Sector* sectores, int tamSector, int tamBuffer, char* charSector);
void sec_showSectores (Sector* sectores, int tamSec);
void sec_showSector (Sector sector);
int emp_getSector (char* msg, char* msgError, Sector* sectores, int tamSec, int reintentos, int* sectorEmpleado);
int isValidID (char* buffer, Employee* employees, int tamEmp);
int emp_modificarEmployee (char* primeraOpcion, char* segundaOpcion ,char* pedidoEmpleado ,char* msg, char* msgError,
                           Employee* employees, int tamEmp, Sector* sectores, int tamSec, int reiteracion,
                           char* msgNombre, char* msgNombreError, char* msgApellido, char* msgApellidoError);

int getEmployee(Employee* employees, int tamEmp, Sector* sectores, int tamSec, int* indice, char* msg, char* msgError);
int menu_modificacion (char* primeraOpcion, char* segundaOpcion ,char* msgError, char* pedido,
                       Employee* employees, int tamEmp, Sector* sectores, int tamSec, int* opcion);
int emp_bajaEmpleado (char* msg, char* msgError, Employee* employees, int tamEmp, Sector* sectores, int tamSec);
void emp_burbujeoNombre (Employee* employee, int tamEmp);
void emp_swap (Employee* pa, Employee* pb);
void emp_burbujeoPromedio (Employee* employee, int tamEmp, Sector* sectores, int tamSec);
int emp_listado (char* primeraOpcion, char* segundaOpcion, char* msg, char* msgError, Employee* employees, int tamEmp, Sector* sectores, int tamSec);
