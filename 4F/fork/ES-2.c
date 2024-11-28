#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // Il primo fork crea il padre e il primo figlio
    int p = fork();

    if (p > 0) { // padre
        printf("Io sono il padre: PID=%d\n", getpid());

        // Il secondo fork crea il secondo figlio
        int f2 = fork();
        if (f2 == 0) {
            // Questo è il secondo figlio
            printf("Io sono il 2° figlio di padre con PID=%d\n", getpid());

            // Il secondo figlio crea due suoi figli
            int ff2a = fork();
            if (ff2a == 0) {
                // Primo figlio del secondo figlio
                printf("Io sono il 1° figlio del 2° figlio con PID=%d\n", getpid());
            }

            int ff2b = fork();
            if (ff2b == 0) {
                // Secondo figlio del secondo figlio
                printf("Io sono il 2° figlio del 2° figlio con PID=%d\n", getpid());
            }
        }

        // Il primo figlio crea un suo figlio
        if (p == 0) {
            int f1 = fork();
            if (f1 == 0) {
                // Questo è il primo figlio
                printf("Io sono il 1° figlio di padre con PID=%d\n", getpid());

                // Il primo figlio crea un suo figlio
                int ff1 = fork();
                if (ff1 == 0) {
                    // Figlio del primo figlio
                    printf("Io sono il figlio del 1° figlio con PID=%d\n", getpid());
                }
            }
        }

    } else if (p == 0) {
        // Il primo fork crea il primo figlio, quindi codice del primo figlio
        int f1 = fork();
        if (f1 == 0) {
            // Questo è il primo figlio
            printf("Io sono il 1° figlio di padre con PID=%d\n", getpid());

            // Il primo figlio crea un suo figlio
            int ff1 = fork();
            if (ff1 == 0) {
                // Figlio del primo figlio
                printf("Io sono il figlio del 1° figlio con PID=%d\n", getpid());
            }
        }
    }

    return 0;
}