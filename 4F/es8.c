#include <stdio.h>
#include <math.h>
/*Progettare un algoritmo che risolve il seguente problema. Si desidera
calcolare la somma delle radici quadrate di N valori numerici inseriti
dall’utente, con N inserito in input.
L’algoritmo deve stampare la somma calcolata. L’algoritmo deve terminare
con un messaggio di errore quando viene inserito un numero che non
permette di effettuare il calcolo (nel dominio dei numeri reali).*/
int main()
{
    int nRadici;
    float n;
    double r, somma = 0;
    printf("Quante radici quadrate di n numeri vuoi sommare? \n ");
    scanf("%d", &nRadici);
    for (int i = 0; i < nRadici; i++)
    {

        printf("Inserisci il %d numero\n", i);
        scanf("%f", &n);
        if (n > 0)
        {
            r = sqrt(n);
            printf("La radice del %d numero è %.2f \n", i, r);
            somma += r;
        }
    }
    if (somma > 0)
        printf("La somma è :%.2f\n", somma);
    else
    {
        printf("è stato inserito un valore n che permetta il calcolo nel dominio dei numeri reali R \n");
    }
    return 0;
}
