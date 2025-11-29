#include <stdio.h>
int main()
{
    /*Progettare un algoritmo che effettui le seguenti operazioni:

• continui a leggere da tastiera una serie di terne di valori interi A ,
B e C finchè non vengono inseriti dei valori tali per cui A + B < C
• conteggi il numero di volte in cui la differenza tra A e B è pari, dispari, e quando è nulla
• prima di terminare, visualizzi il valore dei valori conteggiati*/
    int A, B, C, Differenza, Pari = 0, Dispari = 0, Nulla = 0;
    do
    {
        printf("Inserisci rispettivamente da tastiera A, B, C: \n");
        scanf("%d", &A);
        scanf("%d", &B);
        scanf("%d", &C);
        Differenza = A - B;
        if (Differenza % 2 == 0)
        {
            Pari = Pari + 1;
        }
        if (Differenza % 2 != 0)
        {
            Dispari = Dispari + 1;
        }
        if (Differenza == 0)
        {
            Nulla = Nulla + 1;
        }

    } while ((A + B) < C);
    printf("La differenza tra A e B è pari %d volte \n", Pari);
    printf("La differenza tra A e B è dispari %d volte \n", Dispari);
    printf("La differenza tra A e B è Nulla %d volte \n", Nulla);
    return 0;
}