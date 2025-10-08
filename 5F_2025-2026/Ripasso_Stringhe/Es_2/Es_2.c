/*
Esercizio 2 – Gestione Stringhe
Scrivere un programma in C che dopo aver inserito una stringa a piacere determini e o verifichi:
1) Che contenga solo lettere;
2) Il conteggio di una lettera (se presente) scelta dall’utente;
3) Crei 2 ulteriori stringhe che contengano 1 le lettere di posizione pari; la 2° le lettere di posizione
dispari;
4) Verifichi se contiene doppie.
Inserita una 2° stringa determinare:
1) Quale delle 2 è più lunga e più corta;
2) Quali sono le lettere contenute in ambedue le stringhe;
3) Quale delle 2 stringhe contiene più vocali;
4) Quale delle 2 stringhe contiene più consonanti;
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <string.h>

int soloLettere(char *str)
{
    for (int i = 0; str[i]; i++)
    {
        if (str[i] == '0' || str[i] == '1' || str[i] == '2' || str[i] == '3' || str[i] == '4' || str[i] == '5' || str[i] == '6' || str[i] == '7' || str[i] == '8' || str[i] == '9')
            return 0;
    }
    return 1;
}
int contaLettera(char stringa[], char lettera)
{
    int count = 0;
    for (int i = 0; i < strlen(stringa); i++)
    {
        if (stringa[i] == lettera)
        {
            count++;
        }
    }
    return count;
}
void stringhePariDispari(char stringa[], char pari[], char dispari[])
{
    int lunghezza = strlen(stringa);
    int j = 0, k = 0;
    for (int i = 0; i < lunghezza; i++)
    {
        if (i % 2 == 0)
        {
            pari[j++] = stringa[i];
        }
        else
        {
            dispari[k++] = stringa[i];
        }
    }
}
int contieneDoppie(char stringa[])
{
    for (int i = 0; i < strlen(stringa) - 1; i++)
    {
        if (stringa[i] == stringa[i + 1])
        {
            return 1;
        }
    }
    return 0;
}
int confrontaLunghezza(char s1[], char s2[])
{
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    if (len1 > len2)
    {
        return 1;
    }
    else if (len1 < len2)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}
void lettereComuni(char s1[], char s2[], char comuni[])
{
    int indice = 0;
    int trovato; // verificare se il carattere è già stato aggiunto

    for (int i = 0; i < strlen(s1) + strlen(s2); i++)
    {
        comuni[i] = '\0';
    }

    for (int i = 0; i < strlen(s1); i++)
    {
        for (int j = 0; j < strlen(s2); j++)
        {
            if (s1[i] == s2[j])
            {

                trovato = 0;
                for (int k = 0; k < indice; k++)
                {
                    if (comuni[k] == s1[i])
                    {
                        trovato = 1; // Il carattere è già presente
                        break;
                    }
                }

                // Se non è stato trovato, lo aggiungiamo all'array comuni
                if (!trovato)
                {
                    comuni[indice] = s1[i];
                    indice++;
                }
            }
        }
    }
}
int contaVocali(char stringa[])
{
    int count = 0;
    for (int i = 0; i < strlen(stringa); i++)
    {
        char c = stringa[i];
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ||
            c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            count++;
        }
    }
    return count;
}
int contaConsonanti(char stringa[])
{
    int vocali = contaVocali(stringa);
    return strlen(stringa) - vocali;
}

int main(int argc, char *argv[])
{
    char stringa[100], stringa2[100];
    int scelta = -1;
    printf("Inserisci una stringa:\n ");
    scanf("%s", stringa);
    while (scelta != 9)
    {
        printf("\nMenu:\n");
        printf("1. Verifica solo lettere\n");
        printf("2. Conta una lettera\n");
        printf("3. Stringhe pari/dispari\n");
        printf("4. Verifica doppie\n");
        printf("5. Confronta lunghezza tra due stringhe\n");
        printf("6. Lettere comuni tra due stringhe\n");
        printf("7. Conta vocali\n");
        printf("8. Conta consonanti\n");
        printf("9. Esci\n");
        printf("Scegli un'opzione: ");
        scanf("%d", &scelta);

        if (scelta == 1)
        {
            if (soloLettere(stringa))
            {
                printf("La stringa contiene solo lettere.\n");
            }
            else
            {
                printf("La stringa contiene caratteri non alfabetici.\n");
            }
        }
        else if (scelta == 2)
        {
            char lettera;
            printf("Inserisci la lettera da contare: ");
            scanf(" %c", &lettera);
            int count = contaLettera(stringa, lettera);
            printf("\nLa lettera '%c' appare %d volte nella stringa.\n", lettera, count);
        }
        else if (scelta == 3)
        {
            char pari[100], dispari[100];
            stringhePariDispari(stringa, pari, dispari);
            printf("Stringa pari: %s\n", pari);
            printf("Stringa dispari: %s\n", dispari);
        }
        else if (scelta == 4)
        {
            if (contieneDoppie(stringa))
            {
                printf("La stringa contiene doppie.\n");
            }
            else
            {
                printf("La stringa non contiene doppie.\n");
            }
        }
        else if (scelta == 5)
        {
            printf("Inserisci una seconda stringa da confrontare in lunghezza con la prima:\n ");
            scanf("%s", stringa2);
            int risultato = confrontaLunghezza(stringa, stringa2);
            if (risultato == 1)
            {
                printf("La prima stringa è più lunga.\n");
            }
            else if (risultato == -1)
            {
                printf("La seconda stringa è più lunga.\n");
            }
            else
            {
                printf("Le due stringhe sono della stessa lunghezza.\n");
            }
        }
        else if (scelta == 6)
        {
            printf("Inserisci una seconda stringa per trovare le lettere comuni:\n ");
            scanf("%s", stringa2);
            char comuni[100];
            lettereComuni(stringa, stringa2, comuni);
            printf("Lettere comuni: %s\n", comuni);
        }
        else if (scelta == 7)
        {
            int vocali1 = contaVocali(stringa);
            printf("La prima stringa contiene %d vocali.\n", vocali1);
            printf("Inserisci una seconda stringa per confrontare il numero di vocali:\n ");
            scanf("%s", stringa2);
            int vocali2 = contaVocali(stringa2);
            printf("La seconda stringa contiene %d vocali.\n", vocali2);
            if (vocali1 > vocali2)
            {
                printf("La prima stringa contiene più vocali.\n");
            }
            else if (vocali1 < vocali2)
            {
                printf("La seconda stringa contiene più vocali.\n");
            }
            else
            {
                printf("Entrambe le stringhe contengono lo stesso numero di vocali.\n");
            }
        }
        else if (scelta == 8)
        {
            int consonanti1 = contaConsonanti(stringa);
            printf("La prima stringa contiene %d consonanti.\n", consonanti1);
            printf("Inserisci una seconda stringa per confrontare il numero di consonanti:\n ");
            scanf("%s", stringa2);
            int consonanti2 = contaConsonanti(stringa2);
            printf("La seconda stringa contiene %d consonanti.\n", consonanti2);
            if (consonanti1 > consonanti2)
            {
                printf("La prima stringa contiene più consonanti.\n");
            }
            else if (consonanti1 < consonanti2)
            {
                printf("La seconda stringa contiene più consonanti.\n");
            }
            else
            {
                printf("Entrambe le stringhe contengono lo stesso numero di consonanti.\n");
            }
        }
        else if (scelta == 9)
        {
            printf("Uscita...\n");
        }
        else
        {
            printf("Opzione non valida.\n");
        }
    }
    return 0;
}
