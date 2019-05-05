#include <stdio.h>
#include <stdlib.h>
#include "olivieri.h"

int main()
{
    int flag1 = 0;
    int flag2 = 0;
    int flagCalculo = 0;
    int opcion;
    int primerNumero;
    int segundoNumero;
    int suma;
    int resta;
    int multiplicacion;
    float division;
    int factorial;
    do
    {
        system("cls");
        printf("\t\tBIENVENIDOS\n\n");
        mostrarNumeros(flag1, flag2, primerNumero, segundoNumero);
        opcion = menu();
        switch (opcion)
        {
            case 1:
                primerNumero = ingresarNumero();
                flag1 = cambiarBandera(primerNumero);
                flagCalculo = 0;
                break;
            case 2:
                segundoNumero = ingresarNumero();
                flag2 = cambiarBandera(segundoNumero);
                flagCalculo = 0;
                break;
            case 3:
                if (flag1 == 1 && flag2 == 1)
                {
                    suma = sumar(primerNumero, segundoNumero);
                    resta = restar(primerNumero, segundoNumero);
                    multiplicacion = multiplicar(primerNumero,segundoNumero);
                    division = dividir(primerNumero, segundoNumero);
                    factorial = ffactorial(primerNumero);
                    printf("Calculos realizados correctamente\n");
                    system("pause");
                    flagCalculo = 1;
                } else
                {
                    printf("Primero ingrese los numeros\n");
                    system("pause");
                }
                break;
            case 4:
                mostrarResultados(flagCalculo, suma, resta, multiplicacion, division, factorial, primerNumero ,segundoNumero);
                break;
            case 5:
                printf("Fin de la calculadora\n\n");
                break;
            default:
                printf("Usted ingreso una opcion invalida\n\n");
                system("pause");
        }
    } while (opcion != 5);
    return 0;
}


