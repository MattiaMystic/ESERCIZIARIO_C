#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Errore argomenti \n");
        exit(1);
    }
    int fd, nread;
    char buff;
    char alfabeto[] = "abcdefghilmnopqrstuvz";
    fd = open(argv[1], O_WRONLY | O_CREAT,0644);

    write(fd, alfabeto, strlen(alfabeto));

    close(fd);
}
