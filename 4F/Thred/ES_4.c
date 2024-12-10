#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/fcntl.h>
#include <ctype.h>
#include <string.h>
int main(int argc, char* argv[]){
    if(argc!=2){
        printf("Argomenti argv errati!\n");
        exit(0);
    }
int ricerca = atoi(argv[1]);
    int array[]={1,2,3,4,5};
    int posizione;
    int p=fork();
    if(p==0){
        posizione=Ricerca(ricerca,array);
        if(posizione==-1){
            printf("Numero non trovato\n");
        }else{
            printf("Il numero cercato è in posizione %d dell'array\n",posizione);
        }
        sleep(5);
        exit(2);

        
    }else if(p>0){
        wait(&p);
    }
    printf("Programma terminato");

    return 0;
}
int Ricerca(int n,int array[]){
    for(int i=0;i<5;i++){
        if(array[i]==n){
            return i;
        }
    }
    return -1;

}