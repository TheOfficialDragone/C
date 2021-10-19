//
//  main.c
//  alberghi
//
//  Created by Rocco Carpi on 06/04/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome_albergo[21];
    char stelle[6];
    int n_servizi;
    char servizi_albergo[50];
    
} albergo;

int main(int argc, const char * argv[])
{
    FILE *f;
    f = fopen("alberghi.txt","r");
    
    if (!f)
    {
        perror("errore apertura file");
        exit(EXIT_FAILURE);
    }
    
    char t1[21];
    char t2[6];
    char t3[50];
    int p;
    
    int dimensione = 0;
    while (fscanf(f, "%s %s %d %[^\n]",t1,t2,&p,t3)==4) //calcolo dimensione file
    {
        ++dimensione;
    }
    
    fseek(f, 0, 0); //riavvologo il file
    albergo a[dimensione];
    //printf("dimensione %d",dimensione);
    int i =0;
    
    while (fscanf(f, "%s %s %d %[^\n]",a[i].nome_albergo,a[i].stelle,&a[i].n_servizi,a[i].servizi_albergo) == 4)    // leggo e alloco i valori nella struct
    {
        ++i;
    }
    
    int stelle_input = 0;
    char servizio[30];
    
    //INPUT
    printf("inserire il numero di stelle: ");
    scanf("%d",&stelle_input);
    
    printf("inserire il servizio: ");
    scanf("%s",servizio);
     
    unsigned long cont =0;
    int trovato = 0;

    for (int j = 0; j<9; j++)
    {
        cont = strlen(a[j].stelle);     //conto le stelle di ogni albergo
        
        if (stelle_input >= cont && strstr(a[j].servizi_albergo, servizio) != NULL) //se le stelle sono >= all'input e se è presente la sotto stringa allora ne ho trovato uno
        {
            ++trovato;
           // printf("%s %s %d %s \n",a[j].nome_albergo,a[j].stelle,a[j].n_servizi,a[j].servizi_albergo);
        }
    }
    
    printf("ci sono %d alberghi corrispondenti ai criteri di ricerca \n",trovato);
    
    fclose(f);
    return 0;
}
