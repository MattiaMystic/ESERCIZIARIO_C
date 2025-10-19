#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char nome[30];
    char cognome[30];
    int eta;
    char codice_fiscale[17];
    float reddito_annuo;
    int anno_nascita;
    char citta[30];
} Persona;


void inserisciPersona(Persona *p) {
    printf("Inserisci nome: ");
    scanf("%s", p->nome);

    printf("Inserisci cognome: ");
    scanf("%s", p->cognome);

    printf("Inserisci eta: ");
    scanf("%d", &p->eta);

    printf("Inserisci codice fiscale: ");
    scanf("%s", p->codice_fiscale);

    printf("Inserisci reddito annuo: ");
    scanf("%f", &p->reddito_annuo);

    printf("Inserisci anno di nascita: ");
    scanf("%d", &p->anno_nascita);

    printf("Inserisci citta': ");
    scanf("%s", p->citta);
}

void redditoMaxMin(Persona persone[], int n, int risultati[]) {
    if (n == 0) {
        printf("Nessuna persona inserita.\n");
        return;
    }
    int max = 0, min = 0;
    for (int i = 1; i < n; i++) {
        if (persone[i].reddito_annuo > persone[max].reddito_annuo) max = i;
        if (persone[i].reddito_annuo < persone[min].reddito_annuo) min = i;
    }
    risultati[0] = max; 
    risultati[1] = min; 
}

void ordinaPerAnnoNascita(Persona persone[], int n) {
    Persona temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (persone[i].anno_nascita > persone[j].anno_nascita) {
                temp = persone[i];
                persone[i] = persone[j];
                persone[j] = temp;
            }
        }
    }
}

int cercaPerCodiceFiscale(Persona persone[], int n, char cf[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(persone[i].codice_fiscale, cf) == 0) {
            return i;
        }
    }
    return -1;
       
}

int redditiSuperiori(Persona persone[], int n, float soglia, int risultati[]) {
    int trovati = 0;
    for (int i = 0; i < n; i++) {
        if (persone[i].reddito_annuo >= soglia) {
            risultati[trovati] = i; // Salvo l'indice della persona
            trovati++;
        }
    }
    return trovati; 
}

float mediaRedditi(Persona persone[], int n) {
    if (n == 0) return 0;
    float somma = 0;
    for (int i = 0; i < n; i++)
        somma += persone[i].reddito_annuo;
    return somma / n;
}

int personePerAnno(Persona persone[], int n, int anno, int risultati[]) {
    int trovati = 0;
    for (int i = 0; i < n; i++) {
        if (persone[i].anno_nascita == anno) {
            risultati[trovati] = i; // Salvo l'indice della persona
            trovati++;
        }
    }
    return trovati; 
}

void raggruppaPerCitta(Persona persone[], int n) {
   
}


int main() {
    Persona persone[MAX];
    int n = 0;
    int scelta;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Inserisci persona\n");
        printf("2. Visualizza persone\n");
        printf("3. Reddito massimo e minimo\n");
        printf("4. Ordina per anno di nascita\n");
        printf("5. Cerca per codice fiscale\n");
        printf("6. Visualizza persone con reddito >= soglia\n");
        printf("7. Calcola media redditi\n");
        printf("8. Persone nate in un anno\n");
        printf("9. Raggruppa per citta'\n");
        printf("0. Esci\n");
        printf("Scelta: ");
        scanf("%d", &scelta);

        switch (scelta) {
            case 1:
                if (n < MAX) {
                    inserisciPersona(&persone[n]);
                    n++;
                } else
                    printf("Archivio pieno!\n");
                break;

            case 2:
                if (n == 0)
                    printf("Nessuna persona inserita.\n");
                else
                    for (int i = 0; i < n; i++) {
                        printf("%d) %s %s - Eta: %d - CF: %s - Reddito: %.2f - Nascita: %d - Citta': %s\n",
                               i + 1, persone[i].nome, persone[i].cognome, persone[i].eta,
                               persone[i].codice_fiscale, persone[i].reddito_annuo,
                               persone[i].anno_nascita, persone[i].citta);
                    }
                break;

            case 3:
            int risultati[2];
            redditoMaxMin(persone, n, risultati);
            if (n > 0) {
                printf("\nReddito massimo: %s %s (%s) - %.2f\n",
                       persone[risultati[0]].nome, persone[risultati[0]].cognome,
                       persone[risultati[0]].citta, persone[risultati[0]].reddito_annuo);
                printf("Reddito minimo: %s %s (%s) - %.2f\n",
                       persone[risultati[1]].nome, persone[risultati[1]].cognome,
                       persone[risultati[1]].citta, persone[risultati[1]].reddito_annuo);
            }
            break;
        

            case 4:
                ordinaPerAnnoNascita(persone, n);
                printf("Persone ordinate per anno di nascita.\n");
                break;

            case 5: {
                char cf[17];
                printf("Inserisci codice fiscale da cercare: ");
                scanf("%s", cf);
                int indice = cercaPerCodiceFiscale(persone, n, cf);
                if (indice != -1) {
                    printf("\nTrovato: %s %s  %s - Reddito: %.2f\n",
                           persone[indice].nome, persone[indice].cognome, persone[indice].citta, persone[indice].reddito_annuo);
                } else {
                    printf("Nessuna persona trovata con codice fiscale %s\n", cf);
                }
                break;
            }

            case 6: {
                float soglia;
                printf("Inserisci soglia di reddito: ");
                scanf("%f", &soglia);
                int risultati[MAX];
                int trovati = redditiSuperiori(persone, n, soglia, risultati);
                for (int i = 0; i < trovati; i++) {
                    int k = risultati[i];
                    printf("%s %s  %.2f (%s)\n", persone[k].nome, persone[k].cognome, persone[k].reddito_annuo, persone[k].citta);
                }
                if (trovati == 0) {
                    printf("Nessuna persona con reddito >= %.2f\n", soglia);
                }
                break;
            }

            case 7:
                printf("Media redditi: %.2f\n", mediaRedditi(persone, n));
                break;

            case 8: {
                int anno;
                printf("Inserisci anno di nascita: ");
                scanf("%d", &anno);
                int risultati[MAX];
                int trovati = personePerAnno(persone, n, anno, risultati);
                for (int i = 0; i < trovati; i++) {
                    int k = risultati[i];
                    printf("%s %s - %s - Eta: %d\n", persone[k].nome, persone[k].cognome, persone[k].citta, persone[k].eta);
                }
                if (trovati == 0) {
                    printf("Nessuna persona nata nel %d\n", anno);
                }
                break;
            }

            case 9:
                raggruppaPerCitta(persone, n);
                break;

            case 0:
                printf("Uscita...\n");
                break;

            default:
                printf("Scelta non valida!\n");
        }

    } while (scelta != 0);

    return 0;
}
