#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();  // Crear un proceso hijo

    if (pid < 0) {
        // Error al crear el proceso
        perror("fork failed");
        exit(1);
    } 
    if (pid == 0) {
        // Código del proceso hijo
        printf("Soy el proceso hijo, mi PID es: %d\n", getpid());
        exit(0);  // El proceso hijo termina inmediatamente (esto lo convierte en zombie)
    } else {
        // Código del proceso padre
        printf("Soy el proceso padre, mi PID es: %d\n", getpid());
        printf("El proceso hijo con PID %d ha terminado, pero no lo recojo todavía, se convertirá en zombie.\n", pid);
        
        // Pausar el proceso padre para que no recoja al hijo inmediatamente (crea el estado zombie)
        sleep(60);

        // Ahora, después de 60 segundos, recogemos al proceso hijo
        wait(NULL);  // Recoger al proceso hijo y eliminar el zombie
        printf("El proceso hijo ha sido recogido, ya no es un zombie.\n");
    }

    return 0;
}
