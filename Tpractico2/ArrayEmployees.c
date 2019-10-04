
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <math.h>
#include "ArrayEmployees.h"


static int getI(int *pBuffer) {

    return scanf("%d", pBuffer);

}

static char getC(char *pBuffer) {
    fflush(stdin);

    return scanf("%c", pBuffer);


}

static float getF(float *pBuffer) {

    return scanf("%f", pBuffer);

}

int menu()
{

    int opcion;
    printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
    printf("XXXXXXXXXX--MENU DE OPCIONES-XXXXXXXXXXX\n");
    printf("----------------------------------------\a");
    printf("\n| 1. ALTA.                             |");
    printf("\n| 2. MODIFICACION.                     |");
    printf("\n| 3. BAJA.                             |");
    printf("\n| 4. INFORMAR.                         |");
    printf("\n| 5. SALIR.                            |\n");
    printf("----------------------------------------");
    printf("\n Ingrese una opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);
    return opcion;

}

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployees(Employee employeeArray[], int len) {
    int i;
    for (i = 0; i < len; i++) {
        employeeArray[i].isEmpty = 1;
    }
    return -1;

}

/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*
*/

int addEmployee(Employee employeeArray[], int len, int id, char name[], char lastName[], float salary, int sector) {
    int i;
    i = getFreeSpace(employeeArray, len);
    if (i != -1) {
        employeeArray[i].isEmpty = 0;
        employeeArray[i].id = id;
        strcpy(employeeArray[i].name, name);
        strcpy(employeeArray[i].lastName, lastName);
        employeeArray[i].salary = salary;
        employeeArray[i].sector = sector;
        return 0;
    }
    return -1;
}

/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int
*
*/

void printEmployee(Employee employeeArray[], int len)
{
   int i;
    system("cls");
    for (i = 0; i < len; i++) {
        if (employeeArray[i].isEmpty == 0) {
            printf("------------------------------------------------------------\n");
            printf("ID   |   NOMBRE   |   APELLIDO   |   SALARIO   |   SECTOR\n");
            printf("*%d  | %s       | %s         | %2.f     | %d *\n", employeeArray[i].id,employeeArray[i].name, employeeArray[i].lastName,employeeArray[i].salary, employeeArray[i].sector);
            printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
        }
    }


}


int menuInformar()
{
    int opcion=0;
    system("cls");
    printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
    printf("-------------MENU DE INFORMES-------------\n");
    printf("------------------------------------------");
    printf("\n| 1. LISTAR EMPLEADOS.                   |");
    printf("\n| 2. CALCULAR PROMEDIO DE SALARIO.       |");
    printf("\n| 3. SALIR.                              |\n");
    printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    printf("\nIngrese una opcion a realizar: ");
    fflush(stdin);
    scanf("%d",&opcion);
    return opcion;
}

/**
 * String getter
 * param mensaje *msg pointer to array of chars
 * param input *input pointer to array of chars
 */
void getString(char input[], char msg[]) {
    fflush(stdin);
    printf("%s", msg);
    fgets(input, 200, stdin);
    input[strcspn(input, "\n")] = 0;
}


/**
 * \brief Gets int
 * \param pInt *pInt pointer to int variable.
 * \param msg msg* Pointer to array of chars
 * \param msg Error msg Error* Pointer to array of chars
 * \param min int minimum of number to enter
 * \param max int maximum of number to enter
 * param retries int amount of retries user has
 * return int returns (-1) if Error [Not between min and max or not number] - (0) if OK
 *
 */
int getInt(int *pInt, char msg[], char msgError[], int min, int max, int retries) {
    int returnNum = -1;
    int bufferInt = 0;
    if (pInt != NULL && msg != NULL && msgError != NULL && min <= max && retries >= 0) {
        do {
            retries--;
            printf("%s", msg);
            fflush(stdin);
            if (getI(&bufferInt) && bufferInt >= min && bufferInt <= max) {
                *pInt = bufferInt;
                returnNum = 0;
                break;

            } else {
                printf("%s", msgError);

            }


        } while (retries > 0);

    }
    return returnNum;


}


int validarMenu(int menu, int min, int max) {
    if (menu >= min && menu <= max) {
        return 1;
    } else
        return 0;

}

int getStringLettersOnly(char *input, char *msg, int len, int retries) {
    char aux[len];
    do {
        getString(aux, msg);
        if (isLetter(aux)) {
            strcpy(input, aux);
            return 1;
        } else {
            retries--;
            printf("El nombre debe ser solo letras y no puede estar vacio.\n");
        }

    } while (retries >= 0);
    return 0;
}

int getFreeSpace(Employee employeeArray[], int len) {

    int i;
    int retorno;
    for (i = 0; i < len; i++) {
        if (employeeArray[i].isEmpty == 1) {
            retorno = i;
            break;
        }
        if(i==len)
            {
                system("cls");
                retorno = -1;
                printf("No hay espacio en el array para agregar mas empleados.\n");
            }
    }
    return retorno;

}

int getFloat(float *pFloat, char msg[], char msgError[], float min, float max, int retries) {
    int returnNum = -1;
    float bufferFloat = 0;
    if (pFloat != NULL && msg != NULL && msgError != NULL && min <= max && retries >= 0) {
        do {
            retries--;
            printf("%s", msg);
            fflush(stdin);
            if (getF(&bufferFloat) && bufferFloat >= min && bufferFloat <= max) {

                *pFloat = bufferFloat;
                returnNum = 0;
                break;

            } else {
                printf("%s", msgError);

            }


        } while (retries > 0);

    }
    return returnNum;


}

/**
 * \brief Checks if it is a letter(includes space)
 * \param c c* Pointer to array of chars
 * \return int return 1 if its a letter or 0 if it is there a space or enter in the first element or if it is not a letter
 */
int isLetter(char c[]) {
    int i = 0;
    if (c[0] == ' ' || c[0] == '\r')
        return 0;
    while (c[i] != '\0') {
        if (!(c[i] >= 'a' && c[i] <= 'z' || c[i] >= 'A' && c[i] <= 'Z') && c[i] != ' ')
            return 0;
        i++;
    }
    return 1;
}

/**
 * \brief Gets total of all salaries
 * \param employee *eEmployee pointer to array of structs of type eEmployee
 * \param len int size of array
 * \return int total of salaries
 */
float getAllSalaries(Employee employeeArray[] , int len) {
    float salaries = 0;
    int i;
    for (i = 0; i < len; i++)
        {
        if (employeeArray[i].isEmpty == 0)
            {
                salaries += employeeArray[i].salary;
            }

        }
    return salaries;
}
/**
 *  \brief Gets average salaries of employees
 *\param employee *eEmployee pointer to array of structs of type eEmployee
 * \param len int size of array
 * \return int average of all salaries in array of employees
 */
int getAverageSalaries(Employee employee_Array[], int len)
    {
    int i, averageSalaries = 0, rangeOfNotEmptyEmployees = 0;
    for (i = 0; i < len; i++)
        {
        if (employee_Array[i].isEmpty == 0)
            {
                averageSalaries += employee_Array[i].salary;
                rangeOfNotEmptyEmployees++;
            }
        }
    return averageSalaries / rangeOfNotEmptyEmployees;
}
/**
 * \brief Gets the employees that are above average salary
 * \param employee *eEmployee pointer to array of structs of type eEmployee
 * \param len int size of array
 * \return int returns employees that are above average salary
 */
int employeesAboveAverage(Employee employeeArray[], int len) {
    int getAverageSalary = getAverageSalaries(employeeArray, len);
    int i, employessAboveAverage = 0;
    for (i = 0; i < len; i++)
        {
            if (employeeArray[i].isEmpty == 0 && employeeArray[i].salary > getAverageSalary)
                {
                    employessAboveAverage++;

                }
        }
    return employessAboveAverage;
}

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
void sortBySectorLastNameAndName(Employee employeeArray[] , int len, int order) {
    int i;
    int j;
    Employee auxEmployee;

    if (order == 1) {
        for (i = 0; i < len - 1; i++) {
            for (j = i; j < len; ++j) {
                if (employeeArray[i].sector > employeeArray[j].sector) {
                    auxEmployee = employeeArray[i];
                    employeeArray[i] = employeeArray[j];
                    employeeArray[j] = auxEmployee;
                }

            }

        }
        for (i = 0; i < len - 1; i++) {
            for (j = i; j < len; ++j) {
                if (strcmp(employeeArray[i].lastName, employeeArray[j].lastName) > 0 &&
                    employeeArray[i].sector == employeeArray[j].sector) {
                    auxEmployee = employeeArray[i];
                    employeeArray[i] = employeeArray[j];
                    employeeArray[j] = auxEmployee;
                } else if (strcmp(employeeArray[i].lastName, employeeArray[j].lastName) == 0 &&
                           employeeArray[i].sector == employeeArray[j].sector) {
                    if (strcmp(employeeArray[i].name, employeeArray[j].name) > 0) {
                        auxEmployee = employeeArray[i];
                        employeeArray[i] = employeeArray[j];
                        employeeArray[j] = auxEmployee;
                    }

                }

            }

        }
    }
    if (order == 0) {
        for (i = 0; i < len - 1; i++) {
            for (j = i; j < len; ++j) {
                if (employeeArray[i].sector < employeeArray[j].sector) {
                    auxEmployee = employeeArray[i];
                    employeeArray[i] = employeeArray[j];
                    employeeArray[j] = auxEmployee;
                }

            }

        }
        for (i = 0; i < len - 1; i++) {
            for (j = i; j < len; ++j) {
                if (strcmp(employeeArray[i].lastName, employeeArray[j].lastName) < 0 &&
                    employeeArray[i].sector == employeeArray[j].sector) {
                    auxEmployee = employeeArray[i];
                    employeeArray[i] = employeeArray[j];
                    employeeArray[j] = auxEmployee;
                } else if (strcmp(employeeArray[i].lastName, employeeArray[j].lastName) == 0 &&
                           employeeArray[i].sector == employeeArray[j].sector) {
                    if (strcmp(employeeArray[i].name, employeeArray[j].name) < 0) {
                        auxEmployee = employeeArray[i];
                        employeeArray[i] = employeeArray[j];
                        employeeArray[j] = auxEmployee;
                    }

                }

            }

        }
    }


}

/**
 * \brief Turns to upper every single letter of name and last name.
 * \param employee eEmployee* Pointer to array of employees
 * \param len int size of array
 */
void toUpperLastNameAndName(Employee employeeArray[], int len) {
    int i;
    int j;
        for (i = 0; i < len; i++)
            {
                for (j = 0; j < strlen(employeeArray[i].lastName); ++j)
                {
                    employeeArray[i].lastName[j] = toupper(employeeArray[i].lastName[j]);
                }
            }
            for (i = 0; i < len; i++)
                {
                    for (j = 0; j < strlen(employeeArray[i].name); ++j)
                        {
                            employeeArray[i].name[j] = toupper(employeeArray[i].name[j]);
                        }
                }
}

/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int findEmployeeById(Employee employeeArray[], int len, int id) {
    int i;
        for (i = 0; i < len; i++)
            {
                if (id == employeeArray[i].id)
                {
                return i;
                }
            }
    printf("No se encontraron empleados con ID %d.\n", id);
    return -1;
}

/**
 * \brief Modifies employee selected by the id
 * \param employee_Array pointer to array of structs of type eEmployee
 * \param len int size of array
 * \param id int id of employee
 * \param name *name pointer to array of chars
 * \param lastName *lastName pointer to array of chars
 * \param salary int salary of employee
 * \param sector int sector of employee
 * \return returns 0 if employee was deleted -1 if operation was cancelled
 */
int modifyEmployee(Employee employeeArray[], int len, int id, char name[], char lastName[], float salary, int sector) {
    int i;
        for (i = 0; i < len; ++i)
            {
                if (employeeArray[i].id == id && employeeArray[i].isEmpty == 0)
                    {
                    employeeArray[i].isEmpty = 0;
                    employeeArray[i].id = id;
                    strcpy(employeeArray[i].name, name);
                    strcpy(employeeArray[i].lastName, lastName);
                    employeeArray[i].salary = salary;
                    employeeArray[i].sector = sector;

                    printf("Se ha completado su operacios, su ID %d fue modificado.\n", employeeArray[i].id);
                    return 0;
                    }
            }
        printf("Fallo en la operacion, no se pudo modificar al empleado.\n");
    return -1;
}

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int removeEmployee(Employee employeeArray[] , int len, int id) {
    char tempChar;
    int i, returnNum = -1;
    printf("Esta seguro que desea eliminar el registro (Y/N): \n");
    getC(&tempChar);
    tempChar = toupper(tempChar);
        if (tempChar == 'Y')
            {
            for (i = 0; i < len; i++)
                {
                    if (id == employeeArray[i].id)
                        {
                        employeeArray[i].isEmpty = 1;
                        returnNum = 0;
                        return returnNum;
                        }
                    returnNum = -1;
                }
        if (returnNum != 0)
            {
                printf("Registro no encontrado");
                returnNum = 0;
                return returnNum;
            }
    } else
        {
            system("cls");
            printf("Operacion cancelada-\n");
        }
    return returnNum;

}
