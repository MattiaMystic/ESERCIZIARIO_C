/*
Esercizio 3
Scrivere il codice in C, di un applicazione Socket CLIENT-SERVER in cui il server riceve in input 1 stringa,
e dopo aver effettuato gli eventuali ed opportuni controlli (se necessari), rispedisce al Client la stringa
ordinata alfabeticamente (eliminando i caratteri speciali).
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
#define SERVERPORT 12345

void ordina_stringa(char* str, char* response) {
    int len = 0, i, j = 0;
    char temp[DIM];

    // Rimuovi caratteri speciali
    for (i = 0; str[i] != '\0' && i < DIM; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'a' && str[i] <= 'z') {
            temp[len++] = str[i];
        }
    }
    temp[len] = '\0';

    // Ordinamento alfabetico (Bubble Sort)
    for (i = 0; i < len - 1; i++) {
        for (j = 0; j < len - i - 1; j++) {
            if (temp[j] > temp[j + 1]) {
                char swap = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = swap;
            }
        }
    }
    strcpy(response, temp);
}

int main(){
    struct sockaddr_in servizio, addr_remoto; // record con i dati del server e del client

    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(SERVERPORT);
    int socketfd, soa, fromlen = sizeof(servizio);
    char str[DIM], response[DIM];

    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    bind(socketfd, (struct sockaddr *)&servizio, sizeof(servizio));
    listen(socketfd, 10);

    for(;;)
    {
        printf("\n\nServer in ascolto...");
        fflush(stdout);

        soa = accept(socketfd, (struct sockaddr *)&addr_remoto, &fromlen);
        read(soa, str, sizeof(str));
        printf("Stringa ricevuta: %s\n", str);

        ordina_stringa(str, response);

        printf("Invio risposta al client... %s\n", response);
        write(soa, response, sizeof(response));
        close(soa);
    }
    return 0;
}