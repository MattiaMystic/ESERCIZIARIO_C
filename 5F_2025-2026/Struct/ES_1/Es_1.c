#include <stdio.h>
#include <string.h>


struct Persona{
    char nome[50];
    char cognome[50];
    int eta;
    float altezza;
};

typedef struct{
    char nome[50];
    char cognome[50];
    int eta;
    float altezza;
}Persona;
void stampaDettagliPersona(struct Persona p) {//funzione con struct
    printf("Nome: %s\n", p.nome);
    printf("Cognome: %s\n", p.cognome);
    printf("Età: %d\n", p.eta);
    printf("Altezza: %.2f\n", p.altezza);
} 
void stampaDettagliPersona2(Persona p) {//funzione con typedef
    printf("Nome: %s\n", p.nome);
    printf("Cognome: %s\n", p.cognome);
    printf("Età: %d\n", p.eta);
    printf("Altezza: %.2f\n", p.altezza);
}
void aggiornaEta(Persona* p, int nuovaEta) {
    (*p).eta = nuovaEta;
}   
int main() {
    Persona p1;//Per il typedef
    struct Persona p2; //Per la struct
    stampaDettagliPersona(p2);
    stampaDettagliPersona2(p1);
    Persona p3 = {"Mario", "Rossi", 30, 1.75};
    printf("Età prima: %d\n", p3.eta);
    aggiornaEta(&p3, 31);
    printf("Età dopo: %d\n", p3.eta);

    
    return 0;
}