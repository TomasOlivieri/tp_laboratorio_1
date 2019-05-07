void swap (int* pa, int* pb);
void burbujeo(int* aInt, int tam);
int getString(char* msg, char* cadena, int tam);
int getInt (char* msg, char* msgError, int minimo, int maximo, int tamDigitos, int reintentos, int* resultado);
int getFloat (char* msg, char* msgError, int tamDigitos, int reintentos, float* resultado);
int getName (char* msg, char* msgError, int caracteres, int reintentos, char* nombre);
int getOpcion (char* msg, int* opcion);
void menu(char* msg, int* opcion);
int  getConfirmacion(char* msg, char* msgError);

