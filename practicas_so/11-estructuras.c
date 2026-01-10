#include <stdio.h>
#include <string.h>

typedef struct {
    char nombre[50];
    int edad;
    float altura;
}Persona;

void print_data(Persona *p){
    printf("Nombre: %s\n", p->nombre);
    printf("Edad: %d\n", p->edad);
    printf("Altura: %f\n", p->altura);
}

int main(){

    Persona p1;

    strcpy(p1.nombre, "Santiago");
    p1.edad = 19;
    p1.altura = 1.94;

    print_data(&p1);

    return 0;
}