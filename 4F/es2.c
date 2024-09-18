#include <stdio.h>
int main()
{
    /*
    Progettare un algoritmo che effettui le seguenti operazioni:
• continui a leggere da tastiera due valori numerici, fermandosi quando uno dei due numeri è
0 (zero)
• per ogni coppia di numeri letti:
◦ calcoli il prodotto dei due numeri e ne stampi il valore
◦ sommi il prodotto calcolato ad una variabile che memorizzi la somma di tutti i prodotti
• all’uscita del ciclo, stampi il valore della somma*/
    int n1, n2, prodotto = 0, SommaProdotti = 0;
    printf("Inserisci due numeri finchè uno di questi è uguale a 0\n");
    do
    {
        printf("Inserisci il primo numero\n");
        scanf("%d", &n1);
        printf("Inserisci il secondo numero\n");
        scanf("%d", &n2);
        prodotto = n1 * n2;
        printf("Il prodotto della coppia di numeri è : %d \n", prodotto);
        SommaProdotti = SommaProdotti + prodotto;
    } while (n1 != 0 && n2 != 0);
    printf("La somma di tutti i prodotti è: %d\n", SommaProdotti);
    return 0;
}