int getString(char* msg, char* cadena, int tam);
int getInt (char* msg, char* msgError, int minimo, int maximo, int tamDigitos, int reintentos, int* resultado);
int getFloat (char* msg, char* msgError, int tamDigitos, int reintentos, float* resultado);
int getName (char* msg, char* msgError, int caracteres, int reintentos, char* nombre);
int getOpcion (char* msg, int* opcion);
void autoincremental (int* contador);
int getTelefono (char* msg, char* msgError, int caracteres, int reintentos, char* telefono);
int getSexo (char* msg, char* msgError, int caracteres, int reintentos, char* sexo);
int getTitulo (char* msg, char* msgError, int caracteres, int reintentos, char* texto);
int getMail (char* msg, char* msgError, int caracteres, int reintentos, char* mail);

void menu(char* msg, char* msgBienvenida, char* opcion1, char* opcion2, char* opcion3, char* opcion4,
          char* opcion5, char* opcion6, char* opcion7, char* opcion8, char* opcion9,
          char* opcion10, int* opcion);

int getFecha (char* msgDia, char* msgMes, char* msgAnio, char* msgError, int reintentos, int* dia, int* mes, int* anio);
void subMenu(char* msg, char* opcion1, char* opcion2, int* opcion);
