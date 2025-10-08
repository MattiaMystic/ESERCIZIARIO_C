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
struct Auto
{
    char ModelloAuto[50];
    char marca[50];
    int cilindrata;
    float prezzo;
    int anno_immatricolazione;
    char targa[10];
};
void inserimentoAuto(struct Auto autoList[100],int numAuto)
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
int trovaPrezzoMaxMin(struct Auto autoList[100], int numAuto)
{
    if (numAuto == 0)
    {
        printf("Nessuna auto inserita.\n");
        return -1; // Indica che non ci sono auto
    }
    int prezzoMaxMin[2];

    float prezzoMax = autoList[0].prezzo;
    int indiceMax = 0;
    float prezzoMin = autoList[0].prezzo;
    int indiceMin = 0;

    for (int i = 1; i < numAuto; i++)
    {
        if (autoList[i].prezzo > prezzoMax)
        {
            prezzoMax = autoList[i].prezzo;
            indiceMax = i;
        }
    }
     for (int i = 1; i < numAuto; i++)
    {
        if (autoList[i].prezzo > prezzoMin)
        {
            prezzoMin = autoList[i].prezzo;
            indiceMin = i;
        }
    }

    return prezzoMaxMin[indiceMax,indiceMin];
}

int main(int argc, char *argv[])
{
    int scelta;
    struct Auto autoList[100];
    int numAuto = 0;
  
    while (scelta != 8)
    {
        printf("Scegli un'opzione:\n");
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
                inserimentoAuto(autoList,numAuto);
                numAuto++;
            }
            else
            {
                printf("Limite massimo di auto raggiunto.\n");
            }
            break;
        case 2:
            int prezzoMaxMin[2];
            prezzoMaxMin[0] = trovaPrezzoMaxMin(autoList, numAuto);
            prezzoMaxMin[1] = trovaPrezzoMaxMin(autoList, numAuto);
            printf("Il prezzo massimo è: %d\n", prezzoMaxMin[0]);
            printf("Il prezzo minimo è: %d\n", prezzoMaxMin[1]);

            break;
        case 3:
            break;
        case 4:
            
            break;
        case 5:
          
            break;
        case 6:
            
            break;
        case 8:
            printf("Uscita dal programma.\n");
            break;
        default:
            printf("Scelta non valida. Riprova.\n");
        }
    }

    return 0;
}