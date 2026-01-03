#include <stdio.h>

int main(){
    char letra = 'A';
    printf("Este es el caracter: %c\n", letra );

    int num = 5;
    printf("Este es el numero: %d\n", num );

    double decimal = 3.14;
    printf("Este es el numero decimal: %lf\n", decimal );

    char texto[] = "Hola que tal";
    printf("Este es el texto: %s\n", texto );

    double entrada_salida;
    printf("Escribe un numero: " );
    scanf("%lf", &entrada_salida);
    printf("numero = %lf\n" , entrada_salida );
    return 0;
}