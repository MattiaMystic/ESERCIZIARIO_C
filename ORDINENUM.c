//MATTIA PAVARIN
//Date:05/11/2023
#include <stdio.h>


int main() {
    int numeri[10];       	//10 è una variabile fissa:
    int i, prova, j, temp, somma = 0;

    // leggi i numeri
    for (i = 0; i < 10; i++) {
 
        printf("Inserisci un numero compreso tra 1 e 10: ");
        scanf("%d", &prova);
        while (prova<1 || prova>10){
            printf("Numero sbagliato, Inserisci un numero tra 1 e 10: ");
            scanf("%d", &prova);
        }
        numeri[i]=prova;
        somma += numeri[i];
    }
    // calcola la media
    float media = somma / 10.0;
    printf("La media dei numeri inseriti e': %.2f\n", media);

    // trova il numero massimo e il numero minimo
    int min = numeri[0], max = numeri[0];
    for (i = 1; i < 10; i++) {
        if (numeri[i] < min) {
            min = numeri[i];
        }
        if (numeri[i] > max) {
            max = numeri[i];
        }
    }
    printf("Il numero minimo e': %d\n", min);
    printf("Il numero massimo e': %d\n", max);

    // ordina i numeri in ordine crescente
    for (i = 0; i < 9; i++) {
        for (j = i + 1; j < 10; j++) {
            if (numeri[i] > numeri[j]) {
                temp = numeri[i];
                numeri[i] = numeri[j];
                numeri[j] = temp;
            }
        }
    }
    printf("I numeri in ordine crescente sono: ");
    for (i = 0; i < 10; i++) {
        printf("%d ", numeri[i]);
    }
    printf("\n");

    // sposta i numeri verso destra
    temp = numeri[9];
    for (i = 8; i >= 0; i--) {
        numeri[i + 1] = numeri[i];
    }
    numeri[0] = temp;
    printf("I numeri scalati verso destra sono: ");
    for (i = 0; i < 10; i++) {
        printf("%d ", numeri[i]);
    }
    printf("\n");

    return 0;
}