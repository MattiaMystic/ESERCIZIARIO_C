#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
    int p = fork();
    if (p > 0)
    {
        // siamo nel padre

        printf("Io sono il Padre: PID=%d. ", getpid());
        printf("\n Mio figlio ha PID=%d\n", p);
    }
    else if (p == 0)
    {
        // siamo nel figlio
        printf("Io sono il figlio: PID=%d. \n", getpid());
        printf("Mio padre ha PID=%d", getppid());
    }
    else
    {
        // errore
        printf("Errore generazione figlio\n");
    }
    // la cpu li disordina lei perchè non sa che ordine seguire

    return 0;
}