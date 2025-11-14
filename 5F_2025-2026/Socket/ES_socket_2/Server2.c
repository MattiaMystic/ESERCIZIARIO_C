/*
Esercizio 2
Scrivere il codice in C, di un applicazione Socket CLIENT-SERVER in cui il server riceve in input 1 stringa
e un carattere, e dopo aver effettuato gli eventuali ed opportuni controlli (se necessari), rispedisce al Client il
numero di occorrenze del carattere nella stringa.
*/

// SERVER
#include <stdio.h>      //std in-out
#include <stdlib.h>     //per utilizzo di certe funzioni:htonl,rand,....
#include <sys/socket.h> //funz. accept+bind+listen
#include <sys/types.h>  //funz. accept
#include <netinet/in.h> //definiscono la struttura degli indirizzi
#include <netdb.h>      //strutture hostent e servent che identificano l'host tramite iol nome
#include <string.h>     //funz. stringhe
#include <fcntl.h>      //descrittore di file
#include <signal.h>     //consente l'utilizzo delle funzioni per la gestione dei segnali fra processi
#include <errno.h>      //gestioni errori connessione
#include <ctype.h>      //bind
#include <unistd.h>     // file header che consente l'accesso alle API dello standard POSIX

#define DIM 50
#define SERVERPORT 1450

int trovaOccorrenze(char str[], char c) {
    int count = 0;
    for (int i = 0; i < strlen(str); i++)
        if (str[i] == c)
            count++;
    return count;
}

int main() {
    struct sockaddr_in servizio, addr_remoto;
    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(SERVERPORT);

    int socketfd, soa, fromlen = sizeof(servizio);
    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    bind(socketfd, (struct sockaddr *)&servizio, sizeof(servizio));
    listen(socketfd, 10);

    
    while (1) {
        printf("Server in ascolto...\n");
        soa = accept(socketfd, (struct sockaddr *)&addr_remoto, &fromlen);

        char str[DIM], c;
        read(soa, str, sizeof(str));
        read(soa, &c, sizeof(c));

        printf("Ricevuto: \"%s\" e carattere '%c'\n", str, c);

        int occ = trovaOccorrenze(str, c);
        write(soa, &occ, sizeof(occ));

        close(soa);
    }

    close(socketfd);
    return 0;
}