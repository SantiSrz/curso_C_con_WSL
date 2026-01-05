#include <stdio.h>

int main(){
    char calculadora;
    double num1, num2;

    printf("\nEscribe un operador: ");
    scanf("%c", &calculadora);

    printf("\n Escribe el primer numero para la operacion: ");
    scanf("%lf", &num1);

    printf("\n Escribe el segundo numero para la operacion: ");
    scanf("%lf", &num2);

    switch(calculadora){
        case '+':
        double suma = num1 + num2;
        printf("\nResultado: %lf\n", suma);
        break;

        case '-':
        double resta = num1 - num2;
        printf("\nResultado: %lf\n", resta);
        break;

        case '*':
        double multiplicacion = num1 * num2;
        printf("\nResultado: %lf\n", multiplicacion);
        break;

        case '/':
        double division = num1 / num2;
        printf("\nResultado: %lf\n", division);
        break;

    }

    return 0;
}