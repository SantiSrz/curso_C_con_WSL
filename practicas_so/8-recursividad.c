#include <stdio.h>
int suma(int a){
    if (a != 0){
        return a + suma(a-1);
    }else{
        return a;
    }
}

int main(){
    int num1, resultado;

    printf("\nIngresa un numero: ");
    scanf("%d", &num1);

    resultado = suma(num1);

    printf("El resultado de la suma es: %d\n", resultado);
    return 0;
}