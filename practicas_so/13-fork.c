#include <stdio.h>
#include <unistd.h> // OBLIGATORIA: Contiene fork(), getpid(), sleep()
#include <sys/types.h>
#include <sys/wait.h> // <--- OBLIGATORIA para wait()

int main() {
    printf("--- INICIO: Soy el proceso original (PID: %d) ---\n", getpid());

    printf("Voy a hacer un fork()...\n");
    
    // AQUÍ OCURRE LA MAGIA: El proceso se duplica
    pid_t pid1 = fork();

    // A partir de esta línea, hay DOS programas ejecutándose a la vez
    // Ambos ejecutan este 'if', pero entran en sitios distintos.

    if (pid1 == -1) {
        // Si fork devuelve -1, hubo un error (falta de memoria, etc.)
        perror("Error al crear el proceso");
    }
    else if (pid1 == 0) {
        // --- ZONA DEL HIJO ---
        // El hijo SIEMPRE recibe un 0
        printf("Soy el HIJO. Mi PID es %d. Mi Padre es %d\n", getpid(), getppid());
        pid_t pid2 = fork();
        if (pid2 == -1) {
            // Si fork devuelve -1, hubo un error (falta de memoria, etc.)
            perror("Error al crear el proceso");
        }
        else if (pid2 == 0) {
            // --- ZONA DEL HIJO ---
            // El hijo SIEMPRE recibe un 0
            printf("Soy el NIETO. Mi PID es %d. Mi Padre es %d\n", getpid(), getppid());
        }
        else {
            // --- ZONA DEL PADRE ---
            // El padre recibe el PID del hijo (ej: 12345)
            printf("Soy el PADRE. Mi PID es %d. He creado al hijo con PID %d\n", getpid(), pid2);
            
            // El padre espera 1 segundo para dar tiempo a que leas lo del hijo
            wait(NULL);
        }

    }
    else {
        // --- ZONA DEL PADRE ---
        // El padre recibe el PID del hijo (ej: 12345)
        printf("Soy el ABUELO. Mi PID es %d. He creado al hijo con PID %d\n", getpid(), pid1);
        
        // El padre espera 1 segundo para dar tiempo a que leas lo del hijo
        wait(NULL);
    }

    printf("Finalizando proceso %d...\n", getpid());
    return 0;
}