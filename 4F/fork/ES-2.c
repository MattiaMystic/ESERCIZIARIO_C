#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
    int p=fork();

    if(p>0){//padre
        printf("Io sono il padre: PID=%d\n",getpid());

        

    }else if(p==0){//figlio
    
    int f1=fork();
    if(f1==0){
         printf("Io sono il 1 figlio di padre con PID=%d\n",getpid());
    }
    int f2=fork();
    if(f2==0){
         printf("Io sono il 2 figlio di padre con PID=%d\n",getpid());
    }
   
   int ff=fork();
   if(ff==0){
printf("Io sono il figlio del figlio del padre con PID=%d\n",getpid());
   }
    

        
    }else{
        //errore
        printf("ERRORE generazione figlio");
    }
    return 0;
}
