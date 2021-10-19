//
//  main.c
//  converti_Binario
//
//  Created by Rocco Carpi on 27/01/21.
//

#include <stdio.h>
#include <stdlib.h>

void dectobyte(int, char []);

int main(int argc, const char * argv[]) {
    
    
    FILE *fp;
    FILE *fBin;
    
    int primo_byte;
    int secondo_byte;
    int terzo_byte;
    int quarto_byte;
    
    char bin[9];
    
    
    /*
   printf("inserire il nome del file ");       //nome del file binario
   scanf("%s",nomeBin);
    
    fBin = fopen("binario.txt", "w");
     */
    
    fp=fopen("ipdec.txt", "r");

    if(! fp)
    {
            printf("Errore nell'apertura del file \n");
            exit(1);
    }
    
    
    while (fscanf(fp, "%d.%d.%d.%d", &primo_byte, &secondo_byte, &terzo_byte, &quarto_byte) == 4)
    {
        printf("%d %d %d %d \n", primo_byte,secondo_byte,terzo_byte,quarto_byte);
        
        
        /*
        dectobyte(primo_byte, &bin[9]);
        fprintf(fBin, "%s",bin);
        dectobyte(secondo_byte, &bin[9]);
        fprintf(fBin, "%s",bin);
        dectobyte(terzo_byte, &bin[9]);
        fprintf(fBin, "%s",bin);
        dectobyte(quarto_byte, &bin[9]);
        fprintf(fBin, "%s",bin);
         */
        
    }
    
    dectobyte(primo_byte, &bin[9]);
    printf("%s",bin);
    dectobyte(secondo_byte, &bin[9]);
    printf("%s",bin);
    dectobyte(terzo_byte, &bin[9]);
    printf("%s",bin);
    dectobyte(quarto_byte, &bin[9]);
    printf("%s",bin);

    fclose(fp);
   // fclose(fBin);
    return 0;

}

void dectobyte(int n, char bin[])
{
    int k = 0;
    while (n!=0)
    {
          if (n%2 == 1)
             bin[k] = 1;
           else
              bin[k] = 0;
           n /= 2;
           k++;
       }
}
 
    


