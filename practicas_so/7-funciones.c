#include <stdio.h>

int esPar(int num){
    if (num % 2 == 0){
        printf("El numero %d es par\n", num);
    }else if(num % 2 != 0){
        printf("El numero %d es impar\n", num);
    }else{
        printf("El numero %d no es valido\n", num);
    }
}

int main(){
    int a;
    printf("\nIngresa un numero para saber si es par: ");
    scanf("%d", &a);
    esPar(a);
    return 0;
}