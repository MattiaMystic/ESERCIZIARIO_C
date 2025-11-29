#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
/*
Scrivere un programma concorrente che realizzi il seguente comando:

cat costituzione.txt | more*/

int main(int argc, char *argv[])
{
  

    if (argc != 2)
    {
        printf("Numero argomenti sbagliato\n");
        exit(1);
    }
    int pid;
    int p1p0[2];
    pipe(p1p0);

    pid = fork();
    if (pid == 0)
    {
        // CAT
        close(p1p0[0]); // scrittura
        close(1);
        dup(p1p0[1]);
        close(p1p0[1]);
        execl("/bin/cat", "cat", argv[1], (char *)0);
        exit(0);
    }
    pid = fork();
    if (pid == 0)
    {
        // CAT
        close(p1p0[1]); // lettura
        close(0);
        dup(p1p0[0]);
        close(p1p0[0]);
        execl("/bin/more", "more", (char *)0);
        exit(0);
    }

    close(p1p0[1]);
    close(p1p0[0]);
    wait(&pid);
    wait(&pid);

    return 0;
}