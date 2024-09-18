#include <stdio.h>
int main()
{
    /*
Esercizio 1
Progettare un algoritmo che effettui la lettura da tastiera di una serie di coppie di valori numerici.
L’algoritmo deve calcolare e stampare il rapporto tra il valore minore e quello maggiore dei due. Il
programma termina quando uno dei due valori o entrambi sono uguali a zero.*/
    int n1, n2;
    float rapporto;
    do
    {
        printf("Inserisci una coppia di numeri: \n");
        scanf("%d", &n1);
        scanf("%d", &n2);
        if (n1 < n2)
        {
            rapporto = (double)n1 / (double)n2;
        }
        else
        {
            rapporto = (double)n2 / (double)n1;
        }
        printf("Il rapporto è : %f \n", rapporto);
    } while (n1 != 0 && n2 != 0);
    printf("Fine programma");
    return 0;
}