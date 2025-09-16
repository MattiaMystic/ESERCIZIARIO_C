/*
Esercizio Gestione del Vettore
Scrivere un programma in C che effettui, attraverso un menù, le seguenti operazione sugli array:
1) Visualizzi a video gli elementi dell’array inseriti o generati casualmente;
2) Visualizzi a video l’array invertito, cioè, sostituendo il primo elemento con l’ultimo, il secondo con il
penultimo e così via;
3) Visualizzi a video la somma e media degli elementi del vettore;
4) Visualizzi a video tutti i numeri pari;
5) Visualizzi a video tutti i numeri dispari;
6) Ricerchi un numero (letto in input) nell’array;
7) Elimini un elemento (letto in input) dell’array (se esistente);
8) Alterni (o scambi) a due a due le posizioni del vettore: esempio
vettore: 1,2,3,4 vettore alternato: 2,1,4,3 (attenzione se lungo dispari);
9) Ordini il vettore (ordinamento a scelta).
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DIM 9


void visualizzazione(int array[], int dim)
{
    printf("Array: ");
    for (int i = 0; i < dim; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void invertito(int array[], int dim)
{
    for (int i = 0; i < dim / 2; i++)
    {
        int temp = array[i];
        array[i] = array[dim - i - 1];
        array[dim - i - 1] = temp;
    }
}

int sommaElementi(int array[], int dim)
{
    int somma = 0;
    for (int i = 0; i < dim; i++)
    {
        somma += array[i];
    }
    return somma;
}

int mediaElementi(int array[], int dim)
{
    return sommaElementi(array, dim) / dim;
}

void pari(int array[], int dim)
{
    printf("Numeri pari: ");
    for (int i = 0; i < dim; i++)
    {
        if (array[i] % 2 == 0)
        {
            printf("%d ", array[i]);
        }
    }
    printf("\n");
}

void dispari(int array[], int dim)
{
    printf("Numeri dispari: ");
    for (int i = 0; i < dim; i++)
    {
        if (array[i] % 2 != 0)
        {
            printf("%d ", array[i]);
        }
    }
    printf("\n");
}

int ricerca(int array[], int dim, int num)
{
    for (int i = 0; i < dim; i++)
    {
        if (array[i] == num)
        {
            return i;
        }
    }
    return -1;
}

void cancella(int array[], int *dim, int num)
{
    int pos = ricerca(array, *dim, num);
    if (pos == -1)
    {
        printf("Elemento non trovato.\n");
        return;
    }
    for (int i = pos; i < *dim - 1; i++)
    {
        array[i] = array[i + 1];
    }
    (*dim)--;
    printf("Elemento eliminato.\n");
}
void alternato(int array[], int dim)
{
    for (int i = 0; i < dim - 1; i += 2)
    {
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
    }
}
void ordinamentoMaggioreMinore(int array[], int dim)
{
    for (int i = 0; i < dim - 1; i++)
    {
        for (int j = 0; j < dim - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int array[MAX_DIM];
    int dim = MAX_DIM; 
    int scelta, num;

    srand(time(NULL));
    for (int i = 0; i < dim; i++)
    {
        array[i] = rand() % 100;
    }

    do
    {
        printf("inserisci l'operazione che vuoi svolgere tra queste citate: \n1 Visualizzi a video gli elementi dell’array inseriti o generati casualmente \n2) Visualizzi a video l’array invertito, cioè, sostituendo il primo elemento con l’ultimo, il secondo con il penultimo e così via; \n3) Visualizzi a video la somma e media degli elementi del vettore;\n4) Visualizzi a video tutti i numeri pari;\n5) Visualizzi a video tutti i numeri dispari;\n6) Ricerchi un numero (letto in input) nell’array;\n7) Elimini un elemento (letto in input) dell’array (se esistente);\n8) Alterni (o scambi) a due a due le posizioni del vettore: esempio vettore: 1,2,3,4 vettore alternato: 2,1,4,3;\n9) Ordini il vettore da maggiore a minore;\n10) Esci dal programma.\n");
        printf("\nScegli un'opzione: \n");
        if (scanf("%d", &scelta) != 1)
        {
            printf("Errore nella lettura dell'input.\n");
            return 1;
        }

        if (scelta == 1)
        {
            visualizzazione(array, dim);
        }
        else if (scelta == 2)
        {
            invertito(array, dim);
            visualizzazione(array, dim);
        }
        else if (scelta == 3)
        {
            int somma = sommaElementi(array, dim);
            int media = mediaElementi(array, dim);
            printf("Somma: %d, Media: %d\n", somma, media);
        }
        else if (scelta == 4)
        {
            pari(array, dim);
        }
        else if (scelta == 5)
        {
            dispari(array, dim);
        }
        else if (scelta == 6)
        {
            printf("Inserisci il numero da cercare: ");
            if (scanf("%d", &num) != 1)
            {
                printf("Errore nella lettura dell'input.\n");
                return 1;
            }
            int pos = ricerca(array, dim, num);
            if (pos != -1)
            {
                printf("Numero trovato in posizione: %d\n", pos);
            }
            else
            {
                printf("Numero non trovato.\n");
            }
        }
        else if (scelta == 7)
        {
            printf("Inserisci il numero da eliminare: ");
            if (scanf("%d", &num) != 1)
            {
                printf("Errore nella lettura dell'input.\n");
                return 1;
            }
            cancella(array, &dim, num);
        }
        else if (scelta == 8)
        {
            alternato(array, dim);
           
        }
        else if (scelta == 9)
        {
            ordinamentoMaggioreMinore(array, dim);
            
        }
        else if (scelta == 10)
        {
            break;
        }
        else
        {
            printf("Opzione non valida.\n");
        }
    } while (1);

    printf("FINE\n");
    return 0;
}

