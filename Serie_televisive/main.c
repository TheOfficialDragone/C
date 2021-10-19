//
//  main.c
//  Serie_televisive
//
//  Created by Rocco Carpi on 04/02/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int MAXS = 100;
const int MAXL = 120;
const int MAXE = 30;

struct Serie{
  char titolo_serie[MAXL+1];
  int num_episodi;
  char* elenco_episodi[MAXE];
};

int main(int argc, const char * argv[]) {
    FILE *f;
    char s [121];
    int i = 0;
    struct Serie collezione[MAXS];     //array che contiene le struct delle serie
    
    if ((f=fopen("titoli.txt", "r")) == NULL){
        printf("errore nella apertura del file \n");
        exit(0);
    }
    
    int z;
    char stringa[1000];
    while (fscanf(f, " %[^\n]",s) == 1)
    {
        
        strcpy(collezione[i].titolo_serie,s);       //leggo e copio il titolo della serie
        fscanf(f, "%d", collezione[i].num_episodi);  //leggo numero episodi
        
        for(z = 0; z <collezione[i].num_episodi; z++)
        {
            fscanf(f, "%[^\n]",stringa);
            int lung = (int)strlen(stringa);
            collezione[i].elenco_episodi[z] = calloc(1,lung);
            strcpy(collezione[i].elenco_episodi[z], stringa);
            printf("%s \n",collezione[i].elenco_episodi[z]);
        }
        
        i++;
        
    }
    
    
    
    return 0;
}
