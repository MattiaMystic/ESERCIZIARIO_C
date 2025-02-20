
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(int argc,char*argv[]){
    /*
Scrivi il codice sorgente di un programma in cui:
-Visualizza il proprio PID
-Genera 4 figli e sono: f1,f2,f3,f4
-Genera 2 numeri interi random che sono (n1,n2) compresi tra 1 e 20 necessariamente diversi tra loro
-Visualizza n1 e n2:
A prescindere dal valore di n1 e n2 , f2 dovrà dormire per un numero di secondi pari a n1 e restituire al padre un numero n2_DIM intero compreso tra 2 e 6 estremi compresi.
-F3 dovrà dormire per un numero di secondi pari a n2 e restituire al padre un numero n3_DIM intero compreso tra 1 e 10 (estremi compresi); Non si sa chi dormirà di meno o di più, ossia non si sa chi tra f2 e f3 terminerà per primo
-Solo dopo avere generato entrambi (sia f2 sia f3) attende la loro terminazione : Il numero intero restituito da f2 rappresenterà la dimensione DIM del vettore che f1 dovrà generare
-Per ciascun figlio, il padre visualizza il proprio PID e del relativo figlio

-Ciascun figlio deve:
-Identificarsi dicendo se è f1 o f2 o f3 o f4
-Visualizzare il proprio PID e il PID del proprio padre

f1 deve:
-Generare vettore v[] di numeri interi di dimensione DIM forniti in ingresso dall'utente e compresi tra 1 e 10 estremi inclusi
-Calcolarne la somma(somma)

f4 deve:
-Calcolare media(media) dei numeri forniti in ingresso dall'utente e memorizzati nel vettore e restituirlo al padre

Il padre deve:
-Visualizzare il proprio PID e il valore restituito da f4 con un chiaro messaggio in cui precisa ciò che esso rappresenta:
"Sono il padre, il mio PID è uguale a... , il valore medio dei numeri con cui hai popolato il vettore vale... " 
*/
int f1,f2,f3,f4;

f1=fork();

if(f1==0){

}else if(f1>0){

}else{
    printf("Errore generazione figlio");
    exit(0);
}

    return 0;
}