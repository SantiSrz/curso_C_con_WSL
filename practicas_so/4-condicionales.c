#include <stdio.h>

int main(){
    double entrada;
    printf("Escribe un numero: ");
    scanf("%lf", &entrada);
    if (entrada > 5){
        printf("El numero ingresado es mayor que 5\n");
    }else if(entrada == 5){
        printf("El numero ingresado es igual que 5\n");
    }else{
        printf("El numero ingresado es menor que 5\n");
    }
return 0;
}