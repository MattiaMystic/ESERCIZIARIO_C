#include <stdio.h>
#include <string.h>
/*
Esercizio - Strutture
Scrivere un programma in C che dopo aver dichiarato una struttura denominata Auto con i seguenti
campi: ModelloAuto, marca, cilindrata, prezzo, anno_immatricolazione, targa; determini:
1) Il prezzo + alto e quello + basso visualizzando anche il modello dell&#39;auto;
2) Ordinare la lista delle auto in base all&#39;anno d&#39;immatricolazione;
3) Visualizzare il nome delle auto a partire da un prezzo scelto dall&#39;utente.
4) Ricerchi un Auto scelta dall’utente (utilizzare il campo targa): visualizzando tutti i campi;
5) La media dei prezzi delle auto inserite;
6) Visualizzare le Auto con anno di immatricolazione scelto dall’utente;
*/

/**
 * @brief Struttura auto con attributi: ModelloAuto, marca, cilindrata, prezzo, anno_immatricolazione, targa.
 */
struct Auto
{
    char ModelloAuto[50];
    char marca[50];
    int cilindrata;
    float prezzo;
    int anno_immatricolazione;
    char targa[10];
};

/**
 * @brief Inserimento nuova auto nella lista.
 *
 * @param autoList Lista delle auto.
 * @param numAuto Indice della nuova auto da inserire.
 */
void inserimentoAuto(struct Auto autoList[100], int numAuto)
{
    printf("Inserisci il modello dell'auto: ");
    scanf("%s", autoList[numAuto].ModelloAuto);
    printf("Inserisci la marca dell'auto: ");
    scanf("%s", autoList[numAuto].marca);
    printf("Inserisci la cilindrata dell'auto: ");
    scanf("%d", &autoList[numAuto].cilindrata);
    printf("Inserisci il prezzo dell'auto: ");
    scanf("%f", &autoList[numAuto].prezzo);
    printf("Inserisci l'anno di immatricolazione dell'auto: ");
    scanf("%d", &autoList[numAuto].anno_immatricolazione);
    printf("Inserisci la targa dell'auto: ");
    scanf("%s", autoList[numAuto].targa);
}

/**
 * @brief Trova il prezzo massimo e minimo tra le auto inserite.
 *
 * @param autoList Lista delle auto.
 * @param numAuto Numero di auto inserite.
 * @param indiceMax Indice dell'auto con il prezzo massimo.
 * @param indiceMin Indice dell'auto con il prezzo minimo.
 */
void trovaPrezzoMaxMin(struct Auto autoList[100], int numAuto, int *indiceMax, int *indiceMin)
{
    float prezzoMax = autoList[0].prezzo;
    float prezzoMin = autoList[0].prezzo;
    *indiceMax = 0;
    *indiceMin = 0;

    for (int i = 1; i < numAuto; i++)
    {
        if (autoList[i].prezzo > prezzoMax)
        {
            prezzoMax = autoList[i].prezzo;
            *indiceMax = i;
        }
        if (autoList[i].prezzo < prezzoMin)
        {
            prezzoMin = autoList[i].prezzo;
            *indiceMin = i;
        }
    }
}

/**
 * @brief Ordina la lista delle auto in base all'anno di immatricolazione.
 *
 * @param autoList Lista delle auto.
 * @param numAuto Numero di auto inserite.
 */
void ordinaPerAnno(struct Auto autoList[100], int numAuto)
{
    struct Auto temp;
    for (int i = 0; i < numAuto - 1; i++)
    {
        for (int j = 0; j < numAuto - i - 1; j++)
        {
            if (autoList[j].anno_immatricolazione > autoList[j + 1].anno_immatricolazione)
            {
                temp = autoList[j];
                autoList[j] = autoList[j + 1];
                autoList[j + 1] = temp;
            }
        }
    }
}

/**
 * @brief Trova le auto con un prezzo maggiore o uguale a quello scelto dall'utente.
 *
 * @param autoList Lista delle auto.
 * @param numAuto Numero di auto inserite.
 * @param prezzoScelto Prezzo minimo scelto dall'utente.
 * @param risultati Array di indici delle auto che soddisfano il criterio.
 * @return Numero di auto trovate.
 */
int trovaAutoDaPrezzo(struct Auto autoList[100], int numAuto, float prezzoScelto, int risultati[100])
{
    int contatore = 0;
    for (int i = 0; i < numAuto; i++)
    {
        if (autoList[i].prezzo >= prezzoScelto)
        {
            risultati[contatore++] = i;
        }
    }
    return contatore;
}

/**
 * @brief Cerca un'auto in base alla targa.
 *
 * @param autoList Lista delle auto.
 * @param numAuto Numero di auto inserite.
 * @param targaScelta Targa dell'auto da cercare.
 * @return Indice dell'auto trovata, -1 se non trovata.
 */
int cercaAutoPerTarga(struct Auto autoList[100], int numAuto, char targaScelta[10])
{
    for (int i = 0; i < numAuto; i++)
    {
        if (strcmp(autoList[i].targa, targaScelta) == 0)
        {
            return i;
        }
    }
    return -1;
}

