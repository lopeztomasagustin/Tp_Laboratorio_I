#include "Operaciones.h"

    float sumar (int numeroUno, int numeroDos)
    {
        float suma = (numeroUno + numeroDos);
        printf("--El resultado de la suma es: %.2f\n", suma);
        return 0;
    }

    float restar (int restaUno, int restaDos)
    {
        float resta =(restaUno - restaDos);
        printf("---El resultado de la resta es: %.2f\n", resta);
        return 0;
    }

    float multiplicar (int multiplicacionUno, int multiplicacionDos)
    {
        float multiplicacion = (multiplicacionUno*multiplicacionDos);
        printf("----El resultado de la multiplicacion es: %.2f\n", multiplicacion);
        return 0;
    }

    float dividir(float divisionUno, float divisionDos)
    {
        float division = divisionUno/divisionDos;
        if(divisionDos == 0)
        {
            printf("-----Error, no se puede dividir por cero\n");
        }else
        {
            printf("-----El resultado de la division es: %.2f\n", division);
        }
        return 0;
    }
    float factorial(int numeroN)
    {
        int i;
        int resultado = 1;
        for ( i = 1; i <= numeroN; i++)
        {
            resultado = resultado*i;
        }
        printf("------El resultado del factorial es: %d", resultado);
        return resultado;
    }

