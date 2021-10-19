//
//  main.c
//  Cambio_valuta
//
//  Created by Rocco Carpi on 16/02/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct valuta
{
    char nome[4];
    float tasso;
    int giorno,mese,anno;
};

int main(int argc, const char * argv[])
{
    char Nome_file[10];
    char codice_iso[4];
    int j;
    
    
    printf("inserire il codice iso: ");
    scanf("%s",codice_iso);
    
    for (j = 0; j<sizeof(codice_iso); j++)
    {
        codice_iso[j] = toupper(codice_iso[j]);
    }
    
    strcpy(Nome_file,codice_iso);
    strcat(Nome_file, ".txt");
    
    
    FILE *fp;
    fp = fopen(Nome_file, "r");
    
    if(!fp)
    {
        perror("errore nell'apertura del file");
        exit(EXIT_FAILURE);
    }
    printf("sto usando il file %s \n",Nome_file);
    
    struct valuta temporanea;
    int righe = 0;
    
    while (fscanf(fp, "  %[^,],%f,%d,%d,%d",temporanea.nome,&temporanea.tasso,&temporanea.giorno,&temporanea.mese,&temporanea.anno) == 5)
    {
        righe++;
    }
    
    //printf(" il file contiene %d righe \n",righe);
    
    struct valuta *tassi = malloc(righe*sizeof(struct valuta));
    if(!tassi)
    {
        perror(" errore nella malloc");
        exit(EXIT_FAILURE);
    }
    
    fseek(fp, 0, SEEK_SET);
    int riga = 0;
    while (fscanf(fp, "  %[^,],%f,%d,%d,%d",tassi[riga].nome,&tassi[riga].tasso,&tassi[riga].giorno,&tassi[riga].mese,&tassi[riga].anno) == 5)
    {
        //printf(" %s,%f,%d,%d,%d \n",tassi[riga].nome,tassi[riga].tasso,tassi[riga].giorno,tassi[riga].mese,tassi[riga].anno);
        riga++;
    }
    fclose(fp);
    
    int scelta;
    while (1)
    {
        
    printf("fare una scelta: ");
    scanf("%d",&scelta);
    
    switch (scelta)
    {
        case 0:
            printf("hai scelto di uscire.. \n");
            exit(EXIT_SUCCESS);
            break;
        case 1:
        {
            int mese;
            int anno;
            int giorni = 0;
            float media = 0;
            int i;
            printf("inserire mese: ");
            scanf("%d",&mese);
            
            printf("inserire anno: ");
            scanf("%d",&anno);
            
            for (i=0; i<righe; i++)
            {
                if (mese == tassi[i].mese && anno == tassi[i].anno)
                {
                    media += tassi[i].tasso;
                }
                giorni++;
            }
            if(giorni)
                printf("Il tasso di cambio medio  %s/EUR per il mese %02d-%04d era %f\n", tassi[0].nome, mese, anno, media/giorni);
            else
                printf("Il tasso di cambio medio  %s/EUR per il mese %02d-%04d non e' calcolabile\n", tassi[0].nome, mese, anno);
            break;
        }
        case 2:
        {
            int i;
            printf("Primi 10 valori letti:\n");
            for(i=0; i<10; ++i)
            {
                printf("%2d: %s\t%f\t%02d/%02d/%04d\n", i+1, tassi[i].nome, tassi[i].tasso, tassi[i].giorno, tassi[i].mese, tassi[i].anno);
            }
            break;
        }
        default:
            exit(EXIT_SUCCESS);
     }
    }
    return 0;
}






