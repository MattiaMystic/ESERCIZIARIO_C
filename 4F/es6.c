#include <stdio.h>
int main()
{
    /*
    Progettare un algoritmo che effettui le seguenti operazioni:
• legga da tastiera una coppia di valori interi A e B con A<B;
• continui a leggere da tastiera una serie di valori interi, terminando
quando il valore letto è al di fuori dell’intervallo [A, B];
• conteggi la media dei valori letti;
• prima di terminare, stampi il valore calcolato.*/
    int A, B, Somma = 0, N, i = 0;
    double media;
    do
    {

        printf("Inserisci A \n");
        scanf("%d", &A);
        printf("Inserisci B \n");
        scanf("%d", &B);
    } while (A > B);
    do
    {
        printf("Inserisci un numero compreso tra A e B \n");
        scanf("%d", &N);
        if (N >= A && N <= B)
        {
            Somma = Somma + N;
            i++;
        }

    } while (N >= A && N <= B);
    media = (double)Somma / (double)i;
    printf("La media è : %f \n", media);
    return 0;
}