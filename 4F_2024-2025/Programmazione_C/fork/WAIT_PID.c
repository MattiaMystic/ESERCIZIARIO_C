/*
Scrivi il codice
sorgente di un programma in cui


il processo padre P1



_ genera un processo
figlio P2


P2
_ genera un vettore v[
] di 5 numeri interi, forniti in input dall’utente >> N.B.
Fare attenzione!!!


_ visualizza il
contenuto del vettore


_ calcola la somma dei
numeri del vettore che, però, verrà visualizzata dal padre P1


_ successivamente,
genera il processo figlio P3


P3 calcola il valore
minimo tra i numeri del vettore


P2


_ attende la terminazione
di P3 e visualizza il valore minimo


_ successivamente,
genera il processo figlio P4


P4 calcola il valore
massimo tra i numeri del vettore


P2


_ attende la terminazione
di P4 e visualizza il valore massimo


_ successivamente,
genera il processo figlio P5


P5 calcola il valore medio
tra i numeri del vettore


P2


_ attende la terminazione
di P5 e visualizza il valore medio


\La prima cosa che
ciascun processo deve fare, appena genera un processo figlio, è dichiararsi nel
modo seguente:


"P1: mio PID=...,
mio figlio P2 ha PID=...


La prima cosa che
ciascun processo figlio deve fare appena è stato generato,


è dichiararsi nel modo
seguente:


"P2: mio PID=...,
mio padre P1 ha PID=..."





Ogni volta che un
processo visualizza qualcosa sullo schermo deve dichiararsi nel modo seguente:


"P1 mio PID=...:
quello che P1 deve visualizzare"


"Pn mio PID=...:
quello che Pn deve visualizzare"*/
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

#define DIM 5

int main(int argc, char *argv[]) {
    int p2, p3, p4, p5;
    int somma = 0;
    int status;
    float valMedio;
    int figlio, minimo, max;
    int v[DIM];

    p2 = fork();
    if (p2 == 0) {
        // P2
        printf("\nP2 PID:%d, mio padre ha PID:%d\n", getpid(), getppid());
        
        // Leggi i numeri
        for (int i = 0; i < DIM; i++) {
            printf("Inserisci il numero per v[%d]: ", i);
            scanf("%d", &v[i]);
            somma += v[i];
        }

        // Visualizza il contenuto dell'array
        printf("Visualizzazione contenuto array:\n");
        for (int i = 0; i < DIM; i++) {
            printf("Elemento in posizione %d del vettore è: %d\n", i, v[i]);
        }

        // Processo P3 - Calcola il valore minimo
        p3 = fork();
        if (p3 == 0) {
            printf("\nP3 PID:%d, mio padre P2 ha PID:%d\n", getpid(), getppid());
            minimo = v[0];
            for (int i = 1; i < DIM; i++) {
                if (v[i] < minimo) {
                    minimo = v[i];
                }
            }
            exit(minimo);
        } else if (p3 > 0) {
            figlio = waitpid(p3, &status, 0);
            printf("\nPADRE P2: il mio PID è: %d, mio figlio P3 ha PID: %d, e il valore minimo del vettore è: %d\n", getpid(), figlio, WEXITSTATUS(status));
        }

        // Processo P4 - Calcola il valore massimo
        p4 = fork();
        if (p4 == 0) {
            printf("\nP4 PID:%d, mio padre P2 ha PID:%d\n", getpid(), getppid());
            max = v[0];
            for (int i = 1; i < DIM; i++) {
                if (v[i] > max) {
                    max = v[i];
                }
            }
            exit(max);
        } else if (p4 > 0) {
            figlio = waitpid(p4, &status, 0);
            printf("\nPADRE P2: il mio PID è: %d, mio figlio P4 ha PID: %d, e il valore massimo del vettore è: %d\n", getpid(), figlio, WEXITSTATUS(status));
        }

        // Processo P5 - Calcola il valore medio
         p5 = fork();
        if (p5 == 0)
        {
            printf("\n P5  PID:%d, mio padre p2 ha PID:%d\n", getpid(), getppid());
            valMedio = (double)somma / (double)DIM;
            exit(valMedio);
        }
            else if (p5 > 0)
        {
            figlio = waitpid(p5, &status, 0);
            printf("\n PADRE  il mio pid è:%d, mio figlio p5 ha PID:%d, e il valore medio del vettore di p5 è:%d", getpid(), figlio, WEXITSTATUS(status));
        }
        else
        {
            printf("ERRORRE GENERAZIONE FIGLIO\n");
        }


        exit(somma);
    } else if (p2 > 0) {
        // P1
        figlio = waitpid(p2, &status, 0);
        printf("\nPADRE P1: il mio PID è: %d, mio figlio P2 ha PID: %d, e la somma del vettore è: %d\n", getpid(), figlio, WEXITSTATUS(status));
    } else {
        printf("ERRORE: Generazione processo figlio fallita\n");
    }

    return 0;
}

