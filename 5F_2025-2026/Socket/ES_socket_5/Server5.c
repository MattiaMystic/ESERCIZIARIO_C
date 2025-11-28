// ...existing code...
/*Scrivere il codice in C di un’applicazione socket CLIENT–SERVER
in cui il server riceve in input una stringa e, dopo aver effettuato
 gli opportuni controlli (se necessari), rispedisce al client il numero totale di parole presenti nella stringa.*/

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

int main(int argc, char **argv)
{

    struct sockaddr_in servizio, addr_remoto;


    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(SERVERPORT);

    char str[DIM];
    int socketfd, soa;
    socklen_t fromlen = sizeof(addr_remoto);

    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    bind(socketfd, (struct sockaddr *)&servizio, sizeof(servizio));
    listen(socketfd, 5);

    for (;;)
    {
        printf("\n\nServer in ascolto...");
        fflush(stdout);

        soa = accept(socketfd, (struct sockaddr *)&addr_remoto, &fromlen);
        ssize_t n = read(soa, str, sizeof(str) - 1);
        if (n > 0)
        {
            str[n] = '\0';
            printf("Stringa ricevuta: %s\n", str);

            /* conteggio parole semplice */
            int count = 0;
            for (int i = 0; str[i] != '\0'; ++i)
            {
                char c = str[i];
                count++;
            }

            printf("Numero di parole: %d\n", count);
        }
        else
        {
           printf("Errore lettura\n");
        }

        close(soa);
    }

    close(socketfd);
    return 0;
}