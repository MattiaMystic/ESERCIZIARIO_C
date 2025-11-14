/*
Esercizio 1
Scrivere il codice in C, di un applicazione Socket CLIENT-SERVER in cui il server riceve in input 1 stringa
e, dopo aver effettuato gli eventuali ed opportuni controlli (se necessari), rispedisce al Client il messaggio se
è palindroma oppure non lo è.
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

void reverseString(char str[], char reverseStr[]){
    for(int i = 0; i < strlen(str); i++){
        reverseStr[i] = str[strlen(str) - i - 1];
    }
}

int palindromità(char str[], char reverseStr[]){
    reverseString(str, reverseStr);
    if(strcmp(str, reverseStr) == 0){
        return 1; // è palindroma
    } else {
        return 0; // non è palindroma
    }
}

int main(){
    struct sockaddr_in servizio, addr_remoto; // record con i dati del server e del client

    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(SERVERPORT);
    int socketfd, soa, fromlen = sizeof(servizio);
    char str[DIM], reverseStr[DIM], response[DIM];

    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    bind(socketfd, (struct sockaddr *)&servizio, sizeof(servizio));
    listen(socketfd, 10);

    for(;;){
        printf("\n\nServer in ascolto...");
        fflush(stdout);

        soa = accept(socketfd, (struct sockaddr *)&addr_remoto, &fromlen);
        read(soa, str, sizeof(str));
        printf("Stringa ricevuta: %s\n", str);


        if(palindromità(str, reverseStr) == 1){
            strcpy(response, "La stringa è palindroma");
        } else {
            strcpy(response, "La stringa non è palindroma");
        }
        printf("Invio risposta al client... %s\n", response);
        write(soa, response, sizeof(response));
        close(soa);
    }
    return 0;
}