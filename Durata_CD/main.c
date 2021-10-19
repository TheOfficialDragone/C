//
//  main.c
//  Durata_CD
//  Created by Rocco Carpi on 25/03/21.
//

#include <stdio.h>
#include <stdlib.h>


struct canzone
{
    int minuti;
    int secondi;
    char titolo[50];
    
};

int main(int argc, const char * argv[])
{
    struct canzone temp[15];
    
    FILE *f;
    
    f = fopen("input.txt", "r");
    
    if (!f)
    {
        perror("errore apertura file");
        return -1;
    }
    int i = 0;
    while(fscanf(f, " %d:%d%[^\n]",&temp[i].minuti,&temp[i].secondi,temp[i].titolo)==3)
    {
        //printf("sto leggendo \n");
        ++i;
    }
    float minuti_totali = 0;
    
    for (int k = 0; k < i; k++)
    {
        minuti_totali = minuti_totali + temp[k].minuti;
    }
    
    int secondi_totali = 0;
    
    for (int j = 0; j < i; j++)
    {
        secondi_totali = secondi_totali + temp[j].secondi;
      // minuti_totali = minuti_totali +(secondi_totali/60);
    }
    
    int ore = 0;
    int secondi_rimanenti = 0;
    
    
    
    minuti_totali = minuti_totali + (secondi_totali/60);
    if (minuti_totali >= 60)
    {
        ++ore;
        minuti_totali = minuti_totali - 60;
        
    }
    
    printf("la durata totale del cd è: %d ore: %2.f minuti \n",ore,minuti_totali);
    fclose(f);
    return 0;
}



