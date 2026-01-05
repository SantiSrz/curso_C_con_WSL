#include <stdio.h>

int main(){
    int num1 = 5;
    int num2 = 2;
    int suma = num1 + num2;
    printf("el resultado de la suma es: %d\n", suma );

    int num3 = 5;
    int num4 = 2;
    int resta = num3 - num4;
    printf("el resultado de la resta es: %d\n", resta );

    int num5 = 5;
    int num6 = 2;
    int multiplicacion = num5 * num6;
    printf("el resultado de la multiplicacion es: %d\n", multiplicacion );

    double num7 = 5;
    double num8 = 2;
    double division = num7 / num8;
    printf("el resultado de la division es: %lf\n", division );

    int num9 = 6, num10 = 4, modulo = num9 % num10;
    printf("el resultado de la modulo es: %d\n", modulo );

    int a = 8;
    int subida = ++a;
    printf("el incremento es: %d\n", subida );

    int b = 8;
    int bajada = --b;
    printf("el deincremento es: %d\n", bajada );

    int c = 4;
    int d = 2;
    int multi = c *= d;
    printf("el resultado de la multiplicacion es: %d\n", multi );

    int g = 1, h = 2;
    int mayor = g < h;
    printf("respuesta: %d\n", mayor );

    int p = 1, o = 2;
    int menor = p > o;
    printf("respuesta: %d\n", menor );

    int r;
    printf("El tamaño del dato es de: %lu bytes \n", sizeof(r));
    return 0;

}
