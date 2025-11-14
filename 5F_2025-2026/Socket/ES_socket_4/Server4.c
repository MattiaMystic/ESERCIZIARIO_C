/*
Esercizio 4
Scrivere il codice in C, di un applicazione Socket CLIENT-SERVER in cui il server riceve in input 1 stringa
e, dopo aver effettuato gli eventuali ed opportuni controlli (se necessari), rispedisce al Client 2 stringhe>; la
prima composta dalle lettere di posizione pari e la seconda composta dalle lettere di posizione dispari.
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

void lettere_pari_dispari(char* str,  char* pari, char* dispari){
    int i, j=0, k=0;
    for(i=0; str[i]!='\0'; i++){
        if(i%2==0){
            pari[j++] = str[i];
        } else {
            dispari[k++] = str[i];
        }
    }
    pari[j] = '\0';
    dispari[k] = '\0';
}

int main(){
    struct sockaddr_in servizio, addr_remoto; // record con i dati del server e del client

    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(SERVERPORT);
    int socketfd, soa, fromlen = sizeof(servizio);
    char str[DIM], pari[DIM], dispari[DIM];

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

        lettere_pari_dispari(str, pari, dispari);

        printf("Invio risposta al client... %s\n", pari);
        write(soa, pari, sizeof(pari));

        printf("Invio risposta al client... %s\n", dispari);
        write(soa, dispari, sizeof(dispari));

        close(soa);
    }
    return 0;
}