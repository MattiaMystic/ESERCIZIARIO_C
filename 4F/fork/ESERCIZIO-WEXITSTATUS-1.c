#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
int main(int argc, char *argv[])
{
    /*
    Scrivi il codice sorgente di un programma in
cui
il processo padre P1 genera un vettore V[3] di
tre numeri interi casuali
appartenenti all'intervallo [0;5] estremi
compresi.
Successivamente, P1 genera due processi figli:
P2 e P3.
P2 genera due figli, P4 e P5:
P4 calcola e visualizza il prodotto delle
componenti del vettore V[];
P5 calcola e visualizza la media delle
componenti del vettore V[] .
P3 visualizza le componenti del vettore V[],
genera un figlio P6 che calcola la somma delle
componenti di V[] e
restituisce il risultato al padre P3 che la
visualizza.
La prima cosa che ciascun processo deve fare,
appena genera un processo
figlio, è dichiararsi nel modo seguente:
"P1: mio PID=..., mio figlio P2 ha PID=...
La prima cosa che ciascun processo figlio deve
fare appena è stato generato,
è dichiararsi nel modo seguente:
"P2: mio PID=..., mio padre P1 ha
PID=..."
Ogni volta che un processo visualizza qualcosa
sullo schermo deve
dichiararsi nel modo seguente:
"P4: quello che P4 deve visualizzare"
"P5: quello che P4 deve visualizzare*/

    int v1[3];
    int n, p2, p3, p4, p5, p6;
    int status;
    int Prodotto = 1;
    int Somma = 0;
    int Somma1 = 0;
    float Media = 0;

    for (int i = 0; i < 3; i++)
    {
        do
        {
            printf("Inserisci un numero valido da 0 a 5 compresi in posizione %d del nostro vettore\n", i);
            scanf("%d", &n);

        } while (n > 5 || n < 0);
        v1[i] = n;
    }
    p2 = fork();
    if (p2 == 0)
    { // figlio p2
        printf("P2. Io sono il figlio p2 e ho PID:%d. Mio padre ha PID:%d\n", getpid(), getppid());
        p4 = fork();
        if (p4 == 0)
        { // p4
            printf("P4. Io sono il figlio p4 e ho PID:%d. Mio padre ha PID:%d\n", getpid(), getppid());
            for (int i = 0; i < 3; i++)
            {
                Prodotto = Prodotto * v1[i];
            }
            printf("P4, QUELLO CHE P4 DEVE VISUALIZZARE:\n\n\n");
            printf("Prodotto dei 3 numeri del vettore è %d\n", Prodotto);
            exit(25);
        }
        else if (p4 > 0)
        { // p2
            wait(&status);
            printf("Il valore d'uscita di p4 è :%d\n", WEXITSTATUS(status));
            printf("PADRE p2: Io sono il padre e ho PID:%d. Mio figlio p4 ha PID:%d\n", getpid(), p4);
        }
        else
        { // errore
            printf("Errore generazione figlio\n");
            exit(0);
        }

        p5 = fork();
        if (p5 == 0)
        { // p4
            printf("P5. Io sono il figlio p5 e ho PID:%d. Mio padre ha PID:%d\n", getpid(), getppid());
            for (int i = 0; i < 3; i++)
            {
                Somma = Somma + v1[i];
            }
            Media = (float)Somma / 3;
            printf("P5, QUELLO CHE P5 DEVE VISUALIZZARE:\n\n\n");
            printf("Media dei 3 numeri del vettore è %f\n", Media);
            exit(25);
        }
        else if (p5 > 0)
        { // p2
            wait(&status);
            printf("Il valore d'uscita di p5 è :%d\n", WEXITSTATUS(status));
            printf("PADRE p2: Io sono il padre e ho PID:%d. Mio figlio p5 ha PID:%d\n", getpid(), p5);
        }
        else
        { // errore
            printf("Errore generazione figlio\n");
            exit(0);
        }

        exit(25);
    }
    else if (p2 > 0)
    { // padre
        wait(&status);
        printf("Il valore d'uscita di p2 è :%d\n", WEXITSTATUS(status));
        printf("PADRE: Io sono il padre e ho PID:%d. Mio figlio p2 ha PID:%d\n", getpid(), p2);
    }
    else
    { // errore
        printf("Errore generazione figlio\n");
        exit(0);
    }

    // p3,p6:
    p3 = fork();
    if (p3 == 0)
    { // figlio p3
        printf("P3, Io sono P3 e ho PID: %d, mio padre ha PID:%d", getpid(), getppid());
        printf("P3, QUELLO CHE P3 DEVE VISUALIZZARE:\n\n\n");
        for (int i = 0; i < 3; i++)
        {
            printf("La componente del vettore in posizione %d , è : %d\n", i, v1[i]);
        }

        p6 = fork();
        if (p6 == 0)
        { // p6
            printf("P6, Io sono p6 e ho PID:%d, mio padre p3 ha PID:%d\n", getpid(), getppid());

            for (int i = 0; i < 3; i++)
            {
                Somma1 = Somma1 + v1[i];
            }
            exit(Somma1);
        }
        else if (p6 > 0)
        { // p3
            wait(&status);
           
            printf("PADRE P3: Io sono il padre e ho PID:%d. Mio figlio p6 ha PID:%d\n", getpid(), p6);

            printf("P3, QUELLO CHE P3 DEVE VISUALIZZARE:\n\n\n");
            printf("La somma degli elementi del vettore è:%d\n", WEXITSTATUS(status));
        }
        else
        { // errore
            printf("Errore generazione figlio\n");
            exit(0);
        }
        exit(25);
    }
    else if (p3 > 0)
    { // PADRE
        wait(&status);
        printf("Il valore d'uscita di p3 è :%d\n", WEXITSTATUS(status));
        printf("PADRE: Io sono il padre e ho PID:%d. Mio figlio p3 ha PID:%d\n", getpid(), p3);
    }
    else
    { // errore
        printf("Errore generazione figlio\n");
        exit(0);
    }

    return 0;
}