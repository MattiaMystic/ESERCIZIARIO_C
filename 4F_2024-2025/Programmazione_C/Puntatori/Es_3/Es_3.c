#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    char car;
    printf("inserisci un carattere da tastiera \n");
    car = getc(stdin);
    printf("\n Hai inserito %c\n", car);
    printf("\n Hai inserito %d\n", car);
    putc(car,stdout);
    FILE *fp;
    fp=fopen("file.txt","w");
    if(fp!=NULL){
        printf("\nScrittura avvenuta con successo!\n");
        putc(car,fp);
        fclose(fp);
    }else{
        printf("Impossibile aprire il file!\n");
    }

    putchar(car);
    printf("\n");
    return 0;
}