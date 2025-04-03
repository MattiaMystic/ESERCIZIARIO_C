#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i;
    char v_nomi[20];
    FILE *nomi;
    nomi = fopen("nomi.txt", "w");
    if (nomi == NULL)
    {
        printf("Impossibile aprire il file!\n");
        exit(1);
    }
    else
    {
        printf("File inserito correttamente\n");
        for (i = 0; i < 3; i++)
        {
            printf("Inserisci il nome %d: \n", i + 1);
            scanf("%s", v_nomi);
            fputs(v_nomi, nomi);
            fputc('\n', nomi);
        }
    }
    fclose(nomi);
    return 0;
    
}
