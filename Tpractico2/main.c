#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <math.h>
#include "ArrayEmployees.h"

#define A 1000
#define B 64

int main()
{
    int id=0;
    int sector;
    int opcion;
    int opcionInforme;
    int opcionOrden;
    int idBuscar;
    int index;
    int orden;

    int cantidadEmpleados=0;
    int employeeOk;

    float salary;
    char name[B];
    char lastname[B];

    Employee employeeArray [A];

     while(opcion !=5){
        opcion=menu();
        if(!validarMenu(opcion, 1, 5))
            {
                printf("\nError. Ingrese una opcion valida\n");
                opcion= 0;
                getch();
            }

        switch(opcion)
        {
        case 1:
            if (cantidadEmpleados == 0)
                    initEmployees(employeeArray, A);
                if (getFreeSpace(employeeArray, A) != -1)
                    id++;

                getStringLettersOnly(name, "\nIngrese nombre: ", B, 100);

                getStringLettersOnly(lastname, "\nIngrese Apellido: ", B, 100);

                getInt(&sector, "\nIngrese el sector:\n", "Solo se permiten numeros entre 0 y 5\n",1, 5, 3);

                getFloat(&salary, "Ingrese el salario:\n", "Un salario no puede ser negativo.\n",
                         1, pow(2, 1024), 100);
                employeeOk = addEmployee(employeeArray, A, id, name, lastname, salary, sector);
                if (employeeOk == 0)
                    {
                        cantidadEmpleados++;
                    }

            break;

            case 2:
                    if (cantidadEmpleados > 0)
                        {
                            getInt(&idBuscar, "Ingrese el ID del empleado que desea modificar\n",
                            "Solo estan permitidos numeros.\n",
                            0, A, 3);
                            index = findEmployeeById(employeeArray, A, idBuscar);

                                if (index != -1 && idBuscar != -1)
                                    {
                                    getStringLettersOnly(name, "Ingrese el nombre: \n", B, 3);

                                    getStringLettersOnly(lastname, "Ingrese el apellido: \n", B, 3);

                                    getInt(&sector, "Ingrese el sector: ", "\nSolo se permiten numeros entre 0 y 5\n", 1, 5, 3);

                                    getFloat(&salary, "\nIngrese el salario: ", "Un salario no puede ser negativo y debe estar compuesto de numeros.\n",
                                    1, pow(2, 1024), 3);
                                    modifyEmployee(employeeArray, A, idBuscar, name, lastname, salary, sector);
                                    }
                        }

                break;
            case 3:
            if (cantidadEmpleados > 0)
                {
                    idBuscar = getInt(&idBuscar, "Ingrese el ID del empleado que desea eliminar\n",
                    "Error de ingreso, solo se permiten numeros.\n",
                    0, A, 3);
                    employeeOk = removeEmployee(employeeArray, A, id);

                    if (employeeOk == 0)
                        {
                            cantidadEmpleados--;
                            id--;
                        }
                }
                break;
        case 4:
                {
                    do
                       {
                            opcionInforme = menuInformar();

                            if(!validarMenu(opcionInforme, 1, 3))
                            {
                                printf("\nError. Ingrese una opcion valida\n");
                                opcion= 0;
                                getch();
                            }

                        } while (opcionInforme != 1 && opcionInforme != 3);
                            switch (opcionInforme) {
                                case 1:
                                    fflush(stdin);
                                    opcionOrden = getInt(&orden,
                                    "-Ingrese 1 para ordenamiento ascendente\n-Ingrese 0 para ordenamiento descendente:  \n",
                                    "Solo se permiten los numeros 1 y 0.\n",
                                    0, 1, 3);

                                    if (opcionOrden != -1)
                                        {
                                            toUpperLastNameAndName(employeeArray, A);
                                            sortBySectorLastNameAndName(employeeArray, A, orden);
                                            printEmployee(employeeArray, A);
                                            getch();
                                        }
                                break;
                                case 2:
                                    printf("----------------------------------------------------------------------------------\n");
                                    printf("| Total de empleados: %d\n", cantidadEmpleados);
                                    printf("| Total de salarios: %.2lf\n", getAllSalaries(employeeArray, A));
                                    printf("| Promedio de salarios de todos los empleados: %d\n", getAverageSalaries(employeeArray, A));
                                    printf("| Empleados que superan la media salarial: %d\n", employeesAboveAverage(employeeArray, A));
                                    printf("----------------------------------------------------------------------------------\n");
                            getch();
                            break;
                    }


                }
               break;
        case 5:
            {
            break;
            }

    }
    system("cls");

}


    return 0;
}
