#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h> // Necesario para wait()
#include <sys/types.h>

int main(){
    // DEFINICIÓN DE TUBERÍAS
    // tubo_PH: Padre escribe [1] -> Hijo lee [0]
    // tubo_HP: Hijo escribe [1] -> Padre lee [0]
    int tubo_PH[2]; 
    int tubo_HP[2];
    
    pid_t pid; 
    int numero_enviado, numero_recibido, resultado;

    // 1. CREAR LAS DOS TUBERÍAS (Antes del fork)
    // Si fallan, salimos.
    if(pipe(tubo_PH) == -1 || pipe(tubo_HP) == -1){
        perror("Error creando tuberias");
        return 1;
    }

    // 2. CLONAR EL PROCESO
    pid = fork();

    if(pid == 0){
        // --- ZONA DEL HIJO (Calculadora) ---
        
        // CIERRES DE SEGURIDAD (Cerrar lo que no uso):
        // El hijo NO va a escribir en el tubo del padre -> cerramos PH[1]
        // El hijo NO va a leer del tubo de vuelta -> cerramos HP[0]
        close(tubo_PH[1]); 
        close(tubo_HP[0]);

        // A. Leer el número que manda papá
        // Fíjate que leemos directamente un entero, sin buffers de texto
        read(tubo_PH[0], &numero_recibido, sizeof(int));
        printf("   👶 HIJO: He recibido el numero %d. Calculando...\n", numero_recibido);

        // B. Calcular
        int cuadrado = numero_recibido * numero_recibido;

        // C. Enviar respuesta
        write(tubo_HP[1], &cuadrado, sizeof(int));
        printf("   👶 HIJO: Resultado enviado. Me muero.\n");

        // Cerrar los descriptores que usamos antes de salir
        close(tubo_PH[0]);
        close(tubo_HP[1]);
        
        return 0; // El hijo termina aquí
    }
    else {
        // --- ZONA DEL PADRE (Usuario) ---

        // CIERRES DE SEGURIDAD:
        // El padre NO lee de su propio tubo -> cerramos PH[0]
        // El padre NO escribe en el tubo de vuelta -> cerramos HP[1]
        close(tubo_PH[0]);
        close(tubo_HP[1]);

        printf("👨 PADRE: Dame un numero entero: ");
        scanf("%d", &numero_enviado);

        // A. Enviar numero al hijo
        write(tubo_PH[1], &numero_enviado, sizeof(int));

        // B. Esperar respuesta (read se bloquea hasta que el hijo conteste)
        read(tubo_HP[0], &resultado, sizeof(int));

        printf("👨 PADRE: El hijo me ha dicho que el cuadrado es: %d\n", resultado);

        // Cerrar conexiones y ESPERAR al hijo (para no dejar zombis)
        close(tubo_PH[1]);
        close(tubo_HP[0]);
        wait(NULL);
    }

    return 0;
}