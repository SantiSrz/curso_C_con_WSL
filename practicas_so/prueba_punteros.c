#include <stdio.h>

int main() {
    int nota = 10;
    int *ptr = &nota;
    
    printf("Nota original: %d\n", nota);
    *ptr = 5; 
    printf("Nota modificada: %d\n", nota);
    return 0;
}