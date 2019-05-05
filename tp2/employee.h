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
int emp_modificarEmployee (char* msg, char* msgError, sEmployee* employees, int tamEmp, sSector sectores, int tamSec);
int isValidID (char* buffer, sEmployee* employees, int tamEmp);
