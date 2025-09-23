#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

#define DIM 5

int main(int argc, char *argv[]) {
int p2, p3, p4, p5;
    int somma = 0;
    int status;
    float valMedio;
    int figlio, minimo, max;
    int v[DIM];

    p2 = fork();
  if(p2==0){
    printf("MIO PID è %d",getpid());
    close(0);
    sleep(10);

  }
  return 0;


}