/**
 * @brief Calcola la media dei prezzi delle auto inserite.
 *
 * @param autoList Lista delle auto.
 * @param numAuto Numero di auto inserite.
 * @return Media dei prezzi.
 */
float calcolaMediaPrezzi(struct Auto autoList[100], int numAuto)
{
    float somma = 0;
    for (int i = 0; i < numAuto; i++)
    {
        somma += autoList[i].prezzo;
    }
    return somma / numAuto;
}

/**
 * @brief Trova le auto con un anno di immatricolazione scelto dall'utente.
 *
 * @param autoList Lista delle auto.
 * @param numAuto Numero di auto inserite.
 * @param annoScelto Anno di immatricolazione scelto dall'utente.
 * @param risultati Array di indici delle auto che soddisfano il criterio.
 * @return Numero di auto trovate.
 */
int trovaAutoPerAnno(struct Auto autoList[100], int numAuto, int annoScelto, int risultati[100])
{
    int count = 0;
    for (int i = 0; i < numAuto; i++)
    {
        if (autoList[i].anno_immatricolazione == annoScelto)
        {
            risultati[count++] = i;
        }
    }
    return count;
}

int main()
{
    int scelta;
    struct Auto autoList[100];
    int numAuto = 0;

    do
    {
        printf("\nScegli un'opzione:\n");
        printf("1. Inserisci una nuova auto\n");
        printf("2. Trova il prezzo più alto e più basso\n");
        printf("3. Ordina le auto per anno di immatricolazione\n");
        printf("4. Visualizza le auto a partire da un prezzo scelto\n");
        printf("5. Cerca un'auto per targa\n");
        printf("6. Calcola la media dei prezzi delle auto\n");
        printf("7. Visualizza le auto con anno di immatricolazione scelto\n");
        printf("8. Esci\n");
        scanf("%d", &scelta);

        switch (scelta)
        {
        case 1:
            if (numAuto < 100)
            {
                inserimentoAuto(autoList, numAuto);
                numAuto++;
            }
            else
            {
                printf("Limite massimo di auto raggiunto.\n");
            }
            break;
        case 2:
        {
            int indiceMax, indiceMin;
            trovaPrezzoMaxMin(autoList, numAuto, &indiceMax, &indiceMin);
            printf("Prezzo massimo: %.2f, Modello: %s\n", autoList[indiceMax].prezzo, autoList[indiceMax].ModelloAuto);
            printf("Prezzo minimo: %.2f, Modello: %s\n", autoList[indiceMin].prezzo, autoList[indiceMin].ModelloAuto);
            break;
        }
        case 3:
            ordinaPerAnno(autoList, numAuto);
            printf("Lista ordinata per anno di immatricolazione.\n");
            break;
        case 4:
        {
            float prezzoScelto;
            int risultati[100];
            printf("Inserisci il prezzo minimo: ");
            scanf("%f", &prezzoScelto);
            int count = trovaAutoDaPrezzo(autoList, numAuto, prezzoScelto, risultati);
            for (int i = 0; i < count; i++)
            {
                int k = risultati[i];
                printf("Modello: %s, Prezzo: %.2f\n", autoList[k].ModelloAuto, autoList[k].prezzo);
            }
            break;
        }
        case 5:
        {
            char targaScelta[10];
            printf("Inserisci la targa dell'auto da cercare: ");
            scanf("%s", targaScelta);
            int indice = cercaAutoPerTarga(autoList, numAuto, targaScelta);
            if (indice != -1)
            {
                printf("Modello: %s, Marca: %s, Cilindrata: %d, Prezzo: %.2f, Anno: %d, Targa: %s\n", autoList[indice].ModelloAuto, autoList[indice].marca, autoList[indice].cilindrata, autoList[indice].prezzo, autoList[indice].anno_immatricolazione, autoList[indice].targa);
            }
            else
            {
                printf("Auto con targa %s non trovata.\n", targaScelta);
            }
            break;
        }
        case 6:
            if (numAuto > 0)
            {
                printf("La media dei prezzi è: %.2f\n", calcolaMediaPrezzi(autoList, numAuto));
            }
            else
            {
                printf("Nessuna auto inserita.\n");
            }
            break;
        case 7:
        {
            int annoScelto, risultati[100];
            printf("Inserisci l'anno di immatricolazione: ");
            scanf("%d", &annoScelto);
            int count = trovaAutoPerAnno(autoList, numAuto, annoScelto, risultati);
            for (int i = 0; i < count; i++)
            {
                int k = risultati[i];
                printf("Modello: %s, Marca: %s, Prezzo: %.2f\n",
                       autoList[k].ModelloAuto, autoList[k].marca, autoList[k].prezzo);
            }
            break;
        }
        case 8:
            printf("Uscita dal programma.\n");
            break;
        default:
            printf("Scelta non valida. Riprova.\n");
        }
    } while (scelta != 8);

    return 0;
}