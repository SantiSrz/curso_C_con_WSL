#include <stdio.h>

int main(){
    char calculadora;
    double num1, num2;
    int variable = 1;

    while(variable){
        printf("\nEscribe un operador o X para parar: ");
        scanf("%c", &calculadora);

        if (calculadora == 'X' || calculadora == 'x') {
            printf("El programa ha finalizado.\n");
            variable = 0;
            break;   
        }

        printf("\nEscribe el primer numero para la operacion: ");
        scanf("%lf", &num1);

        printf("\nEscribe el segundo numero para la operacion: ");
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
            if(num2 == 0){
                    printf("Error: No se puede dividir por cero.\n");
                } else {
                    printf("Resultado: %lf\n", num1 / num2);
                }
                break;

            default:
                printf("Operador no valido. Intentalo de nuevo.\n");

        }
    }
    return 0;
}