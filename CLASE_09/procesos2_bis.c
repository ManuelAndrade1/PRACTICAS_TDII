#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    // Comenzamos creando el primer hijo
    int rc = fork(); 
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0) {
        printf("Soy Amaranta, hija de Jose Arcadio.\n");
        exit(0);
    }
    // Creamos el siguiente hijo
    rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0) {
        printf("Soy Aureliano, hijo de Jose Arcadio.\n");
        exit(0);
    }
    // Creamos el ultimo hijo
    rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0) {
        printf("Soy Jose Acardio, hijo de Jose Arcadio.\n");
        exit(0);
    }
    // Hacemos que el padre espere a c/u de los hijos
    for (int i = 0; i < 3; i++) {
        wait(NULL);
    }

    // Printeamos el mensaje del padre.
    printf("Soy Jose Acardio, padre de todas/os\n\n");
    
    return 0;
}