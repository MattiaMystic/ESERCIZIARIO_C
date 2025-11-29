#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    char car;

    printf("Inserisci un carattere: \n");
    car=getc(stdin);
    printf("Il carattere inserito è: %c\n", car);

    putc(car, stdout);



    return 0;
}