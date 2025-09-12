#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define DIM 9
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
int main(int argc, char * argv[]){
    int menu[DIM];
    int uscita=0;
    int scelta;
    do{
        printf("inserisci l'operazione che vuoi svolgere tra queste citate: \n1 Visualizzi a video gli elementi dell’array inseriti o generati casualmente \n2) Visualizzi a video l’array invertito, cioè, sostituendo il primo elemento con l’ultimo, il secondo con il penultimo e così via; \n3) Visualizzi a video la somma e media degli elementi del vettore;\n4) Visualizzi a video tutti i numeri pari;\n5) Visualizzi a video tutti i numeri dispari;\n6) Ricerchi un numero (letto in input) nell’array;\n7) Elimini un elemento (letto in input) dell’array (se esistente);\n8) Alterni (o scambi) a due a due le posizioni del vettore: esempio vettore: 1,2,3,4 vettore alternato: 2,1,4,3 (attenzione se lungo dispari);\n9) Ordini il vettore (ordinamento a scelta). ");
        scanf("%d",&scelta);
        if(scelta==1){
            
        }else if(scelta==2){
            
        }else if(scelta==3){
            
        }else if(scelta==4){
            
        }else if(scelta==5){
            
        }else if(scelta==6){
            
        }else if(scelta==7){
            
        }else if(scelta==8){
            
        }else if(scelta==9){
            
        }else{
            uscita=1;
        }
        
    }while(uscita==0);
    printf("FINE");
    return 0;
}
