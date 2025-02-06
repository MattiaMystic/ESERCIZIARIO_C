#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("ERRORE argomenti inseriti errati\n");
        exit(0);
    }
    execl("/usr/bin/cat", "cat", argv[1], NULL);                  // il comando /usr/bin/cat serve per andare a chiamare il programma cat nella cartella /usr/bin/.. è il percorso del programma
    execl("usr/bin/grep", "grep", "costituzione", argv[1], NULL); // esempio
  

    return 0;
}