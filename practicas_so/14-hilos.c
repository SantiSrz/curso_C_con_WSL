#include <stdio.h>
#include <pthread.h> // Librería de hilos

// 1. VARIABLE GLOBAL (Compartida por todos)
// La ponemos aquí fuera para que ambos hilos accedan a la MISMA memoria.
int saldo = 1000; 

// 1. CREAMOS EL CERROJO (Mutex)
pthread_mutex_t cerrojo;

// 2. FUNCIÓN DE SUMAR
// La firma TIENE que ser: void *nombre(void *arg)
void *ingresar_dinero(void *arg) {
    // Hacemos un bucle gigante para "estresar" al sistema
    for (int i = 0; i < 1000000; i++) {
        // 2. CERRAR: "¡Mio! Nadie más toque el saldo"
        pthread_mutex_lock(&cerrojo);
        
        // SECCIÓN CRÍTICA (Donde ocurre el peligro)
        saldo = saldo + 1; // Sumamos 1 euro un millón de veces
        
        // 3. ABRIR: "Ya terminé, pase el siguiente"
        pthread_mutex_unlock(&cerrojo);
 
    }
    return NULL;
}

// 3. FUNCIÓN DE RESTAR
void *retirar_dinero(void *arg) {
    for (int i = 0; i < 1000000; i++) {
        pthread_mutex_lock(&cerrojo);
        
        saldo = saldo - 1;// Restamos 1 euro un millón de veces
        
        pthread_mutex_unlock(&cerrojo);
 
    }
    return NULL;
}

int main() {
    pthread_t hilo1, hilo2; // Declaramos las "identificaciones" de los hilos

    printf("Saldo INICIAL: %d euros\n", saldo);

    // 0. INICIALIZAR EL CERROJO (¡Importante!)
    pthread_mutex_init(&cerrojo, NULL);

    // 4. CREAMOS LOS HILOS
    // Argumentos: &variable_hilo, Atributos(NULL), Función, Argumentos_función(NULL)
    pthread_create(&hilo1, NULL, ingresar_dinero, NULL);
    pthread_create(&hilo2, NULL, retirar_dinero, NULL);

    // 5. ESPERAMOS A QUE TERMINEN (JOIN)
    // Si no hacemos join, el main termina y mata a los hilos a medias.
    pthread_join(hilo1, NULL);
    pthread_join(hilo2, NULL);

    // 4. DESTRUIR EL CERROJO (Limpieza)
    pthread_mutex_destroy(&cerrojo);

    printf("Saldo FINAL esperado: 1000 euros\n");
    printf("Saldo FINAL real:     %d euros\n", saldo);

    return 0;
}