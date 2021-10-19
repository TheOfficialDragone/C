//
//  main.c
//  ricerca_nomi
//
//  Created by Rocco Carpi on 15/02/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


struct persona
{
    char nome[100];
    char cognome[100];
    int numero;
};

int main(int argc, const char * argv[]) {
   
    FILE *f;
    int DIM = 1;
    struct persona a[DIM];
    f = fopen("input.txt", "r");
    int i = 0;
    if (!f)
    {
        printf("errore nell'apertura del file");
        exit(1);
    }
    
    while (fscanf(f, "%s %[^#]#%d",a[i].nome,a[i].cognome,&a[i].numero) == 3)
    {
        i++;
        DIM++;
    }
    
    int input;
    int risultato = 0;
    int j;
    
    printf("inserire un numero: ");
    scanf("%d",&input);
    
    risultato = log10(input)+1;
    
   // printf("%d \n",risultato);
    
    if(risultato <= 1)
    {
        for (j = 0; j < i; j++)
        {
           
            printf("%s %s %d \n",a[j].nome,a[j].cognome,a[j].numero);
        }
    }
    else
    {
        for (j = 0; j<i; j++)
       {
           if (input == a[j].numero)
           {
               printf("%s %s \n",a[j].nome,a[j].cognome);
           }else
           {
               printf("numero inesistente \n");
               break;
           }
       }
    }
   
    
    
    fclose(f);
    return 0;
    }
    

