#include <stdio.h>
// Definimos el plano (La Estructura)
typedef struct {
    int id_camara;
    float velocidad_detectada;
    char matricula[10];
} Multa;

void procesar_multa(Multa *m) { 
    // Recibimos un PUNTERO (*m)
    // Usamos '->' para acceder a los miembros a través del puntero
    if (m->velocidad_detectada > 120.0) {
        printf("Multa generada para: %s\n", m->matricula);
        // Al modificarlo aquí, se modifica en la memoria original
        m->velocidad_detectada = 0; // Reset (ejemplo)
    }
}

int main() {
    // Creamos la instancia en memoria (Stack)
    Multa coche1 = {101, 145.5, "1234-KLA"};
    
    // Pasamos la DIRECCIÓN de memoria (&)
    procesar_multa(&coche1); 
    
    return 0;
}