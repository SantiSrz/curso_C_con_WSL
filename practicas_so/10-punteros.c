#include <stdio.h>
#include <stdlib.h>

void changeValue(char *letter){
    *letter = 'a';
}

void puntero_que_apunta_a_una_cadena_de_caracteres(){
    char str[] = "Hola Mundo!";
    char *ptr = str;
    printf("Caracteres de la cadena: ");
    while(*ptr != '\0'){
        printf("%c", *ptr);
        ptr++;
    }
    printf("\n");
}

void pasar_datos_por_referencia_con_manipulacion_de_memoria_dinamica(){
    char *n = malloc(sizeof(char));
    if(n == NULL){
        fprintf(stderr, "Error: no se puedo encontrar memoria\n");
        return;
        }

    *n = 'a';
    changeValue(n);
    printf("%c\n", *n);
    free(n);

}

void pasar_datos_por_referecia_a_una_funcion(){

    char l; 
    l = 'b';
    changeValue(&l);
    printf("%c\n", l);

}

void punteros(){

    int valor = 10;
    int *puntero = &valor;
    int **puntero_a_puntero = &puntero;
    printf("La direccion de memoria del puntero es: %p\n", puntero);

}

int main() {
    puntero_que_apunta_a_una_cadena_de_caracteres();
    pasar_datos_por_referencia_con_manipulacion_de_memoria_dinamica();
    pasar_datos_por_referecia_a_una_funcion();
    punteros();
    return 0;
}

