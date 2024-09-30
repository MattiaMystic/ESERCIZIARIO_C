#include <stdio.h>
#include <limits.h>
/*Progettare un algoritmo che risolva il seguente problema. Si richieda
all’utente di inserire una serie di terne di dati numerici (A, B, C).
Il programma deve terminare quando uno dei valori inseriti è minore di
zero. Si scartino le terne nelle quali i valori non sono in ordine
strettamente crescente, ovvero quelle terne per cui non valga A < B < C.
Su tutte le terne non scartate si calcoli il massimo e il minimo dei
valori inseriti. Si stampino a video tali valori massimi e minimi prima
di terminare il programma.*/
int main()
{
    int A, B, C, min = INT_MAX, max = 0;
    do
    {
        printf("Inserisci A \n");
        scanf("%d", &A);
        printf("Inserisci B\n");
        scanf("%d", &B);
        printf("Inserisci C \n");
        scanf("%d", &C);
        if (A < B && B < C)
        {
            if (A < min)
            {
                min = A;
            }
            if (C > max)
            {
                max = C;
            }
        }
        else
        {
            printf("terna non valida\n");
        }

    } while (A >= 0 && B >= 0 && C >= 0);
    printf("Il valore massimo è %d \n", max);
    printf("Il valore minimo è %d \n", min);
    return 0;
}