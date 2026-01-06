#include <stdio.h>

int main() {
    // 1. Declaramos una variable normal (El buzón)
    int nota = 5;

    // 2. Declaramos el puntero (El papel con la dirección)
    // El asterisco aquí solo dice "soy un puntero"
    int *puntero;

    // 3. Conectamos los cables
    // &nota significa "DAME LA DIRECCIÓN DE MEMORIA DE NOTA"
    puntero = &nota; 

    printf("--- ANTES DEL CAMBIO ---\n");
    printf("Valor de nota: %d\n", nota);
    // %p es para imprimir direcciones de memoria (Hexadecimal)
    printf("Direccion de memoria (donde vive la nota): %p\n", puntero);

    // 4. LA MAGIA: Modificamos 'nota' sin tocar la variable 'nota'
    // El asterisco aquí significa "ACCEDE al contenido de esa dirección"
    *puntero = 10; 

    printf("\n--- DESPUES DEL CAMBIO ---\n");
    printf("Valor de nota (deberia ser 10): %d\n", nota);
    
    return 0;
}