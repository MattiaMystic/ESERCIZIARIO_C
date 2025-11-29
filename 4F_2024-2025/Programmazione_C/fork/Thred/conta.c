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
    int b;
    b = fork();
    int pidFiglio = b;

    if (b < 0)
    {
        printf("Errore generazione figlio\n");
        exit(-1);
    }
    else if (b == 0)
    {
        printf("Io sono il figlio, il mio PID= %d\n", getpid());
        printf("Mio padre è= %d\n", getppid());
        for (int i = 0; i <= 9; i++)
        {
            printf("%d ", i);
        }
        printf("\n\n");
        exit(0);
    }
    else
    {
        wait(&b);
        printf("Io sono il padre, il mio PID= %d\n", getpid());
        printf("Mio figlio è= %d\n", pidFiglio);
        for (int i = 0; i <= 19; i++)
        {
            printf("%d ", i);
        }
        printf("\n\n");
    }

    printf("programma terminato\n");
    return 0;
}
