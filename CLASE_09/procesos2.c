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
    // Printeamos el mensaje del padre.
    printf("Soy Jose Acardio, padre de todas/os\n");
    
    /*
    Observaciones:
        - No usamos un else final para cada fork puesto que queremos printear 
        "Jose Acardio, padre de todas/os una sola vez."
        - Ponemos un exit() [podria ser un retunr 0 tambien] luego de cada print de c/ hijo
        para que estos no sigan ejecutando las lineas de codigo siguientes. 
    */
    return 0;
}

// VERSION ALTERNATIVA

// int main() {
//     // Comenzamos creando el primer hijo
//     int rc = fork(); 
//     if (rc < 0) {
//         fprintf(stderr, "fork failed\n");
//         exit(1);
//     }
//     else if (rc == 0) {
//         printf("Soy Amaranta, hija de Jose Arcadio.\n");
//         exit(0);
//     }
//     else {
//         // Creamos el siguiente hijo
//         rc = fork();
//         if (rc < 0) {
//             fprintf(stderr, "fork failed\n");
//             exit(1);
//         }
//         else if (rc == 0) {
//             printf("Soy Aureliano, hijo de Jose Arcadio.\n");
//             exit(0);
//         } 
//         else {  
//             // Creamos el ultimo hijo
//             rc = fork();
//             if (rc < 0) {
//             fprintf(stderr, "fork failed\n");
//             exit(1);
//             }
//             else if (rc == 0) {
//                 printf("Soy Jose Acardio, hijo de Jose Arcadio.\n");
//                 exit(0);
//             }
//             else{
//                 printf("Soy Jose Acardio, padre de todas/os\n");
//             }
//         }
//     }
//     /*
//     Observaciones:
//         - No usamos un else final para cada fork puesto que queremos printear 
//         "Jose Acardio, padre de todas/os una sola vez."
//         - Ponemos un exit() [podria ser un retunr 0 tambien] luego de cada print de c/ hijo
//         para que estos no sigan ejecutando las lineas de codigo siguientes. 
//     */
//     return 0;
// }

