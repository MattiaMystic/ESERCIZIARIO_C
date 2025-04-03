/*Il nome del file pu contenere al massimo FILENAME_MAX caratteri ( -> 260) e
si possono aprire al massimo FOPEN_MAX file ( -> 20)
*/
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#define lungh 81
/* se diminuisco il numero dei caratteri della stringa
per es. 60
allora aumenta il numero delle righe*/

int main()
{
    FILE *puntaFile;
    char nome[FILENAME_MAX], buffer[lungh]; // FILENAME_MAX= 260 caratteri = 260 Byte
    int nr = 0, nc = 0;
    // printf("Nome del file: ");
    // gets (nome);
    // if ((puntaFile=fopen(nome, "r")) ==NULL)
    puntaFile = fopen("costituzione.txt", "r");
    if (puntaFile == NULL)
    {
        printf("Errore nell'apertura del file");
        exit(1);
    }
    else
    {
        
        while (fgets(buffer, lungh, puntaFile) != NULL)
        {
            nr++;
            nc = nc + strlen(buffer) - 1; //-1 poiche ogni stringa termina col csarattere terminatore \0
        }
        fclose(puntaFile);
    }
}