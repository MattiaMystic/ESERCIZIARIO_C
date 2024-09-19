#include <stdio.h>
#include <math.h>

int main()
{
    /*
    Progettare un algoritmo che effettui la lettura da tastiera di una serie
di coppie di valori numerici reali (sia positivi che negativi che zero).
Per ciascuna coppia, l’algoritmo deve calcolare e stampare il valore
della radice quadrata del rapporto tra il valore maggiore e quello
minore dei due. Il programma termina quando vengono inseriti dei valori
che non permettono di svolgere il calcolo nel dominio dei numeri reali.
Prima di terminare si richiede di stampare un messaggio che indichi la
ragione per cui non è stato possibile svolgere il calcolo.
    */
    int n1,n2;
    double r;
    do{
    printf("Inserisci una coppia di numeri reali: \n");
    scanf("%d",&n1);
        scanf("%d",&n2);
        if (a < b)
			r = (double)b / (double)a;
		else
			r = (double)a / (double)b;

		if (r > 0)
		{
			r = sqrt(r);
			printf("radice quadrata del rapporto: %f", r);
		}
    }while(r>0);
    printf("\n La radice non può avere valore 0");
    

    return 0;
}
