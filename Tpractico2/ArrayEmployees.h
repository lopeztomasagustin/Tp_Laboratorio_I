#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <math.h>


typedef struct
{
    int id;
    int sector;
    int isEmpty;
    char name[51];
    char lastName[51];
    float salary;

}Employee;

    int menu();
    int initEmployees(Employee employeeArray[], int len);
    int addEmployee(Employee employeeArray[], int len, int id, char name[], char lastName[], float salary, int sector);
    int menuInformar();
    int getInt(int *pInt, char msg[], char msgError[], int min, int max, int retries);
    int validarMenu(int menu, int min, int max);
    int getStringLettersOnly(char *input, char *msg, int len, int retries);
    int getFreeSpace(Employee employeeArray[], int len);
    int getFloat(float *pFloat, char msg[], char msgError[], float min, float max, int retries);
    int isLetter(char c[]);
    int findEmployeeById(Employee employeeArray[], int len, int id);
    int modifyEmployee(Employee employeeArray[], int len, int id, char name[], char lastName[], float salary, int sector);
    int removeEmployee(Employee employeeArray[] , int len, int id);
    int getAverageSalaries(Employee employeeArray[], int len);
    int employeesAboveAverage(Employee employeeArray[], int len);


    float getAllSalaries(Employee employeeArray[] , int len);

    void sortBySectorLastNameAndName(Employee employeeArray[] , int len, int order);
    void toUpperLastNameAndName(Employee employeeArray[], int len);
    void printEmployee(Employee employeeArray[], int len);
    void getString(char input[], char msg[]);


