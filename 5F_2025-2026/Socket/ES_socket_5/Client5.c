#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#define DIM 50
#define SERVERPORT 12345

int main(int argc, char **argv)
{
    struct sockaddr_in servizio;
    servizio.sin_family = AF_INET;
    servizio.sin_port = htons(SERVERPORT);
    servizio.sin_addr.s_addr = htonl(INADDR_ANY); /* indirizzo server */

    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd < 0)
    {
        perror("socket");
        return 1;
    }

    if (connect(socketfd, (struct sockaddr *)&servizio, sizeof(servizio)) < 0)
    {
        perror("connect");
        close(socketfd);
        return 1;
    }

    char str1[DIM];
    printf("Inserisci la stringa: ");
    if (fgets(str1, DIM, stdin) == NULL)
    {
        close(socketfd);
        return 0;
    }

    if (write(socketfd, str1, strlen(str1)) < 0)
        printf("Errore invio\n");

    close(socketfd);
    return 0;
}