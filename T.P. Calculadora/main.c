#include "Operaciones.h"
#include <stdlib.h>
#include <windows.h>

    int main()
    {
        int opcionA;
        int opcionB;
        char menuDeOpc;
        char flag;
        char continuar;

        printf("----------------------------Calculadora-------------------------\n");
        printf("----------------------------------------------------------------\n");
        Sleep(1000);
        printf("------------------Iniciando");
        Sleep(350);
        printf(".");
        Sleep(350);
        printf(".");
        Sleep(350);
        printf(".");
        Sleep(350);
        printf(".\n");
        Sleep(200);



do{
        printf("----------Ingrese el primer numero: ");
        fflush(stdin);
        scanf("%d", &opcionA);

        printf("----------Ingrese el segundo numero: ");
        fflush(stdin);
        scanf("%d", &opcionB);

        printf("\nXXXXXXXXXXXXXXXXXX-MENU DE OPCIONES-XXXXXXXXXXXXXXXXXX\n");

        printf("\n-----Los numeros ingresados son: %d",opcionA);
        printf(" y %d",opcionB);
    do{
        printf("\n\n1.Sumar.\n2.Restar.\n3.Multiplicar.\n4.Dividir.\n");
        printf("5.Todos los calculos anteriores.\n6.Factorial del Primer Nro.\n7.Factorial del Segundo Nro.\n8.Salir.");
        printf("\n***Ingrese el numero de operacion que desee realizar: ");

        fflush(stdin);
        scanf("%c", &menuDeOpc);
        flag = menuDeOpc;

    while(!(flag=='8'))
        {
            printf("\n-----------Realizando Calculos");
            Sleep(350);
            printf(".\a");
            Sleep(350);
            printf(".");
            Sleep(350);
            printf(".");
            Sleep(350);
            printf(".\n\a");
            Sleep(200);
            flag = '8';
        }

        switch (menuDeOpc )
            {
                case '1':
                    sumar(opcionA,opcionB);
                    break;

                case '2':
                    restar(opcionA, opcionB);
                    break;

                case '3':
                    multiplicar(opcionA, opcionB);
                    break;

                case '4':
                    dividir (opcionA,opcionB);
                    break;

                case '5':
                    sumar(opcionA,opcionB);

                    restar(opcionA, opcionB);

                    multiplicar(opcionA, opcionB);

                    dividir (opcionA,opcionB);
                    break;
                case '6':
                    if(opcionA < 0)
                    {
                        printf("Error, no existe factorial de numeros negativos. ");

                    }else
                    {
                        factorial(opcionA);
                    }
                    break;

                case '7':
                    if(opcionB < 0)
                    {
                        printf("Error, no existe factorial de numeros negativos. ");

                    }else
                    {
                        factorial(opcionB);
                    }
                    break;
                case '8':
                    break;
            }
        }while(menuDeOpc =!'8');

    printf("\n**************Desea Salir: ");
    fflush(stdin);
    scanf("%c", &continuar);


    }while(continuar=='n');


            printf("\n\n-----------------------------------------------------------------\n");
            printf("-------------------------Finalizando-----------------------------");
            Sleep(3000);
    return 0;
}




