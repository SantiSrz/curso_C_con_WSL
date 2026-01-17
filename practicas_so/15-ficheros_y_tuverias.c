#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h> // Para wait()

int main() {
    int fd[2]; // File Descriptors: [0] es LECTURA, [1] es ESCRITURA
    char buffer[100]; // Donde guardaremos el mensaje recibido
    pid_t pid;

    // 1. CREAR LA TUBERÍA (Antes del fork, para que ambos la tengan)
    if (pipe(fd) == -1) {
        perror("Error al crear la tuberia");
        return 1;
    }

    printf("--- Tubería creada. Iniciando fork... ---\n");
    pid = fork();

    if (pid == 0) {
        // --- ZONA DEL HIJO (El que ESCRIBE) ---
        
        // PASO CLAVE: Cerrar el lado de lectura (el hijo solo quiere escribir)
        close(fd[0]); 

        char mensaje[] = "Hola Papa, soy tu hijo enviando datos desde otro proceso!";
        
        printf("👶 HIJO: Escribiendo en la tuberia...\n");
        write(fd[1], mensaje, strlen(mensaje) + 1); // +1 para enviar el \0 final

        // Cerramos el lado de escritura al terminar (como colgar el teléfono)
        close(fd[1]); 
    }
    else {
        // --- ZONA DEL PADRE (El que LEE) ---
        
        // PASO CLAVE: Cerrar el lado de escritura (el padre solo quiere leer)
        close(fd[1]);

        printf("👨 PADRE: Esperando mensaje...\n");
        
        // read() se bloquea hasta que alguien escriba algo
        read(fd[0], buffer, sizeof(buffer)); 
        
        printf("👨 PADRE: Mensaje recibido: \"%s\"\n", buffer);

        // Cerramos y esperamos al hijo
        close(fd[0]);
        wait(NULL);
    }

    return 0;
}