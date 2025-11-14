/*
Esercizio 2
Scrivere il codice in C, di un applicazione Socket CLIENT-SERVER in cui il server riceve in input 1 stringa
e un carattere, e dopo aver effettuato gli eventuali ed opportuni controlli (se necessari), rispedisce al Client il
numero di occorrenze del carattere nella stringa.
*/

// CLIENT
#include <stdio.h>      //std in-out
#include <stdlib.h>     //per utilizzo di certe funzioni:htonl,rand,....
#include <sys/socket.h> //funz. accept+bind+listen
#include <sys/types.h>  //funz. accept
#include <netinet/in.h> //definiscono la struttura degli indirizzi
#include <string.h>     //funz. stringhe
#include <errno.h>      //gestioni errori connessione
#include <ctype.h>      //bind
#include <unistd.h>     // file header che consente l'accesso alle API dello standard POSIX

#define DIM 50
#define SERVERPORT 1450

int main() {
    struct sockaddr_in servizio;
    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(SERVERPORT);

    char str1[DIM], charDaCercare;
    int socketfd;

    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    connect(socketfd, (struct sockaddr *)&servizio, sizeof(servizio));

    printf("Inserisci la stringa: ");
    scanf("%s", str1);

    //flush(stdin); //non riesce a pulire il buffer, uso spazio prima di %c nello scanf successivo

    printf("Inserisci il carattere da cercare: ");
    scanf(" %c", &charDaCercare); //spazio precedente %c per consumare il newline (\n) rimasto nel buffer dallo scanf precedente

    write(socketfd, str1, sizeof(str1));
    write(socketfd, &charDaCercare, sizeof(charDaCercare));

    int occorrenze;
    read(socketfd, &occorrenze, sizeof(int));
    printf("Numero di occorrenze: %d\n", occorrenze);

    close(socketfd);
    return 0;
}