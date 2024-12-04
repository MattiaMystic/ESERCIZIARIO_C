#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int b, c, d, e, f;
    printf("Io sono il padre A, il mio PID= %d\n\n", getpid());

    b = fork();
    if (b < 0)
    {
        printf("Errore generazione figlio\n");
        exit(-1);
    }
    else if (b == 0)
    {
        printf("Io sono il primo figlio di A (B), il mio PID= %d\n", getpid());
        printf("Mio padre è= %d\n\n", getppid());

        d = fork();
        if (d < 0)
        {
            printf("Errore generazione figlio\n");
            exit(-1);
        }
        else if (d == 0)
        {
            printf("Io sono il figlio di B (D), il mio PID= %d\n", getpid());
            printf("Mio padre è= %d\n\n", getppid());
            exit(0);
        }
        else
        {
            wait(&d);
        }
        exit(0);
    }
    else
    {
        wait(&b);

        c = fork();
        if (c < 0)
        {
            printf("Errore generazione figlio\n");
            exit(-1);
        }
        else if (c == 0)
        {
            printf("Io sono il secondo figlio di A (C), il mio PID= %d\n", getpid());
            printf("Mio padre è= %d\n\n", getppid());

            e = fork();
            if (e < 0)
            {
                printf("Errore generazione figlio\n");
                exit(-1);
            }
            else if (e == 0)
            {
                printf("Io sono il primo figlio di C (E), il mio PID= %d\n", getpid());
                printf("Mio padre è= %d\n\n", getppid());
                exit(0);
            }
            else
            {
                wait(&e);

                f = fork();
                if (f < 0)
                {
                    printf("Errore generazione figlio\n");
                    exit(-1);
                }
                else if (f == 0)
                {
                    printf("Io sono il secondo figlio di C (F), il mio PID= %d\n", getpid());
                    printf("Mio padre è= %d\n\n", getppid());
                    exit(0);
                }
                else
                {
                    wait(&f);
                }
            }
            exit(0);
        }
        else
        {
            wait(&c);
        }
    }

    printf("programma terminato\n");
    return 0;
}
