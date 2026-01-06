#include <stdio.h>
int main(void){
    int numeros[5] = {};
    printf("\n");
    for (int i = 0; i < 5; i++){
        printf("Escribe el numero de la posicion numero %d del array: ", i);
        scanf("%d", &numeros[i]);
    }

    printf("\n");

    for (int i = 0; i < 4; i++){
        printf("%d ", numeros[i]);
    }
    printf("\n");
    printf("\n");
    return 0;
}