CONSEGNA VINAIO 2

Il cliente del vinaio può acquistare i seguenti vini 
selezionandoli con un valore intero.
1 Prosecco 2 euro 
2 Merlot 1.5 euro
3 Lugana 5 euro
Modificare l'esercizio precedente in modo da calcolare il totale del vino acquistato in relazione al tipo di vino.



PAVARIN MATTIA 28/11/2023

import java.util.Scanner;
public class vinaio2{
    public static void main(String[]args){
       //creazione di un oggeto 
        //scanner per l'input da tastiera 
        Scanner scanner=new Scanner(System.in);
        //inserimento del primo Numero 
        System.out.print("inserisci il numero dei bottiglioni di vino da 1.5 litri che vuoi acquistare ");
        double NBottiglioni=
        scanner.nextInt();
         System.out.println("il numero dei bottiglioni da 1.5 litri che vui acquistare sono: "+NBottiglioni);
         

          System.out.print("se vuoi il prosecco scrivi (1) se vuoi il merlot scrivi (2) se vuoi il lugana scrivi (3) ");
        double Scelta=
        scanner.nextInt();

        //scelta secondo gli if
        if(Scelta==1){
            System.out.println("hai scelto il prosecco che costa 2$ al litro");
            double Risultato1=NBottiglioni*1.5;
            double Prezzo1=NBottiglioni*2;
            System.out.println("il prezzo del vino prosecco senza iva e' di"+Prezzo1);
            System.out.println("l'iva da aggiungere al prezzo del vino e' del 22%");
        double IVA1=(Prezzo1/100)*22;
        double PrezzoTotale1=IVA1+Prezzo1;
        System.out.println("il prezzo totale + iva e'"+PrezzoTotale1);


        } else if (Scelta==2){
System.out.println("hai scelto il merlot che costa 1.5$ al litro");
            double Risultato2=NBottiglioni*1.5;
            double Prezzo2=NBottiglioni*1.5;
            System.out.println("il prezzo del vino merlot senza iva e' di"+Prezzo2);
            System.out.println("l'iva da aggiungere al prezzo del vino e' del 22%");
        double IVA2=(Prezzo2/100)*22;
        double PrezzoTotale2=IVA2+Prezzo2;
        System.out.println("il prezzo totale + iva e'"+PrezzoTotale2);





        }else if (Scelta==3){
System.out.println("hai scelto il lugana che costa 2$ al litro");
            double Risultato3=NBottiglioni*1.5;
            double Prezzo3=NBottiglioni*5;
            System.out.println("il prezzo del vino lugana senza iva e' di"+Prezzo3);
            System.out.println("l'iva da aggiungere al prezzo del vino e' del 22%");
        double IVA3=(Prezzo3/100)*22;
        double PrezzoTotale3=IVA3+Prezzo3;
        System.out.println("il prezzo totale + iva e'"+PrezzoTotale3);





        } else {
            System.out.println("La scelta del vino non risulta corretta");
        }




          
        
}
}
