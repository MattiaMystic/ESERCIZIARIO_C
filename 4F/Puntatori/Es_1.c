#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    int *p = NULL, *q;
    if (p == NULL)
    {
        printf("P punta null\n"); // p==0
    }
    if (p)
    {
        printf("P non è null. Questa operazione non viene eseguita\n"); // p==1
    }
    if (q)
    {
        printf("Puntatore q non inizialinizzato\n");
    }
    //funzioni di input
    //scanf()
    //getc()utilizzata x leggere un singolo carattere da file o tastiera
    //getchar() serve per leggere un carattere da tastiera e corrisponde ad una funzione specifica di getc(), corrisponde a getc(stdin)
    //funzioni di oputput
    //printf()
    //putc() scrive ogni singolo carattere in un file o su un specificato dispositivo di output 
    //putchar() serve per scrivere un carattere su stdout e corrisponde ad una funzione specifica di putc(), corrisponde a putc(stdout, c



    //fgets()
    //fputs()
    //funzioni di file
    //fopen() apre un file in lettura o scrittura
    //fclose() chiude un file
    //fread() legge un numero di byte da un file e li carica in una struttura
    //fwrite() scrive un numero di byte da una struttura in un file
    //fflush() svuota il buffer di output
    //funzioni di stringhe
    //strcpy() copia una stringa in un'altra
    //strncpy() copia una parte di una stringa in un'altra
    //strcmp() compara due stringhe
    //strncmp() compara una parte di due stringhe
    //strcat() concatena due stringhe
    //strncat() concatena una parte di due stringhe
    //strlen() calcola la lunghezza di una stringa     
    return 0;
}