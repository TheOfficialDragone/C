//
//  main.c
//  Unisci_file
//
//  Created by Rocco Carpi on 06/04/21.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int matricola;
    char nome[50];
    char cognome[50];
    
} studente;
int cmpGiorni(const void * a, const void * b);
int main(int argc, const char * argv[])
{
    FILE *f1;
    FILE *f2;
    
    f1 = fopen("elenco1.txt", "r");
    if (!f1)
    {
        perror("errore apertura file");
        exit(EXIT_FAILURE);
    }
    
    f2 = fopen("elenco2.txt", "r");
    if (!f2)
    {
        perror("errore apertura file");
        exit(EXIT_FAILURE);
    }
    
    int dimensione1 = 0;
    int dimensione2 = 0;
    
    int t1;
    char t2[50];
    char t3[50];
    
    while (fscanf(f1, "%d %s %s",&t1,t2,t3) == 3)
    {
        dimensione1++;
    }
    fseek(f1, 0, 0);
    
    while (fscanf(f2, "%d %s %s",&t1,t2,t3) == 3)
    {
        dimensione2++;
    }
    fseek(f2, 0, 0);
    
    int dimensione_totale = dimensione1 + dimensione2;
    studente s [dimensione_totale];
    int j = 0;
    while (fscanf(f1, "%d %s %s",&s[j].matricola,s[j].nome,s[j].cognome) == 3)
    {
        j++;
       // printf("primo while ok \n");
    }
    
    while (fscanf(f2, "%d %s %s",&s[j].matricola,s[j].nome,s[j].cognome) == 3)
    {
        j++;
        //printf("secondo while ok \n");
    }
    
    
    for (int k = 0; k<dimensione_totale; k++)
    {
        
        //printf( "%d %s %s \n",s[k].matricola,s[k].nome,s[k].cognome);
    }
     
    fclose(f1);
    fclose(f2);
    return 0;
}


