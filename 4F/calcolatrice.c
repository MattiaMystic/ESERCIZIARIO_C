//LA CALCOLATRICE

#include <stdio.h>

void somma(float n1, float n2, float *ris){
    *ris = n1+n2;
}

void sottrazione(float n1, float n2, float *ris){
    *ris = n1-n2;
}

void divisioni(float n1, float n2, float *ris){
    *ris = n1/n2;
}

void moltiplicazione(float n1, float n2, float *ris){
    *ris = n1*n2;
}

void sceltaOperazione(char oper, float n1, float n2, float *ris){
    switch (oper) {
        case '+':
            somma(n1,n2,ris);
            break;
        case '-':
            sottrazione(n1,n2,ris);
            break;
        case '/':
            divisioni(n1,n2,ris);
            break;
        case '*':
            moltiplicazione(n1,n2,ris);
            break;
        default:
        printf("OPERATORE ERRATO, VERGOGNATI!!!\n");
        *ris=0;
        
    }
}


int main(int argc, char *agrv[]){
    
    float num1,num2,ris;
    char oper;

    /*printf("Inserisci num1:\n");
    scanf("%f",&num1);
    printf("Inserisci num2:\n");
    scanf("%f", &num2);
    printf("Inserisci operatore:\n");
    scanf("%c",&oper);*/
    printf("Inserisci formato: num1 operatore num2\n");
    scanf("%f %c %f", &num1, &oper, &num2);

    sceltaOperazione(oper, num1,num2,&ris);
    
    
    printf("Il risultato è: %.2f\n", ris);
    
    
    return 0;
}
