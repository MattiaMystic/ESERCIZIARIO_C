#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("ERRORE argomenti inseriti errati\n");
        exit(0);
    }
    execl("/usr/bin/cp", "cp", argv[1],argv[2], NULL);//argv·[2] è la destinazione
    

    return 0;
}